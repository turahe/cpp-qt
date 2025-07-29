**📋 Apa yang akan dipelajari**

Pada bab ini kita akan mempelajari tentang bekerja dengan file, stream, dan XML dalam Qt:

- Bekerja dengan direktori dan path menggunakan QDir
- Membaca dan menulis file dengan QFile
- Text stream dan data stream
- XML dan cara memanipulasinya
- DOM dan QXMLStreamReader

\minitoc

## 📁 Bekerja dengan Direktori dan Path

### Apa itu QDir?

QDir adalah class Qt untuk bekerja dengan direktori dan path. Class ini menyediakan berbagai method untuk:

- **Navigasi direktori** - Pindah antar folder
- **Informasi file** - Mendapatkan informasi file dan folder
- **Filtering** - Menampilkan file/folder tertentu
- **Path manipulation** - Mengelola path dengan mudah

### Static Methods QDir

QDir menyediakan beberapa static method yang berguna:

- **QDir::current()** - Mendapatkan direktori kerja saat ini
- **QDir::home()** - Mendapatkan direktori home user
- **QDir::root()** - Mendapatkan root direktori
- **QDir::drives()** - Mendapatkan daftar semua drive

### QFileInfo - Informasi File

QFileInfo menyimpan informasi detail tentang file dan direktori:

- **isDir()** - Cek apakah berupa direktori
- **isFile()** - Cek apakah berupa file
- **isSymLink()** - Cek apakah berupa symbolic link
- **exists()** - Cek apakah file/direktori ada
- **isHidden()** - Cek apakah file tersembunyi
- **isReadable()** - Cek apakah file bisa dibaca
- **isWritable()** - Cek apakah file bisa ditulis
- **fileName()** - Mendapatkan nama file tanpa path
- **filePath()** - Mendapatkan nama file dengan path relatif
- **absoluteFilePath()** - Mendapatkan path absolut
- **completeBaseName()** - Mendapatkan nama file tanpa ekstensi
- **completeSuffix()** - Mendapatkan ekstensi file

### Contoh: Menampilkan Daftar Drive

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menampilkan daftar drives dari root directories, label=contoh12-1]{../code/contoh12-1.cpp}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
Drive :  "C:/"
  "MATLAB"
  "PerfLogs"
  "Program Files"
  "Program Files (x86)"
  "Qt"
  "system.sav"
  "Users"
  "Windows"
Drive :  "D:/"
  "Music"
  "My Web Sites"
  "Photo"
  "Portable"
  "Referensi"
  "Software"
  "video"
  "webs"
\end{lcverbatim}

**Analisis Program:**

- **QDir::drives()** - Mendapatkan semua drive yang ada
- **foreach** - Loop untuk mengakses setiap drive
- **setFilter(QDir::Dirs)** - Hanya tampilkan direktori
- **entryList()** - Mendapatkan daftar file/direktori

### Filter Options QDir

<div align="center">
| \hline
**Filter** | **Deskripsi** |
|---|---|
| \hline
QDir::Dirs | Hanya direktori |
| \hline
QDir::Files | Hanya file |
| \hline
QDir::Drives | Hanya drive |
| \hline
QDir::AllEntries | Semua (file, direktori, drive) |
| \hline
QDir::NoSymLinks | Tidak termasuk symbolic links |
| \hline
QDir::NoDotAndDotDot | Tidak termasuk . dan .. |
| \hline
QDir::Readable | File yang bisa dibaca |
| \hline
QDir::Writable | File yang bisa ditulis |
| \hline
QDir::Executable | File yang bisa dieksekusi |
| \hline
QDir::Hidden | File tersembunyi |
| \hline
QDir::System | File sistem |
| \hline |
</div>

## 📄 Bekerja dengan File

### Apa itu QFile?

QFile adalah class Qt untuk bekerja dengan file. Class ini menyediakan:

- **File operations** - Buka, tutup, baca, tulis file
- **File information** - Ukuran, tanggal modifikasi, dll
- **Error handling** - Penanganan error yang baik
- **Cross-platform** - Sama di semua platform

### File Permissions

QFile mendukung berbagai permission:

- **QIODevice::ReadOnly** - Hanya baca
- **QIODevice::WriteOnly** - Hanya tulis
- **QIODevice::ReadWrite** - Baca dan tulis
- **QIODevice::Append** - Tambah di akhir file
- **QIODevice::Truncate** - Hapus isi file
- **QIODevice::Text** - Mode teks (untuk Windows)

### Contoh: Memeriksa File

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Memeriksa apakah file ada dan bisa diakses, label=contoh12-2]{../code/contoh12-2.cpp}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
File :  "testfile.txt"  tidak ditemukan
\end{lcverbatim}

- Buat file "testfile.txt" di folder build, lalu jalankan lagi:

\begin{lcverbatim}
File berhasil dibuka !
\end{lcverbatim}

**Analisis Program:**

- **exists()** - Cek apakah file ada
- **open()** - Buka file dengan permission tertentu
- **Error handling** - Tangani error jika file tidak bisa dibuka

## 🌊 Stream - Membaca dan Menulis File

### Apa itu Stream?

Stream adalah cara untuk membaca dan menulis data secara berurutan. Qt menyediakan dua jenis stream:

- **QTextStream** - Untuk file teks
- **QDataStream** - Untuk file biner

### Keunggulan Stream

- **Operator overloading** - Gunakan << dan >> untuk I/O
- **Type safety** - Mencegah kesalahan tipe data
- **Error handling** - Penanganan error yang baik
- **Cross-platform** - Sama di semua platform

### Text Stream - File Teks

QTextStream digunakan untuk membaca dan menulis file teks.

#### Membaca File Teks

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan Stream untuk membaca file, label=contoh12-3]{../code/contoh12-3.cpp}

- Buat file teks "sample.txt" dengan isi "Buku Pemrograman C++"
- Jalankan program dan perhatikan output:

\begin{lcverbatim}
Buku Pemrograman C++
\end{lcverbatim}

**Method QTextStream:**

- **readAll()** - Baca semua isi file
- **readLine()** - Baca satu baris
- **atEnd()** - Cek apakah sudah di akhir file
- **operator>>()** - Baca data dengan tipe tertentu
- **operator<<()** - Tulis data ke stream

### Data Stream - File Biner

QDataStream digunakan untuk membaca dan menulis file biner. File biner lebih efisien untuk data yang kompleks.

#### Menggunakan Data Stream

- Buka Qt Creator dan buat project Qt Console Application baru
- Tambahkan library GUI di file .pro:

\lstinputlisting[language=c++, caption=File pro untuk membuka library Qt GUI]{../code/12-file-stream-xml-file-pro-untuk-membuka-library-qt-gui.c++}

- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan Data Stream, label=contoh12-4]{../code/12-file-stream-xml-contoh12-4.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
content
\end{lcverbatim}

**Analisis Program:**

- **Struct Warna** - User-defined type untuk menyimpan data
- **Operator <<** - Untuk menulis data ke stream
- **Operator >>** - Untuk membaca data dari stream
- **QDataStream** - Untuk file biner

## 📋 XML - Extensible Markup Language

### Apa itu XML?

XML (Extensible Markup Language) adalah bahasa markup untuk menyimpan data terstruktur. XML memiliki:

- **Tag** - Elemen yang membungkus data
- **Attribute** - Properti dari elemen
- **Text** - Data yang disimpan
- **Hierarchical** - Struktur parent-child

### Struktur XML

```cpp{../code/12-file-stream-xml-code-3.xml}
```

**Analisis XML:**

- **<document>** - Root element
- **name="example"** - Attribute
- **<author>** - Child element
- **Text content** - Data dalam elemen

### Qt XML Support

Qt mendukung tiga cara untuk bekerja dengan XML:

- **DOM** - Document Object Model (tree-based)
- **SAX** - Simple API for XML (event-based)
- **QXMLStreamReader/Writer** - Stream-based (modern)

### Menambahkan Library XML

Untuk menggunakan XML di Qt, tambahkan di file .pro:

```cpp
#-------------------------------------------------
#
# Project created by QtCreator 2016-01-03T21:43:04
#
#-------------------------------------------------
QT += core
QT -= gui
QT += xml
TARGET = Contoh 5
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp
```

## 🌳 DOM - Document Object Model

### Apa itu DOM?

DOM adalah cara untuk merepresentasikan dokumen XML sebagai tree di memory. Setiap elemen XML menjadi node dalam tree.

### Keunggulan DOM

- **Tree structure** - Mudah navigasi
- **Random access** - Akses elemen secara langsung
- **Modification** - Mudah modifikasi dokumen
- **Complete document** - Seluruh dokumen di memory

### Kekurangan DOM

- **Memory usage** - Butuh memory besar untuk file besar
- **Performance** - Lambat untuk file besar
- **Complexity** - Lebih kompleks untuk operasi sederhana

### Membuat File XML dengan DOM

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Membuat Nodes untuk membuat simple XML Document, label=contoh12-5]{../code/12-file-stream-xml-contoh12-5.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
content
\end{lcverbatim}

Hasil file XML "simple.xml":

```cpp{../code/12-file-stream-xml-code-6.xml}
```

**Analisis Program:**

- **QDomDocument** - Container untuk dokumen XML
- **QDomElement** - Membuat elemen XML
- **QDomText** - Menambah teks ke elemen
- **appendChild()** - Menghubungkan elemen
- **QTextStream** - Menulis ke file

### Membaca File XML dengan DOM

- Buka Qt Creator dan buat project Qt Console Application baru
- Copy file "simple.xml" ke folder build
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Contoh Membaca DOM dari dokumen XML, label=contoh12-6]{../code/12-file-stream-xml-contoh12-6.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
content
\end{lcverbatim}

**Analisis Program:**

- **setContent()** - Load XML ke QDomDocument
- **documentElement()** - Ambil root element
- **firstChild()** - Ambil child pertama
- **nextSibling()** - Pindah ke sibling berikutnya
- **tagName()** - Ambil nama tag
- **attribute()** - Ambil nilai attribute

### Memodifikasi File XML dengan DOM

- Buka Qt Creator dan buat project Qt Console Application baru
- Buat file "simple.xml" dengan isi:

```cpp{../code/12-file-stream-xml-code-8.xml}
```

- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Main program Modifikasi data dokumen XML, label=contoh12-7]{../code/12-file-stream-xml-contoh12-7.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
content
\end{lcverbatim}

Hasil modifikasi file "simplemodif.xml":

```cpp{../code/12-file-stream-xml-code-10.xml}
```

**Analisis Program:**

- **elementsByTagName()** - Cari elemen berdasarkan tag
- **createElement()** - Buat elemen baru
- **createTextNode()** - Buat node teks
- **appendChild()** - Tambah elemen ke parent

## ⚡ QXMLStreamReader - Stream-based XML

### Apa itu QXMLStreamReader?

QXMLStreamReader adalah parser XML yang bekerja secara incremental. Parser ini:

- **Fast** - Lebih cepat dari DOM
- **Memory efficient** - Tidak load seluruh dokumen
- **Stream-based** - Baca token per token
- **Simple** - API yang sederhana

### Token Types

<div align="center">
| \hline
**Token Type** | **Contoh** | **Getter Functions** |
|---|---|---|
| \hline
StartDocument | N/A | isStandaloneDocument() |
| \hline
EndDocument | N/A | isStandaloneDocument() |
| \hline
StartElement | <item> | namespaceUri(), name(), attributes() |
| \hline
EndElement | </item> | namespaceUri(), name() |
| \hline
Characters | AT\ | T | text(), isWhitespace() |
| \hline
Comment | <!-- fix --> | text() |
| \hline
DTD | <!DOCTYPE ...> | text() |
| \hline
EntityReference | \ | trade; | name(), text() |
| \hline
ProcessingInstruction | <?alert?> | processingInstructionTarget() |
| \hline
Invalid | >\ | <! | error(), errorString() |
| \hline |
</div>

### Contoh XML untuk Parsing

```cpp{../code/12-file-stream-xml-code-11.xml}
```

Cara membaca token per token:

```cpp
StartDocument
StartElement (name() == "doc")
StartElement (name() == "quote")
Characters (text() == "Einmal ist keinmal")
EndElement (name() == "quote")
EndElement (name() == "doc")
EndDocument
```

### Membaca XML dengan QXMLStreamReader

- Buka Qt Creator dan buat project Qt Console Application baru
- Buat file "simple.xml":

```cpp{../code/12-file-stream-xml-code-13.xml}
```

- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan QXMLStream Reader untuk membaca XML, label=contoh12-8]{../code/12-file-stream-xml-contoh12-8.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
content
\end{lcverbatim}

**Analisis Program:**

- **atEnd()** - Cek apakah sudah di akhir dokumen
- **readNext()** - Baca token berikutnya
- **isStartElement()** - Cek apakah start element
- **name()** - Ambil nama elemen
- **text()** - Ambil teks dalam elemen

### Membuat XML dengan QXMLStreamWriter

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Membuat dokumen XML dengan QXMLStreamWriter, label=contoh12-9]{../code/12-file-stream-xml-contoh12-9.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
File sudah berhasil di buat !
\end{lcverbatim}

Hasil file XML "simple.xml":

```cpp{../code/12-file-stream-xml-code-16.xml}
```

**Analisis Program:**

- **setAutoFormatting()** - Format XML otomatis
- **writeStartDocument()** - Mulai dokumen XML
- **writeStartElement()** - Tulis start element
- **writeAttribute()** - Tulis attribute
- **writeEndElement()** - Tulis end element
- **writeEndDocument()** - Akhiri dokumen XML

## 🔧 Best Practices File dan XML

### Tips Menggunakan File I/O

- **Gunakan QFile** - Jangan campur dengan std::fstream
- **Error handling** - Selalu cek error setelah operasi file
- **Resource management** - Tutup file setelah selesai
- **Path handling** - Gunakan QDir untuk path yang aman
- **Cross-platform** - Perhatikan perbedaan platform

### Tips Menggunakan XML

- **Pilih parser yang tepat** - DOM untuk file kecil, Stream untuk file besar
- **Memory management** - Perhatikan penggunaan memory
- **Error handling** - Tangani error parsing
- **Validation** - Validasi XML sebelum parsing
- **Encoding** - Perhatikan encoding XML

### Kesalahan Umum

- **Lupa close file** - File tidak ditutup setelah selesai
- **Wrong permission** - Permission tidak sesuai kebutuhan
- **Path issues** - Path tidak valid atau tidak ada
- **Memory leak** - DOM tidak dihapus untuk file besar
- **Encoding issues** - Encoding XML tidak sesuai

## 📚 Referensi dan Bacaan Lanjutan

File I/O dan XML adalah topik yang luas dan terus berkembang. Untuk pemahaman yang lebih mendalam, pembaca dapat merujuk pada:

- **Qt Documentation** - Dokumentasi resmi Qt[^1]: Qt Company. (2023). "Qt Core Module". https://doc.qt.io/qt-6/qtcore-index.html
- **XML Tutorial** - Tutorial XML dari W3Schools[^1]: W3Schools. (2023). "XML Tutorial". https://www.w3schools.com/xml/
- **Qt File I/O** - Dokumentasi file I/O Qt[^1]: Qt Company. (2023). "QFile Class". https://doc.qt.io/qt-6/qfile.html
- **Qt XML** - Dokumentasi XML Qt[^1]: Qt Company. (2023). "Qt XML Module". https://doc.qt.io/qt-6/qtxml-index.html

## 🎉 Kesimpulan

File I/O dan XML adalah komponen penting dalam pengembangan aplikasi. Dengan memahami QDir, QFile, stream, dan XML parsing, Anda dapat membuat aplikasi yang dapat bekerja dengan berbagai jenis data dan format.

<div align="center">
**Selamat! Anda telah menguasai dasar-dasar File I/O dan XML** 📄
</div>




<div align="center">
*--- Bab selanjutnya: Qt WebKit ---*
</div>
