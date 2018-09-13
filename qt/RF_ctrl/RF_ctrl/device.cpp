#include "fpga.h"
#include <QMessageBox>

F_Device::F_Device()
{

	//            QString name,					start_addr,  end_addr,  id
	reg_op.add_reg("board_sel",						0,			0,		0);
	// sfs
	reg_op.add_reg("sfs_LO3",						0,			15,		11);	//11
	// DC
	reg_op.add_reg("dc_sp2t_rif",					0,			1,		21);	//21
	reg_op.add_reg("dc_sp2t_lna",					0,			0,		22);	//22
	reg_op.add_reg("dc_hmc939",						0,			4,		23);	//23
	reg_op.add_reg("dc_hmc939_l",					8,			12,		23);	//23
	reg_op.add_reg("dc_sw_fil",						16,			21,		23);	//23
	reg_op.add_reg("dc_bw",							0,			1,		24);	//24
	reg_op.add_reg("dc_hmc624",						0,			6,		25);	//25
	// UC
	reg_op.add_reg("uc_sp2t_rif",					0,			1,		31);	//31
	reg_op.add_reg("uc_sp2t_lna",					0,			0,		32);	//32
	reg_op.add_reg("uc_hmc939",						0,			4,		33);	//33
	reg_op.add_reg("uc_hmc939_l",					0,			4,		34);	//34
	reg_op.add_reg("uc_hmc624_3G",					0,			6,		35);	//35
	// Sweep Frequency
	reg_op.add_reg("sweep_addr",					0,			11,		12);	//12
	reg_op.add_reg("sweep_data",					0,			15,		13);	//13
	reg_op.add_reg("delay_time",					0,			31,		14);	//14
	reg_op.add_reg("sweep_start",					0,			1,		15);	//15
	reg_op.add_reg("sweep_repeat",					0,			32,		16);	//16
	reg_op.add_reg("sweep_stop",					0,			1,		17);	//17

	qDebug("Finished to Map Reg.");
}

F_Device::~F_Device()
{
	
}

int F_Device::init_Device()
{
	int tmp = reg_op.reg_init();
	
	if (tmp == 0)
	{
		this->Apply_Cmd("board_sel", "1","W");
		this->Apply_Cmd("sfs_LO3", "aa","W");
		//	this->Apply_Cmd("lo_en", "1");
		// DC board
		this->Apply_Cmd("board_sel", "2","W");
		this->Apply_Cmd("dc_sp2t_rif", "1","W"); // dc
		this->Apply_Cmd("dc_sp2t_lna", "1","W");
		this->Apply_Cmd("dc_hmc939", "f");
		this->Apply_Cmd("dc_hmc939_l", "f");
		this->Apply_Cmd("dc_sw_fil", "22"); // 0-3G
		this->Apply_Cmd("dc_bw", "0","W");
		this->Apply_Cmd("dc_hmc624", "3f","W");
		// UC board
		this->Apply_Cmd("board_sel", "3", "W");
		this->Apply_Cmd("uc_sp2t_rif", "2", "W"); // uc
		this->Apply_Cmd("uc_sp2t_lna", "1", "W");
		this->Apply_Cmd("uc_hmc939", "0", "W");
		this->Apply_Cmd("uc_hmc939_l", "0", "W");
		this->Apply_Cmd("uc_hmc624_3G", "0", "W");

		qDebug("Finished to Init Device.");
		return 0;
	}
	else
		return tmp;
		
//	return tmp;
}

void F_Device::write_device(QByteArray addr, QByteArray data)
{
	reg_op.write_reg(addr, data);
}

QByteArray F_Device::read_device(QByteArray addr)
{
	return reg_op.read_reg(addr);
}

void F_Device::Apply_Cmd(QString name, QByteArray qdata, QString action)
{
	qint8 rd;
	QByteArray a;
	if (action == "W")
	{
		
		a = QByteArray::number(reg_op.get_id(name));
		this->write_device(QByteArray::number(reg_op.get_id(name)), qdata);
//		qDebug("Info: Write %s", qPrintable(qdata));
	}
	else
	{
		a = QByteArray::number(reg_op.get_id(name));
		rd = reg_op.get_id(name);
		if (rd == -1)
			QMessageBox::warning(NULL, "警告", "程序出错\n错误地址：device.cpp/F_Device:Apply_Cmd/61", "确认");
		else
		{
			QByteArray rd_data = this->read_device(QByteArray::number(rd));
			if (rd_data != "EOF")
			{
//				qDebug("Info: Read %s", qPrintable(rd_data));
				quint32 rd_data_int = rd_data.toUInt(0, 16);
				// quint32 qdata_int = qdata.toUInt(0,16);
//				quint8 tt = reg_op.get_reg_len(name);
//				quint8 tt2 = reg_op.get_start_addr(name);
				quint32 write_data_int = (rd_data_int & (~(((1 << reg_op.get_reg_len(name)) - 1) << reg_op.get_start_addr(name)))) | ((qdata.toUInt(0, 16)) << reg_op.get_start_addr(name));
				QByteArray write_data = QByteArray::number(write_data_int, 16);
//				qDebug("Info: Write %s", qPrintable(write_data));
				this->write_device(QByteArray::number(reg_op.get_id(name)), write_data);
			}
		}
	}
}

