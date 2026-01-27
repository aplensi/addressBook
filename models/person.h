#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person{
    int m_id;
    QString m_name;
    QString m_address;
    QString m_phone;
public:
    Person(const int& id, const QString& name, const QString& address, const QString& phone);
    int id() const;
    QString name() const;
    QString address() const;
    QString phone() const;
    void setName(QString name);
    void setAddress(QString address);
    void setPhone(QString phone);
};

#endif // PERSON_H
