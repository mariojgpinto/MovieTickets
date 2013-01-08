#ifndef _MY_PRINTER
#define _MY_PRINTER

#include <QPainter>
#include <QPrinter>
#include "MovieEntry.h"

//#define

class Printer{
	public:
		Printer();
		~Printer();

		void setPath(QString path);
		void setMovies(QVector<MovieEntry*>* movies);
		void print();

		int margin_top,margin_right,margin_down,margin_left;
		int margin_center_h,margin_center_v;

	private:
		QPrinter printer;
		QPainter painter;

		QString file_path;

		QVector<MovieEntry*>* movies;
};

#endif