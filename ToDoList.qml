import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import ToDo 1.0

Frame {
    ListView {
        implicitWidth: 250
        implicitHeight: 250
        clip: true

        // 存放属性枚举量
        model: ToDoModel {}

        // 设置展示model数据的格式
        delegate: RowLayout {
            width: parent.width

            CheckBox {
                checked: model.done
                onClicked: model.done = checked
            }
            TextField {
                text: model.description
                onEditingFinished: model.description = text
                Layout.fillWidth: true
            }
        }
    }
}
