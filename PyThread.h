#ifndef PYTHREAD_H
#define PYTHREAD_H

#include <QThread>
#include <Python.h>
#include <string>
#include <vector>
#include <QDebug>

class PyThread : public QThread {
	Q_OBJECT
private:
	void run() noexcept;
public:
	PyThread(QObject *parent = nullptr);
Q_SIGNALS:
	void updateOutsideData(QString temp, QString hu,
			     QString wc, QString ac);
};

#endif
