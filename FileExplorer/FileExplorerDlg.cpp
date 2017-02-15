#include "FileExplorerDlg.h"

FileExplorerDlg::FileExplorerDlg() {

	pSplitter = new QSplitter();
	
	pTreeView = new QTreeView(pSplitter);
	pListView = new QListView(pSplitter);

	pFileSystemModel = new QFileSystemModel;
	pDirModel = new QFileSystemModel;

	pFileSystemModel->setRootPath ( QDir::currentPath() );
	pFileSystemModel->setFilter ( QDir::AllDirs | 
				      QDir::Dirs | 
				      QDir::Files |
				      QDir::NoDotAndDotDot
			 );
	pDirModel->setRootPath ( QDir::currentPath() );
	pDirModel->setFilter ( QDir::AllDirs | 
				      QDir::Dirs | 
				      QDir::NoDotAndDotDot
			 );

	pTreeView->setModel ( pDirModel );

	pTreeView->setColumnHidden( 1, true );
	pTreeView->setColumnHidden( 2, true );
	pTreeView->setColumnHidden( 3, true );

	pListView->setModel ( pFileSystemModel );

	pLayout = new QHBoxLayout;

	pLayout->addWidget ( pSplitter );

	setLayout ( pLayout );

	connect (
		pTreeView,
		SIGNAL ( clicked(QModelIndex) ),
		this,
		SLOT ( onTreeViewClicked(QModelIndex) )
	);
	
}

void FileExplorerDlg::onTreeViewClicked( QModelIndex index ) {
	QString path = (pDirModel->fileInfo(index)).absoluteFilePath();
	pListView->setRootIndex ( pFileSystemModel->setRootPath ( path ) );
}
