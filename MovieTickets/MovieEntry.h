#ifndef _MOVIE_ENTRY
#define _MOVIE_ENTRY

#include <QString>
#include <QStringList>

class MovieEntry{
	public:
		MovieEntry();
		MovieEntry(QString entry);
		MovieEntry(MovieEntry* entry);
		~MovieEntry();
		
		void setTitle(QString title);
		void setDirector(QString director);
		void setYear(QString year);
		void setDuration(QString duration);
		void setRating(QString rating);
		void setVisualization_date(QString date);
		void setCast(QStringList cast);
		void setPlot(QString spot);
		void setImage_path(QString image_path);
		
		QString getTitle();
		QString getDirector();
		QString getYear();
		QString getDuration();
		QString getRating();
		QString getVisualization_date();
		QStringList getCast();
		QString getPlot();
		QString getImage_path();

		QString toString();

		const QString mark;

	private:
		QString title;
		QString director;
		QString year;
		QString duration;
		QString rating;
		QString visualization_date;
		QStringList cast;
		QString plot;
		QString image_path;
};

#endif