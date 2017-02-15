#include <QThread>
#include <QString>
#include <QDebug>
#include <QMutex>

class Thread : public QThread {
Q_OBJECT
private:
	static int count;
	static int progress;
	static QMutex mutex;
	QString name;	
protected:
	void run();
public:
	Thread();
};
