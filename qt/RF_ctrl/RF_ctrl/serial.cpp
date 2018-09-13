#include "fpga.h"
#include <QTextStream>
#include <QtSerialPort/qserialportglobal.h>
#include <QApplication>



Serial::Serial()
{
	this->serial = new QSerialPort;
}

Serial::~Serial()
{
	delete this->serial;
}

void Serial::config_serial(QString com)//prevese
{
	//serial_info = new QSerialPortInfo;
	this->serial->setPortName(com);
	this->serial->setBaudRate(QSerialPort::Baud115200);
	this->serial->setDataBits(QSerialPort::Data8);
	this->serial->setStopBits(QSerialPort::OneStop);
	this->serial->setParity(QSerialPort::NoParity);
	this->serial->setFlowControl(QSerialPort::NoFlowControl);

}

void Serial::open_serial(QIODevice::OpenMode mode)
{
	QTextStream out(stdout);
	this->serial->open(mode);
	out << this->serial->errorString();
}

void Serial::close_serial()
{
	this->serial->close();
}

QList<QSerialPortInfo> Serial::get_available_ports()
{
	return QSerialPortInfo::availablePorts();
}

QString Serial::get_sp_available_ports()
{
	int COM_enum = 0;
	QTime qtm;
	QByteArray line;
	QString com_port = "NONE";
	QList<QSerialPortInfo> serialPortInfoList = this->get_available_ports();

	foreach(const QSerialPortInfo &serialPortInfo, serialPortInfoList)
	{
		this->config_serial(serialPortInfo.portName());
		//´ò¿ª´®¿Ú
		this->serial->open(QIODevice::ReadWrite);
		qDebug("Open %s, %s", qPrintable(serialPortInfo.portName()), this->serial->errorString().toStdString().c_str());
		this->serial->readAll();

		this->serial->write("dw 0x00 = 0x00\r");
		qtm = QTime::currentTime().addMSecs(300);
		line = this->readline_serial();
		qDebug("line length:,%d\n", line.length());
		if (line.length() < 1)
		{
			this->serial->close();
			COM_enum += 1;
			if(COM_enum>=5)
				qWarning("%s is not avaliable, skipped!", qPrintable(serialPortInfo.portName()));
			continue;
		}
//		while (!(line.length() > 15 && line.mid(17, 8) == QByteArray("53575246")))
//		{
//			if (qtm < QTime::currentTime())
//			{
//				goto C1;
//			}
//			line = this->readline_serial();
//		}
		com_port = serialPortInfo.portName();
		this->serial->close();
		qDebug("Using %s, Finished to Scan COM!", qPrintable(serialPortInfo.portName()));
		
	}
	return com_port;
}


void Serial::write_serial(const QByteArray &msg)
{
	serial->readAll();
	this->serial->write(msg);
	this->serial->flush();

}
/*
QByteArray Serial::read_serial()
{
	return "";
}
*/
QByteArray Serial::readline_serial()
{
	// while(~(this->serial->waitForReadyRead(300)));
	QByteArray serial_buffer_temp;
	QTextStream out(stdout);
	if (this->serial->waitForBytesWritten(300)) {
		// read response
		if (this->serial->waitForReadyRead(300)) {
			serial_buffer_temp = this->serial->readAll();
		}
	}
	this->user_serial_buffer.append(serial_buffer_temp);
	int LF = this->user_serial_buffer.indexOf("\n");
	QByteArray temp;
	if (LF == -1)
	{
		return QByteArray("");
	}
	else
	{
		temp = this->user_serial_buffer.mid(0, LF);
		this->user_serial_buffer = this->user_serial_buffer.mid(LF + 1, -1);
		return temp;

	}
}

