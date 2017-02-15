#include "MyDlg.h"

MyDlg::MyDlg() {

	pFirstNumberEdit = new QLineEdit;
	pSecondNumberEdit = new QLineEdit;
	pResultEdit = new QLineEdit;

	pFirstNumberEdit->setValidator ( new QIntValidator(0,100) );

	pAddBttn = new QPushButton ("Add");
	pSubtractBttn = new QPushButton ("Subtract");
	pMultiplyBttn = new QPushButton ("Multiply");
	pDivideBttn = new QPushButton ("Divide");

	pFormLayout = new QFormLayout;
	pMainLayout = new QVBoxLayout;
	pNavigationLayout = new QHBoxLayout;

	pNavigationLayout->addStretch();
	pNavigationLayout->addWidget ( pAddBttn );
	pNavigationLayout->addWidget ( pSubtractBttn );
	pNavigationLayout->addWidget ( pMultiplyBttn );
	pNavigationLayout->addWidget ( pDivideBttn );

	pFormLayout->addRow ( "First Number", pFirstNumberEdit );
	pFormLayout->addRow ( "Second Number", pSecondNumberEdit );
	pFormLayout->addRow ( "Result", pResultEdit );

	pMainLayout->addLayout ( pFormLayout ); 
	pMainLayout->addLayout ( pNavigationLayout );

	setLayout ( pMainLayout );

	connect (
		pAddBttn,
		SIGNAL ( clicked() ),
		this,
		SLOT ( onAddButtonClicked() )
	);
	connect (
		pSubtractBttn,
		SIGNAL ( clicked() ),
		this,
		SLOT ( onSubtractButtonClicked() )
	);
	connect (
		pMultiplyBttn,
		SIGNAL ( clicked() ),
		this,
		SLOT ( onMultiplyButtonClicked() )
	);
	connect (
		pDivideBttn,
		SIGNAL ( clicked() ),
		this,
		SLOT ( onDivideButtonClicked() )
	);
}

void MyDlg::onAddButtonClicked(){
	qDebug() << "Add clicked";
	QString strFirstNumber = pFirstNumberEdit->text();
	QString strSecondNumber = pSecondNumberEdit->text();

	double firstNumber = strFirstNumber.toDouble();
	double secondNumber = strSecondNumber.toDouble();
	double result = firstNumber + secondNumber;

	QString strResult;
	strResult.setNum ( result );
	
	pResultEdit->setText ( strResult );
}

void MyDlg::onSubtractButtonClicked(){
	qDebug() << "Subtract clicked";
	QString strFirstNumber = pFirstNumberEdit->text();
	QString strSecondNumber = pSecondNumberEdit->text();

	double firstNumber = strFirstNumber.toDouble();
	double secondNumber = strSecondNumber.toDouble();
	double result = firstNumber - secondNumber;

	QString strResult;
	strResult.setNum ( result );
	
	pResultEdit->setText ( strResult );
}

void MyDlg::onMultiplyButtonClicked(){
	qDebug() << "Multiply clicked";
	QString strFirstNumber = pFirstNumberEdit->text();
	QString strSecondNumber = pSecondNumberEdit->text();

	double firstNumber = strFirstNumber.toDouble();
	double secondNumber = strSecondNumber.toDouble();
	double result = firstNumber * secondNumber;

	QString strResult;
	strResult.setNum ( result );
	
	pResultEdit->setText ( strResult );
}

void MyDlg::onDivideButtonClicked(){
	qDebug() << "Divide clicked";
	QString strFirstNumber = pFirstNumberEdit->text();
	QString strSecondNumber = pSecondNumberEdit->text();

	double firstNumber = strFirstNumber.toDouble();
	double secondNumber = strSecondNumber.toDouble();
	double result = firstNumber / secondNumber;

	QString strResult;
	strResult.setNum ( result );
	
	pResultEdit->setText ( strResult );
}
