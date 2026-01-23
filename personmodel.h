#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractListModel>

class person{
    int m_id;
    QString m_name;
    QString m_address;
    QString m_phone;
public:
    person(const int& id, const QString& name, const QString& address, const QString& phone);
    int id() const;
    QString name() const;
    QString address() const;
    QString phone() const;
};

class personModel : public QAbstractListModel
{
    Q_OBJECT
    QList<person> people;

protected:
    QHash<int, QByteArray> roleNames() const;

public:
    enum personRole{
        idRole = Qt::UserRole + 1,
        nameRole,
        addressRole,
        phoneRole
    };

    personModel(QObject* parent = 0);
    void addPerson(const person& pers);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // PERSONMODEL_H
