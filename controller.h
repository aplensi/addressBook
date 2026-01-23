#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <database.h>
#include <person.h>
#include <personmodel.h>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class SortPeople{
    QList<Person>& m_people;
public:
    SortPeople(QList<Person>& people);
    void sort(int column);
};

class Controller : public QObject
{
    Q_OBJECT
    QQmlApplicationEngine& m_engine;
    QList<Person> m_people;
    Database m_db;
    PersonModel* m_model;
    GetDatabase* m_getDb;
    SetDatabase* m_setDb;
public:
    Controller(QQmlApplicationEngine& engine, QObject *parent = nullptr);
    ~Controller();
public slots:
    void sortColumn(int index);
};

#endif // CONTROLLER_H
