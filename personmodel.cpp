#include "personmodel.h"

QHash<int, QByteArray> PersonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[idRole] = "id";
    roles[nameRole] = "name";
    roles[addressRole] = "address";
    roles[phoneRole] = "phone";
    return roles;
}

PersonModel::PersonModel(QObject *parent) : QAbstractListModel(parent){}

void PersonModel::addPerson(const Person &pers)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_people.push_back(pers);
    endInsertRows();
}

QList<Person> &PersonModel::getPersonList()
{
    return m_people;
}

void PersonModel::updateList()
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    endInsertRows();
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    return m_people.count();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_people.count()){
        return QVariant();
    }

    const Person &pers = m_people[index.row()];
    switch (role) {
        case idRole:      return pers.id();     break;
        case nameRole:      return pers.name();     break;
        case addressRole:   return pers.address();  break;
        case phoneRole:     return pers.phone();    break;
        default:            return QVariant();      break;
    }
}
