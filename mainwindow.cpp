#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Widgets/projectfileswidget.h"
#include "ui_palletewidget.h"
#include "Base/elementtoolbutton.h"

#include <Qt>
#include <QGraphicsView>
#include <QAbstractButton>


const int InsertTextButton = 10;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Important ordering
    setupMenus();
    setupActions();

    palleteWidget = new PalleteWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea, palleteWidget);

    setupToolBox();
    // end

    m_projectFilesMode = new ProjectFileModel(this);
    m_projectFilesMode->setRootPath("");
    projectFilesWidget = new ProjectFilesWidget(m_projectFilesMode, m_projectFilesModelMenu, this);
    addDockWidget(Qt::RightDockWidgetArea, projectFilesWidget);
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
    QAction *action = new QAction(tr("Save"), this);
    action->setIcon(QIcon(":/images/save.png"));
    m_projectFilesModelMenu->addAction(action);
}

void MainWindow::toolboxButtonGroupClicked(int id)
{
    QList<QAbstractButton *> buttons = toolboxButtonGroup->buttons();
    foreach (QAbstractButton *button, buttons)
    {
        if (toolboxButtonGroup->button(id) != button)
            button->setChecked(false);
    }

    if (id == InsertTextButton)
    {
        activeScene()->setMode(DiagramScene::InsertText);
    }
    else
    {
        activeScene()->setItemType(DiagramItem::DiagramType(id));
        activeScene()->setMode(DiagramScene::InsertItem);
    }
}

DiagramScene* MainWindow::activeScene()
{
    return scenes.first();
}

void MainWindow::setupToolBox()
{
    toolboxButtonGroup = new QButtonGroup(this);
    toolboxButtonGroup->setExclusive(false);
    connect(toolboxButtonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(toolboxButtonGroupClicked(int)));




    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new ElementToolButton(QPixmap(), toolboxButtonGroup, "Prvy Button", this));

    palleteWidget->ui->modelPage->setLayout(layout);
//! [21]
/*
    QToolButton *textButton = new QToolButton;
    textButton->setCheckable(true);
    buttonGroup->addButton(textButton, InsertTextButton);
    textButton->setIcon(QIcon(QPixmap(":/images/textpointer.png")
                        .scaled(30, 30)));
    textButton->setIconSize(QSize(50, 50));
    QGridLayout *textLayout = new QGridLayout;
    textLayout->addWidget(textButton, 0, 0, Qt::AlignHCenter);
    textLayout->addWidget(new QLabel(tr("Text")), 1, 0, Qt::AlignCenter);
    QWidget *textWidget = new QWidget;
    textWidget->setLayout(textLayout);
    layout->addWidget(textWidget, 1, 1);

    layout->setRowStretch(3, 10);
    layout->setColumnStretch(2, 10);

    QWidget *itemWidget = new QWidget;
    itemWidget->setLayout(layout);

    backgroundButtonGroup = new QButtonGroup(this);
    connect(backgroundButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(backgroundButtonGroupClicked(QAbstractButton*)));

    QGridLayout *backgroundLayout = new QGridLayout;
    backgroundLayout->addWidget(createBackgroundCellWidget(tr("Blue Grid"),
                ":/images/background1.png"), 0, 0);
    backgroundLayout->addWidget(createBackgroundCellWidget(tr("White Grid"),
                ":/images/background2.png"), 0, 1);
    backgroundLayout->addWidget(createBackgroundCellWidget(tr("Gray Grid"),
                    ":/images/background3.png"), 1, 0);
    backgroundLayout->addWidget(createBackgroundCellWidget(tr("No Grid"),
                ":/images/background4.png"), 1, 1);

    backgroundLayout->setRowStretch(2, 10);
    backgroundLayout->setColumnStretch(2, 10);

    QWidget *backgroundWidget = new QWidget;
    backgroundWidget->setLayout(backgroundLayout);


//! [22]
    toolBox = new QToolBox;
    toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
    toolBox->setMinimumWidth(itemWidget->sizeHint().width());
    toolBox->addItem(itemWidget, tr("Basic Flowchart Shapes"));
    toolBox->addItem(backgroundWidget, tr("Backgrounds"));*/
}
