#include "personmodel.h"
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

    personModel model;

    model.addPerson(person("qwe", "wer", "wer"));
    model.addPerson(person("кен", "кен", "апр"));
    model.addPerson(person("678", "456", "456"));

    engine.rootContext()->setContextProperty("person", QVariant::fromValue(&model));

    return a.exec();
}
