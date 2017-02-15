#include <QDialog>
#include <QTreeView>
#include <QListView>
#include <QFileSystemModel>
#include <QSplitter>
#include <QHBoxLayout>

class FileExplorerDlg : public QDialog {
Q_OBJECT
private:
	QFileSystemModel *pFileSystemModel , *pDirModel;
	QTreeView *pTreeView;
	QListView *pListView;
	QSplitter *pSplitter;
	QHBoxLayout *pLayout;
public:
	FileExplorerDlg();
private slots:
	void onTreeViewClicked(QModelIndex);
};
