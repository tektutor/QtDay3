#include <QCoreApplication>
#include "Thread.h"

int main ( int argc, char **argv ) {

	QCoreApplication theApp ( argc, argv );

	for (int count=0; count<100; ++count )
		(new Thread())->start();

	return theApp.exec();

}
