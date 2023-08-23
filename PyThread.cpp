#include "PyThread.h"

PyThread::PyThread(QObject* parent) : QThread(parent) {}
void PyThread::run() noexcept {
	PyObject *pModule;
	PyObject *pFunc;
	PyObject *pValue;
	std::string data;
	std::string tmp = "";
	std::vector<QString> sendDataSet{};
	
	while (1) {
		Py_Initialize();

		PyRun_SimpleString("import requests");
		PyRun_SimpleString("from bs4 import BeautifulSoup");
		PySys_SetPath(L"/home/pi/smartClock");
		pModule = PyImport_ImportModule("weather_info");
		pFunc = PyObject_GetAttrString(pModule, "weather_crawling");
		pValue = PyObject_CallObject(pFunc, nullptr);

		
		PyObject *objectsRepresentation = PyObject_Repr(pValue);
		PyObject * str = PyUnicode_AsEncodedString(
				objectsRepresentation,
				"utf-8", "~E~");
		data = PyBytes_AsString(str);
		Py_Finalize();

		for (int i = 1; i < (data.size() -1); i++) {
			if (data[i] != '_') {
				tmp += data[i];
			}
			else {
				sendDataSet.emplace_back(
						QString::fromStdString(tmp));
				tmp = "";
			}
		}
		Q_EMIT updateOutsideData(sendDataSet[0],
				sendDataSet[1],
				sendDataSet[2],
				sendDataSet[3]);
				
		sleep(1);
	}
}
