#include "ClockWindow.h"

ClockWindow::ClockWindow(QWidget *parent) : QMainWindow(parent) {
		this->resize(720, 480);
		this->setWindowTitle("Smart Clock");
		this->month = new QLabel("12.", this);
		this->month->setGeometry(60, 10, 30, 20);
		this->day = new QLabel("12.", this);
		this->day->setGeometry(90, 10, 30, 20);
		this->year = new QLabel("0000.", this);
		this->year->setGeometry(10, 10, 60, 20);
		this->DOW = new QLabel("Monday", this);
		this->DOW->setGeometry(130, 10, 60, 20);


		this->hour = new QLabel("12", this);
		this->hour->setGeometry(10, 40, 45, 60);
		this->contour = new QLabel(" : ", this);
		this->contour->setGeometry(60, 40, 30, 60);
		this->minute = new QLabel("00", this);
		this->minute->setGeometry(95, 40, 45, 60);
		this->MA = new QLabel("pm", this);
		this->MA->setGeometry(150, 80, 40, 20);
		this->WC = new QLabel("Unknown", this);
		this->WC->setGeometry(400, 10, 100, 20);
		this->AC = new QLabel("Unknown", this);
		this->AC->setGeometry(400, 40, 100, 20);

		this->title_I = new QLabel("Inside", this);
		this->title_I->setGeometry(10, 105, 120, 20);
		this->temperature_I = new QLabel("00.0*C", this);
		this->temperature_I->setGeometry(10, 125, 55, 20);
		this->humidity_I = new QLabel("0%" ,this);
		this->humidity_I->setGeometry(70, 125, 55, 20);
		this->title_O = new QLabel("Outside", this);
		this->title_O->setGeometry(150, 105, 120, 20);
		this->temperature_O = new QLabel("00.0*C", this);
		this->temperature_O->setGeometry(150, 125, 55, 20);
		this->humidity_O = new QLabel("0%" ,this);
		this->humidity_O->setGeometry(205, 125, 55, 20);
		setup();
		this->ththread = new THThread(this);
		this->pythread = new PyThread(this);

		this->weatherSunnyPlaylist = new QMediaPlaylist;
		this->weatherSunnyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Sunny/볼빨간사춘기-여행.mp3"));
		this->weatherSunnyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Sunny/볼빨간사춘기-별_보러_갈래.mp3"));
		this->weatherSunnyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Sunny/아이유-라일락.mp3"));
		this->weatherSunnyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Sunny/장범준-흔들리는_꽃들_속에서_네_샴푸향이_느껴진거야.mp3"));
		this->weatherSunnyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Sunny/아이유-이_지금.mp3"));
		this->weatherCloudyPlaylist = new QMediaPlaylist;
		this->weatherCloudyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Cloudy/EZ_DO_DANCE_ALEXANDER_ver.mp3"));
		this->weatherCloudyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Cloudy/GIDLE_여자아이들-TOMBOY.mp3"));
		this->weatherCloudyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Cloudy/ITZY-SNEAKERS.mp3"));
		this->weatherCloudyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Cloudy/IVE-After_LIKE.mp3"));
		this->weatherCloudyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Cloudy/NewJeans(뉴진스)-Cookie.mp3"));
		this->weatherRainyPlaylist = new QMediaPlaylist;
		this->weatherRainyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Rainy/폴킴-비.mp3"));
		this->weatherRainyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Rainy/윤하-우산.mp3"));
		this->weatherRainyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Rainy/헤이즈Heize-비도_오고_그래서_Feat_신용재.mp3"));
		this->weatherRainyPlaylist->addMedia(
			QUrl::fromLocalFile("./home/pi/smartClock/resource/playlist/Rainy/아이유-Rain_Drop.mp3"));
		this->weatherRainyPlaylist->addMedia(
			QUrl::fromLocalFile("./home/pi/smartClock/resource/playlist/Rainy/윤하-비가_내리는_날에는.mp3"));
		this->weatherSnowyPlaylist = new QMediaPlaylist;
		this->weatherSnowyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Snowy/정승환-눈사람.mp3"));
		this->weatherSnowyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Snowy/에일리-첫눈처럼_너에게_가겠다.mp3"));
		this->weatherSnowyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Snowy/박효신-눈의_꽃.mp3"));
		this->weatherSnowyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Snowy/정준일-첫_눈.mp3"));
		this->weatherSnowyPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Snowy/Mariah_Carey_All_I_Want_For_Christmas_Is_You.mp3"));
		this->weatherDustPlaylist = new QMediaPlaylist;
		this->weatherDustPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Dust/샤이니-산소같은_너.mp3"));
		this->weatherDustPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Dust/BEAST(비스트)-BREATH(숨).mp3"));
		this->weatherDustPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Dust/DAY6-EMERGENCY.mp3"));
		this->weatherDustPlaylist->addMedia(
			QUrl::fromLocalFile("/home/pi/smartClock/resource/playlist/Dust/RED_VELVET-음파음파.mp3"));

		this->player = new QMediaPlayer;
		this->player->setVolume(100);

		connect(this->ththread, SIGNAL(dataUpdate(QString,QString)),
			this, SLOT(setInsideData(QString, QString)));
		connect(this->ththread, SIGNAL(dateTimeUpdate(
						int, int, int,
						int, int, int)),
			this, SLOT(setClock(
						int, int, int,
						int, int, int)));
		
		connect(this->pythread,
			SIGNAL(updateOutsideData(QString, QString,
					 	 QString, QString)),
			this, SLOT(setOutsideData(QString, QString,
					 	  QString, QString)));
		connect(this, SIGNAL(updateAudio(QString, QString)),
					this, SLOT(setAudioTheme(
						  QString, QString)));
		

		this->pythread->start();
		this->ththread->start();
	}
void ClockWindow::setInsideData(QString temp, QString hu) noexcept {
	this->temperature_I->setText(temp);
	this->humidity_I->setText(hu);
	this->temperature_I->update();
	this->humidity_I->update();
}

void ClockWindow::setClock(int year, int month, int day,
			   int hour, int minute, int DOW) noexcept {
	if (hour > 12) {
		this->MA->setText("PM");
	}
	else {
		this->MA->setText("AM");
	}

	this->hour->setText(QString::number(hour));
	this->minute->setText(QString::number(minute));
	this->year->setText(QString::number(year) + ". ");
	this->month->setText(QString::number(month) + ". ");
	this->day->setText(QString::number(day) + ". ");
	switch(DOW) {
		case 0:
			this->DOW->setText("일");
			break;
		case 1:
			this->DOW->setText("월");
			break;
		case 2:
			this->DOW->setText("화");
			break;
		case 3:
			this->DOW->setText("수");
			break;
		case 4:
			this->DOW->setText("목");
			break;
		case 5:
			this->DOW->setText("금");
			break;
		case 6:
			this->DOW->setText("토");
			break;
		default:
			break;
	}

	this->hour->update();
	this->minute->update();
	this->DOW->update();
	this->MA->update();
	this->year->update();
	this->month->update();
	this->day->update();
}

void ClockWindow::setOutsideData(QString temp, QString hu,
		 	 	 QString wc, QString ac) noexcept {
	this->temperature_O->setText(temp);
	this->humidity_O->setText(hu);
	this->WC->setText(wc);
	this->AC->setText(ac);

	this->temperature_O->update();
	this->humidity_O->update();
	this->WC->update();
	this->AC->update();
	Q_EMIT setAudioTheme(wc, ac);
}

void ClockWindow::setAudioTheme(QString wc, QString ac) noexcept {
	if (ac == "나쁨" || ac == "매우나쁨") {
		if (this->airCondition != "나쁨" ||
				this->airCondition != "매우나쁨") {
			controlLED(4);
			this->weatherDustPlaylist->setCurrentIndex(0);
			this->player->setPlaylist(
					this->weatherDustPlaylist);
			this->player->play();
		}
	}
	else {
		if (wc != this->weather) {
			this->weather = wc;
			if (wc == "맑음") {
				controlLED(0);
				this->weatherSunnyPlaylist->setCurrentIndex(0);
				this->player->setPlaylist(
					this->weatherSunnyPlaylist);
				this->player->play();
			}
			else if (wc == "흐림" || wc == "구름많음") {
				controlLED(1);
				this->weatherCloudyPlaylist->setCurrentIndex(0);
				this->player->setPlaylist(
					this->weatherCloudyPlaylist);
				this->player->play();
			}
			else if (wc == "비") {
				controlLED(2);
				this->weatherRainyPlaylist->setCurrentIndex(0);
				this->player->setPlaylist(
					this->weatherRainyPlaylist);
				this->player->play();
			}
			else if (wc == "눈") {
				controlLED(3);
				this->weatherSnowyPlaylist->setCurrentIndex(0);
				this->player->setPlaylist(
					this->weatherSnowyPlaylist);
				this->player->play();
			}
		}

	}
}

ClockWindow::~ClockWindow() {
	this->ththread->quit();
	this->pythread->quit();
	delete(this->title_I);
	delete(this->temperature_I);
	delete(this->humidity_I);
	delete(this->title_O);
	delete(this->temperature_O);
	delete(this->humidity_O);
	delete(this->hour);
	delete(this->minute);
	delete(this->DOW);
	delete(this->MA);
	delete(this->year);
	delete(this->WC);
	delete(this->AC);
	delete(this->weatherSunnyPlaylist);
	delete(this->weatherCloudyPlaylist);
	delete(this->weatherRainyPlaylist);
	delete(this->weatherSnowyPlaylist);
	delete(this->weatherDustPlaylist);
	delete(this->player);
	delete(this->ththread);
	delete(this->pythread);
}
