#include <QDialog>
#include <QPushButton>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QString>
#include <QIntValidator>

class MyDlg : public QDialog {
Q_OBJECT
private:
	QFormLayout *pFormLayout;
	QVBoxLayout *pMainLayout;
	QHBoxLayout *pNavigationLayout;
	QLineEdit *pFirstNumberEdit, *pSecondNumberEdit, *pResultEdit;	
	QPushButton *pAddBttn, *pSubtractBttn, *pMultiplyBttn, *pDivideBttn;
public:
	MyDlg();
private slots:
	void onAddButtonClicked(); 
	void onSubtractButtonClicked(); 
	void onMultiplyButtonClicked(); 
	void onDivideButtonClicked(); 
};
