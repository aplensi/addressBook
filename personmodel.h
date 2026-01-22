#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractListModel>

class person{
    QString m_name;
    QString m_address;
    QString m_phone;
public:
    person(const QString& name, const QString& address, const QString& phone);
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
        nameRole = Qt::UserRole + 1,
        addressRole,
        phoneRole
    };

    personModel(QObject* parent = 0);
    void addPerson(const person& pers);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // PERSONMODEL_H
