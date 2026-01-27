#ifndef DATABASE_H
#define DATABASE_H

#include "qsqldatabase.h"
#include <models/person.h>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSql>

class IPersonsSource{
public:
    virtual ~IPersonsSource() = default;
    virtual Person add(const QString& name, const QString& address, const QString& phone) = 0;
    virtual bool remove(int id) = 0;
    virtual bool change(int id, const QString& name, const QString& address, const QString& phone) = 0;
};

class IPersonsSink{
public:
    virtual ~IPersonsSink() = default;
    virtual QList<Person> getData() = 0;
};

class Database : public IPersonsSink, public IPersonsSource{
    QSqlDatabase m_db;

    bool createTable();
    int getLastId();
public:
    Database();
    ~Database();

public:
    Person add(const QString& name, const QString& address, const QString& phone) override;
    bool remove(int id) override;
    bool change(int id, const QString &name, const QString &address, const QString &phone) override;
    QList<Person> getData() override;
};

#endif // DATABASE_H
