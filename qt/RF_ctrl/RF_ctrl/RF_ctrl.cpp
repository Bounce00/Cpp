#include "RF_ctrl.h"

RF_ctrl::RF_ctrl(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	dev = new F_Device();
	int rvalue;
	RETRY:
	if (this->dev->init_Device() == -1)
	{
		rvalue = QMessageBox::warning(this, "Warning", "There is no available Serial Port!\r\n", "Retry", "Disable mode", "Quit");
		switch (rvalue)
		{
		case 0:
			goto RETRY;
		case 1:
			ui.tabWidget->setEnabled(false);
			break;
		case 2:
			this->destroyed();
			exit(0);
		default:
			ui.tabWidget->setEnabled(false);
		}
	}
	QObject::connect(ui.radioButton_DC_smallsig, &QAbstractButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.radioButton_DC_bigsig, &QAbstractButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.pushButton_DC_LO3, &QPushButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.comboBox_DC_BW, SIGNAL(currentIndexChanged(int)), this, SLOT(on_apply(int)));
	QObject::connect(ui.pushButton_DC_hmc939, &QPushButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.radioButton_enable_dc, &QAbstractButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.radioButton_bypass_dc, &QAbstractButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.pushButton_DC_hmc624, &QPushButton::clicked, this, &RF_ctrl::on_apply);

	QObject::connect(ui.radioButton_UC_smallsig, &QAbstractButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.radioButton_UC_bigsig, &QAbstractButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.pushButton_UC_LO3, &QPushButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.pushButton_UC_hmc624, &QPushButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.radioButton_enable_uc, &QAbstractButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.radioButton_bypass_uc, &QAbstractButton::clicked, this, &RF_ctrl::on_apply);
	QObject::connect(ui.pushButton_UC_hmc939, &QPushButton::clicked, this, &RF_ctrl::on_apply);

	QObject::connect(ui.pushButton_StartSweep, &QPushButton::clicked, this, &RF_ctrl::btn_FreqCtrl);
	QObject::connect(ui.pushButton_StopSweep, &QPushButton::clicked, this, &RF_ctrl::btn_FreqCtrl);
}

RF_ctrl::~RF_ctrl()
{
	dev->Apply_Cmd("sweep_stop", QByteArray::number(1), "W");
	delete dev;
}


void RF_ctrl::on_apply(int index_combo)
{
	double data_d;
	float text_LO3;
	float freq_LO3;
//	int ftw;
	int index_combobox;
//	QString msg;
	QByteArray data;
	QByteArray data1;
	QByteArray data2;
	QObject *object = QObject::sender();
	QPushButton  *push_button = qobject_cast<QPushButton *>(object);
	QRadioButton *radio_button = qobject_cast<QRadioButton *>(object);
	QComboBox *combobox_button = qobject_cast<QComboBox*>(object);
	QStringList apply;
	apply << "radioButton_DC_smallsig";	//0
	apply << "radioButton_DC_bigsig";	//1
	apply << "pushButton_DC_LO3";		//2
	apply << "comboBox_DC_BW";			//3
	apply << "pushButton_DC_hmc939";	//4
	apply << "radioButton_enable_dc";	//5
	apply << "radioButton_bypass_dc";	//6
	apply << "pushButton_DC_hmc624";	//7
	apply << "radioButton_UC_smallsig"; //8
	apply << "radioButton_UC_bigsig";	//9
	apply << "pushButton_UC_LO3";		//10
	apply << "radioButton_enable_uc";	//11
	apply << "radioButton_bypass_uc";	//12
	apply << "pushButton_UC_hmc624";	//13
	apply << "pushButton_UC_hmc939";	//14

	QString index;
	if (push_button)
	{
		index = push_button->objectName();
	}
	else if (radio_button)
	{
		index = radio_button->objectName();
	}
	else if (combobox_button)
	{
		index = combobox_button->objectName();
	}

	switch (apply.indexOf(index))
	{
	case 0: //select small signal
		ui.label_DC_hmc939->setText("(0-31dB)");
		ui.spinBox_DC_hmc939->setMaximum(31);
		data = QByteArray::number(31 - ui.spinBox_DC_hmc939->text().toInt(), 16);
		dev->Apply_Cmd("board_sel", QByteArray::number(2), "W");
		dev->Apply_Cmd("dc_sp2t_lna", QByteArray::number(1),"W"); //LNA path set to 1
		dev->Apply_Cmd("dc_hmc939", data);
//		ui.ch1->setPixmap(QString::fromUtf8(":/app/ch1-0.bmp"));
		break;
	case 1: //select big signal
		ui.label_DC_hmc939->setText("(0-62dB)");
		ui.spinBox_DC_hmc939->setMaximum(62);
		data_d = ui.spinBox_DC_hmc939->text().toDouble() / 2;
		data1 = QByteArray::number(31 - int(data_d), 16);
		data2 = QByteArray::number(30 - int(data_d), 16);
		dev->Apply_Cmd("board_sel", QByteArray::number(2), "W");
		dev->Apply_Cmd("dc_sp2t_lna", QByteArray::number(2), "W");
		dev->Apply_Cmd("dc_hmc939_l", data1);
		dev->Apply_Cmd("dc_hmc939", data2);
//		ui.ch1->setPixmap(QString::fromUtf8(":/app/ch1-1.bmp"));
		break;
	case 2: //set LO3
		text_LO3 = ui.spinBox_DC_LO3->text().toFloat();
		freq_LO3 = text_LO3 + 22.5;
//		ftw = int((freq_LO3 - 23.3) * 100 + 50.1);
		data = QByteArray::number(uint((freq_LO3 - 23.3) * 100 + 50.001), 16);
		ui.label_DC_LO3->setText(QString::number(freq_LO3));
		dev->Apply_Cmd("board_sel", QByteArray::number(1), "W");
		dev->Apply_Cmd("sfs_LO3", data, "W");
		dev->Apply_Cmd("board_sel", QByteArray::number(2), "W");
		if (text_LO3 < 2.5)
			dev->Apply_Cmd("dc_sw_fil", "22");
		else if (text_LO3 < 3.0)
			dev->Apply_Cmd("dc_sw_fil", "0c");
		else if (text_LO3 < 3.8)
			dev->Apply_Cmd("dc_sw_fil", "09");
		else if (text_LO3 < 5.0)
			dev->Apply_Cmd("dc_sw_fil", "21");
		else if (text_LO3 < 7.0)
			dev->Apply_Cmd("dc_sw_fil", "24");
		else if (text_LO3 < 10.05)
			dev->Apply_Cmd("dc_sw_fil", "0a");
		else
			dev->Apply_Cmd("dc_sw_fil", "10");
//		dev->Apply_Cmd("lo_en", QByteArray::number(1));
		break;
	case 3: //select bw
		index_combobox = ui.comboBox_DC_BW->currentIndex();
		dev->Apply_Cmd("dc_bw", QByteArray::number(index_combobox));

//		ui->ch2->setPixmap(QString::fromUtf8(":/app/ch2-1.bmp"));
		break;
	case 4: // set hmc939 and hmc939_L
		if (ui.radioButton_DC_smallsig->isChecked())
		{
			data = QByteArray::number(31 - ui.spinBox_DC_hmc939->text().toInt(), 16);
			dev->Apply_Cmd("board_sel", QByteArray::number(2), "W");
			dev->Apply_Cmd("dc_sp2t_lna", QByteArray::number(1), "W"); //LNA path set to 1
			dev->Apply_Cmd("dc_hmc939", data);
		}
		else
		{
			data_d = ui.spinBox_DC_hmc939->text().toDouble() / 2;
			data1 = QByteArray::number(31 - int(data_d), 16);
			data2 = QByteArray::number(30 - int(data_d), 16);
			dev->Apply_Cmd("board_sel", QByteArray::number(2), "W");
			dev->Apply_Cmd("dc_sp2t_lna", QByteArray::number(2), "W");
			dev->Apply_Cmd("dc_hmc939_l", data1);
			dev->Apply_Cmd("dc_hmc939", data2);
		}
		break;
	case 5: // enable dc
		ui.comboBox_DC_BW->setEnabled(true);
		dev->Apply_Cmd("board_sel", QByteArray::number(2), "W");
		dev->Apply_Cmd("dc_sp2t_rif", QByteArray::number(1), "W");
		break;
	case 6: // bypass dc
		ui.comboBox_DC_BW->setDisabled(true);
		dev->Apply_Cmd("board_sel", QByteArray::number(2), "W");
		dev->Apply_Cmd("dc_sp2t_rif", QByteArray::number(2), "W");
		break;
	case 7: // set hmc624
		data_d = ui.spinBox_DC_hmc624->text().toDouble();
		if (data_d - int(data_d) != 0.5)
			data_d = int(data_d + 0.5);
		ui.spinBox_DC_hmc624->setValue(data_d);
//		ui.spinBox_DC_hmc624.setText(data_d);
		data = QByteArray::number(uint(127 - data_d * 2), 16);
		dev->Apply_Cmd("board_sel", QByteArray::number(2), "W");
		dev->Apply_Cmd("dc_hmc624", data, "W");
		break;
	case 8: // select radioButton_UC_smallsig 
		ui.label_UC_hmc939->setText("(0-31dB)");
		ui.spinBox_DC_hmc939->setMaximum(31);
		data = QByteArray::number(31 - ui.spinBox_UC_hmc939->text().toInt(), 16);
		dev->Apply_Cmd("board_sel", QByteArray::number(3), "W");
		dev->Apply_Cmd("uc_sp2t_lna", QByteArray::number(1), "W"); //LNA path set to 1
		dev->Apply_Cmd("uc_hmc939", data,"W");
		break;
	case 9: // select radioButton_UC_bigsig 
		ui.label_UC_hmc939->setText("(0-62dB)");
		ui.spinBox_UC_hmc939->setMaximum(62);
		data_d = ui.spinBox_UC_hmc939->text().toDouble() / 2;
		data1 = QByteArray::number(31 - int(data_d), 16);
		data2 = QByteArray::number(30 - int(data_d), 16);
		dev->Apply_Cmd("board_sel", QByteArray::number(3), "W");
		dev->Apply_Cmd("uc_sp2t_lna", QByteArray::number(0), "W");
		dev->Apply_Cmd("uc_hmc939_l", data1, "W");
		dev->Apply_Cmd("uc_hmc939", data2, "W");
		break;
	case 10: //set UC_LO3
		text_LO3 = ui.spinBox_UC_LO3->text().toFloat();
		freq_LO3 = text_LO3 + 22.5;
		//		ftw = int((freq_LO3 - 23.3) * 100 + 50.1);
		data = QByteArray::number(uint((freq_LO3 - 23.3) * 100 + 50.001), 16);
		ui.label_UC_LO3->setText(QString::number(freq_LO3));
		dev->Apply_Cmd("board_sel", QByteArray::number(2), "W");
		dev->Apply_Cmd("sfs_LO3", data, "W");
		break;
	case 11: // select enable uc
		data_d = ui.spinBox_UC_hmc624->text().toDouble();
		if (data_d - int(data_d) != 0.5)
			data_d = int(data_d + 0.5);
		ui.spinBox_UC_hmc624->setValue(data_d);
		data = QByteArray::number(uint(127 - data_d * 2), 16);
		dev->Apply_Cmd("board_sel", QByteArray::number(3), "W");
		dev->Apply_Cmd("uc_sp2t_rif", QByteArray::number(2), "W");	//--------------
		dev->Apply_Cmd("uc_hmc624_3G", data, "W");
		break;
	case 12: // select bypass UC
		data_d = ui.spinBox_UC_hmc624->text().toDouble();
		if (data_d - int(data_d) != 0.5)
			data_d = int(data_d + 0.5);
		ui.spinBox_UC_hmc624->setValue(data_d);
		data = QByteArray::number(uint(127 - data_d * 2), 16);
		dev->Apply_Cmd("board_sel", QByteArray::number(3), "W");
		dev->Apply_Cmd("uc_sp2t_rif", QByteArray::number(1), "W"); //----------------
		break;
	case 13: // set hmc624
		data_d = ui.spinBox_UC_hmc624->text().toDouble();
		if (data_d - int(data_d) != 0.5)
			data_d = int(data_d + 0.5);
		ui.spinBox_UC_hmc624->setValue(data_d);
		data = QByteArray::number(uint(127 - data_d * 2), 16);
		dev->Apply_Cmd("board_sel", QByteArray::number(3), "W");
		dev->Apply_Cmd("uc_hmc624_3G", data, "W");
		break;
	case 14: //set hmc939
		if (ui.radioButton_UC_smallsig->isChecked())
		{
			data = QByteArray::number(31 - ui.spinBox_UC_hmc939->text().toInt(), 16);
			dev->Apply_Cmd("board_sel", QByteArray::number(3), "W");
			dev->Apply_Cmd("uc_sp2t_lna", QByteArray::number(1), "W"); //LNA path set to 1
			dev->Apply_Cmd("uc_hmc939", data);
		}
		else
		{
			data_d = ui.spinBox_UC_hmc939->text().toDouble() / 2;
			data1 = QByteArray::number(31 - int(data_d), 16);
			data2 = QByteArray::number(30 - int(data_d), 16);
			dev->Apply_Cmd("board_sel", QByteArray::number(3), "W");
			dev->Apply_Cmd("uc_sp2t_lna", QByteArray::number(0), "W");
			dev->Apply_Cmd("uc_hmc939_l", data1);
			dev->Apply_Cmd("uc_hmc939", data2);
		}
		break;
	
	default:
		qWarning("Button is inactived!");
		break;
	}
}

void RF_ctrl::btn_FreqCtrl()
{
	QObject *object = QObject::sender();
	QPushButton  *push_button = qobject_cast<QPushButton *>(object);
	QStringList apply;
	apply << "pushButton_StartSweep";	//0
	apply << "pushButton_StopSweep";	//1
	QString index;
	index = push_button->objectName();
	switch (apply.indexOf(index))
	{
	case 0:	// start sweep freq
		if (ui.SpinBox_StartFreq->value() > ui.SpinBox_EndFreq->value())
		{
			QMessageBox::warning(this, GBK::ToUnicode("警告"), "起始频率要小于停止频率!", GBK::ToUnicode("确定"));
		}
		else
		{
			QByteArray data;
			double freq_words = ui.SpinBox_StartFreq->value();
			int sweep_len = int((ui.SpinBox_EndFreq->value() - freq_words) / ui.SpinBox_FreqInc->value() + 1.0001);
			QProgressDialog dialog(GBK::ToUnicode("频率字传输中..."), GBK::ToUnicode("取消"), 0, sweep_len - 1, this);
			dialog.setWindowTitle(GBK::ToUnicode("频率传输"));
			dialog.setWindowModality(Qt::WindowModal);
			dialog.show();
			dev->Apply_Cmd("board_sel", QByteArray::number(1),"W");
			dev->Apply_Cmd("delay_time", QByteArray::number(ui.spinBox_HoldTime->value() * 100000, 16), "W");
			dev->Apply_Cmd("sweep_repeat", QByteArray::number(ui.spinBox_RepeatTimes->value(), 16), "W");
			for (int i = 0; i < sweep_len; i++)//已知最大值不超过2048
			{
				dialog.setValue(i);
				QCoreApplication::processEvents();
				data = QByteArray::number(uint((freq_words - 0.8) * 100 + 50.001), 16);
				qDebug("ADDR:");
				dev->Apply_Cmd("sweep_addr", QByteArray::number(i, 16), "W");
				qDebug("DATA:");
				dev->Apply_Cmd("sweep_data", data, "W");
				if (dialog.wasCanceled())
					break;
				freq_words += ui.SpinBox_FreqInc->value();
			}
			dialog.setValue(sweep_len);
			qDebug("Transmate finished!");
			dev->Apply_Cmd("sweep_start", QByteArray::number(1),"W");
		}
		break;
	case 1:
		dev->Apply_Cmd("sweep_stop", QByteArray::number(1),"W");
	default:
		break;
	}
}


