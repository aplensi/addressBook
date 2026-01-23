import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    minimumHeight: 240
    minimumWidth: 420
    visible: true
    title: "Address Book"

    Rectangle{
        id: header
        height: parent.width
        width: 300
        Rectangle{
            height: 20
            width: parent.width
            color: "#eeeeee"
            Row {
                anchors.fill: parent
                Text {
                    width: list.width / 4
                    text: "<b>Id:</b>"
                    elide: Text.ElideRight
                }
                Text {
                    width: list.width / 4
                    text: "<b>Name:</b>"
                    elide: Text.ElideRight
                }

                Text {
                    width: list.width / 4
                    text: "<b>Address:</b>"
                    elide: Text.ElideRight
                }

                Text {
                    width: list.width / 4
                    text: "<b>Phone:</b>"
                    elide: Text.ElideRight
                }
            }
        }

        ListView {
            id: list
            width: parent.width
            height: parent.height - 20
            anchors.bottom: header.bottom
            focus: true
            model: person

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
                        width: list.width / 4
                        text: model.id
                        elide: Text.ElideRight
                    }
                    Text {
                        width: list.width / 4
                        text: model.name
                        elide: Text.ElideRight
                    }

                    Text {
                        width: list.width / 4
                        text: model.address
                        elide: Text.ElideRight
                    }

                    Text {
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
}
