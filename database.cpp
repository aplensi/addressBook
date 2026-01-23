#include "database.h"

bool Database::createTable()
{
    QSqlQuery query("CREATE TABLE IF NOT EXISTS book("
                    " id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    " name TEXT,"
                    " address TEXT,"
                    " phone TEXT);");
    if (!query.exec()) {
        qDebug() << "Create table error:" << query.lastError().text();
    }
}

QSqlDatabase &Database::getDatabase()
{
    return m_db;
}

Database::Database()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("database.sqlite");
    if(!m_db.open()){
        qDebug()<< m_db.lastError().text();
        return;
    }
    createTable();
}

Database::~Database()
{
    m_db.close();
}

SetDatabase::SetDatabase(QSqlDatabase& db) : m_db(db){}

bool SetDatabase::addPerson(QString name, QString address, QString phone)
{
    QSqlQuery query;
    query.prepare("INSERT INTO book (name, address, phone)"
                  " VALUES (?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(address);
    query.addBindValue(phone);
    if (!query.exec()) {
        qDebug() << "Set person error:" << query.lastError().text();
        return 0;
    }else return 1;
}

bool SetDatabase::removePerson(int id)
{
    QSqlQuery query("DELETE FROM book"
                    " WHERE id = ?");
    query.bindValue(0, id);
    if (!query.exec()) {
        qDebug() << "Delete error:" << query.lastError().text();
        return 0;
    }else return 1;
}

bool SetDatabase::changePerson(int id, QString name, QString address, QString phone)
{
    QSqlQuery query;
    query.prepare("UPDATE book"
                  " SET name = ?, address = ?, phone = ?"
                  " WHERE id = ?");
    query.addBindValue(name);
    query.addBindValue(address);
    query.addBindValue(phone);
    query.addBindValue(id);
    if (!query.exec()) {
        qDebug() << "Change error:" << query.lastError().text();
        return 0;
    }else return 1;
}

GetDatabase::GetDatabase(QSqlDatabase &db): m_db(db){}

bool GetDatabase::getData(QList<Person>& people)
{
    QSqlQuery query("SELECT * FROM book");
    while(query.next()){
        people.append(Person(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString()));
    }
    return 1;
}

int GetDatabase::getLastId()
{
    QSqlQuery query("SELECT * FROM book"
                    " ORDER BY id DESC"
                    " LIMIT 1;");
    if (query.next()) {
        return query.value(0).toInt();
    }
    qDebug() << "Last id error";
    return 0;
}
