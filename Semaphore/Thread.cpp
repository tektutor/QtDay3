#include "Thread.h"

int Thread::count = 0;
int Thread::progress = 0;
QSystemSemaphore* Thread::pSemaphore;

Thread::Thread() {

	QString tempName = "Thread ";
	QString strIndex;
	strIndex.setNum(++count);
	name.append ( tempName );
	name.append ( strIndex );

	pSemaphore = new QSystemSemaphore ( "progress", 1 );
	
	updateProgress ( 0 );
}

int Thread::retrieveProgress() {

	QFile file ("file.txt");

	if ( !file.open ( QIODevice::ReadOnly | QIODevice::Text ) ) {
		qDebug() << "Error reading file ...";
		return -1;
	}

	QTextStream infile ( &file );
	QString strProgress;

	if ( ! infile.atEnd() )
		strProgress = infile.readLine();

	file.close();

	return strProgress.toInt();
}

void Thread::updateProgress(int progress) {


	QFile file ( "file.txt" );

	if ( !file.open ( QIODevice::WriteOnly | QIODevice::Text ) ) {
		qDebug() << "Error Writing to file ...";
		return;
	}

	QTextStream outfile ( &file );
	QString strProgress;
	strProgress.setNum ( progress );

	outfile << strProgress;

	file.close();

}

void Thread::run() {
	int tempProgress = 0;
	for (int count=0; count<100; ++count) {
		qDebug() << name << "Waiting for lock ...";

		pSemaphore->acquire();

		qDebug() << name << "Acquired lock ...";
		tempProgress = retrieveProgress();
		qDebug() << name << " Current progress => " << tempProgress;

		if ( tempProgress > 99 ) {
			qDebug() << "Task completed.";
			pSemaphore->release();
			
			return;
		}

		updateProgress ( ++tempProgress );	

		qDebug() << name << " Progress => " << tempProgress;
		progress = tempProgress;
		qDebug() << name << "Released lock ..." << endl;

		pSemaphore->release();

		yieldCurrentThread();	

		sleep ( 1 );
	}	
}
