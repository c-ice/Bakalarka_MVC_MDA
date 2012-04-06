#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Widgets/projectfileswidget.h"
#include "Base/projectfilemodel.h"
#include <QVector>
#include "Scene/diagramscene.h"

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
    QVector<DiagramScene*> scenes;
private:
    Ui::MainWindow *ui;
    ProjectFilesWidget *projectFilesWidget;
    ProjectFileModel *m_projectFilesMode;

    QMenu *m_projectFilesModelMenu;
    QMenu *m_itemMenu;
};

#endif // MAINWINDOW_H
