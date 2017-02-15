#include "MyDlg.h"

MyDlg::MyDlg() {

	QPushButton *pBttn = NULL;
	QString buttonCaption = "Button ";
	QString tempIndex;
	QString caption;

	pSignalMapper = new QSignalMapper;
	pLayout = new QHBoxLayout;
	for (int count=0; count<10; ++count) {
		tempIndex.setNum ( count+1 );
		caption = buttonCaption;
		caption.append ( tempIndex );
		pBttn = new QPushButton (caption);
	
		pSignalMapper->setMapping ( pBttn, caption );
	
		pLayout->addWidget ( pBttn );
	
		connect (
			pBttn,
			SIGNAL ( clicked() ),
			pSignalMapper,
			SLOT ( map() )
		);
	}

	setLayout ( pLayout );

	connect (
		pSignalMapper,
		SIGNAL ( mapped(QString) ),
		this,
		SLOT ( onButtonClicked(QString) )
	);
}

void MyDlg::onButtonClicked(QString caption) {
	qDebug() << caption << " clicked";
}

