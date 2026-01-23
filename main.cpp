#include "personmodel.h"
#include <controller.h>
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

    Controller controller(engine);

    return a.exec();
}
