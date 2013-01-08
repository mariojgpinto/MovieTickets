#include "movietickets.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MovieTickets w;
	w.show();
	return a.exec();
}
