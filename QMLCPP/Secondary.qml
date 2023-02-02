import QtQuick 2.15
import QtQuick.Controls

Rectangle {
    width: _aSize.width;
    height: _aSize.height;

    color: _background

    Component.onCompleted: {
        console.log("Size: ", _aSize);
    }


}
