#include "Thread.h"

int Thread::count = 0;
int Thread::progress = 0;
QMutex Thread::mutex;

Thread::Thread() {

	QString tempName = "Thread ";
	QString strIndex;
	strIndex.setNum(++count);
	name.append ( tempName );
	name.append ( strIndex );

}

void Thread::run() {
	int tempProgress = 0;
	for (int count=0; count<100; ++count) {
		qDebug() << name << "Waiting for lock ...";
		mutex.lock();
		qDebug() << name << "Acquired lock ...";
		tempProgress = progress;
		qDebug() << name << " Current progress => " << tempProgress;
		qDebug() << name << " Progress => " << ++tempProgress;
		progress = tempProgress;
		qDebug() << name << "Released lock ..." << endl;
		mutex.unlock();

		yieldCurrentThread();	
	}	

}
