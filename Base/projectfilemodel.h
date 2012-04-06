#ifndef PROJECTFILEMODEL_H
#define PROJECTFILEMODEL_H

#include <QFileSystemModel>

class ProjectFileModel : public QFileSystemModel
{
    Q_OBJECT
public:
    explicit ProjectFileModel(QObject *parent = 0);
    
    int columnCount(const QModelIndex &parent) const{
        return 1;
    }

signals:
    
public slots:
    
};

#endif // PROJECTFILEMODEL_H
