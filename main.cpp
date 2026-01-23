#include "personmodel.h"
#include <database.h>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(u"qrc:/main.qml"_qs));

    if (engine.rootObjects().isEmpty())
        return -1;

    PersonModel model;

    Database db;
    GetDatabase getDb(db.getDatabase());
    SetDatabase setDb(db.getDatabase());
    setDb.changePerson(11, "q", "w", "e");
    getDb.getData(model.getPersonList());
    model.updateList();

    engine.rootContext()->setContextProperty("person", QVariant::fromValue(&model));

    return a.exec();
}
