#include "person.h"

Person::Person(const int& id, const QString& name, const QString& address, const QString& phone) : m_id(id), m_name(name), m_address(address), m_phone(phone) {}

int Person::id() const
{
    return m_id;
}

QString Person::name() const
{
    return m_name;
}

QString Person::address() const
{
    return m_address;
}

QString Person::phone() const
{
    return m_phone;
}

void Person::setName(QString name)
{
    m_name = name;
}

void Person::setAddress(QString address)
{
    m_address = address;
}

void Person::setPhone(QString phone)
{
    m_phone = phone;
}
