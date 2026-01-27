#include <models/personmodel.h>
#include <controller/controller.h>
#include <database/database.h>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQmlApplicationEngine engine;

    Database db;
    PersonModel model;
    Controller controller(db, db, model);

    engine.rootContext()->setContextProperty("Controller", &controller);
    engine.rootContext()->setContextProperty("person", &model);

    engine.load(QUrl("qrc:/view/main.qml"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return a.exec();
}
