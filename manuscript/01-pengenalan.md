**📋 Apa yang akan dipelajari**

Pada bab ini kita akan mempelajari dasar-dasar yang perlu diketahui sebelum mulai belajar C++ dan Qt:

- Sejarah dan pengenalan bahasa C++
- Keunggulan bahasa C++ dibanding bahasa lain
- Pengenalan Qt Creator dan fitur-fiturnya
- Teknologi UI Qt (Widget, Quick, WebKit)
- Cara instalasi Qt Creator di berbagai platform
- Membuat program pertama "Hello World"
- Struktur dasar program C++

\minitoc

## 🌍 Sejarah Bahasa C++

### Awal Mula Bahasa C

Bahasa C adalah bahasa pemrograman yang dibuat pada tahun 1972 oleh **Dennis M. Ritchie** di Bell Laboratories. Bahasa ini dirancang sebagai bahasa pemrograman tingkat menengah - tidak terlalu rumit seperti bahasa assembly, tapi juga tidak terlalu sederhana seperti bahasa tingkat tinggi.

<div align="center">
| \hline
**Tahun** | **Peristiwa** |
|---|---|
| \hline
1972 | Dennis Ritchie menciptakan bahasa C |
| \hline
1978 | Buku "The C Programming Language" diterbitkan |
| \hline
1989 | Bahasa C distandarisasi oleh ANSI |
| \hline |
</div>

### Kelahiran Bahasa C++

Bahasa C++ adalah pengembangan dari bahasa C yang dibuat oleh **Bjarne Stroustrup** di Bell Labs. Nama "C++" berasal dari operator increment "++" dalam C, yang berarti "C yang ditingkatkan".

> 
*"C++ adalah bahasa pemrograman yang dirancang untuk mendukung pemrograman berorientasi objek sambil tetap mempertahankan efisiensi dan fleksibilitas bahasa C."* - Bjarne Stroustrup

### Perkembangan Bahasa C++

Bahasa C++ mengalami evolusi yang signifikan:

- **1985:** AT&T Laboratories merilis **cfront** - kompiler C++ pertama
- **1990:** Borland International mengembangkan kompiler C++ langsung
- **1998:** Standar C++ pertama (C++98)
- **2003:** Standar C++03 (perbaikan minor)
- **2011:** Standar C++11 (modernisasi besar)
- **2014:** Standar C++14 (perbaikan C++11)
- **2017:** Standar C++17 (fitur baru)
- **2020:** Standar C++20 (fitur modern)

## ⭐ Keunggulan Bahasa C++

Berikut adalah keunggulan-keunggulan bahasa C++ dibandingkan bahasa pemrograman lainnya:

\begin{description}

- [🎯 **Pemrograman Berorientasi Objek (OOP)**]
C++ mendukung pemrograman berorientasi objek yang memungkinkan kita melihat masalah sebagai objek-objek yang saling berinteraksi, bukan sebagai prosedur-prosedur yang berurutan.

- **Encapsulation** - Penggabungan data dan fungsi
- **Inheritance** - Pewarisan sifat dari class lain
- **Polymorphism** - Kemampuan objek berperilaku berbeda

- [🌍 **Portabilitas**]
Kode C++ yang sama bisa dikompilasi dan dijalankan di berbagai jenis komputer dan sistem operasi tanpa perubahan.

- **Cross-platform** - Windows, Linux, macOS
- **Standard library** - Konsisten di semua platform
- **Compiler support** - Didukung semua compiler utama

- [⚡ **Kecepatan dan Efisiensi**]
C++ memberikan kontrol penuh atas memory dan resources.

- **Direct memory access** - Akses langsung ke memory
- **No garbage collection** - Tidak ada overhead GC
- **Optimized compilation** - Kode yang sangat efisien

- [🔧 **Pemrograman Modular**]
Program C++ bisa terdiri dari beberapa file yang terpisah dan kemudian digabungkan.

- **Header files** - Deklarasi fungsi dan class
- **Source files** - Implementasi fungsi dan class
- **Libraries** - Kode yang bisa digunakan ulang

- [🔄 **Kompatibilitas dengan C**]
C++ sangat kompatibel dengan bahasa C. Kode program yang ditulis dalam C bisa digabungkan dengan C++ dengan mudah.

- **C functions** - Bisa dipanggil dari C++
- **C libraries** - Bisa digunakan di C++
- **Gradual migration** - Migrasi bertahap dari C ke C++

- [📝 **Keringkasan dan Fleksibilitas**]
C++ adalah bahasa tingkat tinggi yang ringkas dan fleksibel.

- **Multiple paradigms** - OOP, procedural, generic
- **Operator overloading** - Operator bisa didefinisikan ulang
- **Templates** - Kode generik yang efisien

\end{description}

## 🛠️ Pengenalan Qt Creator

### Apa itu Qt Creator?

Qt Creator adalah **Integrated Development Environment (IDE)** untuk bahasa C++ yang bisa digunakan di berbagai sistem operasi (cross-platform). IDE adalah program yang menyediakan semua tools yang diperlukan untuk menulis, mengkompilasi, dan menjalankan program dalam satu aplikasi.

> 
*Qt Creator adalah IDE yang powerful dan user-friendly yang dirancang khusus untuk pengembangan aplikasi Qt.*

### Fitur Utama Qt Creator

- **Code Editor** - Editor kode dengan syntax highlighting dan autocompletion
- **Visual Designer** - Designer GUI untuk membuat antarmuka pengguna
- **Debugger** - Debugger visual untuk mencari dan memperbaiki bug
- **Project Manager** - Manajemen project yang terintegrasi
- **Version Control** - Dukungan Git, SVN, dan lainnya
- **Cross-platform** - Sama di Windows, Linux, macOS

### Kompiler yang Didukung

Qt Creator bisa menggunakan berbagai kompiler C++:

<div align="center">
| \hline
**Kompiler** | **Platform** | **Keunggulan** |
|---|---|---|
| \hline
MinGW | Windows | Gratis, ringan |
| \hline
MSVC | Windows | Terintegrasi dengan Visual Studio |
| \hline
GCC | Linux/macOS | Standar, powerful |
| \hline
Clang | Multi-platform | Modern, cepat |
| \hline |
</div>

### Format Project Qt Creator

Qt Creator menggunakan format project **cross-platform** (.pro) yang memungkinkan tim developer berbagi project di berbagai platform yang berbeda.

- **File .pro** - Konfigurasi project
- **Source files** - File .cpp dan .h
- **UI files** - File .ui untuk GUI
- **Resource files** - File .qrc untuk resources
- **Build settings** - Konfigurasi kompilasi

### Cara Membuat Project

Project bisa dibuat dengan dua cara:

- **Manual** - Qt Creator akan menghasilkan file-file yang diperlukan secara otomatis
- **Import** - Menggunakan project yang sudah ada

\begin{figure}[htbp]
\centering 
\shadowimage[width=8cm]{Capture1-1}
\caption{Projek pada Qt Creator}
<a name="fig:projek-pada-qt-creator"></a>
\end{figure}

### Code Editor Qt Creator

Editor kode Qt Creator terintegrasi dengan Qt Designer untuk membuat aplikasi GUI. Qt Creator memisahkan antara editor untuk menulis kode dan editor untuk menjalankan aplikasi.

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{Capture1-2}
<a name="fig:code-editor"></a>
\caption{Code Editor Qt Creator}
\end{figure}

### Keunggulan Code Editor

- **Syntax Highlighting** - Warna berbeda untuk keyword, string, comment
- **Code Completion** - Menebak dan melengkapi kode yang akan ditulis
- **Error Detection** - Menampilkan error dan warning secara real-time
- **Code Navigation** - Jump to definition, find references
- **Refactoring** - Rename, extract method, move class
- **Code Formatting** - Format kode secara otomatis
- **Integrated Help** - Dokumentasi yang terintegrasi

### UI Designer

Qt Creator menyajikan dua buah editor visual: **Qt Designer** dan **Qt Quick Designer**.

#### Qt Designer

Qt Designer adalah tool untuk mendesain dan membangun aplikasi GUI dari Qt widgets. Widgets dan forms yang dibentuk dengan Qt Designer terintegrasi dengan code program, Qt signals dan mekanisme slots.

- **Drag and Drop** - Seret komponen ke form
- **Property Editor** - Edit properti komponen
- **Signal/Slot Editor** - Hubungkan signal dan slot
- **Layout Management** - Atur layout secara visual

#### Qt Quick Designer

Qt Quick Designer digunakan untuk membangun animasi-animasi dengan menggunakan QML (Qt Meta-Object Language). Dalam QML, sebuah user interface dispesifikasikan sebagai sebuah pohon (tree) dari objects dengan properti-properti.

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{Capture1-3}
\caption{Gambar UI Designers}
<a name="fig:gambar-ui-designers"></a>
\end{figure}

### Bahasa yang Didukung

Anda dapat menggunakan code editor untuk menulis kode dalam:

- **Qt C++** - Bahasa utama untuk Qt
- **QML** - Qt Meta-Object Language
- **JavaScript** - Untuk logika aplikasi
- **HTML5** - Untuk konten web
- **Python** - Dengan Qt for Python

### Platform yang Didukung

Qt Creator mendukung untuk membangun dan menjalankan aplikasi Qt untuk:

- **Desktop** - Windows, Linux, FreeBSD, macOS
- **Mobile** - Android, iOS, Windows Phone
- **Embedded** - Linux embedded, QNX, VxWorks
- **Web** - WebAssembly

### Tools Terintegrasi

Qt Creator diintegrasikan dengan kumpulan tool-tool yang bermanfaat:

- **Version Control** - Git, SVN, Mercurial, CVS
- **Qt Simulator** - Simulator untuk testing
- **Qt Assistant** - Dokumentasi Qt
- **Qt Linguist** - Tool untuk internationalization
- **Qt Designer** - Visual GUI designer

### Debuggers

Qt Creator mempunyai plugin debugger yang bekerja sebagai interface antara Qt Creator core dan external native debuggers:

- **GNU Symbolic Debugger (gdb)** - Debugger standar
- **Microsoft Console Debugger (CDB)** - Untuk Windows
- **LLDB** - Debugger modern dari LLVM
- **JavaScript debugger** - Untuk QML dan JavaScript

## 🎨 Teknologi User Interface (UI) Qt

### Apa itu User Interface?

User Interface (UI) adalah cara pengguna berinteraksi dengan program komputer. UI bisa berupa window, tombol, text area, dan komponen visual lainnya.

Qt menyediakan tiga teknologi UI yang bisa dipilih sesuai kebutuhan:

- **QtWidget** - UI tradisional untuk desktop
- **QtQuick** - UI modern dengan animasi
- **QtWebKit** - UI berbasis web

### Contoh Penggunaan di Qt Creator

Qt Creator sendiri adalah contoh bagus dari penggunaan multiple teknologi UI:

- **Menu dan dialog** menggunakan QtWidget
- **Welcome Screen** menggunakan QtQuick (tampilan modern dengan animasi)
- **Help Documentation** menggunakan QtWebKit (seperti halaman web)

Anda bisa menggabungkan ketiga teknologi ini dalam satu aplikasi! 😊

### 🚀 QtQuick - UI Modern dengan Animasi

QtQuick adalah teknologi UI modern Qt yang menggunakan **QML** (Qt Meta-Object Language) dan **JavaScript** untuk membuat antarmuka pengguna.

#### Fitur QtQuick

- **Animasi dan transisi** yang halus
- **Visual effects** yang menarik
- **Hardware acceleration** menggunakan OpenGL
- **Responsive design** yang mudah
- **Touch support** untuk perangkat mobile

#### Keuntungan QtQuick

- Cocok untuk aplikasi modern dengan animasi
- Performa tinggi dengan hardware acceleration
- Mudah membuat UI yang menarik
- Mendukung touch dan gesture
- Cross-platform untuk desktop dan mobile

#### Perlu Diperhatikan

QtQuick membutuhkan dukungan OpenGL dari kartu grafis. Jika OpenGL tidak tersedia, Anda perlu menginstal driver VGA yang sesuai dengan motherboard Anda.

### 🖥️ QtWidget - UI Tradisional Desktop

QtWidget adalah teknologi UI tradisional Qt yang menyediakan komponen-komponen standar untuk aplikasi desktop seperti button, text area, menu, dan lainnya.

#### Karakteristik QtWidget

- **UI tradisional** yang familiar dengan pengguna desktop
- **Menyesuaikan dengan OS** - tampilan mirip dengan sistem operasi
- **Komponen standar** yang sudah dikenal
- **Cocok untuk aplikasi bisnis** dan aplikasi tradisional
- **Stable dan mature** - teknologi yang sudah lama ada

#### Base Class QtWidget

Saat membuat aplikasi QtWidget, Anda akan diminta memilih Base Class:

- **QWidget** - Base class untuk semua elemen GUI QtWidget
- **QDialog** - Window dialog untuk input atau konfirmasi
- **QMainWindow** - Window utama dengan menu bar, toolbar, dan status bar built-in

#### Kapan Menggunakan QtWidget

- Aplikasi desktop tradisional
- Aplikasi bisnis atau enterprise
- Ketika ingin tampilan yang familiar dengan OS
- Aplikasi yang tidak memerlukan animasi kompleks
- Aplikasi yang membutuhkan stabilitas tinggi

### 🌐 QtWebKit - UI Berbasis Web

QtWebKit memungkinkan Anda membuat aplikasi desktop menggunakan teknologi web seperti HTML, CSS, dan JavaScript.

#### Konsep QtWebKit

- **Web content** ditampilkan melalui QML
- **C++ API** digunakan untuk interaksi dengan konten web
- **HTML5 dan CSS3** untuk tampilan modern
- **JavaScript** untuk logika aplikasi

#### Keuntungan QtWebKit

- **Menggunakan skill web** yang sudah ada
- **HTML5 dan CSS3** untuk tampilan modern
- **JavaScript** yang mudah dipelajari
- **Kompatibilitas web** yang luas
- **Rapid prototyping** - cepat membuat prototype

#### Kapan Menggunakan QtWebKit

- Aplikasi yang membutuhkan konten web
- Developer yang sudah familiar dengan HTML/CSS/JavaScript
- Aplikasi yang perlu menampilkan halaman web
- Prototype cepat dengan teknologi web
- Aplikasi hybrid web-desktop

### 📊 Perbandingan Teknologi UI Qt

<div align="center">
| \hline
**Fitur** | **QtWidget** | **QtQuick** | **QtWebKit** |
|---|---|---|---|
| \hline
Tampilan | Tradisional | Modern | Web-based |
| \hline
Animasi | Terbatas | Lengkap | CSS3 |
| \hline
Kemudahan | Mudah | Menengah | Mudah |
| \hline
Performa | Cepat | Sangat Cepat | Sedang |
| \hline
Platform | Desktop | Multi-platform | Multi-platform |
| \hline
Learning Curve | Rendah | Sedang | Rendah |
| \hline |
</div>

## 📥 Install Qt Creator

Pada tutorial ini kita akan menginstall Qt Creator di berbagai platform. Qt Creator dapat diunduh di \href{http://www.qt.io/download}{halaman resmi Qt}[^1]: https://www.qt.io/download-open-source/#section-2.

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{qt-downloads}
<a name="halaman-web-download-qt"></a>
\caption{Halaman web Download Qt Creator}
\end{figure}

### Install Qt Creator di Ubuntu/Linux

#### Langkah 1: Download

Kunjungi website Qt untuk mendownload Qt Creator sesuai dengan versi sistem operasi yang digunakan (64-bit atau 32-bit). Atau download menggunakan command line:

```cpp{../code/01-pengenalan-code-1.sh}
```

Untuk sistem 64-bit:
```cpp{../code/01-pengenalan-code-2.sh}
```

#### Langkah 2: Install

Atur permission, jalankan installer dan ikuti perintah berikut untuk menginstall Qt Creator secara lengkap:

```cpp{../code/01-pengenalan-code-3.sh}
```

#### Langkah 3: Install g++

Buka terminal untuk menginstal g++:

```cpp{../code/01-pengenalan-code-4.sh}
```

#### Langkah 4: Konfigurasi Kompiler

Buka Qt Creator, klik Tools → Options. Klik Build & Run dan pilih tab Kit. Konfigurasikan kompiler jika belum terdeteksi secara otomatis.

#### Langkah 5: Install Pustaka OpenGL

Jalankan perintah berikut untuk menginstall Pustaka OpenGL:

```cpp{../code/01-pengenalan-code-5.sh}
```

### Install Qt Creator di Windows

#### Langkah 1: Download

Anda dapat mendownload Qt Creator di halaman website Qt dan memilih versi yang sesuai dengan sistem operasi Anda (64-bit atau 32-bit).
 
<div align="center">
	 ![install-qt-1](images/install-qt-1)
</div>
 
#### Langkah 2: Install

Jika Anda telah mendownload Qt Creator, jalankan installer. Pilih versi yang sesuai dengan sistem operasi Anda.

<div align="center">
	 ![install-qt-2](images/install-qt-2)
</div>
 
#### Langkah 3: Setup
  
Pilih "Next" dan ikuti langkah-langkah setup. Jika tidak ingin mendaftar, Anda dapat memilih "Skip".
  
<div align="center">
	 ![install-qt-3](images/install-qt-3)
</div>
 
#### Langkah 4: Selesai

Installer akan menginstall aplikasi sampai selesai. Klik "Finish" untuk mengakhiri proses pemasangan.

<div align="center">
	![install-qt-4](images/install-qt-4)
</div>

## 🚀 Program Console Pertama dengan Qt Creator

### Membuat Project Console

Untuk mencoba membuat aplikasi dengan Qt Creator, ikuti langkah-langkah berikut:

- Buka Qt Creator
- Klik File → New Project
- Pilih Application → Qt Console Application
- Klik "Choose"

  <div align="center">
  ![qt-console-aplication](images/qt-console-aplication)
  </div>

### Konfigurasi Project

Beri nama project dan pilih direktori tempat aplikasi akan disimpan:

  <div align="center">
  ![qt-console-aplication-2](images/qt-console-aplication-2)
  </div>

### Pilih Kompiler

Klik "Next", kemudian pilih kompiler yang akan digunakan. Disini penulis menggunakan MinGW sebagai kompilernya.

\begin{quotation}
{\LARGE \ding{46}} **Tips**

Simulator atau kompiler yang tersedia:

- Qt Simulator MinGW 4.4
- Qt Simulator VS 2008, 2010, 2011, 2012, 2013, 2014
- Android SDK dan NDK

\end{quotation}

<div align="center">
![qt-console-aplication-3](images/qt-console-aplication-3)
</div>

### Version Control

Pilih jenis version control yang akan digunakan. Jika Anda tidak menggunakan version control, pilih "None" pada "Add to version control".

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{qt-console-aplication-4}
\caption{Langkah Setup Qt Creator}
\end{figure}

### Hasil Akhir

Apabila dilakukan dengan benar, akan muncul Qt Editor seperti berikut:

<div align="center">
![qt-creator](images/qt-creator)
</div>

## 📝 Struktur Program C++

### Pengenalan Struktur Program

Program Bahasa C/C++ tidak mengenal aturan penulisan di kolom/baris tertentu, jadi bisa dimulai dari kolom/baris manapun. Namun demikian, untuk mempermudah pembacaan program dan untuk keperluan dokumentasi, sebaiknya penulisan program di bahasa C/C++ diatur sedemikian rupa sehingga mudah dan enak dibaca.

### Struktur Dasar Program C++

Berikut adalah struktur dasar program yang dibuat dengan bahasa C++:

```cpp
#include <header>  
using namespace std;    
int main(int argc, char *argv[])
{  
deklarasi variabel;   
deklarasi konstanta;  
perintah perintah;  
//komentar  
return 0;  
}  
```

### Penjelasan Komponen

#### 1. #include <header>

`#include` adalah salah satu pengarah preprocessor directive yang tersedia pada C++. Preprocessor selalu dijalankan terlebih dahulu pada saat proses kompilasi terjadi.

```cpp{../code/01-pengenalan-code-7.c++}
```

Bagian tersebut tidak diakhiri dengan tanda semicolon, karena bentuk tersebut bukanlah suatu bentuk pernyataan, tetapi merupakan preprocessor directive.

#### Header Files yang Umum

- `#include <iostream>` - Input/output stream (cout, cin)
- `#include <conio.h>` - Console I/O (clrscr(), getch())
- `#include <iomanip>` - Input/output manipulators (setw())
- `#include <math.h>` - Mathematical functions (sqrt(), pow())
- `#include <string>` - String handling
- `#include <vector>` - Dynamic arrays
- `#include <algorithm>` - Standard algorithms

#### 2. using namespace std;

Semua elemen standard C++ library dinyatakan dalam namespace bernama `std`. Dengan menulis `using namespace std;`, kita memberitahu compiler bahwa kita akan menggunakan semua elemen dari namespace std.

- **Namespace** - Cara mengelompokkan fungsi dan class
- **std** - Standard namespace untuk C++ library
- **using** - Memberitahu compiler namespace yang digunakan

#### 3. int main()

Program C++ terdiri dari satu atau lebih fungsi, dan di antara salah satunya harus ada fungsi main dan hanya boleh ada satu main pada tiap program C++. Setiap program C++ akan dan pasti akan memulai eksekusi programnya pada fungsi main ini.

- **Entry point** - Titik masuk program
- **Return type** - int (integer)
- **Parameters** - argc (argument count), argv (argument vector)
- **Curly braces** - { dan } untuk scope

#### 4. Komentar

Komentar tidak pernah dicompile oleh compiler. Dalam C++ terdapat 2 jenis komentar:

```cpp
  /* Komentar anda diletakkan
   di dalam ini bisa mengapit
    lebih dari satu baris */

  // Komentar anda diletakkan disini
// (hanya bisa sebaris)
```

#### 5. Tanda Semicolon (;)

Tanda semicolon "`;`" digunakan untuk mengakhiri sebuah pernyataan. Setiap pernyataan harus diakhiri dengan sebuah tanda semicolon.

- **Statement terminator** - Mengakhiri pernyataan
- **Required** - Wajib untuk setiap statement
- **Common error** - Kesalahan yang sering terjadi

#### 6. return 0

Pernyataan return menyebabkan fungsi utama untuk menyelesaikan kegiatannya lalu mengembalikan hasil dari fungsi utama.

- **return 0** - Program berakhir dengan sukses
- **return 1** - Program berakhir dengan error
- **Exit code** - Kode yang dikembalikan ke sistem operasi

### Contoh Program Lengkap

Untuk lebih jelasnya, silakan coba ketik program berikut pada project baru:

```cpp{../code/01-pengenalan-struktur-program-c.c++}
```

Kemudian jalankan dengan menekan tombol Run (CTRL + R)

\begin{lcverbatim}
Hello world
Selamat belajar C/C++ enter my world
\end{lcverbatim}

### Analisis Output

- **Hello world** - Output dari cout pertama
- **endl** - Memberikan newline (enter)
- **Selamat belajar C/C++ enter my world** - Output dari cout kedua
- **Tidak ada spasi** - Karena tidak ada spasi dalam string

## 🎯 Best Practices untuk Pemula

### Tips Menulis Kode

- **Gunakan indentasi yang konsisten** - 2 atau 4 spasi
- **Tulis komentar yang jelas** - Jelaskan logika program
- **Gunakan nama variabel yang bermakna** - Jangan gunakan a, b, c
- **Test program secara teratur** - Jangan menulis semua kode sekaligus
- **Gunakan version control** - Git untuk tracking perubahan

### Kesalahan Umum Pemula

- **Lupa semicolon** - Setiap statement harus diakhiri ;
- **Salah nama header** - Perhatikan nama file header
- **Lupa return 0** - Main function harus return nilai
- **Salah case** - C++ case sensitive
- **Lupa include** - Header yang diperlukan

## 📚 Referensi dan Bacaan Lanjutan

Untuk pemahaman yang lebih mendalam, pembaca dapat merujuk pada:

- **Qt Documentation** - Dokumentasi resmi Qt[^1]: Qt Company. (2023). "Qt Creator Manual". https://doc.qt.io/qtcreator/
- **C++ Reference** - Referensi lengkap C++[^1]: C++ Reference. (2023). "C++ Standard Library". https://en.cppreference.com/
- **Bjarne Stroustrup** - Pencipta C++[^1]: Stroustrup, B. (2013). "The C++ Programming Language Fourth Edition". Addison-Wesley.
- **Qt Tutorial** - Tutorial resmi Qt[^1]: Qt Company. (2023). "Qt Tutorials". https://doc.qt.io/qt-6/tutorials.html

## 🎉 Kesimpulan

Pada bab ini kita telah mempelajari dasar-dasar C++ dan Qt Creator. Dengan memahami sejarah, keunggulan, dan cara menggunakan Qt Creator, Anda siap untuk mulai menulis program C++ yang lebih kompleks.

<div align="center">
**Selamat! Anda telah siap untuk belajar C++ dan Qt** 🚀
</div>




<div align="center">
*--- Bab selanjutnya: Tipe Data dan Variabel ---*
</div>
