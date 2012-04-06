#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Widgets/projectfileswidget.h"
#include <Qt>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Important ordering
    setupMenus();
    setupActions();
    // end

    m_projectFilesMode = new ProjectFileModel(this);
    m_projectFilesMode->setRootPath("");
    projectFilesWidget = new ProjectFilesWidget(m_projectFilesMode, m_projectFilesModelMenu, this);
    addDockWidget(Qt::LeftDockWidgetArea, projectFilesWidget);
    scenes.append(new DiagramScene(m_itemMenu, this));
    scenes.first()->name = "Test tab";
    ui->tabWidget->addTab(new QGraphicsView(scenes.first()), scenes.first()->name);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupMenus()
{
    m_projectFilesModelMenu = new QMenu("File", this);
    m_itemMenu = new QMenu(this);
}

void MainWindow::setupActions()
{
    QAction *action = new QAction(tr("New file"), this);
    action->setIcon(QIcon(":/images/save.png"));
    m_projectFilesModelMenu->addAction(action);
}
