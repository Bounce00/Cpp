#include "fpga.h"
#include <math.h>
#include <QMessageBox>


reg_operation::reg_operation()
{
	
}

reg_operation::~reg_operation()
{
	this->serial.close_serial();
}

int reg_operation::reg_init()
{
	QString com_port = this->serial.get_sp_available_ports();
	if (com_port != "NONE")
	{
		this->serial.config_serial(com_port);
		this->serial.open_serial(QSerialPort::ReadWrite);
		return 0;
	}
	else
		return -1;
}


void reg_operation::add_reg(QString name, quint8 start_addr, quint8 end_addr, quint8 id)
{
	this->reg_name << name;
	this->reg_start_addr << start_addr;
	this->reg_end_addr << end_addr;
	this->reg_id << id;
	this->reg_len << abs(start_addr - end_addr) + 1;
}

void reg_operation::del_reg(QString reg_name)
{

}

quint8 reg_operation::get_start_addr(QString name)
{
	int index = this->reg_name.indexOf(name);
	return this->reg_start_addr.at(index);
}

quint8 reg_operation::get_end_addr(QString name)
{
	int index = this->reg_name.indexOf(name);
	return this->reg_end_addr.at(index);
}

quint8 reg_operation::get_reg_len(QString name)
{
	int index = this->reg_name.indexOf(name);
	return this->reg_len.at(index);
}

qint8 reg_operation::get_id(QString name)
{
	int index = this->reg_name.indexOf(name);
	return this->reg_id.at(index);
}

QByteArray reg_operation::read_reg(QByteArray addr)
{
	QTime qtm;
	int i = 0;
	QByteArray line;
	QByteArray x4addr = QByteArray::number(addr.toUInt(0, 10)*4, 16); // *4
	QByteArray query_cmd = "dw 0x" + x4addr + "\r";
	qDebug("Read: %s", qPrintable(query_cmd));
	
RREAD:
	serial.write_serial(query_cmd);
	qtm = QTime::currentTime().addMSecs(30);
	do {
		if (qtm < QTime::currentTime())
		{
			if (i < 5)
			{
				i++;
				goto RREAD;
			}
			else
				return QByteArray("EOF");

		}
		line = serial.readline_serial();
	} while (line.length() < 15 || line.mid(0, 4) != "\r[0x");
	qDebug("Get Read: %s", qPrintable(line.mid(17, 8)));
	return line.mid(17, 8);
	return 0;
}

void reg_operation::write_reg(QByteArray addr, QByteArray data)
{
	int i = 0;
	int j = 0;
	QByteArray msg;
	QTime qtm;
	QByteArray line;
	QByteArray x4addr = QByteArray::number(addr.toUInt(0, 10)*4 , 16); // *4
	QByteArray write_cmd = "dw 0x" + x4addr + " = 0x" + data + "\r";

	qDebug("Write: %s", qPrintable(write_cmd));
	
RWRITE:
	serial.write_serial(write_cmd);
	qDebug("Reply Write: test");
	qtm = QTime::currentTime().addMSecs(100);
	do {
		if (qtm < QTime::currentTime())
		{
			if (i < 5)
			{
				i++;
				goto RWRITE;
			}
			else
			{
				msg = "read 0x" + addr + "Failed!";
				QMessageBox::warning(NULL, "WARNING", msg, QMessageBox::Yes, QMessageBox::Yes);
				return;
			}
		}
		line = serial.readline_serial();
	} while (line.length() < 15 || line.mid(0, 6) != "\rWrite");
	qDebug("Reply Write: %s", qPrintable(line));
	if (line.mid(24, 8).toUInt() != data.toUInt())
	{
		if (j < 3)
		{
			j++;
			goto RWRITE;
		}
		else
		{
			QMessageBox::warning(NULL, "WARNING", "Write Failed!!!", QMessageBox::Yes, QMessageBox::Yes);
		}
	}
}