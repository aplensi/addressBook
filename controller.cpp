#include "controller.h"

Controller::Controller(QQmlApplicationEngine& engine, QObject *parent) :
    QObject(parent), m_engine(engine), m_getDb(m_db.getDatabase()), m_setDb(m_db.getDatabase()), m_model(m_people)
{
    m_getDb.getData(m_people);
    m_model.updateList();

    engine.rootContext()->setContextProperty("Controller", this);
    engine.rootContext()->setContextProperty("person", QVariant::fromValue(&m_model));
}

Controller::~Controller()
{
}

void Controller::sortColumn(int index)
{
    SortPeople peopleSort(m_people);
    peopleSort.sort(index);
    m_model.updateList();
}

void Controller::deleteButton(int index)
{
    m_setDb.removePerson(m_people[index].id());
    m_people.remove(index);
    m_model.updateList();
}

void Controller::addButton(QString name, QString address, QString phone)
{
    if(name == "" || address == "" || phone == "") return;
    m_setDb.addPerson(name, address, phone);
    m_model.addPerson(Person(m_getDb.getLastId(), name, address, phone));
    m_model.updateList();
}

void Controller::changeButton(int id, QString name, QString address, QString phone)
{
    if(name == "" || address == "" || phone == "") return;
    m_setDb.changePerson(id, name, address, phone);
    ChangePerson changePerson(m_people);
    changePerson.change(id, name, address, phone);
    m_model.updateList();
}

SortPeople::SortPeople(QList<Person> &people) : m_people(people){}

void SortPeople::sort(int column)
{
    switch (column) {
    case 0:     std::sort(m_people.begin(), m_people.end(), [](const Person &a, const Person &b) {return a.id() < b.id();});            break;
    case 1:     std::sort(m_people.begin(), m_people.end(), [](const Person &a, const Person &b) {return a.name() < b.name();});        break;
    case 2:     std::sort(m_people.begin(), m_people.end(), [](const Person &a, const Person &b) {return a.address() < b.address();});  break;
    case 3:     std::sort(m_people.begin(), m_people.end(), [](const Person &a, const Person &b) {return a.phone() < b.phone();});      break;
    default:                                                                                                                            break;
    }
}

ChangePerson::ChangePerson(QList<Person> &people) : m_people(people){}

void ChangePerson::change(int id, QString name, QString address, QString phone)
{
    for(auto& i : m_people){
        if(i.id() == id){
            i.setName(name);
            i.setAddress(address);
            i.setPhone(phone);
        }
    }
}
