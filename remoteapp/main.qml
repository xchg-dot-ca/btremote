/**
 * Created my Misha Lytvynyuk, xchg.ca, @2015
 */

import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true

    MouseArea {
        anchors.fill: parent
        onClicked: {
            //Qt.quit();
        }
    }

    Button {
        id: upBt
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 100

        btmanager: _btManager
        command: 0
        stopCommand: 4;
        label: "UP"
    }
    Button {
        id: leftBt
        anchors.right: upBt.left
        anchors.top: upBt.bottom

        btmanager: _btManager
        command: 2
        stopCommand: 4;
        label: "LEFT"
    }
    Button {
        id: downBt
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: leftBt.bottom

        btmanager: _btManager
        command: 1
        stopCommand: 4;
        label: "DOWN"
    }
    Button {
        id: rightBt
        anchors.left: upBt.right
        anchors.top: upBt.bottom

        btmanager: _btManager
        command: 3
        stopCommand: 4;
        label: "RIGHT"
    }
    Button {

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom

        btmanager: _btManager
        command: 5
        stopCommand: 6;
        label: "TRIGGER"
    }
}
