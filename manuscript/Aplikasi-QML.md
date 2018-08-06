Aplikasi QML
===========

QML adalah bahasa deklaratif dalam Qt Quick yang didesign untuk mendeskripsikan interface dari sebuah program. QML mendeskripsikan bagaimana interface tersebut akan tampak sekaligus behaviornya. Qt Quick memungkinkan desainer untuk membuat interface dengan program favoritnya kemudian diimpor ke Qt secara mudah.

Sintaks Dasar
-----------------

Berikut ini adalah salah satu contoh kode sederhana dari dasar QML.

```qml
Import Qt Quick 1.0
Rectangle {
    Width : 200
    Height : 200
    Color : “blue”

Image {
    source: “pics/logo.png”
    anchors.centerIn: parent
    }
}
```
Dalam kode diatas, kita telah membuat dua buah objek, yaitu rectangle dan image. Objek Image memiliki sebuah property yang kemudian diberi nama source. Property tersebut diberi masukkan “pics/logo.png”. property dan nilainya dapat dipisahkan dengan sebuah tanda titik dua . property juga dapat dispesifikasikan secara perbaris atau dalam satu baris.

```css
Rectangle {
Width : 200
Height : 200
}
```

Saat property dispesifikasikan dalam satu baris maka harus dipisahkan dengan tanda titik koma.

```css
Rectangle {
Width : 200;Height : 200
}
```

Pernyataan “import” menyatakan bahwa kode program yang dibawahnya akan menggunakan modul QtQuick yang mengandung semua elemen dasar QML.tanpa pernyataan “import” tersebut, elemen “Retangle” dan “Image” tidak dapat digunakan.

Object Identifier
-------------------

Setiap objek dapat diberikan nilai ID khusus yang memungkinkan objek tersebut teridentifikasi dan dipanggil oleh objek yang lain. Kode program berikut menunjukkan dua objek teks. Nilai dari objek yang pertama memiliki sebuah ID “text1”. Sedangkan objek text yang kedua dapat diset nilai propertinya agar sama dengan objek yang pertama dengan memberikan referensi ke “text1.text”.

```css
Import QtQuick 1.0
Row {
Text {
id : text1
text :”Hello World”
}
Text {text.text: text1.text}
}
```

Sebuah objek dapat direfer oleh ID yang dimilki dari apapun komponen yang dideklarasikan. Namun, nilainya harus unik dari setiap komponen tunggal.

Nilai ID dalam objek QML tidak dapat diasumsikan sebagai property objek biasa. Sebagai contoh, bahwa sangat tidak mungkin untuk melakukan akses terhadap”text1.id”. dalam contoh diatas. Setelah objek diinstansiasi, maka ID dari objek tersebut tidak dapat diubah. Nilai ID dalam QML sirekomendasikan dalam character yang” lowercase” atau “underscore” dan tidak boleh mengandung selain angka, huruf, dan underscore.

Ekspresi Java Script
--------------------

Ekspresi java script berikut dapat dimasukkan dalam referensi ke objek dan property lain. Dalam beberapa kasus sebuah “data binding” akan terjadi saat nilai dari sebuah ekspresi berubah. Property dari ekspresi yang dimasukkan akan berubah secara otomatis. Contohnya adalah sebagai berikut.

```css
Item {
width: 300
height: 300
Rectangle {
width: parent.width – 50
height: 100
color : “yellow”
}
}
```

Objek rectangle dengan property yang diset relative terhadap lebar “parent”. Saat lebar dari “parent” berubah , nilai lebar dari “Rectangle” juga otomatis juga berubah sesuai dengan nilai lebar dari “parent”.

Signal Handler
----------------

Signal handler menunjukkan kode java script untuk dieksekusi dalam rangka merespon terhadap suatu kejadian(event). Sebagai contoh, saat elemen dari “MouseArea” mendapatkan klik, maka sebuah “handler” dari onCliked dapat digunakan untuk memberikanrespon dari sebuah klik. Berikut adalah sebuah contoh dari cara pengunaan “handler” untuk menampilkan sebuah pesan kelayar saat mouse di klik.

```css
Item {
width: 100; height: 100
MouseArea {
anchors.fill: parent
onClicked: {
console.log(“mouse button clicked”);
}
}
}
```

Properti
---------

Saat property mengalami pergantian nilai, property tersebut akan mengirimkan signal secara otomatis mengenai perubahan tersebut.

Cara menggunakan signal cukup mudah hanya dengan membuat sebuah signal handler yang diberi nama sintaks onChanged. Sebagai contoh elemen rectangle memiliki property lebar dan warna. Berikut adalah contoh untuk kita mendefinisikan duasignal handler untuk project rectangle, yaitu onWidthChanged dan onColorChanged yang akan secara otomatis berubah saat perubahan terhadap kedua property tersebut dieksekusi.

```css
Rectangle {
Width: 100; height: 100
onWidthChanged: console.log(“width has change to: “,width)
onColorChanged: console.log(“color has change to: “,color)
}
```

Kesimpulan
--------------

User Inteface Designer akan sangat menyukainya karena interface dibuat denga metode drag and drop. Designer dapat membuat interface dengan Flowella atau photoshop dan kemudian diimport secara langsung ke Qt Qreator secara langsung. Qt Quick akan langsung mentransformasikan file PSD dari designer ke QML.
