#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSignalMapper>
#include <QDebug>
#include <QString>

class MyDlg : public QDialog {
Q_OBJECT
private:
	QSignalMapper *pSignalMapper;
	QHBoxLayout *pLayout;
public:
	MyDlg();
private slots:
	void onButtonClicked(QString); 
};
