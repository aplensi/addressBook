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
    m_people.push_back(pers);
    endInsertRows();
}

void PersonModel::setPeople(QList<Person> &people)
{
    m_people = people;
    updateList();
}

QList<Person> &PersonModel::getPersonList()
{
    return m_people;
}

void PersonModel::updateList()
{
    beginResetModel();
    endResetModel();
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

    const Person& pers = m_people.at(index.row());
    switch (role) {
        case idRole:      return pers.id();     break;
        case nameRole:      return pers.name();     break;
        case addressRole:   return pers.address();  break;
        case phoneRole:     return pers.phone();    break;
        default:            return QVariant();      break;
    }
}

QVariantMap PersonModel::get(int index) const
{
    if (index < 0 || index >= m_people.size())
        return {};

    const Person &p = m_people.at(index);
    return {
        { "id", p.id() },
        { "name", p.name() },
        { "address", p.address() },
        { "phone", p.phone() }
    };
}

void PersonModel::sort(int column)
{
    switch (column) {
    case 0:     std::sort(m_people.begin(), m_people.end(), [](const Person &a, const Person &b) {return a.id() < b.id();});            break;
    case 1:     std::sort(m_people.begin(), m_people.end(), [](const Person &a, const Person &b) {return a.name() < b.name();});        break;
    case 2:     std::sort(m_people.begin(), m_people.end(), [](const Person &a, const Person &b) {return a.address() < b.address();});  break;
    case 3:     std::sort(m_people.begin(), m_people.end(), [](const Person &a, const Person &b) {return a.phone() < b.phone();});      break;
    default:                                                                                                                            break;
    }
    updateList();
}

void PersonModel::change(int id, QString name, QString address, QString phone)
{
    for(auto& i : m_people){
        if(i.id() == id){
            i.setName(name);
            i.setAddress(address);
            i.setPhone(phone);
        }
    }
    updateList();
}

