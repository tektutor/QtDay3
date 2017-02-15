#include <QThread>
#include <QString>
#include <QDebug>
#include <QSystemSemaphore>
#include <QFile>
#include <QTextStream>

class Thread : public QThread {
Q_OBJECT
private:
	static int count;
	static int progress;
	static QSystemSemaphore *pSemaphore;
	QString name;	

	int retrieveProgress();
	void updateProgress(int);
protected:
	void run();
public:
	Thread();
};
