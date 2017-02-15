#include "File.h"

File::File( QString name ) {
	this->name = name;
}

void File::read() {
	QFile file ( name );
	
	if ( !file.open ( QIODevice::ReadOnly | QIODevice::Text ) ) {
		qDebug() << "#### Error reading filename => " << name;
		return;
	}

	QTextStream infile ( &file );

	while ( !infile.atEnd() ) 
		qDebug() << infile.readLine();
	
	file.close();
}

void File::write() {
	QFile file( name );

	if ( !file.open ( QIODevice::WriteOnly | QIODevice::Text ) ) {
		qDebug() << "#### Error write to filename #### " << name;
		return ;
	}

	QTextStream outfile ( &file );

	outfile << "First line" << endl;
	outfile << "Second line" << endl;
	outfile << "Third line" << endl;

	file.close();
}
