#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

class File {
private:
	QString name;
public:
	File(QString name);
	void read();
	void write();
};
