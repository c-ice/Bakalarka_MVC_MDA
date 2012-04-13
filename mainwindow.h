#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Widgets/projectfileswidget.h"
#include "Base/projectfilemodel.h"
#include <QVector>
#include "Scene/diagramscene.h"
#include <QButtonGroup>
#include "Widgets/palletewidget.h"
#include "Wizards/newprojectwizard.h"

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
    DiagramScene *activeScene();
    void setupToolBox();

private:
    Ui::MainWindow *ui;
    ProjectFilesWidget *projectFilesWidget;
    PalleteWidget *palleteWidget;
    ProjectFileModel *m_projectFilesMode;
    NewProjectWizard *newProjectWizard;

    QButtonGroup *toolboxButtonGroup;
    QMenu *m_projectFilesModelMenu;
    QMenu *m_itemMenu;

private slots:
    void toolboxButtonGroupClicked(int id);
    void on_actionNew_Project_triggered();
};

#endif // MAINWINDOW_H
