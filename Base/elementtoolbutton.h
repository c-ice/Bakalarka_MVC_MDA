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
    explicit ElementToolButton(DiagramItem *diagramItem, QButtonGroup *buttonGroup, QWidget *parent = 0);

signals:
    
public slots:
    
};

#endif // ELEMENTTOOLBUTTON_H
