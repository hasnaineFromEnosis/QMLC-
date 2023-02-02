import QtQuick 2.15
import QtQuick.Controls

Rectangle {
    width: _aSize.width;
    height: _aSize.height;

    color: _background

    Text {
        id: text
        text: "Press me!"
        anchors.centerIn: parent

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.log("Global Lookup: ", _santa)

                var santa = _db.lookup("Fake Santa")
                console.log("Fake santa lookup: ", santa)

                _db.addPerson(_db.makePerson("Hasnaine", 25))
                var has9 = _db.lookup("Hasnaine")
                console.log("Db hasnaine lookup: ", has9)

                has9.age = 33

                console.log("Updating: ", has9)

                has9 = _db.lookup("Hasnaine")
                console.log("DB is unchanged still: ", has9)
            }
        }
    }


}
