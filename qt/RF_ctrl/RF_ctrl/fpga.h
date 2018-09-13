#ifndef FPGA_H
#define FPGA_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QIODevice>
#include <QTime>

class Serial
{
public:
	QSerialPort *serial;
	Serial();
	~Serial();
	QByteArray readline_serial();
	void config_serial(QString com);
	void open_serial(QIODevice::OpenMode mode);
	void close_serial();
	QList<QSerialPortInfo> get_available_ports();
	QString get_sp_available_ports();
	void write_serial(const QByteArray &msg);
//	QByteArray read_serial();
private:
	//QSerialPortInfo *serial_info;
	QByteArray user_serial_buffer;
};

class reg_operation
{
public:
	reg_operation();
	~reg_operation();
	int reg_init();
	void add_reg(QString name, quint8 start_addr, quint8 end_addr, quint8 id);
	void del_reg(QString name);
	quint8 get_start_addr(QString name);
	quint8 get_end_addr(QString name);
	quint8 get_reg_len(QString name);
	qint8 get_id(QString name);
	void write_reg(QByteArray addr, QByteArray data);
	QByteArray read_reg(QByteArray addr);
private:
	Serial serial;
	QList<QString> reg_name;
	QList<quint8> reg_start_addr;
	QList<quint8> reg_end_addr;
	QList<quint8> reg_len;
	QList<quint8> reg_id;
};

class F_Device
{
public:
	F_Device();
	~F_Device();
	void reg_mapper();
	int init_Device();
	void write_device(QByteArray addr, QByteArray data);
	QByteArray read_device(QByteArray addr);
	void Apply_Cmd(QString name, QByteArray qdata, QString action = "RW");
private:
	reg_operation reg_op;
};


#endif // !fpga_H
