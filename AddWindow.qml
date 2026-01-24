import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id: addWindow
    width: 350
    height: 100
    title: "Добавиление записи"
    visible: false

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
            id: textColumn
            TextField{
                id: nameField
                Layout.fillWidth: true
            }
            TextField{
                id: addressField
                Layout.fillWidth: true
            }
            TextField{
                id: phoneField
                Layout.fillWidth: true
            }
        }
        ColumnLayout{
            spacing: 5
            Button{
                text: "Сохранить"
                onClicked: {
                    Controller.addButton(nameField.text, addressField.text, phoneField.text)
                    addWindow.visible = false
                }
            }
            Button{
                text: "Отмена"
                onClicked: {
                    addWindow.visible = false
                    nameField.text = ""
                    addressField.text = ""
                    phoneField.text = ""
                }
            }
        }
    }
}
