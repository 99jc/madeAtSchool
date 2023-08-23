#ifndef THTHREAD_H
#define THTHREAD_H
#include <QThread>
#include <ctime>
#include <cstdlib>

class THThread : public QThread {
	Q_OBJECT
private:
	void run() noexcept;
public:
	THThread(QObject *parent = nullptr);
Q_SIGNALS:
	void dataUpdate(QString temp, QString hi);
	void dateTimeUpdate(int year, int month,
			    int day, int hour,
			    int minute, int DOW);
};

extern "C" {
	int* read_dht_data();
}

#endif

