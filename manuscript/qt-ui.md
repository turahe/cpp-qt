## Mengenal macam - macam Teknologi User Interface (UI) pada QT


Interaksi antara pengguna dengan logic software dinamakan User Interface disingkat dengan UI. UI ini berwujud bisa sebuah window, bisa tombol, bisa sebuah textarea dan lain sebagainya. Inilah komponen User Interface. Sebagai seorang programmer (pembuat program aplikasi), terlebih programmer yang menggunakan Qt, maka anda akan disediakan beragam UI yang bisa anda pilih sesuai kebutuhan. Ada QtWitget, QtQuick dan QtWebKit. Ketiganya dapat anda pilih sesuai kebutuhan sebagai UI progam anda. Ingin tahu bedanya? Mari kita simak.


Sama seperti Visual Studio yang menyediakan beragam Amazing User Interface tingkat tinggi sampai pengguna bingung memilihnya, Qt menyediakan tiga UI yang dapat kita gunakan. Anda pun bisa menggabungkan ketiganya. :)

Qt Creator, sebuah Editor Qt adalah contoh dari perpaduan multiple teknologi UI ini. Coba amati Qt Creator yang selalu anda gunakan tersebut.

Qt Creator menggunakan teknologi QtWidget sebagai User Interface pada menu dan kotak dialog nya. Coba perhatikan kembali Welcome Screen dari Qt Creator, lihat, tampilannya berbeda bukan, bahkan button nya sangat berbeda dan tidak biasa, ini karena UI untuk Welcome Screen menggunakan teknologi QtQuick. Lalu dimana letak penggunaan QtWebkit?

Yup, perhatikan Help Documentation nya, wow, ini seperti halaman web yang menyatu dengan softwarenya bukan? Ya, teknologi QtWebKit digunakan dalam pembangunan Help Documentation ini.

Mari kita lanjut....

### A.Teknologi User Interface QtQuick

QtQuick merupakan salah satu Teknologi UI dari Qt yang menggunakan QML dan JavaScript sebagai penyusun UI nya, kita sudah membahas ini pada tutorial sebelumnya [[C++ QT No.3: Apa itu Qt Quick Application?]]

Mirip seperti XAML yang dikembangkan Microsoft , QML merupakan teknologi binding dari Qt yang memfasilitasi pengguna dengan visual canvas dan rendering engine nya. Teknologi UI ini sangat cocok sekali untuk Hardware Acceleration seperti OpenGL pada VGA driver kita.

Jangan salah, bila anda menggunakan QtQuick versi 2, maka memang butuh OpenGL yang disuport oleh VGA anda. OpenGL sekarang begitu terkenal, banyak games – games yang mulai menargetkan OpenGL karena begitu flexibel dan mudah. Tapi sayangnya, OpenGL ini tidak terdapat pada VGA driver bawaan OS.

Jadi jangan heran, saat anda install ulang komputer (bahkan Windows 8.1 sekalipun) anda akan menemukan bahwa tidak ada OpenGL pada VGA driver anda. Cara terbaik adalah periksa Motherboard anda dan cari driver VGA yang sesuai dengan Motherboard anda. Biasanya gratis.

Animation, Transition, Visual Effect, Shader Effect dan lain – lain merupakan fasilitas yang dapat anda kembangkan saat menggunakan QtQuick sebagai User Interface (UI) aplikasi anda.

Amazing bukan?

### B.Teknologi User Interface QtWidget

QtWidget merupakan tradisional User Interface element yang biasanya terdapat dalam dekstop environment. Bila anda pengguna linux, maka UI ini merupakan bagian dari KDE. Tapi jangan salah, QtWidget sangat dinamis untuk Windows dan Mac OS. Sehingga bila anda menggunakan QtWidget sebagai UI anda maka tampilannya mirip sekali dengan UI pada OS anda.

Bila anda pengguna Windows 8.1 seperti saya dengan Amazing Flat Designnya, maka QtWidget ini menyesuaikan dengan UI OS.

Semua standar komponen untuk aplikasi seperti button, textarea, menu dan lain – lain terdapat pada QtWidget ini. Sehingga sangat cocok sekali untuk anda yang gemar membuat aplikasi tradisional standar.

Bila kita membuat aplikasi dengan QtWidget, maka saat memulai project, akan muncul pemilihan Base Class, ada tiga yaitu Class QWidget, Class QMainWindow, dan Class Qdialog.
Lihat gambar 1:


Perbedaan dari ketiga Base Class di atas adalah berikut ini:

- `*QWidget` merupakan base class untuk semua GUI element pada QtWidget User Interface. Coba lah explorasi dan bedakan ketiganya :)
 
- `*QDialog` merupakan sebuah window yang biasanya digunakan untuk mengejutkan pengguna, seperti saat window dialog muncul ketika pengguna harus memasukan input dengan benar atau hal – hal yang lain, tampilan dari Qdialog tidak berbeda dengan Qwidget, anda bisa menggunakan salah satu.
 
- `*QMainWindow`, nah, ini adalah sebuah class yang sangat unik, karena menggunakan feature built in yang sangat populer seperti status bar, toolbar, dan menu bar. Cobalah membuat applikasi QtWidget dengan QmainWindow sebagai base class nya, pasti secara otomatis akan ditampilan menubar , toolbar, dan statusbar.

### C.Teknologi User Interface QtWebkit

Tahukah anda bahwa web programing adalah kegiatan yang paling berkembang di dunia saat ini? Tahukah anda bahwa web koding seperti html, css, js sangat populer dan mudah digunakan dan mulai merambah ke teknologi desktop seperti Html5 dan Css3?

Lalu kenapa tidak digunakan dalam pemrograman desktop? Ya, dengan menggunakan User Interface QtWebkit ini anda bisa membuat sebuah desktop application dengan menggunakan koding web. Unik bukan?

Teknologi QtWebkit menampilkan web content melalui QML, sedangkan C++ API digunakan untuk interaksi dengan web content tersebut.

Perlu diperhatikan bersama bahwa pemilihan teknologi adalah biasa, so, tetaplah berkreasi, berikut kita kutipkan beberapa perbandingan antar tiga teknologi UI dari Qt Help Documentation.
