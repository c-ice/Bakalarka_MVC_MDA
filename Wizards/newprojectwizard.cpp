#include "newprojectwizard.h"
#include "ui_newprojectwizard.h"
#include "newprojectpage.h"

NewProjectWizard::NewProjectWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::NewProjectWizard)
{
    ui->setupUi(this);
}

NewProjectWizard::~NewProjectWizard()
{
    delete ui;
}

void NewProjectWizard::accept()
{


    QWizard::accept();
}
