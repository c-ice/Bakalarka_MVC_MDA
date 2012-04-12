#ifndef PALLETEWIDGET_H
#define PALLETEWIDGET_H

#include <QDockWidget>

namespace Ui {
class PalleteWidget;
}

class PalleteWidget : public QDockWidget
{
    Q_OBJECT
    
public:
    explicit PalleteWidget(QWidget *parent = 0);
    ~PalleteWidget();
    Ui::PalleteWidget *ui;
};

#endif // PALLETEWIDGET_H
