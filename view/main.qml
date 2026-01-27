import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    height: 240
    width: 600
    visible: true
    title: "Книга адресов"

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
                            onClicked: Controller.sortColumn(0)
                        }
                    }
                    Text {
                        width: list.width / 4
                        text: "<b>Ф.И.О:</b>"
                        elide: Text.ElideRight
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: Controller.sortColumn(1)
                        }
                    }

                    Text {
                        width: list.width / 4
                        text: "<b>Адрес:</b>"
                        elide: Text.ElideRight
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: Controller.sortColumn(2)
                        }
                    }

                    Text {
                        width: list.width / 4
                        text: "<b>Телефон:</b>"
                        elide: Text.ElideRight
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: Controller.sortColumn(3)
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
                        onClicked: list.currentIndex = index
                    }
                }
            }
        }
        ColumnLayout{
            Layout.preferredWidth: 120
            spacing: 5
            anchors.verticalCenter: parent.verticalCenter

            Button {
                text: "Удалить"
                onClicked: Controller.deleteButton(list.currentIndex)
            }
            Button {
                text: "Добавить"
                onClicked: addWindow.visible = true
            }
            Button {
            text: "Изменить"
            onClicked:{
            changeWindow.currentIndex = list.currentIndex
            changeWindow.personModel = person
            changeWindow.visible = true
            }
            }
        }
    }

    AddWindow{
        id: addWindow
    }
    ChangeWindow{
        id: changeWindow
    }
}
