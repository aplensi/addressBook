#ifndef DATABASE_H
#define DATABASE_H

#include "qsqldatabase.h"
#include <person.h>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSql>

class SetDatabase{
    QSqlDatabase& m_db;
public:
    SetDatabase(QSqlDatabase& db);

    bool addPerson(QString name, QString address, QString phone);
    bool removePerson(int id);
    bool changePerson(int id, QString name, QString address, QString phone);
};

class GetDatabase{
    QSqlDatabase& m_db;
public:
    GetDatabase(QSqlDatabase& db);
    bool getData(QList<Person>& people);
    int getLastId(); // добавить элемент в бд, посмотреть у него id и доваить в список
};

class Database
{
    QSqlDatabase m_db;

    bool createTable();
public:
    QSqlDatabase& getDatabase();
    Database();
    ~Database();
};

#endif // DATABASE_H
