#include "controller.h"

Controller::Controller(IPersonsSink& personSink, IPersonsSource& personSource, PersonModel& model, QObject *parent) :
    QObject(parent), m_personSink(personSink), m_personSource(personSource), m_model(model)
{
    m_model.setPeople(m_personSink.getData());
}

void Controller::sortColumn(int index)
{
    m_model.sort(index);
}

void Controller::deleteButton(int index, int id)
{
    m_personSource.remove(id);
    m_model.remove(index);
}

void Controller::addButton(QString name, QString address, QString phone)
{
    if(name == "" || address == "" || phone == "") return;
    m_model.addPerson(m_personSource.add(name,address, phone));
}

void Controller::changeButton(int id, QString name, QString address, QString phone)
{
    if(name == "" || address == "" || phone == "") return;
    m_personSource.change(id, name, address, phone);
    m_model.change(id, name, address, phone);
}
