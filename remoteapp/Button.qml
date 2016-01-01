/**
 * Created my Misha Lytvynyuk, xchg.ca, @2015
 */

import QtQuick 2.0

Rectangle {

    property var btmanager;
    property int command:0
    property int stopCommand:4
    property string label: "value"

    id: root

    width: 300
    height: 200

    color: "blue"

    Text {
        text: qsTr(label)
        anchors.centerIn: parent
    }

    MouseArea {

        anchors.fill: parent

//        onPressAndHold: {
//            console.error("PressedHold")
//            root.color = "red"
//        }

        onPressed: {
            console.error("Pressed")
            root.color = "red"
            btmanager.setCommand(command)
        }

        onReleased: {
            console.error("Released")
            root.color = "blue"
            btmanager.setCommand(stopCommand)
        }
    }
}
