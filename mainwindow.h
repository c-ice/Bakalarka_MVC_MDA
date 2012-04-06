#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Widgets/projectfileswidget.h"
#include "Base/projectfilemodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    void setupMenus();
    void setupActions();
private:
    Ui::MainWindow *ui;
    ProjectFilesWidget *projectFilesWidget;
    ProjectFileModel *m_projectFilesMode;

    QMenu *m_projectFilesModelMenu;
};

#endif // MAINWINDOW_H
