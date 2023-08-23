#ifndef CLOCKWINDOW_H
#define CLOCKWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "THThread.h"
#include "PyThread.h"

class ClockWindow : public QMainWindow { 
	Q_OBJECT
private:
	QLabel* 	 month;
	QLabel* 	 day;
	QLabel* 	 year;
	QLabel* 	 title_I;            // inside
	QLabel* 	 temperature_I;      // inside
	QLabel* 	 humidity_I;         // inside
	QLabel* 	 title_O; 	     // outside
	QLabel* 	 temperature_O;      // outside
	QLabel* 	 humidity_O;         // outside
	QLabel* 	 hour;
	QLabel* 	 minute;
	QLabel* 	 contour; 	     // :
	QLabel* 	 DOW; 		     // day of week
	QLabel* 	 MA;  		     // morning and afternoon
	QLabel* 	 WC; 	 	     // weather condition
	QLabel* 	 AC; 	 	     // air condition
	THThread* 	 ththread; 	     // temperature and humidity thread
	PyThread* 	 pythread;           // 
	QMediaPlayer*    player;
	QString 	 weather = "unknown";// current weather
	QString  	 airCondition = "unknown";
	QMediaPlaylist*  weatherSunnyPlaylist;
	QMediaPlaylist*  weatherCloudyPlaylist;
	QMediaPlaylist*  weatherRainyPlaylist;
	QMediaPlaylist*  weatherSnowyPlaylist;
	QMediaPlaylist*  weatherDustPlaylist;

public:
	ClockWindow(QWidget *parent = nullptr);
	~ClockWindow();
public Q_SLOTS:
	void setInsideData(QString temp, QString hu) noexcept;
	void setOutsideData(QString temp, QString hu,
			    QString wc, QString ac) noexcept;
	void setClock(int hour, int minute, int year,
		      int month, int day, int DOW) noexcept;
	void setAudioTheme(QString wc, QString ac) noexcept;
Q_SIGNALS:
	void updateAudio(QString wc, QString ac);
};

extern "C" {
	void setup();                  //  setup wiringPi
	void controlLED(int state);    //  control LED
}

#endif
