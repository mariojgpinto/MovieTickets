#include  "Printer.h"

//------------------------------------------------
// CONSTRUCTORS
//------------------------------------------------
Printer::Printer():
					margin_top(250),
					margin_right(300),
					margin_down(250),
					margin_left(300),
					margin_center_h(50),
					margin_center_v(50){
	this->printer.setOutputFormat(QPrinter::PdfFormat);
	this->printer.setPageSize(QPrinter::A4);

	this->movies = NULL;


	int margin_top,margin_right,margin_down,margin_left;
	int margin_center_h,margin_center_v;
}

Printer::~Printer(){

}


//------------------------------------------------
// METHODS
//------------------------------------------------
/**
 *
 */
void Printer::setPath(QString path){
	this->file_path.clear();
	this->file_path.append(path);
}

/**
 *
 */
void Printer::setMovies(QVector<MovieEntry*>* movies){
	if(movies){
		if(movies->size()){
			this->movies = movies;
		}
	}
}

/**
 *
 */
void Printer::print(){
	if (!painter.begin(&printer)){
		printf("ERROR\n");
		return;
	}

	printer.setPageMargins(	this->margin_left,
							this->margin_top,
							this->margin_right,
							this->margin_down, QPrinter::Millimeter);

	int r1_x = 0;
	int r1_y = 0;
	//int r2_x = printer_width/2.0;
	int r2_y = 0;
	int r3_x = 0;
	//int r3_y = printer_height/2.0;
	//int r4_x = printer_width/2.0;
	//int r4_y = printer_height/2.0;
}