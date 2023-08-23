#include "THThread.h"

THThread::THThread(QObject* parent) : QThread(parent) {}
void THThread::run() noexcept {
	sleep(1);             // wait setup()
	time_t       rawtime;
	int  	     *data;
	struct tm    *tm;
	while (1) {
		data = read_dht_data();
		rawtime = time(NULL);
		tm = localtime(&rawtime);
		if (data != nullptr) {
			QString humidity = QString::number(data[0]) +
			       	           "%";
			QString temperature = QString::number(data[2]) +
					      "." + QString::number(data[3]) +
					      "*C";
			Q_EMIT dataUpdate(temperature, humidity);
			free(data);
		}
		sleep(1);
		Q_EMIT dateTimeUpdate(tm->tm_year + 1900, tm->tm_mon + 1,
				    tm->tm_mday,
				    tm->tm_hour, tm->tm_min, tm->tm_wday);
	}
}
