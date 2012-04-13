#include "newprojectpage.h"
#include "ui_newprojectpage.h"

NewProjectPage::NewProjectPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::NewProjectPage)
{
    ui->setupUi(this);

    dialog = new QFileDialog(this, tr("Choose Project Location"));
    dialog->setAcceptMode(QFileDialog::AcceptOpen);
    dialog->setFileMode(QFileDialog::Directory);
    dialog->setOption(QFileDialog::ShowDirsOnly, true);
    connect(dialog, SIGNAL(accepted()), this, SLOT(dialogAccepted()));
}

NewProjectPage::~NewProjectPage()
{
    delete ui;
}


void NewProjectPage::on_pushButton_clicked()
{
    dialog->exec();
}

void NewProjectPage::dialogAccepted()
{
    ui->location->setText(dialog->selectedFiles().first());
}
