#include "elementtoolbutton.h"
#include <QToolButton>
#include <QGridLayout>
#include <QLabel>

ElementToolButton::ElementToolButton(const QPixmap &image, QButtonGroup *buttonGroup, const QString &text, QWidget *parent) :
    QWidget(parent)
{
    QIcon icon(image);

    QToolButton *button = new QToolButton(this);
    button->setIcon(icon);
    button->setIconSize(QSize(50, 50));
    button->setCheckable(true);
    buttonGroup->addButton(button);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button, 0, 0, Qt::AlignHCenter);

    layout->addWidget(new QLabel(text), 1, 0, Qt::AlignCenter);

    this->setLayout(layout);
}
