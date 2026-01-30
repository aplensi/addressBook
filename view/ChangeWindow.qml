import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

Window {
    id: changeWindow
    visible: false
    width: 350
    height: 100

    property string titleText: ""
    property int idRow: 0
    property string nameRow: ""
    property string addressRow: ""
    property string phoneRow: ""
    property bool changeFunction: false

    signal saveButtonClicked(int idRowS, string nameRowS, string addressRowS, string phoneRowS)

    RowLayout{
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: 10
        ColumnLayout{
            spacing: 5
            Text{ text: "Ф.И.О"; Layout.alignment: Qt.AlignRight}
            Text{ text: "Адрес"; Layout.alignment: Qt.AlignRight}
            Text{ text: "Телефон"; Layout.alignment: Qt.AlignRight}
        }

        ColumnLayout{
            spacing: 5
            TextField{
                id: nameField
                text: nameRow
                Layout.fillWidth: true
            }
            TextField{
                id: addressField
                text: addressRow
                Layout.fillWidth: true
            }
            TextField{
                id: phoneField
                text: phoneRow
                Layout.fillWidth: true
            }
        }
        ColumnLayout{
            spacing: 5

            Button{
                text: "Сохранить"
                onClicked: {
                    changeWindow.saveButtonClicked(idRow, nameField.text, addressField.text, phoneField.text)
                    changeWindow.visible = false
                }
            }
            Button{
                text: "Отмена"
                onClicked: {
                    changeWindow.visible = false
                }
            }
        }
    }
}

