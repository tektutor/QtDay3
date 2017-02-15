#include <QApplication>
#include "FileExplorerDlg.h"

int main ( int argc, char **argv ) {

	QApplication theApp ( argc, argv );

	FileExplorerDlg dlg;
	dlg.show();

	return theApp.exec();
}
