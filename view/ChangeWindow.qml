import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

Window {
    id: changeWindow
    visible: false
    width: 350
    height: 100
    title: "Редактировать запись"
    property int currentIndex: -1
    property var personModel: null


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
                text: currentIndex >= 0 && personModel ? personModel.get(currentIndex).name : ""
                Layout.fillWidth: true
                onTextChanged: if (currentIndex >= 0 && personModel) personModel.get(currentIndex).name = text
            }
            TextField{
                id: addressField
                text: currentIndex >= 0 && personModel ? personModel.get(currentIndex).address : ""
                Layout.fillWidth: true
                onTextChanged: if (currentIndex >= 0 && personModel) personModel.get(currentIndex).address = text
            }
            TextField{
                id: phoneField
                text: currentIndex >= 0 && personModel ? personModel.get(currentIndex).phone : ""
                Layout.fillWidth: true
                onTextChanged: if (currentIndex >= 0 && personModel) personModel.get(currentIndex).phone = text
            }
        }
        ColumnLayout{
            spacing: 5
            Button{
                text: "Сохранить"
                onClicked: {
                    Controller.changeButton(personModel.get(currentIndex).id, nameField.text, addressField.text, phoneField.text)
                    changeWindow.visible = false
                }
            }
            Button{
                text: "Отмена"
                onClicked: {
                    changeWindow.visible = false
                    nameField.text = ""
                    addressField.text = ""
                    phoneField.text = ""
                }
            }
        }
    }
}

