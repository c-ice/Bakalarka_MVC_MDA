#include "elementtoolbutton.h"
#include <QToolButton>
#include <QGridLayout>
#include <QLabel>

ElementToolButton::ElementToolButton(DiagramItem *diagramItem, QWidget *parent) :
    QWidget(parent)
{
    QIcon icon(diagramItem->image());

    QToolButton *button = new QToolButton(this);
    button->setIcon(icon);
    button->setIconSize(QSize(50, 50));
    button->setCheckable(true);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button, 0, 0, Qt::AlignHCenter);
    //TODO:TEXT
    layout->addWidget(new QLabel("text"), 1, 0, Qt::AlignCenter);


    this->setLayout(layout);
}
