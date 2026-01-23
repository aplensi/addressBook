#include "controller.h"

Controller::Controller(QQmlApplicationEngine& engine, QObject *parent) : QObject(parent), m_engine(engine)
{
    m_getDb = new GetDatabase((m_db.getDatabase()));
    m_setDb = new SetDatabase((m_db.getDatabase()));
    m_model = new PersonModel(m_people);
    m_getDb->getData(m_people);
    m_model->updateList();

    engine.rootContext()->setContextProperty("Controller", this);
    engine.rootContext()->setContextProperty("person", QVariant::fromValue(m_model));
}

Controller::~Controller()
{
    delete m_getDb;
    delete m_setDb;
    delete m_model;
}

void Controller::sortColumn(int index)
{
    SortPeople peopleSort(m_people);
    peopleSort.sort(index);
    m_model->updateList();
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
