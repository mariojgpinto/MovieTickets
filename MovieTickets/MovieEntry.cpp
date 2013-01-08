#include "MovieEntry.h"

//------------------------------------------------
// CONSTRUCTORS
//------------------------------------------------
MovieEntry::MovieEntry():mark("###"){

}

MovieEntry::MovieEntry(QString entry):mark("###"){
	std::string s = entry.toStdString();
	const char* data = s.data();

	char* tokens = strtok((char*)data,(char*)mark.data());

	if(tokens){
		title.append(tokens);
		tokens = strtok(NULL,(char*)mark.data());

		if(tokens){
			if(tokens){
				director.append(tokens);
				tokens = strtok(NULL,(char*)mark.data());
				if(tokens){
					year.append(tokens);
					tokens = strtok(NULL,(char*)mark.data());
					if(tokens){
						duration.append(tokens);
						tokens = strtok(NULL,(char*)mark.data());
						if(tokens){
							rating.append(tokens);
							tokens = strtok(NULL,(char*)mark.data());
							if(tokens){
								visualization_date.append(tokens);
								tokens = strtok(NULL,(char*)mark.data());
								if(tokens){
									int n = QString(tokens).toInt();
									tokens = strtok(NULL,(char*)mark.data());

									for(int i = 0 ; i < n ; i++){
										cast.append(tokens);
										tokens = strtok(NULL,(char*)mark.data());
									}

									if(tokens){
										plot.append(tokens);
										tokens = strtok(NULL,(char*)mark.data());
										if(tokens){
											setImage_path(QString(tokens));
											//image_path.append(tokens);
											tokens = strtok(NULL,(char*)mark.data());
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

MovieEntry::MovieEntry(MovieEntry* entry):mark("###"){
	if(entry){
		this->setCast(entry->getCast());
		this->setDirector(entry->getDirector());
		this->setDuration(entry->getDuration());
		this->setImage_path(entry->getImage_path());
		this->setPlot(entry->getPlot());
		this->setRating(entry->getRating());
		this->setTitle(entry->getTitle());
		this->setVisualization_date(entry->getVisualization_date());
		this->setYear(entry->getYear());
	}
}

MovieEntry::~MovieEntry(){

}

//------------------------------------------------
// Set Methods
//------------------------------------------------
/**
 *
 */
void MovieEntry::setTitle(QString title){
	this->title.clear();
	this->title.append(title);
}

/**
 *
 */
void MovieEntry::setDirector(QString director){
	this->director.clear();
	this->director.append(director);
}

/**
 *
 */
void MovieEntry::setYear(QString year){
	this->year.clear();
	this->year.append(year);
}

/**
 *
 */
void MovieEntry::setDuration(QString duration){
	this->duration.clear();
	this->duration.append(duration);
}

/**
 *
 */
void MovieEntry::setRating(QString rating){
	this->rating.clear();
	this->rating.append(rating);
}

/**
 *
 */
void MovieEntry::setVisualization_date(QString date){
	this->visualization_date.clear();
	this->visualization_date.append(date);
}

/**
 *
 */
void MovieEntry::setCast(QStringList cast){
	this->cast.clear();
	this->cast.append(cast);
}

/**
 *
 */
void MovieEntry::setPlot(QString plot){
	this->plot.clear();
	this->plot.append(plot);
}

/**
 *
 */
void MovieEntry::setImage_path(QString _image_path){
	this->image_path.clear();
	if(_image_path.endsWith('\n')){
		_image_path[_image_path.length()-1] = '\0'; 
	}

	this->image_path.append(_image_path);
}


//------------------------------------------------
// Get Methods
//------------------------------------------------
/**
 *
 */
QString MovieEntry::getTitle(){
	return this->title;
}

/**
 *
 */
QString MovieEntry::getDirector(){
	return this->director;
}

/**
 *
 */
QString MovieEntry::getYear(){
	return this->year;
}

/**
 *
 */
QString MovieEntry::getDuration(){
	return this->duration;
}

/**
 *
 */
QString MovieEntry::getRating(){
	return this->rating;
}

/**
 *
 */
QString MovieEntry::getVisualization_date(){
	return this->visualization_date;
}

/**
 *
 */
QStringList MovieEntry::getCast(){
	return this->cast;
}

/**
 *
 */
QString MovieEntry::getPlot(){
	return this->plot;
}

/**
 *
 */
QString MovieEntry::getImage_path(){
	return this->image_path;
}

QString MovieEntry::toString(){
	QString str;

	//Magic goes here
	str.append(mark);
	str.append(title);
	str.append(mark);
	str.append(director);
	str.append(mark);
	str.append(year);
	str.append(mark);
	str.append(duration);
	str.append(mark);
	str.append(rating);
	str.append(mark);
	str.append(visualization_date);
	str.append(mark);
	str.append(QString::number(cast.size()));
	str.append(mark);
	for(int i = 0 ; i < cast.size() ; i++){
		str.append(cast[i]);
		str.append(mark);
	}
//	str.append(mark);
	str.append(plot);
	str.append(mark);
	str.append(image_path);
	str.append(mark);
	
	return str;
}