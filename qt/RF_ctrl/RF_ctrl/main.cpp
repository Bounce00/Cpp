#include "RF_ctrl.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RF_ctrl w;
	w.show();
	return a.exec();
}
