#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractListModel>
#include <person.h>

class PersonModel : public QAbstractListModel
{
    Q_OBJECT
    QList<Person> m_people;

    void updateList();

protected:
    QHash<int, QByteArray> roleNames() const;

public:
    enum personRole{
        idRole = Qt::UserRole + 1,
        nameRole,
        addressRole,
        phoneRole
    };

    PersonModel(QObject* parent = nullptr);
    void addPerson(const Person& pers);
    void setPeople(QList<Person>& people);
    QList<Person>& getPersonList();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void sort(int column);
    void change(int id, QString name, QString address, QString phone);
    Q_INVOKABLE QVariantMap get(int index) const;
};

#endif // PERSONMODEL_H
