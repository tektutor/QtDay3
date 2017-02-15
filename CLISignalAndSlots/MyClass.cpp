#include "MyClass.h"

void MyClass::onSignalOne(int value) {
	qDebug() << "Signal One =>" 
	         << value ;
}

void MyClass::onSignalTwo(int value1,int value2) {
	qDebug() << "Signal Two =>" 
	         << value1 << " " 
		 << value2;
}

void MyClass::sendSignalOne() {
	emit signalOne(10);
}

void MyClass::sendSignalTwo() {
	emit signalTwo(10,20);
}
