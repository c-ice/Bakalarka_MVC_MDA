#ifndef ELEMENTTOOLBUTTON_H
#define ELEMENTTOOLBUTTON_H

#include <QToolButton>
#include <QWidget>
#include <QButtonGroup>
#include "Scene/diagramitem.h"

class ElementToolButton : public QWidget
{
    Q_OBJECT
public:
    explicit ElementToolButton(const QPixmap &image, QButtonGroup *buttonGroup, const QString &text, QWidget *parent);

signals:
    
public slots:
    
};

#endif // ELEMENTTOOLBUTTON_H
