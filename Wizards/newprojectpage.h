#ifndef NEWPROJECTPAGE_H
#define NEWPROJECTPAGE_H

#include <QWizardPage>
#include <QFileDialog>

namespace Ui {
class NewProjectPage;
}

class NewProjectPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit NewProjectPage(QWidget *parent = 0);
    ~NewProjectPage();
    
private slots:
    void on_pushButton_clicked();
    void dialogAccepted();

private:
    Ui::NewProjectPage *ui;
    QFileDialog *dialog;
};

#endif // NEWPROJECTPAGE_H
