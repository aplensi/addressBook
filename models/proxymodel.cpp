#include "proxymodel.h"

ProxyModel::ProxyModel(QObject *parent) : QSortFilterProxyModel(parent){}

void ProxyModel::sortByColumn(int column)
{
    switch (column) {
    case 0:     setSortRole(PersonModel::idRole);       break;
    case 1:     setSortRole(PersonModel::nameRole);     break;
    case 2:     setSortRole(PersonModel::addressRole);  break;
    case 3:     setSortRole(PersonModel::phoneRole);    break;
    default:    setSortRole(PersonModel::idRole);       break;
    }
    sort(0, Qt::AscendingOrder);
}
