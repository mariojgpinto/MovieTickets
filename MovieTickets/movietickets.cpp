#include "movietickets.h"

//------------------------------------------------
// Constructors
//------------------------------------------------
MovieTickets::MovieTickets(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags), 
	file_path("Data\\backup.txt"),
	pdf_path("Data\\movies.pdf"),
	pdf_launch("cmd /c start Data\\movies.pdf"),
	image_path("Data\\Images\\"),
	processed(false),
	center_v(50),
	center_h(100),
	line_step(20),
	movie_index(0),
	movie_index_edit(0)
	//printer(QPrinter::PrinterResolution)
{
	this->window.setupUi(this);

	this->setup();
	
	this->read_from_file();

	this->updateMovieView();
	this->updateMovieEdit();
	//Connecting the dots
	connect(this->window.add_image_pushButton, SIGNAL(clicked()), this, SLOT(on_add_image_clicked()));
	connect(this->window.add_cast_pushButton, SIGNAL(clicked()), this, SLOT(on_add_cast_clicked()));
	connect(this->window.add_reset_pushButton, SIGNAL(clicked()), this, SLOT(on_add_reset_clicked()));
	connect(this->window.add_save_pushButton, SIGNAL(clicked()), this, SLOT(on_add_save_clicked()));
	connect(this->window.add_actionPrint_All, SIGNAL(triggered()), this, SLOT(on_add_print_all_clicked()));
	connect(this->window.view_next_pushButton, SIGNAL(clicked()), this, SLOT(on_view_next_clicked()));
	connect(this->window.view_previous_pushButton, SIGNAL(clicked()), this, SLOT(on_view_previous_clicked()));


	connect(this->window.edit_image_pushButton, SIGNAL(clicked()), this, SLOT(on_edit_image_clicked()));
	connect(this->window.edit_cast_pushButton, SIGNAL(clicked()), this, SLOT(on_edit_cast_clicked()));
	connect(this->window.edit_reset_pushButton, SIGNAL(clicked()), this, SLOT(on_edit_reset_clicked()));
	connect(this->window.edit_save_pushButton, SIGNAL(clicked()), this, SLOT(on_edit_save_clicked()));
	connect(this->window.edit_remove_pushButton, SIGNAL(clicked()), this, SLOT(on_edit_remove_clicked()));
	connect(this->window.edit_next_pushButton, SIGNAL(clicked()), this, SLOT(on_edit_next_clicked()));
	connect(this->window.edit_previous_pushButton, SIGNAL(clicked()), this, SLOT(on_edit_previous_clicked()));

	QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+P"), this);
	connect(shortcut, SIGNAL(activated()), this, SLOT(on_add_print_all_clicked()));

	QShortcut *shortcut2 = new QShortcut(QKeySequence("Ctrl+R"), this);
	connect(shortcut2, SIGNAL(activated()), this, SLOT(on_reorder_clicked()));
	
}

MovieTickets::~MovieTickets()
{

}

//------------------------------------------------
// SETUP
//------------------------------------------------
void MovieTickets::setup(){
	this->window.add_image_label->setAlignment(Qt::AlignCenter);
	this->window.view_image_label->setAlignment(Qt::AlignCenter);
	this->window.edit_image_label->setAlignment(Qt::AlignCenter);

	this->window.edit_remove_pushButton->setCheckable(false);
}

void MovieTickets::setupPrinter(){
	//printer.setResolution(QPrinter::HighResolution);
	printer.setOutputFileName(this->pdf_path);
	printer.setOutputFormat(QPrinter::PdfFormat);
	printer.setPageSize(QPrinter::A4);
	

	if (!painter.begin(&printer))
        printf("ERROR\n");

	printer_orig_width = printer.width();
	printer_orig_height = printer.height();

	printer.setPageMargins(20., 15., 20., 15., QPrinter::Millimeter);
	printer_width = printer.width();
	printer_height = printer.height();

	r1_x = (printer_orig_width - printer_width)/2.0;
	r1_y = (printer_orig_height - printer_height)/2.0;

	r2_x = printer_orig_width/2.0 + center_v/2.0;
	r2_y = (printer_orig_height - printer_height)/2.0;

	r3_x = (printer_orig_width - printer_width)/2.0;
	r3_y = printer_orig_height/2.0 + center_h/2.0;

	r4_x = printer_orig_width/2.0 + center_v/2.0;
	r4_y = printer_orig_height/2.0 + center_h/2.0;

	r_width = printer_width/2.0 - center_v/2.0;
	r_height = printer_height/2.0 - center_h/2.0;
}

//------------------------------------------------
// SLOTS
//------------------------------------------------
void MovieTickets::on_add_cast_clicked(){
	QString raw_cast = this->window.add_cast_textEdit->toPlainText();

	std::string str = raw_cast.toStdString();

	const char* data = str.data();
	
	char* delim = strtok((char*)data,"\n\t");
	QStringList lines;
	
	delim = strtok (NULL, "\n");
	while (delim != NULL){
		std::string line(delim);
		//line.pop_back();
		bool points = false;
		while(line.at(line.length()-1) == '.' || line.at(line.length()-1) == '\t'){
			line.pop_back();
			points = true;
		}
		if(points) line.pop_back();
		
		if(line.at(line.length()-1) == '\t'){
			line.pop_back();
		}
		line.push_back('\0');

		//Remove space from first character
		if(line.at(0) == ' '){
			line.erase(line.begin());
		}
		if(line.at(0) == '\t'){
			line.erase(line.begin());
		}
	
		lines.push_back(line.data());
		delim = strtok (NULL, "\n");
	}

	this->window.add_cast_textEdit->clear();

	QString toShow("");

	for(int i = 0 ; i < lines.length() ; i+=2){
		toShow.append(lines[i]);
		toShow.append(" ... ");
		toShow.append(lines[i+1]);
		toShow.append("\n");
	}
	
	this->window.add_cast_textEdit->setPlainText(toShow);

	this->processed = true;
}

void MovieTickets::on_add_reset_clicked(){

	this->window.add_title_lineEdit->clear();
	this->window.add_director_lineEdit->clear();
	this->window.add_year_comboBox->setCurrentIndex(0);
	this->window.add_duration_lineEdit->clear();
	this->window.add_rating_doubleSpinBox->setValue(5.0);
	this->window.add_visualization_dateEdit->setDate(QDate(2012,1,1));
	this->window.add_cast_textEdit->clear();
	this->window.add_plot_textEdit->clear();
	this->window.add_image_lineEdit->clear();
	this->window.add_image_label->clear();

	this->processed = false;
}

void MovieTickets::on_add_save_clicked(){
	MovieEntry newEntry;

	//Save Title
	newEntry.setTitle(this->window.add_title_lineEdit->text());

	//Save Director
	newEntry.setDirector(this->window.add_director_lineEdit->text());

	//Save Year
	newEntry.setYear(this->window.add_year_comboBox->currentText());

	//Save Duration
	newEntry.setDuration(this->window.add_duration_lineEdit->text());

	//Save Rating
	newEntry.setRating(QString::number(this->window.add_rating_doubleSpinBox->value()));

	//Save Visualization Date
	newEntry.setVisualization_date(this->window.add_visualization_dateEdit->date().toString("dd/MM/yyyy"));

	//Save Cast
	newEntry.setCast(this->getCast());

	//Save Plot
	newEntry.setPlot(this->window.add_plot_textEdit->toPlainText());

	//Save Image Path
	newEntry.setImage_path(this->window.add_image_lineEdit->text());

	//Save New Entry
	this->movies.push_back(newEntry);
	this->save_to_file();

	//Reset Info
	this->on_add_reset_clicked();
}

void MovieTickets::on_add_image_clicked(){
	QString image_name(this->window.add_image_lineEdit->text());
	
	QPixmap* image;
	if(image_name.length() > 0){
		QString image_full_path(this->image_path);
		image_full_path.append(image_name);

		image = new QPixmap(image_full_path);

		if(image->isNull()){
			image = new QPixmap("..\\Data\\Images\\no_movie.jpg");
		}
	}
	else{
		image = new QPixmap("..\\Data\\Images\\no_movie.jpg");
	}
	
	QPixmap aux = image->scaledToWidth(this->window.add_image_label->width());

	if(aux.height() > this->window.add_image_label->height()){
		aux = image->scaledToHeight(this->window.add_image_label->height());
	}

	this->window.add_image_label->setPixmap(aux);
}

void MovieTickets::on_add_print_all_clicked(){
	this->setupPrinter();
	this->createPDF();
	
	system(this->pdf_launch.toStdString().data());
}

void MovieTickets::on_view_next_clicked(){
	this->movie_index = ((this->movie_index + 1)%this->movies.size());

	this->updateMovieView();
}

void MovieTickets::on_view_previous_clicked(){
	//this->movie_index = ((this->movie_index - 1)%this->movies.size());
	this->movie_index--;

	if(this->movie_index < 0){
		this->movie_index = this->movies.size() -1;
	}

	this->updateMovieView();
}

void MovieTickets::on_edit_next_clicked(){
	this->movie_index_edit = ((this->movie_index_edit + 1)%this->movies.size());

	this->updateMovieEdit();
}

void MovieTickets::on_edit_previous_clicked(){
	//this->movie_index_edit = ((this->movie_index_edit - 1)%this->movies.size());
	this->movie_index_edit--;

	if(this->movie_index_edit < 0){
		this->movie_index_edit = this->movies.size() -1;
	}

	this->updateMovieEdit();
}

void MovieTickets::on_reorder_clicked(){
	std::vector<MovieEntry> movies_aux;
	//this->movies.clear();

	QFile file(this->file_path);
	if (!file.open (QIODevice::ReadOnly | QIODevice::Text))
		return ;
	
	QString line;
	while( !file.atEnd() ) {
		line = file.readLine();

		MovieEntry newEntry(line);
		movies_aux.push_back(newEntry);
	}
	file.close(); // when your done.

	std::vector<MovieEntry> movies_order;

	int index = 0;
	int year, month, day;
	int min_year = 3000 , min_month = 13, min_day = 41;

//	sscanf_s(movies_aux[0].getVisualization_date().toStdString().data(),"%d/%d/%d",&min_day,&min_month,&min_year);

	bool *done = (bool*)malloc(sizeof(bool)*movies_aux.size());

	for(int i = 0 ; i < movies_aux.size() ; i++){
		done[i] = false;
	}

	int left = movies_aux.size();
	while(left){
		left = 0;
		min_year = 3000; min_month = 20; min_day = 40;

		for(int i = 0 ; i < movies_aux.size() ; i++){
			if(! done[i]){
				left++;
				sscanf_s(movies_aux[i].getVisualization_date().toStdString().data(),"%d/%d/%d",&day,&month,&year);

				if(year < min_year){
					min_year = year;
					min_month = month;
					min_day = day;
					index = i;
				}
				else{
					if(year == min_year){
						if(month < min_month){
							min_year = year;
							min_month = month;
							min_day = day;
							index = i;
						}
						else{
							if(month == min_month){
								if(day < min_day){
									min_year = year;
									min_month = month;
									min_day = day;
									index = i;
								}
							}
						}
					}
				}
			}
		} // End for;
		if(left){
			done[index]= true;
			movies_order.push_back(movies_aux[index]);
		}
	}

	printf("");

	QFile file2(this->file_path);
    file2.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file2);
   
	for(int i = 0 ; i < movies_order.size() ; i++){
		out << movies_order[i].toString();
		out << "\n";
	}

    // optional, as QFile destructor will already do it:
    file2.close(); 

	while(this->movies.size()) this->movies.pop_back();
	//this->movie_index = 0;
	//this->movie_index_edit = 0;

	this->read_from_file();

}

//------------------------------------------------
// Methods
//------------------------------------------------

QStringList MovieTickets::getCast(){
	if(!processed){
		this->on_add_cast_clicked();
	}

	QString _cast = this->window.add_cast_textEdit->toPlainText();
	std::string str = _cast.toStdString();
	const char* data = str.data();
	QStringList list;

	char* delim = strtok((char*)data,"\n");
	while (delim != NULL){
		std::string line(delim);

		int pos = line.find(" ... ");
		std::string actor = line.substr(0,pos);
		std::string character = line.substr(pos+5, line.size());;
		
		list.push_back(actor.data());
		list.push_back(character.data());

		delim = strtok(NULL,"\n");
	}

	return list;
}


QStringList MovieTickets::getCastEdit(){

	QString _cast = this->window.edit_cast_textEdit->toPlainText();
	std::string str = _cast.toStdString();
	const char* data = str.data();
	QStringList list;

	char* delim = strtok((char*)data,"\n");
	while (delim != NULL){
		std::string line(delim);

		int pos = line.find(" ... ");
		std::string actor = line.substr(0,pos);
		std::string character = line.substr(pos+5, line.size());;
		
		list.push_back(actor.data());
		list.push_back(character.data());

		delim = strtok(NULL,"\n");
	}

	return list;
}


void MovieTickets::save_to_file(){
	QFile file(this->file_path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
   
	for(int i = 0 ; i < this->movies.size() ; i++){
		out << this->movies[i].toString();
		out << "\n";
	}

    // optional, as QFile destructor will already do it:
    file.close(); 
}

void MovieTickets::read_from_file(){
	//this->movies.clear();
	while(this->movies.size()) this->movies.pop_back();

	QFile file(this->file_path);
	if (!file.open (QIODevice::ReadOnly | QIODevice::Text))
		return ;
	
	QString line;
	while( !file.atEnd() ) {
		line = file.readLine();

		MovieEntry newEntry(line);
		this->movies.push_back(newEntry);
	}
	file.close(); // when your done.
}

void MovieTickets::createPDF(){
	if((this->movies.size() % 2) == 0){
		for(int i = 0 ; i < this->movies.size() ; i+=2){
			//movies[i]
			this->createMovieEntry(movies[i], r1_x,r1_y,r2_x,r2_y);
			painter.drawLine(0,printer_orig_height/2.0,printer_orig_width,printer_orig_height/2.0);
			this->createMovieEntry(movies[i+1],r3_x,r3_y,r4_x,r4_y);
			printer.newPage();
		}
	}
	else{
		for(int i = 0 ; i < this->movies.size()-1 ; i+=2){
			//movies[i]
			this->createMovieEntry(movies[i], r1_x,r1_y,r2_x,r2_y);
			painter.drawLine(0,printer_orig_height/2.0,printer_orig_width,printer_orig_height/2.0);
			this->createMovieEntry(movies[i+1],r3_x,r3_y,r4_x,r4_y);
			printer.newPage();
		}
		this->createMovieEntry(movies[this->movies.size()-1], r1_x,r1_y,r2_x,r2_y);
		painter.drawLine(0,printer_orig_height/2.0,printer_orig_width,printer_orig_height/2.0);
	}

	painter.end();
}

void MovieTickets::createMovieEntry(MovieEntry entry, int top_x, int top_y, int center_x, int center_y){
	//load image
	QPixmap* image;
	QString image_full_path(this->image_path);
	image_full_path.append(entry.getImage_path());
	image = new QPixmap(image_full_path);
	
	//Adapt image
	QPixmap aux = image->scaledToWidth(r_width);

	int image_x = top_x + (r_width - aux.width())/2.0;
	int image_y = top_y + (r_height - aux.height())/2.0;

	if(aux.height() > r_height){
		aux = image->scaledToHeight(r_height);

		image_x = top_x + (r_width - aux.width())/2.0;
		image_y = top_y + (r_height - aux.height())/2.0;
	}

	//Paint Image
	painter.drawPixmap(image_x,image_y,aux);

	//Text Preparation
	int advance = 20;
	QFont font_normal = painter.font();
	QFont font_bold = painter.font();
	font_bold.setBold(true);

	//Print Title
	painter.setFont(font_bold);
	painter.drawText(center_x,center_y + advance, "Title:");
	//advance += 20;
	painter.setFont(font_normal);
	painter.drawText(center_x + 35,center_y + advance, entry.getTitle());
	advance += 20;


	//Print Director
	painter.setFont(font_bold);
	painter.drawText(center_x,center_y + advance, "Director:");
	//advance += 20;
	painter.setFont(font_normal);
	painter.drawText(center_x + 55,center_y + advance, entry.getDirector());
	advance += 20;

	//Print Year
	painter.setFont(font_bold);
	painter.drawText(center_x,center_y + advance, "Year:");
	//advance += 20;
	painter.setFont(font_normal);
	painter.drawText(center_x + 35,center_y + advance, entry.getYear());
	advance += 20;

	//Print Duration
	painter.setFont(font_bold);
	painter.drawText(center_x,center_y + advance, "Duration:");
	//advance += 20;
	painter.setFont(font_normal);
	painter.drawText(center_x + 55,center_y + advance, entry.getDuration().append("min"));
	advance += 20;

	//Print IMDB Rating
	painter.setFont(font_bold);
	painter.drawText(center_x,center_y + advance, "IMDB Rating:");
	//advance += 20;
	painter.setFont(font_normal);
	painter.drawText(center_x + 77,center_y + advance, entry.getRating().append("/10.0"));
	advance += 20;

	//Print Visualzation Date
	painter.setFont(font_bold);
	painter.drawText(center_x,center_y + advance, "Visualization Date:");
	//advance += 20;
	painter.setFont(font_normal);
	painter.drawText(center_x + 110,center_y + advance, entry.getVisualization_date());
	advance += 20;

	//Print Plot
	painter.setFont(font_bold);
	painter.drawText(center_x,center_y + advance, "Plot:");
	advance += 10;
	painter.setFont(font_normal);
	int nLines = 1;

	//this represent the required rectangled size
	QRect required = QRect(); 
		
	//this represent our calculated rectangle size
	QRect r = QRect(center_x, center_y + advance, r_width, 20);
		
	painter.drawRect(r);
		
	//now we draw the text into the given rectangle, using word wrap option.
	//the last parameter indicates a rectangle in which the text should be enclosed         
	painter.drawText(r, Qt::AlignJustify | Qt::TextWordWrap, entry.getPlot(), &required);
	
	while (required.height() > r.height())
	{
		//here you must call painter.eraseRect(r) for each drawn rectangle,
		nLines++;
		painter.eraseRect(r);
		r.setHeight(nLines * 20);
		painter.drawText(r, Qt::AlignJustify | Qt::TextWordWrap, entry.getPlot(), &required);
		}

	advance += (nLines * 20) + 10;

	
	//Print cast
	painter.setFont(font_bold);
	painter.drawText(center_x,center_y + advance, "Cast:");
	advance += 20;
	painter.setFont(font_normal);

	int lines_left = (((printer_orig_height/2.0 - advance)/20) - 1) * 2;
	for(int i = 0 ; i < entry.getCast().size() && i < lines_left ; i+=2){
		QString cast_entry(entry.getCast()[i]);
		cast_entry.append(" ... ");
		cast_entry.append(entry.getCast()[i+1]);

		painter.drawText(center_x,center_y + advance, cast_entry);
		advance += 20;
	}

	
}

void MovieTickets::updateMovieView(){
	if(this->movie_index < this->movies.size() && this->movie_index >= 0){
		//Update Title
		this->window.view_title_label->clear();
		this->window.view_title_label->setText("Title: " + this->movies[this->movie_index].getTitle());

		//Update Director
		this->window.view_director_label->clear();
		this->window.view_director_label->setText("Director: " + this->movies[this->movie_index].getDirector());

		//Update Year
		this->window.view_year_label->clear();
		this->window.view_year_label->setText("Year: " + this->movies[this->movie_index].getYear());

		//Update Duration
		this->window.view_duration_label->clear();
		this->window.view_duration_label->setText("Duration: " + this->movies[this->movie_index].getDuration());

		//Update Rating
		this->window.view_rating_label->clear();
		this->window.view_rating_label->setText("IMDB Rating: " + this->movies[this->movie_index].getRating());

		//Update Visualization Date
		this->window.view_visualization_label->clear();
		this->window.view_visualization_label->setText("Visualization Date: " + this->movies[this->movie_index].getVisualization_date());

		//Update Plot
		this->window.view_plot_textBrowser->clear();
		this->window.view_plot_textBrowser->setText(this->movies[this->movie_index].getPlot());

		//Update Cast
		QString cast_;
		for(int i = 0 ; i < this->movies[this->movie_index].getCast().size() ; i+=2){
			cast_.append(this->movies[this->movie_index].getCast()[i]);
			cast_.append(" ... ");
			cast_.append(this->movies[this->movie_index].getCast()[i+1]);
			cast_.append("\n");
		}
		
		this->window.view_cast_textBrowser->clear();
		this->window.view_cast_textBrowser->setText(cast_);

		//Update Picture
		QString image_name(this->movies[movie_index].getImage_path());
	
		QPixmap* image;
		if(image_name.length() > 0){
			QString image_full_path(this->image_path);
			image_full_path.append(image_name);

			image = new QPixmap(image_full_path);

			if(image->isNull()){
				image = new QPixmap("..\\Data\\Images\\no_movie.jpg");
			}
		}
		else{
			image = new QPixmap("..\\Data\\Images\\no_movie.jpg");
		}
	
		QPixmap aux = image->scaledToWidth(this->window.view_image_label->width());

		if(aux.height() > this->window.view_image_label->height()){
			aux = image->scaledToHeight(this->window.view_image_label->height());
		}

		this->window.view_image_label->setPixmap(aux);
	}
}





void MovieTickets::on_edit_image_clicked(){
	QString image_name(this->window.edit_image_lineEdit->text());
	
	QPixmap* image;
	if(image_name.length() > 0){
		QString image_full_path(this->image_path);
		image_full_path.append(image_name);

		image = new QPixmap(image_full_path);

		if(image->isNull()){
			image = new QPixmap("..\\Data\\Images\\no_movie.jpg");
		}
	}
	else{
		image = new QPixmap("..\\Data\\Images\\no_movie.jpg");
	}
	
	QPixmap aux = image->scaledToWidth(this->window.edit_image_label->width());

	if(aux.height() > this->window.edit_image_label->height()){
		aux = image->scaledToHeight(this->window.edit_image_label->height());
	}

	this->window.edit_image_label->setPixmap(aux);
}

void MovieTickets::on_edit_cast_clicked(){
	QString raw_cast = this->window.edit_cast_textEdit->toPlainText();

	std::string str = raw_cast.toStdString();

	const char* data = str.data();
	
	char* delim = strtok((char*)data,"\n\t");
	QStringList lines;
	
	delim = strtok (NULL, "\n");
	while (delim != NULL){
		std::string line(delim);
		//line.pop_back();
		bool points = false;
		while(line.at(line.length()-1) == '.' || line.at(line.length()-1) == '\t'){
			line.pop_back();
			points = true;
		}
		if(points) line.pop_back();
		
		if(line.at(line.length()-1) == '\t'){
			line.pop_back();
		}
		line.push_back('\0');

		//Remove space from first character
		if(line.at(0) == ' '){
			line.erase(line.begin());
		}
		if(line.at(0) == '\t'){
			line.erase(line.begin());
		}
	
		lines.push_back(line.data());
		delim = strtok (NULL, "\n");
	}

	this->window.edit_cast_textEdit->clear();

	QString toShow("");

	for(int i = 0 ; i < lines.length() ; i+=2){
		toShow.append(lines[i]);
		toShow.append(" ... ");
		toShow.append(lines[i+1]);
		toShow.append("\n");
	}
	
	this->window.edit_cast_textEdit->setPlainText(toShow);

	this->processed = true;
}

void MovieTickets::on_edit_reset_clicked(){
	this->updateMovieEdit();
}

void MovieTickets::on_edit_save_clicked(){
	MovieEntry *newEntry = &this->movies[movie_index_edit];

	//Save Title
	newEntry->setTitle(this->window.edit_title_lineEdit->text());

	//Save Director
	newEntry->setDirector(this->window.edit_director_lineEdit->text());

	//Save Year
	newEntry->setYear(this->window.edit_year_comboBox->currentText());

	//Save Duration
	newEntry->setDuration(this->window.edit_duration_lineEdit->text());

	//Save Rating
	newEntry->setRating(QString::number(this->window.edit_rating_doubleSpinBox->value()));

	//Save Visualization Date
	newEntry->setVisualization_date(this->window.edit_visualization_dateEdit->date().toString("dd/MM/yyyy"));

	//Save Cast
	newEntry->setCast(this->getCastEdit());

	//Save Plot
	newEntry->setPlot(this->window.edit_plot_textEdit->toPlainText());

	//Save Image Path
	newEntry->setImage_path(this->window.edit_image_lineEdit->text());

	//Save New Entry
	this->save_to_file();

	this->updateMovieView();
}

void MovieTickets::on_edit_remove_clicked(){
	//this->movies.pop_back();
	//this->movies.erase(this->movies.begin() + this->movie_index_edit);

	QFile file(this->file_path);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
   
	for(int i = 0 ; i < this->movies.size() ; i++){
		if(i != this->movie_index_edit){
			out << this->movies[i].toString();
			out << "\n";
		}
	}

    // optional, as QFile destructor will already do it:
    file.close(); 

	this->read_from_file();
	this->updateMovieEdit();
	this->updateMovieView();
}


void MovieTickets::updateMovieEdit(){
	if(this->movie_index_edit < this->movies.size() && this->movie_index >= 0){
		//Update Title
		this->window.edit_title_lineEdit->clear();
		this->window.edit_title_lineEdit->setText(this->movies[this->movie_index_edit].getTitle());

		//Update Director
		this->window.edit_director_lineEdit->clear();
		this->window.edit_director_lineEdit->setText(this->movies[this->movie_index_edit].getDirector());

		//Update Year
		int index = -1;
		for(int i = 0 ; index < 0 && i < this->window.edit_year_comboBox->count() ; i++){
			if(this->window.edit_year_comboBox->itemText(i).toInt() ==  this->movies[this->movie_index_edit].getYear().toInt()){
				index = i; 
			}
		}

		this->window.edit_year_comboBox->setCurrentIndex(index);

		//Update Duration
		this->window.edit_duration_lineEdit->clear();
		this->window.edit_duration_lineEdit->setText(this->movies[this->movie_index_edit].getDuration());

		//Update Rating
		this->window.edit_rating_doubleSpinBox->setValue(this->movies[this->movie_index_edit].getRating().toDouble());
		

		//Update Visualization Date
		int day,month,year;
		sscanf_s(this->movies[this->movie_index_edit].getVisualization_date().toStdString().data(),"%d/%d/%d",&day,&month,&year);
		
		this->window.edit_visualization_dateEdit->setDate(QDate(year,month,day));

		//Update Plot
		this->window.edit_plot_textEdit->clear();
		this->window.edit_plot_textEdit->setPlainText(this->movies[this->movie_index_edit].getPlot());

		//Update Cast
		QString cast_;
		for(int i = 0 ; i < this->movies[this->movie_index_edit].getCast().size() ; i+=2){
			cast_.append(this->movies[this->movie_index_edit].getCast()[i]);
			cast_.append(" ... ");
			cast_.append(this->movies[this->movie_index_edit].getCast()[i+1]);
			cast_.append("\n");
		}
		
		this->window.edit_cast_textEdit->clear();
		this->window.edit_cast_textEdit->setPlainText(cast_);

		//Update Picture
		QString image_name(this->movies[movie_index_edit].getImage_path());
		this->window.edit_image_lineEdit->setText(this->movies[movie_index_edit].getImage_path());
	
		QPixmap* image;
		if(image_name.length() > 0){
			QString image_full_path(this->image_path);
			image_full_path.append(image_name);

			image = new QPixmap(image_full_path);

			if(image->isNull()){
				image = new QPixmap("..\\Data\\Images\\no_movie.jpg");
			}
		}
		else{
			image = new QPixmap("..\\Data\\Images\\no_movie.jpg");
		}
	
		QPixmap aux = image->scaledToWidth(this->window.edit_image_label->width());

		if(aux.height() > this->window.edit_image_label->height()){
			aux = image->scaledToHeight(this->window.edit_image_label->height());
		}

		this->window.edit_image_label->setPixmap(aux);
	}
}