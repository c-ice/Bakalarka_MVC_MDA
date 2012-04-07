#include "palletewidget.h"
#include "ui_palletewidget.h"

PalleteWidget::PalleteWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::PalleteWidget)
{
    ui->setupUi(this);
}

PalleteWidget::~PalleteWidget()
{
    delete ui;
}
