#include "projectfileswidget.h"
#include "ui_projectfileswidget.h"


ProjectFilesWidget::ProjectFilesWidget(QFileSystemModel *model, QMenu *contextMenu, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ProjectFilesWidget)
{
    ui->setupUi(this);
    ui->treeView->setModel(model);
    this->contextMenu = contextMenu;
}

ProjectFilesWidget::~ProjectFilesWidget()
{
    delete ui;
}

void ProjectFilesWidget::on_treeView_customContextMenuRequested(const QPoint &pos)
{
    contextMenu->popup(QWidget::mapToGlobal(pos));
}
