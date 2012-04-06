#ifndef PROJECTFILESWIDGET_H
#define PROJECTFILESWIDGET_H

#include <QDockWidget>
#include <QFileSystemModel>
#include <QMenu>

namespace Ui {
class ProjectFilesWidget;
}

class ProjectFilesWidget : public QDockWidget
{
    Q_OBJECT
    
public:
    explicit ProjectFilesWidget(QFileSystemModel *model, QMenu *contextMenu, QWidget *parent = 0);
    ~ProjectFilesWidget();
    
private slots:
    void on_treeView_customContextMenuRequested(const QPoint &pos);

private:
    Ui::ProjectFilesWidget *ui;
    QMenu *contextMenu;
};

#endif // PROJECTFILESWIDGET_H
