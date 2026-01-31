#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractListModel>
#include <models/person.h>

class PersonModel : public QAbstractListModel
{
    Q_OBJECT
    QList<Person> m_persons;

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
    void setPeople(QList<Person> persons);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void change(int id, QString name, QString address, QString phone);
    void remove(int id);
    Q_INVOKABLE QVariantMap get(int index) const;
};

#endif // PERSONMODEL_H
