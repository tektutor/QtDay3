#include <QObject>
#include <QDebug>

class MyClass : public QObject {
Q_OBJECT
public:
	void sendSignalOne();
	void sendSignalTwo();
signals:
	void signalOne(int);
	void signalTwo(int,int);
private slots:
	void onSignalOne(int);
	void onSignalTwo(int,int);
};
