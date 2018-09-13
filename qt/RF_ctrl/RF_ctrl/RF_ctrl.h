#pragma once
#ifndef RF_CTRL_H
#define RF_CTRL_H


#include <QtWidgets/QMainWindow>
#include "ui_RF_ctrl.h"
#include <QPushButton>
#include <QSpinBox>
#include <QAbstractButton>
#include <QComboBox>
#include <QString>
#include <QBitArray>
#include <QProgressDialog> 
#include <QMessageBox>
#include "fpga.h"
#include "GBK.h"

class RF_ctrl : public QMainWindow
{
	Q_OBJECT

public:
	RF_ctrl(QWidget *parent = Q_NULLPTR);
	~RF_ctrl();
	
private slots:
	void on_apply(int index_combo = 1);
	void btn_FreqCtrl();
	
private:
	Ui::RF_ctrlClass ui;
	F_Device *dev;
};


#endif // !RF_CTRL_H


