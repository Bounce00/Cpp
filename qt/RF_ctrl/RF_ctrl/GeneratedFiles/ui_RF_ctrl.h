/********************************************************************************
** Form generated from reading UI file 'RF_ctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RF_CTRL_H
#define UI_RF_CTRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RF_ctrlClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *DC;
    QGroupBox *DC_input_param;
    QGroupBox *DC_input_freq;
    QWidget *layoutWidget_10;
    QHBoxLayout *DC_LO3_freq;
    QLabel *label_input_reduction_10;
    QLabel *label_DC_LO3;
    QLabel *label_input_reduction_13;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *spinBox_DC_LO3;
    QLabel *label_input_reduction_8;
    QLabel *label;
    QPushButton *pushButton_DC_LO3;
    QGroupBox *DC_input_bw;
    QWidget *layoutWidget_9;
    QHBoxLayout *DC_in_bw_sel;
    QLabel *label_input_reduction_9;
    QComboBox *comboBox_DC_BW;
    QWidget *layoutWidget_8;
    QHBoxLayout *small_big_sel;
    QRadioButton *radioButton_DC_smallsig;
    QRadioButton *radioButton_DC_bigsig;
    QGroupBox *DC_sel;
    QWidget *layoutWidget_13;
    QHBoxLayout *DC_sel_ctrl;
    QRadioButton *radioButton_enable_dc;
    QRadioButton *radioButton_bypass_dc;
    QGroupBox *DC_if_att;
    QLabel *label_input_reduction_15;
    QLabel *label_input_reduction_16;
    QDoubleSpinBox *spinBox_DC_hmc624;
    QPushButton *pushButton_DC_hmc624;
    QGroupBox *DC_rf_att;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinBox_DC_hmc939;
    QLabel *label_input_reduction_6;
    QLabel *label_DC_hmc939;
    QPushButton *pushButton_DC_hmc939;
    QWidget *UC;
    QGroupBox *UC_rf_att;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinBox_UC_hmc939;
    QLabel *label_input_reduction_23;
    QLabel *label_UC_hmc939;
    QPushButton *pushButton_UC_hmc939;
    QGroupBox *UC_sel;
    QWidget *layoutWidget_5;
    QHBoxLayout *UC_sel_ctrl;
    QRadioButton *radioButton_enable_uc;
    QRadioButton *radioButton_bypass_uc;
    QGroupBox *UC_output_param;
    QWidget *layoutWidget3;
    QHBoxLayout *UC_small_big_sel;
    QRadioButton *radioButton_UC_smallsig;
    QRadioButton *radioButton_UC_bigsig;
    QGroupBox *UC_if_att;
    QDoubleSpinBox *spinBox_UC_hmc624;
    QLabel *label_input_reduction_19;
    QLabel *label_UC_hmc624;
    QPushButton *pushButton_UC_hmc624;
    QGroupBox *UC_output_freq;
    QWidget *layoutWidget_4;
    QHBoxLayout *UC_LO3;
    QLabel *label_input_reduction_21;
    QLabel *label_UC_LO3;
    QLabel *label_input_reduction_22;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *spinBox_UC_LO3;
    QLabel *label_input_reduction_12;
    QLabel *label_2;
    QPushButton *pushButton_UC_LO3;
    QWidget *sweep_ctrl;
    QGroupBox *groupBox;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QDoubleSpinBox *SpinBox_StartFreq;
    QLabel *label_4;
    QDoubleSpinBox *SpinBox_EndFreq;
    QLabel *label_5;
    QDoubleSpinBox *SpinBox_FreqInc;
    QLabel *label_6;
    QSpinBox *spinBox_HoldTime;
    QLabel *label_7;
    QSpinBox *spinBox_RepeatTimes;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_StartSweep;
    QPushButton *pushButton_StopSweep;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RF_ctrlClass)
    {
        if (RF_ctrlClass->objectName().isEmpty())
            RF_ctrlClass->setObjectName(QStringLiteral("RF_ctrlClass"));
        RF_ctrlClass->resize(307, 834);
        centralWidget = new QWidget(RF_ctrlClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        DC = new QWidget();
        DC->setObjectName(QStringLiteral("DC"));
        DC_input_param = new QGroupBox(DC);
        DC_input_param->setObjectName(QStringLiteral("DC_input_param"));
        DC_input_param->setGeometry(QRect(10, 20, 261, 171));
        DC_input_freq = new QGroupBox(DC_input_param);
        DC_input_freq->setObjectName(QStringLiteral("DC_input_freq"));
        DC_input_freq->setGeometry(QRect(10, 50, 241, 71));
        layoutWidget_10 = new QWidget(DC_input_freq);
        layoutWidget_10->setObjectName(QStringLiteral("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(10, 50, 134, 16));
        DC_LO3_freq = new QHBoxLayout(layoutWidget_10);
        DC_LO3_freq->setSpacing(6);
        DC_LO3_freq->setContentsMargins(11, 11, 11, 11);
        DC_LO3_freq->setObjectName(QStringLiteral("DC_LO3_freq"));
        DC_LO3_freq->setContentsMargins(0, 0, 0, 0);
        label_input_reduction_10 = new QLabel(layoutWidget_10);
        label_input_reduction_10->setObjectName(QStringLiteral("label_input_reduction_10"));

        DC_LO3_freq->addWidget(label_input_reduction_10);

        label_DC_LO3 = new QLabel(layoutWidget_10);
        label_DC_LO3->setObjectName(QStringLiteral("label_DC_LO3"));

        DC_LO3_freq->addWidget(label_DC_LO3);

        label_input_reduction_13 = new QLabel(layoutWidget_10);
        label_input_reduction_13->setObjectName(QStringLiteral("label_input_reduction_13"));
        label_input_reduction_13->setMaximumSize(QSize(20, 16777215));

        DC_LO3_freq->addWidget(label_input_reduction_13);

        layoutWidget = new QWidget(DC_input_freq);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 21, 231, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBox_DC_LO3 = new QDoubleSpinBox(layoutWidget);
        spinBox_DC_LO3->setObjectName(QStringLiteral("spinBox_DC_LO3"));
        spinBox_DC_LO3->setMinimumSize(QSize(75, 0));
        spinBox_DC_LO3->setDecimals(2);
        spinBox_DC_LO3->setMinimum(0.55);
        spinBox_DC_LO3->setMaximum(18);
        spinBox_DC_LO3->setValue(2);

        horizontalLayout_2->addWidget(spinBox_DC_LO3);

        label_input_reduction_8 = new QLabel(layoutWidget);
        label_input_reduction_8->setObjectName(QStringLiteral("label_input_reduction_8"));
        label_input_reduction_8->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_2->addWidget(label_input_reduction_8);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        pushButton_DC_LO3 = new QPushButton(layoutWidget);
        pushButton_DC_LO3->setObjectName(QStringLiteral("pushButton_DC_LO3"));
        pushButton_DC_LO3->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_2->addWidget(pushButton_DC_LO3);

        DC_input_bw = new QGroupBox(DC_input_param);
        DC_input_bw->setObjectName(QStringLiteral("DC_input_bw"));
        DC_input_bw->setGeometry(QRect(10, 125, 241, 36));
        layoutWidget_9 = new QWidget(DC_input_bw);
        layoutWidget_9->setObjectName(QStringLiteral("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(10, 10, 231, 22));
        DC_in_bw_sel = new QHBoxLayout(layoutWidget_9);
        DC_in_bw_sel->setSpacing(6);
        DC_in_bw_sel->setContentsMargins(11, 11, 11, 11);
        DC_in_bw_sel->setObjectName(QStringLiteral("DC_in_bw_sel"));
        DC_in_bw_sel->setContentsMargins(0, 0, 0, 0);
        label_input_reduction_9 = new QLabel(layoutWidget_9);
        label_input_reduction_9->setObjectName(QStringLiteral("label_input_reduction_9"));

        DC_in_bw_sel->addWidget(label_input_reduction_9);

        comboBox_DC_BW = new QComboBox(layoutWidget_9);
        comboBox_DC_BW->setObjectName(QStringLiteral("comboBox_DC_BW"));
        comboBox_DC_BW->setMinimumSize(QSize(70, 0));
        comboBox_DC_BW->setMaximumSize(QSize(70, 16777215));
        comboBox_DC_BW->setAcceptDrops(false);

        DC_in_bw_sel->addWidget(comboBox_DC_BW);

        layoutWidget_8 = new QWidget(DC_input_param);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(20, 20, 240, 18));
        small_big_sel = new QHBoxLayout(layoutWidget_8);
        small_big_sel->setSpacing(6);
        small_big_sel->setContentsMargins(11, 11, 11, 11);
        small_big_sel->setObjectName(QStringLiteral("small_big_sel"));
        small_big_sel->setContentsMargins(0, 0, 0, 0);
        radioButton_DC_smallsig = new QRadioButton(layoutWidget_8);
        radioButton_DC_smallsig->setObjectName(QStringLiteral("radioButton_DC_smallsig"));
        radioButton_DC_smallsig->setChecked(true);

        small_big_sel->addWidget(radioButton_DC_smallsig);

        radioButton_DC_bigsig = new QRadioButton(layoutWidget_8);
        radioButton_DC_bigsig->setObjectName(QStringLiteral("radioButton_DC_bigsig"));
        radioButton_DC_bigsig->setEnabled(true);
        radioButton_DC_bigsig->setAutoRepeatDelay(300);

        small_big_sel->addWidget(radioButton_DC_bigsig);

        DC_sel = new QGroupBox(DC);
        DC_sel->setObjectName(QStringLiteral("DC_sel"));
        DC_sel->setGeometry(QRect(10, 260, 261, 51));
        layoutWidget_13 = new QWidget(DC_sel);
        layoutWidget_13->setObjectName(QStringLiteral("layoutWidget_13"));
        layoutWidget_13->setGeometry(QRect(30, 20, 240, 18));
        DC_sel_ctrl = new QHBoxLayout(layoutWidget_13);
        DC_sel_ctrl->setSpacing(6);
        DC_sel_ctrl->setContentsMargins(11, 11, 11, 11);
        DC_sel_ctrl->setObjectName(QStringLiteral("DC_sel_ctrl"));
        DC_sel_ctrl->setContentsMargins(0, 0, 0, 0);
        radioButton_enable_dc = new QRadioButton(layoutWidget_13);
        radioButton_enable_dc->setObjectName(QStringLiteral("radioButton_enable_dc"));
        radioButton_enable_dc->setChecked(true);

        DC_sel_ctrl->addWidget(radioButton_enable_dc);

        radioButton_bypass_dc = new QRadioButton(layoutWidget_13);
        radioButton_bypass_dc->setObjectName(QStringLiteral("radioButton_bypass_dc"));

        DC_sel_ctrl->addWidget(radioButton_bypass_dc);

        DC_if_att = new QGroupBox(DC);
        DC_if_att->setObjectName(QStringLiteral("DC_if_att"));
        DC_if_att->setGeometry(QRect(10, 320, 261, 51));
        label_input_reduction_15 = new QLabel(DC_if_att);
        label_input_reduction_15->setObjectName(QStringLiteral("label_input_reduction_15"));
        label_input_reduction_15->setGeometry(QRect(100, 25, 15, 16));
        label_input_reduction_15->setMaximumSize(QSize(15, 16777215));
        label_input_reduction_16 = new QLabel(DC_if_att);
        label_input_reduction_16->setObjectName(QStringLiteral("label_input_reduction_16"));
        label_input_reduction_16->setGeometry(QRect(114, 25, 60, 16));
        label_input_reduction_16->setMaximumSize(QSize(60, 16777215));
        spinBox_DC_hmc624 = new QDoubleSpinBox(DC_if_att);
        spinBox_DC_hmc624->setObjectName(QStringLiteral("spinBox_DC_hmc624"));
        spinBox_DC_hmc624->setGeometry(QRect(23, 24, 75, 20));
        spinBox_DC_hmc624->setMinimumSize(QSize(75, 0));
        spinBox_DC_hmc624->setDecimals(1);
        spinBox_DC_hmc624->setMaximum(63.5);
        spinBox_DC_hmc624->setSingleStep(0.5);
        spinBox_DC_hmc624->setValue(32);
        pushButton_DC_hmc624 = new QPushButton(DC_if_att);
        pushButton_DC_hmc624->setObjectName(QStringLiteral("pushButton_DC_hmc624"));
        pushButton_DC_hmc624->setGeometry(QRect(182, 21, 70, 23));
        pushButton_DC_hmc624->setMaximumSize(QSize(70, 16777215));
        DC_rf_att = new QGroupBox(DC);
        DC_rf_att->setObjectName(QStringLiteral("DC_rf_att"));
        DC_rf_att->setGeometry(QRect(10, 200, 261, 51));
        layoutWidget1 = new QWidget(DC_rf_att);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(21, 21, 231, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        spinBox_DC_hmc939 = new QSpinBox(layoutWidget1);
        spinBox_DC_hmc939->setObjectName(QStringLiteral("spinBox_DC_hmc939"));
        spinBox_DC_hmc939->setMinimumSize(QSize(75, 0));
        spinBox_DC_hmc939->setMaximumSize(QSize(88, 16777215));
        spinBox_DC_hmc939->setReadOnly(false);
        spinBox_DC_hmc939->setValue(16);

        horizontalLayout_3->addWidget(spinBox_DC_hmc939);

        label_input_reduction_6 = new QLabel(layoutWidget1);
        label_input_reduction_6->setObjectName(QStringLiteral("label_input_reduction_6"));
        label_input_reduction_6->setMaximumSize(QSize(15, 16777215));

        horizontalLayout_3->addWidget(label_input_reduction_6);

        label_DC_hmc939 = new QLabel(layoutWidget1);
        label_DC_hmc939->setObjectName(QStringLiteral("label_DC_hmc939"));
        label_DC_hmc939->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label_DC_hmc939);

        pushButton_DC_hmc939 = new QPushButton(layoutWidget1);
        pushButton_DC_hmc939->setObjectName(QStringLiteral("pushButton_DC_hmc939"));
        pushButton_DC_hmc939->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_3->addWidget(pushButton_DC_hmc939);

        tabWidget->addTab(DC, QString());
        DC_if_att->raise();
        DC_input_param->raise();
        DC_sel->raise();
        DC_rf_att->raise();
        UC = new QWidget();
        UC->setObjectName(QStringLiteral("UC"));
        UC_rf_att = new QGroupBox(UC);
        UC_rf_att->setObjectName(QStringLiteral("UC_rf_att"));
        UC_rf_att->setGeometry(QRect(10, 290, 261, 51));
        layoutWidget2 = new QWidget(UC_rf_att);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(21, 21, 231, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        spinBox_UC_hmc939 = new QSpinBox(layoutWidget2);
        spinBox_UC_hmc939->setObjectName(QStringLiteral("spinBox_UC_hmc939"));
        spinBox_UC_hmc939->setMinimumSize(QSize(75, 0));
        spinBox_UC_hmc939->setMaximumSize(QSize(88, 16777215));
        spinBox_UC_hmc939->setReadOnly(false);
        spinBox_UC_hmc939->setMaximum(62);

        horizontalLayout_6->addWidget(spinBox_UC_hmc939);

        label_input_reduction_23 = new QLabel(layoutWidget2);
        label_input_reduction_23->setObjectName(QStringLiteral("label_input_reduction_23"));
        label_input_reduction_23->setMaximumSize(QSize(15, 16777215));

        horizontalLayout_6->addWidget(label_input_reduction_23);

        label_UC_hmc939 = new QLabel(layoutWidget2);
        label_UC_hmc939->setObjectName(QStringLiteral("label_UC_hmc939"));
        label_UC_hmc939->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_6->addWidget(label_UC_hmc939);

        pushButton_UC_hmc939 = new QPushButton(layoutWidget2);
        pushButton_UC_hmc939->setObjectName(QStringLiteral("pushButton_UC_hmc939"));
        pushButton_UC_hmc939->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_6->addWidget(pushButton_UC_hmc939);

        UC_sel = new QGroupBox(UC);
        UC_sel->setObjectName(QStringLiteral("UC_sel"));
        UC_sel->setGeometry(QRect(10, 230, 261, 51));
        layoutWidget_5 = new QWidget(UC_sel);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(20, 20, 234, 18));
        UC_sel_ctrl = new QHBoxLayout(layoutWidget_5);
        UC_sel_ctrl->setSpacing(6);
        UC_sel_ctrl->setContentsMargins(11, 11, 11, 11);
        UC_sel_ctrl->setObjectName(QStringLiteral("UC_sel_ctrl"));
        UC_sel_ctrl->setContentsMargins(0, 0, 0, 0);
        radioButton_enable_uc = new QRadioButton(layoutWidget_5);
        radioButton_enable_uc->setObjectName(QStringLiteral("radioButton_enable_uc"));
        radioButton_enable_uc->setChecked(true);

        UC_sel_ctrl->addWidget(radioButton_enable_uc);

        radioButton_bypass_uc = new QRadioButton(layoutWidget_5);
        radioButton_bypass_uc->setObjectName(QStringLiteral("radioButton_bypass_uc"));

        UC_sel_ctrl->addWidget(radioButton_bypass_uc);

        UC_output_param = new QGroupBox(UC);
        UC_output_param->setObjectName(QStringLiteral("UC_output_param"));
        UC_output_param->setGeometry(QRect(10, 20, 261, 131));
        layoutWidget3 = new QWidget(UC_output_param);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 20, 240, 18));
        UC_small_big_sel = new QHBoxLayout(layoutWidget3);
        UC_small_big_sel->setSpacing(6);
        UC_small_big_sel->setContentsMargins(11, 11, 11, 11);
        UC_small_big_sel->setObjectName(QStringLiteral("UC_small_big_sel"));
        UC_small_big_sel->setContentsMargins(0, 0, 0, 0);
        radioButton_UC_smallsig = new QRadioButton(layoutWidget3);
        radioButton_UC_smallsig->setObjectName(QStringLiteral("radioButton_UC_smallsig"));
        radioButton_UC_smallsig->setChecked(true);

        UC_small_big_sel->addWidget(radioButton_UC_smallsig);

        radioButton_UC_bigsig = new QRadioButton(layoutWidget3);
        radioButton_UC_bigsig->setObjectName(QStringLiteral("radioButton_UC_bigsig"));
        radioButton_UC_bigsig->setEnabled(true);
        radioButton_UC_bigsig->setAutoRepeatDelay(300);

        UC_small_big_sel->addWidget(radioButton_UC_bigsig);

        UC_if_att = new QGroupBox(UC);
        UC_if_att->setObjectName(QStringLiteral("UC_if_att"));
        UC_if_att->setGeometry(QRect(10, 160, 261, 51));
        spinBox_UC_hmc624 = new QDoubleSpinBox(UC_if_att);
        spinBox_UC_hmc624->setObjectName(QStringLiteral("spinBox_UC_hmc624"));
        spinBox_UC_hmc624->setGeometry(QRect(22, 23, 75, 22));
        spinBox_UC_hmc624->setDecimals(1);
        spinBox_UC_hmc624->setMaximum(63.5);
        label_input_reduction_19 = new QLabel(UC_if_att);
        label_input_reduction_19->setObjectName(QStringLiteral("label_input_reduction_19"));
        label_input_reduction_19->setGeometry(QRect(101, 26, 15, 16));
        label_input_reduction_19->setMaximumSize(QSize(15, 16777215));
        label_UC_hmc624 = new QLabel(UC_if_att);
        label_UC_hmc624->setObjectName(QStringLiteral("label_UC_hmc624"));
        label_UC_hmc624->setGeometry(QRect(114, 22, 60, 23));
        label_UC_hmc624->setMaximumSize(QSize(60, 16777215));
        pushButton_UC_hmc624 = new QPushButton(UC_if_att);
        pushButton_UC_hmc624->setObjectName(QStringLiteral("pushButton_UC_hmc624"));
        pushButton_UC_hmc624->setGeometry(QRect(181, 22, 70, 23));
        pushButton_UC_hmc624->setMaximumSize(QSize(70, 16777215));
        UC_output_freq = new QGroupBox(UC);
        UC_output_freq->setObjectName(QStringLiteral("UC_output_freq"));
        UC_output_freq->setGeometry(QRect(20, 70, 241, 71));
        layoutWidget_4 = new QWidget(UC_output_freq);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 50, 134, 16));
        UC_LO3 = new QHBoxLayout(layoutWidget_4);
        UC_LO3->setSpacing(6);
        UC_LO3->setContentsMargins(11, 11, 11, 11);
        UC_LO3->setObjectName(QStringLiteral("UC_LO3"));
        UC_LO3->setContentsMargins(0, 0, 0, 0);
        label_input_reduction_21 = new QLabel(layoutWidget_4);
        label_input_reduction_21->setObjectName(QStringLiteral("label_input_reduction_21"));

        UC_LO3->addWidget(label_input_reduction_21);

        label_UC_LO3 = new QLabel(layoutWidget_4);
        label_UC_LO3->setObjectName(QStringLiteral("label_UC_LO3"));

        UC_LO3->addWidget(label_UC_LO3);

        label_input_reduction_22 = new QLabel(layoutWidget_4);
        label_input_reduction_22->setObjectName(QStringLiteral("label_input_reduction_22"));
        label_input_reduction_22->setMaximumSize(QSize(20, 16777215));

        UC_LO3->addWidget(label_input_reduction_22);

        layoutWidget4 = new QWidget(UC_output_freq);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 20, 231, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        spinBox_UC_LO3 = new QDoubleSpinBox(layoutWidget4);
        spinBox_UC_LO3->setObjectName(QStringLiteral("spinBox_UC_LO3"));
        spinBox_UC_LO3->setMinimumSize(QSize(75, 0));
        spinBox_UC_LO3->setValue(2);

        horizontalLayout_4->addWidget(spinBox_UC_LO3);

        label_input_reduction_12 = new QLabel(layoutWidget4);
        label_input_reduction_12->setObjectName(QStringLiteral("label_input_reduction_12"));
        label_input_reduction_12->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(label_input_reduction_12);

        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        pushButton_UC_LO3 = new QPushButton(layoutWidget4);
        pushButton_UC_LO3->setObjectName(QStringLiteral("pushButton_UC_LO3"));
        pushButton_UC_LO3->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_4->addWidget(pushButton_UC_LO3);

        tabWidget->addTab(UC, QString());
        UC_output_param->raise();
        UC_if_att->raise();
        UC_rf_att->raise();
        UC_sel->raise();
        UC_output_freq->raise();
        sweep_ctrl = new QWidget();
        sweep_ctrl->setObjectName(QStringLiteral("sweep_ctrl"));
        groupBox = new QGroupBox(sweep_ctrl);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 261, 361));
        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 20, 181, 291));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        SpinBox_StartFreq = new QDoubleSpinBox(layoutWidget_2);
        SpinBox_StartFreq->setObjectName(QStringLiteral("SpinBox_StartFreq"));
        SpinBox_StartFreq->setMinimumSize(QSize(150, 0));
        SpinBox_StartFreq->setMinimum(0.8);
        SpinBox_StartFreq->setMaximum(18);

        verticalLayout->addWidget(SpinBox_StartFreq);

        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        SpinBox_EndFreq = new QDoubleSpinBox(layoutWidget_2);
        SpinBox_EndFreq->setObjectName(QStringLiteral("SpinBox_EndFreq"));
        SpinBox_EndFreq->setMinimumSize(QSize(150, 0));
        SpinBox_EndFreq->setMinimum(0.8);
        SpinBox_EndFreq->setMaximum(18);

        verticalLayout->addWidget(SpinBox_EndFreq);

        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        SpinBox_FreqInc = new QDoubleSpinBox(layoutWidget_2);
        SpinBox_FreqInc->setObjectName(QStringLiteral("SpinBox_FreqInc"));
        SpinBox_FreqInc->setMinimumSize(QSize(150, 0));
        SpinBox_FreqInc->setMaximum(18);

        verticalLayout->addWidget(SpinBox_FreqInc);

        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        spinBox_HoldTime = new QSpinBox(layoutWidget_2);
        spinBox_HoldTime->setObjectName(QStringLiteral("spinBox_HoldTime"));
        spinBox_HoldTime->setMinimumSize(QSize(150, 0));
        spinBox_HoldTime->setMaximum(100000000);

        verticalLayout->addWidget(spinBox_HoldTime);

        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        spinBox_RepeatTimes = new QSpinBox(layoutWidget_2);
        spinBox_RepeatTimes->setObjectName(QStringLiteral("spinBox_RepeatTimes"));
        spinBox_RepeatTimes->setMinimumSize(QSize(150, 0));
        spinBox_RepeatTimes->setMaximum(1000000000);

        verticalLayout->addWidget(spinBox_RepeatTimes);

        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 330, 181, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_StartSweep = new QPushButton(layoutWidget_3);
        pushButton_StartSweep->setObjectName(QStringLiteral("pushButton_StartSweep"));
        pushButton_StartSweep->setMinimumSize(QSize(70, 0));
        pushButton_StartSweep->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_5->addWidget(pushButton_StartSweep);

        pushButton_StopSweep = new QPushButton(layoutWidget_3);
        pushButton_StopSweep->setObjectName(QStringLiteral("pushButton_StopSweep"));
        pushButton_StopSweep->setMinimumSize(QSize(70, 0));
        pushButton_StopSweep->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_5->addWidget(pushButton_StopSweep);

        tabWidget->addTab(sweep_ctrl, QString());

        horizontalLayout->addWidget(tabWidget);

        RF_ctrlClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(RF_ctrlClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RF_ctrlClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RF_ctrlClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RF_ctrlClass->setStatusBar(statusBar);

        retranslateUi(RF_ctrlClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RF_ctrlClass);
    } // setupUi

    void retranslateUi(QMainWindow *RF_ctrlClass)
    {
        RF_ctrlClass->setWindowTitle(QApplication::translate("RF_ctrlClass", "RF_ctrl", Q_NULLPTR));
        DC_input_param->setTitle(QApplication::translate("RF_ctrlClass", "\350\276\223\345\205\245\345\217\202\346\225\260", Q_NULLPTR));
        DC_input_freq->setTitle(QApplication::translate("RF_ctrlClass", "\350\276\223\345\205\245\344\277\241\345\217\267\344\270\255\345\277\203\351\242\221\347\216\207", Q_NULLPTR));
        label_input_reduction_10->setText(QApplication::translate("RF_ctrlClass", "\346\234\254\346\214\257LO3\351\242\221\347\216\207\357\274\232", Q_NULLPTR));
        label_DC_LO3->setText(QApplication::translate("RF_ctrlClass", "24.5", Q_NULLPTR));
        label_input_reduction_13->setText(QApplication::translate("RF_ctrlClass", "GHz", Q_NULLPTR));
        label_input_reduction_8->setText(QApplication::translate("RF_ctrlClass", "GHz", Q_NULLPTR));
        label->setText(QApplication::translate("RF_ctrlClass", "(\302\261500M)", Q_NULLPTR));
        pushButton_DC_LO3->setText(QApplication::translate("RF_ctrlClass", "\345\272\224\347\224\250", Q_NULLPTR));
        DC_input_bw->setTitle(QString());
        label_input_reduction_9->setText(QApplication::translate("RF_ctrlClass", "\350\276\223\345\205\245\344\277\241\345\217\267\345\270\246\345\256\275\351\200\211\346\213\251\357\274\232 ", Q_NULLPTR));
        comboBox_DC_BW->clear();
        comboBox_DC_BW->insertItems(0, QStringList()
         << QApplication::translate("RF_ctrlClass", "\342\211\244 1  G", Q_NULLPTR)
         << QApplication::translate("RF_ctrlClass", "\342\211\244400 M", Q_NULLPTR)
         << QApplication::translate("RF_ctrlClass", "\342\211\244200 M", Q_NULLPTR)
         << QApplication::translate("RF_ctrlClass", "\342\211\24420  M", Q_NULLPTR)
        );
        radioButton_DC_smallsig->setText(QApplication::translate("RF_ctrlClass", "\345\260\217\344\277\241\345\217\267\350\276\223\345\205\245\357\274\210<-30dbm\357\274\211", Q_NULLPTR));
        radioButton_DC_bigsig->setText(QApplication::translate("RF_ctrlClass", "\345\244\247\344\277\241\345\217\267\350\276\223\345\205\245", Q_NULLPTR));
        DC_sel->setTitle(QApplication::translate("RF_ctrlClass", "\344\270\213\345\217\230\351\242\221\351\200\211\346\213\251", Q_NULLPTR));
        radioButton_enable_dc->setText(QApplication::translate("RF_ctrlClass", "\344\270\213\345\217\230\351\242\221\344\275\277\350\203\275           ", Q_NULLPTR));
        radioButton_bypass_dc->setText(QApplication::translate("RF_ctrlClass", "\344\270\213\345\217\230\351\242\221\346\227\201\350\267\257", Q_NULLPTR));
        DC_if_att->setTitle(QApplication::translate("RF_ctrlClass", "\344\270\255\351\242\221\350\241\260\345\207\217", Q_NULLPTR));
        label_input_reduction_15->setText(QApplication::translate("RF_ctrlClass", "dB", Q_NULLPTR));
        label_input_reduction_16->setText(QApplication::translate("RF_ctrlClass", "(0-63.5dB)", Q_NULLPTR));
        pushButton_DC_hmc624->setText(QApplication::translate("RF_ctrlClass", "\345\272\224\347\224\250", Q_NULLPTR));
        DC_rf_att->setTitle(QApplication::translate("RF_ctrlClass", "\345\260\204\351\242\221\350\241\260\345\207\217", Q_NULLPTR));
        spinBox_DC_hmc939->setSpecialValueText(QApplication::translate("RF_ctrlClass", "0", Q_NULLPTR));
        label_input_reduction_6->setText(QApplication::translate("RF_ctrlClass", "dB", Q_NULLPTR));
        label_DC_hmc939->setText(QApplication::translate("RF_ctrlClass", "(0-31dB)", Q_NULLPTR));
        pushButton_DC_hmc939->setText(QApplication::translate("RF_ctrlClass", "\345\272\224\347\224\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(DC), QApplication::translate("RF_ctrlClass", "\344\270\213\345\217\230\351\242\221\346\216\247\345\210\266", Q_NULLPTR));
        UC_rf_att->setTitle(QApplication::translate("RF_ctrlClass", "\345\260\204\351\242\221\350\241\260\345\207\217", Q_NULLPTR));
        spinBox_UC_hmc939->setSpecialValueText(QApplication::translate("RF_ctrlClass", "0", Q_NULLPTR));
        label_input_reduction_23->setText(QApplication::translate("RF_ctrlClass", "dB", Q_NULLPTR));
        label_UC_hmc939->setText(QApplication::translate("RF_ctrlClass", "(0-31dB)", Q_NULLPTR));
        pushButton_UC_hmc939->setText(QApplication::translate("RF_ctrlClass", "\345\272\224\347\224\250", Q_NULLPTR));
        UC_sel->setTitle(QApplication::translate("RF_ctrlClass", "\344\270\213\345\217\230\351\242\221\351\200\211\346\213\251", Q_NULLPTR));
        radioButton_enable_uc->setText(QApplication::translate("RF_ctrlClass", "\344\270\212\345\217\230\351\242\221\344\275\277\350\203\275          ", Q_NULLPTR));
        radioButton_bypass_uc->setText(QApplication::translate("RF_ctrlClass", "\344\270\212\345\217\230\351\242\221\346\227\201\350\267\257", Q_NULLPTR));
        UC_output_param->setTitle(QApplication::translate("RF_ctrlClass", "\350\276\223\345\207\272\345\217\202\346\225\260", Q_NULLPTR));
        radioButton_UC_smallsig->setText(QApplication::translate("RF_ctrlClass", "\345\244\247\344\277\241\345\217\267\350\276\223\345\207\272           ", Q_NULLPTR));
        radioButton_UC_bigsig->setText(QApplication::translate("RF_ctrlClass", "\345\260\217\344\277\241\345\217\267\350\276\223\345\207\272", Q_NULLPTR));
        UC_if_att->setTitle(QApplication::translate("RF_ctrlClass", "\344\270\255\351\242\221\350\241\260\345\207\217", Q_NULLPTR));
        label_input_reduction_19->setText(QApplication::translate("RF_ctrlClass", "dB", Q_NULLPTR));
        label_UC_hmc624->setText(QApplication::translate("RF_ctrlClass", "(0-63.5dB)", Q_NULLPTR));
        pushButton_UC_hmc624->setText(QApplication::translate("RF_ctrlClass", "\345\272\224\347\224\250", Q_NULLPTR));
        UC_output_freq->setTitle(QApplication::translate("RF_ctrlClass", "\350\276\223\345\207\272\344\277\241\345\217\267\344\270\255\345\277\203\351\242\221\347\216\207", Q_NULLPTR));
        label_input_reduction_21->setText(QApplication::translate("RF_ctrlClass", "\346\234\254\346\214\257LO3\351\242\221\347\216\207\357\274\232", Q_NULLPTR));
        label_UC_LO3->setText(QApplication::translate("RF_ctrlClass", "24.5", Q_NULLPTR));
        label_input_reduction_22->setText(QApplication::translate("RF_ctrlClass", "GHz", Q_NULLPTR));
        label_input_reduction_12->setText(QApplication::translate("RF_ctrlClass", "GHz", Q_NULLPTR));
        label_2->setText(QApplication::translate("RF_ctrlClass", "(\302\261500M)", Q_NULLPTR));
        pushButton_UC_LO3->setText(QApplication::translate("RF_ctrlClass", "\345\272\224\347\224\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(UC), QApplication::translate("RF_ctrlClass", "\344\270\212\345\217\230\351\242\221\346\216\247\345\210\266", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("RF_ctrlClass", "\346\211\253\351\242\221\350\256\276\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("RF_ctrlClass", "\350\265\267\345\247\213\351\242\221\347\216\207(GHz):", Q_NULLPTR));
        label_4->setText(QApplication::translate("RF_ctrlClass", "\345\201\234\346\255\242\351\242\221\347\216\207(GHz):", Q_NULLPTR));
        label_5->setText(QApplication::translate("RF_ctrlClass", "\351\242\221\347\216\207\346\255\245\350\277\233(GHz):", Q_NULLPTR));
        label_6->setText(QApplication::translate("RF_ctrlClass", "\351\242\221\347\216\207\351\251\273\347\225\231\346\227\266\351\227\264(ms):", Q_NULLPTR));
        label_7->setText(QApplication::translate("RF_ctrlClass", "\351\207\215\345\244\215\346\254\241\346\225\260\357\274\232", Q_NULLPTR));
        pushButton_StartSweep->setText(QApplication::translate("RF_ctrlClass", "\345\220\257\345\212\250\346\211\253\351\242\221", Q_NULLPTR));
        pushButton_StopSweep->setText(QApplication::translate("RF_ctrlClass", "\345\201\234\346\255\242\346\211\253\351\242\221", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(sweep_ctrl), QApplication::translate("RF_ctrlClass", "\346\211\253\351\242\221\346\216\247\345\210\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RF_ctrlClass: public Ui_RF_ctrlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RF_CTRL_H
