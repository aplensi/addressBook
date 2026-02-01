import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.0
import QtQuick.Dialogs

Window {
    id: mainW
    height: 240
    width: 600
    visible: true
    title: "Книга адресов"
    property int idRow: 0
    property string nameRow: ""
    property string addressRow: ""
    property string phoneRow: ""

    RowLayout{
        anchors.fill: parent
        spacing: 10
        ColumnLayout{
            Layout.fillHeight: true
            Layout.fillWidth: true
            Rectangle{
                id: header
                height: 20
                width: parent.width
                color: "#eeeeee"
                Row {
                    anchors.fill: parent

                    Text {
                        width: list.width / 4
                        text: "<b>Id:</b>"
                        elide: Text.ElideRight
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: person.sortByColumn(0)
                        }
                    }
                    Text {
                        width: list.width / 4
                        text: "<b>Ф.И.О:</b>"
                        elide: Text.ElideRight
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: person.sortByColumn(1)
                        }
                    }

                    Text {
                        width: list.width / 4
                        text: "<b>Адрес:</b>"
                        elide: Text.ElideRight
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: person.sortByColumn(2)
                        }
                    }

                    Text {
                        width: list.width / 4
                        text: "<b>Телефон:</b>"
                        elide: Text.ElideRight
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: person.sortByColumn(3)
                        }
                    }
                }
            }
            ListView {
                id: list
                Layout.fillHeight: true
                Layout.fillWidth: true
                model: person
                focus: true

                delegate: Rectangle {
                    width: list.width
                    height: 40
                    color: ListView.isCurrentItem ? "#b0c4de" : "transparent"

                    Rectangle{
                        width: parent.width
                        height: 1
                        color: "#cccccc"
                        anchors.bottom: parent.bottom
                    }

                    Row {
                        anchors.fill: parent
                        Text {
                            id: listId
                            width: list.width / 4
                            text: model.id
                            elide: Text.ElideRight
                        }
                        Text {
                            id: listName
                            width: list.width / 4
                            text: model.name
                            elide: Text.ElideRight
                        }

                        Text {
                            id: listAddress
                            width: list.width / 4
                            text: model.address
                            elide: Text.ElideRight
                        }

                        Text {
                            id: listPhone
                            width: list.width / 4
                            text: model.phone
                            elide: Text.ElideRight
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            list.currentIndex = index
                            idRow = listId.text
                            nameRow = listName.text
                            addressRow = listAddress.text
                            phoneRow = listPhone.text
                        }
                    }
                }
                currentIndex: -1
            }
        }
        ColumnLayout{
            Layout.preferredWidth: 120
            spacing: 5

            Button {
                text: "Удалить"
                onClicked: {
                    Controller.deleteButton(idRow)
                    list.currentIndex = -1
                }
            }
            Button {
                text: "Добавить"
                onClicked: {
                    addWindow.visible = true
                    addWindow.title = "Добавить запись"
                    addWindow.nameRow = ""
                    addWindow.addressRow = ""
                    addWindow.phoneRow = ""
                }
            }
            Button {
                text: "Изменить"
                onClicked:{
                    changeWindow.visible = true
                    changeWindow.title = "Редактировать запись"
                    changeWindow.nameRow = ""
                    changeWindow.addressRow = "" // я не знаю почему, но без обнуления иногда могут отобразиться данные прошлой измененнйо записи
                    changeWindow.phoneRow = ""
                    changeWindow.idRow = idRow
                    changeWindow.nameRow = nameRow
                    changeWindow.addressRow = addressRow
                    changeWindow.phoneRow = phoneRow
                }
            }
        }
    }

    ChangeWindow {
        id: changeWindow

        onSaveButtonClicked: {
            Controller.changeButton(idRowS, nameRowS, addressRowS, phoneRowS)
        }
    }
    ChangeWindow {
        id: addWindow

        onSaveButtonClicked: {
            Controller.addButton(nameRowS, addressRowS, phoneRowS)
        }
    }
}
