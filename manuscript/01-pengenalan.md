# Mukadimah

## Pengenalan Bahasa C++

Bahasa C merupakan bahasa pemrograman tingkat menengah. Pada tahun 1972 bahasa C
pertama kali dirancang oleh [Dennis M Ritchie](https://id.wikipedia.org/wiki/Dennis_Ritchie) di Bell aboratories. Kemudian tahun 1978 Dennis dan [Brian W. Kernighan](https://id.wikipedia.org/wiki/Brian_Kernighan) empublikasikan bahasa C melalui [The C Programming Language](https://id.wikipedia.org/wiki/The_C_Programming_Language) sehingga bahasa C dikenal banyak orang. Selanjutnya pada tahun 1989, akhirnya bahasa C distandardisasi [ANSI](https://id.wikipedia.org/wiki/ANSI_C)(American National Standard Institute) sehingga bahasa C menjadi bahasa pemrograman standar hingga saat ini dan bisa dibuat kompilernya pada beberapa platform yang berbeda-beda.

Bahasa C dikatakan sebagai bahasa pemrograman terstruktur, fungsional karena strukturnya menggunakan fungsi-fungsi sebagai program-program bagian (subroutine/ module). Fungsifungsi selain fungsi utama disebut subroutine/ module dan ditulis setelah fungsi utama (main) atau diletakkan pada file pustaka (library). Jika fungsi-fungsi diletakkan pada file pustaka dan akan dipakai disuatu program, maka nama file header-nya harus dilibatkan dalam program menggunakan preprocessor directive `#include`.

Kemudian bahasa C dikembangkan oleh Bjarne Stroustrup at Bell Labs menjadi bahasa C++. Pada bulan Oktober 1985 munculah buku The C++ Programming Language yang membahas tentang bahasa pemrograman itu langsung dari penciptanya sendiri. Bahasa C++ mengalami dua tahap evolusi.

- Pertama, dirilis oleh [AT&T Laboratories](https://id.wikipedia.org/wiki/Bell_Laboratories), dinamakan [cfront](https://en.wikipedia.org/wiki/Cfront). C++ versi ini hanya berupa
kompiler yang menterjemahkan bahasa C++ menjadi bahasa C untuk dieksekusi
- Kedua, [Borland International Inc](https://en.wikipedia.org/wiki/Borland). mengembangkan kompiler C++ menjadi sebuah kompiler yang mampu mengubah C++ langsung menjadi bahasa mesin (assembly). Tahun
1990, C++ mulai diarahkan ke pengembangan [Pemrograman Berorientasi Obyek](https://id.wikipedia.org/wiki/Pemrograman_berorientasi_objek).

Beberapa keunggulan C++ dibandingkan dengan bahasa C adalah sebagai berikut.

Object-oriented programming
: Bahasa pemrograman ini sangat mendukung pemrograman berorientasi obyek yang
melihat permasalahan secara obyek dan bukan prosedural.

Portability
: Kita dapat mengkompilasi C++ kode yang sama di hampir semua jenis komputer dan
sistem operasi tanpa membuat perubahan apapun. C++ adalah bahasa pemrograman yang
paling sering digunakan di dunia.

Brevity
: Karena bahasa C++ merupakan bahasa tingkat tinggi, maka bahasa yang ditulis dengan
bahasa C++ termasuk ringkas dan pendek dibandingkan bahasa-bahasa sejamannya
pada waktu itu.Bahasa C++ termasuk bahasa pemrograman tua yang sudah mendukung
berbagai macam kata kunci yang mampu menyingkat proses penulisan kode program.

Modular programming
: Tubuh program pada bahasa C++ dapat terdiri dari beberapa file source code yang disusun
secara terpisah dan kemudian dihubungkan secara bersama-sama. Kemampuan ini jelas
menghemat waktu karena tidak perlu mengkompilasi ulang aplikasi yang lengkap ketika
membuat satu perubahan, tetapi hanya file yang berisi perubahan itu saja. Selain itu,
karakteristik ini memungkinkan kita untuk menghubungkan kode C++ dengan kode yang
dibuat oleh bahasa lain, seperti bahasa Assembly dan C dan dapat digunakan kembali
(reuseable).

C Compatibility
: C++ sangat backward compatible dengan bahasa C, sehingga aplikasi / kode program yang
ditulis dengan bahasa C dapat digabungkan dengan bahasa C++ dengan sangat mudah,
bahkan hampir tidak perlu mengubah kodenya.

Speed
: Kode yang dihasilkan dari kompilasi C++ sangat efisien, karena C++ mendukung prinsip
dualitas bahwa dia mendukung bahasa tingkat tinggi dan bahasa tingkat rendah sehingga
dapat mengurangi ukuran hasil kompiliasi dari bahasa itu.

## Pengantar Qt Creator

Qt Creator merupakan cross-platform C++ integrated development environment yang merupakan bagian dari Qt SDK. Qt Creator mempunyai debugger dalam bentuk visual dan layout GUI serta tempat perancangan form. Teks editornya mempunyai fasilitas syntax highlighting dan autocompletion. Qt Creator menggunakan compiler C++ dari kumpulan compiler GNU pada Linux dan FreeBSD. Pada Windows Qt Creator dapat menggunakan MinGW[^mingw] atau [MSVC](https://id.wikipedia.org/wiki/Microsoft_Visual_Studio_Express) yang sudah build-in di dalam install.


[^mingw]: minGW adalah salah satu aplikasi yng digunakan untuk mengkompile bahasa C agar dapat dipahami oleh bahasa mesin (asembler) pada komputer. Aplikasi ini dapat di unduh secara gratis.

Project Qt Creator menggunakan format cross platform project (.pro) untuk mengizinkan tim developer untuk share project yang mempunyai platform-platform yang berbeda-beda dan menggunakan common tool untuk implementasi dan
debugging program. Sebuah project dapat meliputi: file-file yang digroup secara bersama-sama, langkah-langkah build program, form-form dan file-file resource, dan pengaturan untuk menjalankan aplikasi. Projek dapat dibuat secara manual atau diimport dari file projek yang sudah ada. Jika projeknya dibuat secara manual, maka sebuah file-file akan digenerate oleh Qt Creator, tergantung dari tipe file yang dimiliki. Seperti Jika filenya adalah sebuah GUI application, maka Qt Creator men-generate sebuah file kosong yang berektensikan `.ui` yang akan imodifikasikan melalui Qt Designer. Qt Creator diinterrasikan dengan sistem cross-platform untuk mem-build secara automatis: qmake dan CMake. Projek yang tidak menggunakan qmake atau CMake dapat diimport-kan, dan Qt Creator dapat meng-ignore sistem build.

![Gambar Projek pada Qt Creator](images/capture1-1.png)

Editor Qt Creator mempunyai sebuah code editor dan mengintegrasikan Nokia's Qt Designer untuk mendesain dan
membangun aplikasi GUI dari Qt widgets. Karena Qt Creator adalah sebuah Integrated Development Enviroment (IDE), maka Qt Creator memisahkan antara text editor untuk build dan editor untuk menjalankan (run) aplikasi-aplikasi. Qt Creator bukan hanya bisa membaca text file biasa, akan tetapi juga bisa membaca file C++ dan bahasa QML.

Keunggulan Code Editor

- Dapat menulis code dengan format yang benar.
- engantisipasikan apa yang akan programer tulis dan code yang komplit.
- Menampilkan baris-baris yang error dan pesan-pesan warning.
- Memandu programer secara semantik untuk menulis classes, functions, dan symbols.
- Menyediakan fasilitas bantuan context-sensitive pada classes, functions, dan symbols.
- Me-rename symbol-symbol dengan langkah intelligent, sehingga simbol-simbol yang lain dengan nama yang sama tidak ter-rename.
- Menampilkan lokasi function, class yang dideklarasikan atau yang dipanggil

[Gambar Code Editor](images/capture1-2.png)

### UI Designer

Qt Creator menyajikan dua buah editor visual: Qt Designer dan Qt Quick Designer. Qt Designer merupakan sebuah tool untuk mendesain dan membangun aplikasi GUI dari Qt widgets. Widgets dan forms yang dibentuk dengan Qt Designer terintegrasi dengan code program, Qt signals and mekanisme slots, sehingga kita dengan mudah memberikan nilai-nilai dan properti-properti pada pada elemen-elemen grafik. Semua properti-properti yang diatur pada Qt Designer dapat diubah secara dinamik melalui/di dalam code.

Qt Quick Designer digunakan untuk membangun secara mudah animasi-animasi dengan menggunakan sebuah bahasa pemograman yang dikenal dengan [Qt Meta-Object Language (QML)](https://en.wikipedia.org/wiki/QML). Dalam QML, sebuah user interface dispesifikasikan sebagai sebuah pohon (tree) dari objects dengan properti-properti. Kamu menggunaan teks editor visual untuk menciptakan items, screens, dan aplikasi, serta mendefinisikan perubahan action-acton pada komponennya.
• Dapat digunakan Qt atau JavaScript untuk mengimplementasikan logik aplikasi.

![Gambar UI Designers](images/capture1-3.png)

Pilih File -> New File or Project

### Bahasa yang di dukung

Kamu dapat menggunakan code editor menulis code dalam Qt C++ atau bahasa pemograman QML, javascript bahkan HTML5 . Syntax highlighting juga disajikan untuk banyak bahasa pemograman yang lain.

### Platform

• Qt Creator men-support untuk membangun dan menjalankanaplikasi-aplikasi Qt untuk desktop environments (Seperti Windows, Linux, FreeBSD dan Mac OS) Selain itu juga bisa dijalankan pada mobile devices (seperti Symbian, Maemo, andMeeGo). Ketika sebuah aplikasi dibangun untuk mobile device yang bisa mengkoneksi ke Personal Computer (PC), maka Qt Creator men-generate sebuah package instalasi, menginstall package tersebut pada device, dan meneksekusikannya. 

### Tools

Qt Creator diintegrasikan dengan kumpulan tool-tool yang bermanfaat dan membantu, seperti version control systems
dan Qt Simulator. Qt Creator menggunakan command line client version control system untuk mengakses repositories ([Git](https://git-scm.com/), [subversion](https://subversion.apache.org/), [Perfoce](https://www.perforce.com), [CVS](www.nongnu.org/cvs/), [Mercurial](https://www.mercurial-scm.org)).

### Debuggers

 Qt Creator tidak mempunyai debugger. Qt Creator mempunyai plugin debugger yang bekerja sebagai interface antara Qt Creator core dan external native debuggers

• Debuggers adalah:

- GNU Symbolic Debugger (gdb)
- Microsoft Console Debugger (CDB)
- internal Java Script debugger

Dapat menghubungkan mobile devices dengan PC dan memproses debug yang berjalan pada devices.

## Mengenal macam - macam Teknologi User Interface (UI) pada QT


Interaksi antara pengguna dengan logic software dinamakan User Interface disingkat dengan UI. UI ini berwujud bisa sebuah window, bisa tombol, bisa sebuah textarea dan lain sebagainya. Inilah komponen User Interface. Sebagai seorang programmer (pembuat program aplikasi), terlebih programmer yang menggunakan Qt, maka anda akan disediakan beragam UI yang bisa anda pilih sesuai kebutuhan. Ada QtWitget, QtQuick dan QtWebKit. Ketiganya dapat anda pilih sesuai kebutuhan sebagai UI progam anda. Ingin tahu bedanya? Mari kita simak.


Sama seperti Visual Studio yang menyediakan beragam Amazing User Interface tingkat tinggi sampai pengguna bingung memilihnya, Qt menyediakan tiga UI yang dapat kita gunakan. Anda pun bisa menggabungkan ketiganya. :)

Qt Creator, sebuah Editor Qt adalah contoh dari perpaduan multiple teknologi UI ini. Coba amati Qt Creator yang selalu anda gunakan tersebut.

Qt Creator menggunakan teknologi QtWidget sebagai User Interface pada menu dan kotak dialog nya. Coba perhatikan kembali Welcome Screen dari Qt Creator, lihat, tampilannya berbeda bukan, bahkan button nya sangat berbeda dan tidak biasa, ini karena UI untuk Welcome Screen menggunakan teknologi QtQuick. Lalu dimana letak penggunaan QtWebkit?

Yup, perhatikan Help Documentation nya, wow, ini seperti halaman web yang menyatu dengan softwarenya bukan? Ya, teknologi QtWebKit digunakan dalam pembangunan Help Documentation ini.


### A.Teknologi User Interface QtQuick

QtQuick merupakan salah satu Teknologi UI dari Qt yang menggunakan QML dan JavaScript sebagai penyusun UI nya, kita sudah membahas ini pada tutorial sebelumnya [[C++ QT No.3: Apa itu Qt Quick Application?]]

Mirip seperti XAML yang dikembangkan Microsoft , QML merupakan teknologi binding dari Qt yang memfasilitasi pengguna dengan visual canvas dan rendering engine nya. Teknologi UI ini sangat cocok sekali untuk Hardware Acceleration seperti OpenGL pada VGA driver kita.

Jangan salah, bila anda menggunakan QtQuick versi 2, maka memang butuh OpenGL yang disuport oleh VGA anda. OpenGL sekarang begitu terkenal, banyak games – games yang mulai menargetkan OpenGL karena begitu flexibel dan mudah. Tapi sayangnya, OpenGL ini tidak terdapat pada VGA driver bawaan OS.

Jadi jangan heran, saat anda install ulang komputer (bahkan Windows 8.1 sekalipun) anda akan menemukan bahwa tidak ada OpenGL pada VGA driver anda. Cara terbaik adalah periksa Motherboard anda dan cari driver VGA yang sesuai dengan Motherboard anda. Biasanya gratis.

Animation, Transition, Visual Effect, Shader Effect dan lain – lain merupakan fasilitas yang dapat anda kembangkan saat menggunakan QtQuick sebagai User Interface (UI) aplikasi anda.

### B.Teknologi User Interface QtWidget

QtWidget merupakan tradisional User Interface element yang biasanya terdapat dalam dekstop environment. Bila anda pengguna linux, maka UI ini merupakan bagian dari KDE. Tapi jangan salah, QtWidget sangat dinamis untuk Windows dan Mac OS. Sehingga bila anda menggunakan QtWidget sebagai UI anda maka tampilannya mirip sekali dengan UI pada OS anda.

Bila anda pengguna Windows 8.1 seperti saya dengan Amazing Flat Designnya, maka QtWidget ini menyesuaikan dengan UI OS.

Semua standar komponen untuk aplikasi seperti button, textarea, menu dan lain – lain terdapat pada QtWidget ini. Sehingga sangat cocok sekali untuk anda yang gemar membuat aplikasi tradisional standar.

Bila kita membuat aplikasi dengan QtWidget, maka saat memulai project, akan muncul pemilihan Base Class, ada tiga yaitu Class QWidget, Class QMainWindow, dan Class Qdialog.


Perbedaan dari ketiga Base Class di atas adalah berikut ini:

- `*QWidget` merupakan base class untuk semua GUI element pada QtWidget User Interface. Coba lah explorasi dan bedakan ketiganya :)
 
- `*QDialog` merupakan sebuah window yang biasanya digunakan untuk mengejutkan pengguna, seperti saat window dialog muncul ketika pengguna harus memasukan input dengan benar atau hal – hal yang lain, tampilan dari Qdialog tidak berbeda dengan Qwidget, anda bisa menggunakan salah satu.
 
- `*QMainWindow`, nah, ini adalah sebuah class yang sangat unik, karena menggunakan feature built in yang sangat populer seperti status bar, toolbar, dan menu bar. Cobalah membuat applikasi QtWidget dengan QmainWindow sebagai base class nya, pasti secara otomatis akan ditampilan menubar , toolbar, dan statusbar.

### C.Teknologi User Interface QtWebkit

Tahukah anda bahwa web programing adalah kegiatan yang paling berkembang di dunia saat ini? Tahukah anda bahwa web koding seperti html, css, js sangat populer dan mudah digunakan dan mulai merambah ke teknologi desktop seperti Html5 dan Css3?

Lalu kenapa tidak digunakan dalam pemrograman desktop? Ya, dengan menggunakan User Interface QtWebkit ini anda bisa membuat sebuah desktop application dengan menggunakan koding web. Unik bukan?

Teknologi QtWebkit menampilkan web content melalui QML, sedangkan C++ API digunakan untuk interaksi dengan web content tersebut.

Perlu diperhatikan bersama bahwa pemilihan teknologi adalah biasa, so, tetaplah berkreasi, berikut kita kutipkan beberapa perbandingan antar tiga teknologi UI dari Qt Help Documentation.

## Install Qt Creator

Pada tutorial ini kita akan menginstall Qt pada ubuntu 14.04  dengan menggunakan versi terbaru dari Qt Creator yang dapat di unduh di [halaman](http://www.qt.io/download) Qt cCreator. 
This is a tutorial for installation of Qt 5.0.2 to Ubuntu 12.10. It may be used also for newer versions of Qt and Ubuntu. A difference for OpenGL has been found and added as a note below.

### Installation Guide

####    Download

Kunjungi website Qt untuk mendowload Qt Crator sesui dengan versi sisem operasi yang di gunakan baik itu 64-bit atau 32 bit. atau juga dapat di download dengan menggunakan command line di linux dengan mengetikan.

Contoh:

wget http://download.qt.io/official_releases/online_installers/qt-unified-linux-x86-online.run

jika menggunakan sistem operasi beberbasis 64 bit

wget http://download.qt.io/official_releases/qt/5.6/5.6.0/qt-opensource-linux-x64-5.6.0.run

####  Install

Adjust permission, run the installer and follow the instruction to complete the installation.

	chmod +x qt-opensource-linux-x64-5.6.0.run
	./qt-opensource-linux-x64-5.6.0.run

####    Install g++

Buka terminal untuk menginstal g++: 

	sudo apt-get install build-essential

#### KOnfigurasi Kompiler

Buka Qt Creator klik tool > Options. Klik build & run dan pilih tab Kit. Konfigurasi 
Launch Qt Creator. Go to Tools > Options. Click Build & Run and select tab Kit. Configure a compiler if it is not automatically detected.

####    Install OpenGL libraries

Execute the following command to install OpenGL libraries:

	sudo apt-get install mesa-common-dev

Note: Just installing the above-mentioned mesa-common-dev kit is not sufficient for more recent Ubuntu versions. Based on this comment in the forum an additional package needs installation. Execute following command:

	sudo apt-get install libglu1-mesa-dev -y

Tested with Qt5.3.1 and Ubuntu 14.04 and it solved the problem with missing -lGL.

####    Set file association with pro files

When installing from the on-line source the file association is not done automatically. It also not show up when you try to associate it with file explorer. Create a file named “Qt-Creator.desktop” and fill the file with the following.

	[Desktop Entry]
	Version=1.0
	Encoding=UTF-8
	Type=Application
	Name=QtCreator
	Comment=QtCreator
	NoDsiplay=true
	Exec=(Install folder of QT)/Tools/QtCreator/bin/qtcreator %f
	Icon=(Install folder of QT)/5.4/Src/qtdoc/doc/images/landing/icon_QtCreator_78x78px.png
	Name[en_US]=Qt-Creator

Place this file in home .local/share/applications .

Edit a file named “defaults.list” in the same directory . Add the following line.

	text/qtcreator=Qt-Creator.desktop;

open file mimeapps.list and check if the following line is present.

	application/vnd.nokia.qt.qmakeprofile=qtcreator.desktop

if not add it under [added Associations].

Run the following command.

	sudo update-mime-database /usr/share/mime

now Qt has been added to the list of file associations.

### Troubleshooting

####    Qt Creator needs a compiler set up to build

Follow the instruction from the previous section to configure compiler for Qt Creator.

####    error: g++: Command not found

Solution:

	sudo apt-get install build-essential

####    error: GL/gl.h: No such file or directory

Solution:

	sudo apt-get install mesa-common-dev
