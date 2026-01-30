#ifndef SORTMODEL_H
#define SORTMODEL_H

#include <QSortFilterProxyModel>
#include "personmodel.h"

class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    ProxyModel(QObject* parent = nullptr);
    Q_INVOKABLE void sortByColumn(int column);
};

#endif // SORTMODEL_H
