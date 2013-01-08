#ifndef MOVIETICKETS_H
#define MOVIETICKETS_H

#include <QtGui/QMainWindow>
#include <QPrinter>
#include <QFileDialog>
#include <QPainter>
#include <QPicture>
#include <QShortcut>
#include <QTextStream>
#include "ui_movietickets.h"

#include "MovieEntry.h"

class MovieTickets : public QMainWindow
{
	Q_OBJECT

public:
	MovieTickets(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MovieTickets();
	MovieTickets& operator=(MovieTickets&& other) { /* ... */ return *this; }
	

public slots:
	//User Slot Methods
	void on_add_image_clicked();
	void on_add_cast_clicked();
	void on_add_reset_clicked();
	void on_add_save_clicked();
	void on_add_print_all_clicked();

	void on_edit_image_clicked();
	void on_edit_cast_clicked();
	void on_edit_reset_clicked();
	void on_edit_save_clicked();
	void on_edit_remove_clicked();
	
	void on_reorder_clicked();

	void on_view_next_clicked();
	void on_view_previous_clicked();

	void on_edit_next_clicked();
	void on_edit_previous_clicked();

private:
	void setup();
	void setupPrinter();
	void save_to_file();
	void read_from_file();
	//void write_movie_entry();
	QStringList getCast();
	QStringList getCastEdit();
	void createMovieEntry(MovieEntry entry, int top_x, int top_y, int center_x, int center_y);
	void createPDF();
	void updateMovieView();

	void updateMovieEdit();

public:
	QString file_path;
	QString pdf_path;
	QString pdf_launch;
	QString image_path;

	int center_v;
	int center_h;
	int line_step;

private:
	Ui::MovieTicketsClass window;
	std::vector<MovieEntry> movies;

	bool processed;
	QPrinter printer;
	QPainter painter;

	int printer_orig_width;
	int printer_orig_height;
	int printer_width;
	int printer_height;

	int r1_x, r1_y;
	int r2_x, r2_y;
	int r3_x, r3_y;
	int r4_x, r4_y;

	int r_width;
	int r_height;

	int movie_index;
	int movie_index_edit;
};

#endif // MOVIETICKETS_H