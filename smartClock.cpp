#include <QApplication>
#include "ClockWindow.h"

int main(int argc, char* argv[])
{
	QApplication appl(argc, argv);
	ClockWindow widget;
	widget.show();
	return appl.exec();
}
