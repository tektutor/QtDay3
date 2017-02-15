#include <QCoreApplication>
#include "MyClass.h"

int main ( int argc, char **argv ) {

	QCoreApplication theApp ( argc, argv );

	MyClass objectOne,objectTwo;

	QObject::connect (
		&objectOne,
		SIGNAL ( signalOne(int) ),
		&objectTwo,
		SLOT ( onSignalOne(int) ) 
	);
	QObject::connect (
		&objectTwo,
		SIGNAL ( signalTwo(int,int) ),
		&objectTwo,
		SLOT ( onSignalTwo(int,int) ) 
	);

	objectOne.sendSignalOne();
	
	
	return theApp.exec();
}
