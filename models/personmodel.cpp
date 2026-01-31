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

PersonModel::PersonModel(QObject* parent) : QAbstractListModel(parent){}

void PersonModel::addPerson(const Person &pers)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_persons.push_back(pers);
    endInsertRows();
}

void PersonModel::setPeople(QList<Person> persons)
{
    m_persons = std::move(persons); // не уверен что так стоит делать
    updateList();
}

void PersonModel::updateList()
{
    beginResetModel();
    endResetModel();
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    return m_persons.count();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_persons.count()){
        return QVariant();
    }

    const Person& pers = m_persons.at(index.row());
    switch (role) {
        case idRole:        return pers.id();       break;
        case nameRole:      return pers.name();     break;
        case addressRole:   return pers.address();  break;
        case phoneRole:     return pers.phone();    break;
        default:            return QVariant();      break;
    }
}

QVariantMap PersonModel::get(int index) const
{
    if (index < 0 || index >= m_persons.size())
        return {};

    const Person &p = m_persons.at(index);
    return {
        { "id", p.id() },
        { "name", p.name() },
        { "address", p.address() },
        { "phone", p.phone() }
    };
}

void PersonModel::change(int id, QString name, QString address, QString phone)
{
    for(auto& i : m_persons){
        if(i.id() == id){
            i.setName(name);
            i.setAddress(address);
            i.setPhone(phone);
        }
    }
    updateList();
}

void PersonModel::remove(int id)
{
    for(int i = 0; i < m_persons.length(); i++){
        if(m_persons[i].id() == id){
            m_persons.remove(i);
            break;
        }
    }
    updateList();
}

