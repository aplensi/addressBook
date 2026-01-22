import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    width: 420
    height: 240
    visible: true
    title: "Address Book"

    ListView {
        id: list
        anchors.fill: parent
        model: person
        clip: true
        focus: true

        delegate: Rectangle {
            width: list.width
            height: 40
            color: ListView.isCurrentItem ? "#b0c4de" : "transparent"
            border.color: "#cccccc"

            Row {
                anchors.fill: parent
                anchors.margins: 6
                spacing: 10

                Text {
                    width: list.width / 3
                    text: model.name
                    elide: Text.ElideRight
                }

                Text {
                    width: list.width / 3
                    text: model.address
                    elide: Text.ElideRight
                }

                Text {
                    width: list.width / 3
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
