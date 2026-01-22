#include "personmodel.h"

person::person(const QString& name, const QString& address, const QString& phone) : m_name(name), m_address(address), m_phone(phone) {}

QString person::name() const
{
    return m_name;
}

QString person::address() const
{
    return m_address;
}

QString person::phone() const
{
    return m_phone;
}

QHash<int, QByteArray> personModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[nameRole] = "name";
    roles[addressRole] = "address";
    roles[phoneRole] = "phone";
    return roles;
}

personModel::personModel(QObject *parent) : QAbstractListModel(parent){}

void personModel::addPerson(const person &pers)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    people.push_back(pers);
    endInsertRows();
}

int personModel::rowCount(const QModelIndex &parent) const
{
    return people.count();
}

QVariant personModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= people.count()){
        return QVariant();
    }

    const person &pers = people[index.row()];
    switch (role) {
        case nameRole:      return pers.name();     break;
        case addressRole:   return pers.address();  break;
        case phoneRole:     return pers.phone();    break;
        default:            return QVariant();      break;
    }
}
