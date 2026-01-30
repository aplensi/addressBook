#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <database/database.h>
#include <models/person.h>
#include <models/personmodel.h>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class Controller : public QObject
{
    Q_OBJECT

    PersonModel& m_model;
    IPersonsSink& m_personSink;
    IPersonsSource& m_personSource;
public:
    Controller(IPersonsSink& personSink, IPersonsSource& personSource, PersonModel& model, QObject *parent = nullptr);
public slots:
    void sortColumn(int index);
    void deleteButton(int index, int id);
    void addButton(QString name, QString address, QString phone);
    void changeButton(int id, QString name, QString address, QString phone);
};

#endif // CONTROLLER_H
