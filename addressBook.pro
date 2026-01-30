QT       += core gui sql qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cpp \
    database/database.cpp \
    main.cpp \
    models/person.cpp \
    models/personmodel.cpp \
    models/proxymodel.cpp

HEADERS += \
    controller/controller.h \
    database/database.h \
    models/person.h \
    models/personmodel.h \
    models/proxymodel.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
