**📋 Apa yang akan dipelajari**

Pada bab ini kita akan mempelajari tentang pemrograman GUI (Graphical User Interface) dengan Qt:

- Pengenalan GUI dan Qt Widgets
- Signal dan Slot mechanism
- Membuat aplikasi GUI sederhana
- Layout management
- Event handling

\minitoc

## 🎨 Pengenalan GUI (Graphical User Interface)

### Apa itu GUI?

GUI (Graphical User Interface) adalah antarmuka pengguna yang menggunakan elemen grafis seperti ikon, tombol, menu, dan jendela untuk berinteraksi dengan pengguna. GUI membuat aplikasi lebih user-friendly dibandingkan dengan aplikasi berbasis teks (command line).

### Keunggulan GUI

- **User-friendly** - Mudah digunakan bahkan untuk pemula
- **Visual** - Informasi ditampilkan secara grafis
- **Intuitif** - Pengguna dapat langsung memahami fungsi
- **Modern** - Sesuai dengan standar aplikasi masa kini

### Qt sebagai Framework GUI

Qt adalah framework C++ yang powerful untuk membuat aplikasi GUI cross-platform. Qt menyediakan:

- **QtWidgets** - Widget tradisional untuk desktop
- **QtQuick** - Framework modern untuk UI yang dinamis
- **Qt Designer** - Tool visual untuk membuat UI
- **Signal-Slot** - Mekanisme komunikasi antar komponen

## 🏗️ Komponen Dasar Qt GUI

### QWidget - Base Class

QWidget adalah kelas dasar untuk semua elemen GUI dalam Qt. Setiap widget dapat:

- Memiliki parent widget
- Menampilkan konten
- Merespons event
- Memiliki layout

### Jenis-jenis Widget

#### Widget Input

- **QPushButton** - Tombol yang dapat diklik
- **QLineEdit** - Kotak input teks satu baris
- **QTextEdit** - Area input teks multi-baris
- **QComboBox** - Dropdown list
- **QCheckBox** - Checkbox untuk pilihan
- **QRadioButton** - Radio button untuk pilihan tunggal

#### Widget Display

- **QLabel** - Menampilkan teks atau gambar
- **QTextBrowser** - Menampilkan teks dengan format
- **QProgressBar** - Bar progress
- **QSlider** - Slider untuk nilai numerik

#### Container Widget

- **QGroupBox** - Mengelompokkan widget
- **QTabWidget** - Tab untuk multiple pages
- **QScrollArea** - Area dengan scroll
- **QFrame** - Frame untuk border dan styling

## 🔗 Signal dan Slot

### Konsep Signal dan Slot

Signal dan Slot adalah mekanisme komunikasi antar objek dalam Qt yang memungkinkan:

- **Signal** - Event yang dikirim oleh widget
- **Slot** - Fungsi yang merespons signal
- **Connection** - Menghubungkan signal dengan slot

### Cara Kerja Signal-Slot

- Widget mengirim signal ketika event terjadi
- Signal terhubung ke slot melalui connection
- Slot dijalankan untuk merespons event
- Program dapat merespons interaksi pengguna

### Sintaks Signal-Slot

```cpp
// Menghubungkan signal dengan slot
connect(sender, SIGNAL(signalName()), receiver, SLOT(slotName()));

// Contoh: Menghubungkan klik tombol dengan fungsi
connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
```

## 💻 Membuat Aplikasi GUI Sederhana

### Struktur Program GUI

Program GUI Qt terdiri dari:

- **Header file** (.h) - Deklarasi kelas dan slot
- **Source file** (.cpp) - Implementasi kelas dan slot
- **UI file** (.ui) - Desain antarmuka (opsional)
- **Main file** - Entry point aplikasi

### Contoh Program GUI Sederhana

#### Header File (mainwindow.h)

\lstinputlisting[language=c++, caption=Header file untuk aplikasi GUI, label=gui-header]{../code/gui-mainwindow.h}

#### Source File (mainwindow.cpp)

```cpp{../code/gui-mainwindow.cpp}
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set window properties
    setWindowTitle("Aplikasi GUI Sederhana");
    setFixedSize(400, 300);

    // Create central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Create buttons
    buttonA = new QPushButton("Tampilkan Gambar A", this);
    buttonB = new QPushButton("Tampilkan Gambar B", this);

    // Create image label
    imageLabel = new QLabel("Klik tombol untuk menampilkan gambar", this);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setStyleSheet("QLabel { border: 2px solid gray; padding: 10px; }");

    // Add widgets to layout
    mainLayout->addWidget(buttonA);
    mainLayout->addWidget(buttonB);
    mainLayout->addWidget(imageLabel);

    // Connect signals to slots
    connect(buttonA, SIGNAL(clicked()), this, SLOT(onButtonAClicked()));
    connect(buttonB, SIGNAL(clicked()), this, SLOT(onButtonBClicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::onButtonAClicked()
{
    imageLabel->setText("Gambar A ditampilkan");
    imageLabel->setStyleSheet("QLabel { border: 2px solid blue; padding: 10px; background-color: lightblue; }");
}

void MainWindow::onButtonBClicked()
{
    imageLabel->setText("Gambar B ditampilkan");
    imageLabel->setStyleSheet("QLabel { border: 2px solid red; padding: 10px; background-color: lightcoral; }");
}
```

#### Main File (main.cpp)

```cpp{../code/gui-main.cpp}
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    MainWindow window;
    window.show();
    
    return app.exec();
}
```

## 📐 Layout Management

### Pentingnya Layout

Layout management memastikan:

- Widget tersusun rapi dan teratur
- Aplikasi responsive terhadap perubahan ukuran
- UI konsisten di berbagai platform
- Mudah untuk maintenance dan modifikasi

### Jenis-jenis Layout

#### QVBoxLayout (Vertical Layout)

- Menyusun widget secara vertikal
- Widget ditumpuk dari atas ke bawah
- Cocok untuk form atau menu vertikal

#### QHBoxLayout (Horizontal Layout)

- Menyusun widget secara horizontal
- Widget disusun dari kiri ke kanan
- Cocok untuk toolbar atau status bar

#### QGridLayout (Grid Layout)

- Menyusun widget dalam bentuk grid/tabel
- Widget dapat menempati multiple cell
- Cocok untuk form yang kompleks

#### QFormLayout (Form Layout)

- Khusus untuk form input
- Label dan input field otomatis tersusun
- Cocok untuk dialog atau form pengaturan

## 🎯 Event Handling

### Konsep Event

Event adalah kejadian yang terjadi dalam aplikasi GUI:

- **Mouse events** - klik, drag, scroll
- **Keyboard events** - tekan tombol, release
- **Window events** - resize, close, focus
- **Custom events** - event yang dibuat sendiri

### Cara Menangani Event

#### Menggunakan Signal-Slot
```cpp
// Menangani klik mouse
connect(widget, SIGNAL(clicked()), this, SLOT(onClicked()));

// Menangani perubahan teks
connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
```

#### Override Event Handler
```cpp
// Override event handler
void MyWidget::mousePressEvent(QMouseEvent *event)
{
    // Handle mouse press event
    QWidget::mousePressEvent(event);
}
```

## 🎨 Styling dan Theming

### Qt Style Sheets

Qt Style Sheets (QSS) memungkinkan styling widget menggunakan CSS-like syntax:

- **Selector** - Memilih widget yang akan di-style
- **Property** - Properti visual (warna, font, border)
- **Value** - Nilai dari properti

### Contoh Style Sheet

```cpp
// Style untuk QPushButton
QPushButton {
    background-color: #4CAF50;
    border: none;
    color: white;
    padding: 15px 32px;
    text-align: center;
    font-size: 16px;
    border-radius: 8px;
}

QPushButton:hover {
    background-color: #45a049;
}

QPushButton:pressed {
    background-color: #3d8b40;
}
```

## 🔧 Best Practices GUI Programming

### Tips Menulis GUI yang Baik

- **Gunakan layout manager** - Jangan set posisi widget secara manual
- **Berikan nama yang jelas** - Nama widget dan fungsi yang deskriptif
- **Gunakan signal-slot** - Hindari polling atau callback manual
- **Handle error dengan baik** - Validasi input dan error handling
- **Test di berbagai platform** - Pastikan konsisten di Windows, Mac, Linux

### Kesalahan Umum

- **Lupa connect signal-slot** - Widget tidak merespons event
- **Manual positioning** - UI tidak responsive
- **Memory leak** - Lupa delete widget yang dibuat
- **Blocking UI thread** - Aplikasi freeze saat operasi berat

## 📱 Membuat Aplikasi Modern

### Qt Quick vs Qt Widgets

<div align="center">
| \hline
**Aspek** | **Qt Widgets** | **Qt Quick** |
|---|---|---|
| \hline
Target platform | Desktop | Desktop, Mobile, Embedded |
| \hline
Performance | C++ native | QML + JavaScript |
| \hline
Learning curve | Moderate | Steep (QML) |
| \hline
Animation | Limited | Rich |
| \hline
Touch support | Basic | Excellent |
| \hline |
</div>

### QML untuk UI Modern

QML (Qt Modeling Language) adalah bahasa deklaratif untuk membuat UI modern:

- **Declarative** - UI dideklarasikan, bukan diprogram
- **Animation** - Animasi yang smooth dan natural
- **Responsive** - UI yang responsive terhadap input
- **Cross-platform** - Sama di semua platform

## 🔍 Latihan dan Project

### 📝 Latihan 1: Kalkulator Sederhana

Buat aplikasi kalkulator dengan GUI yang memiliki:

- Display untuk menampilkan angka
- Tombol angka 0-9
- Tombol operator (+, -, *, /)
- Tombol equals (=) dan clear (C)

### 📝 Latihan 2: Text Editor Sederhana

Buat text editor dengan fitur:

- Area text untuk menulis
- Menu File (New, Open, Save)
- Menu Edit (Copy, Paste, Cut)
- Status bar untuk informasi

### 📝 Latihan 3: Image Viewer

Buat image viewer dengan:

- Area untuk menampilkan gambar
- Tombol untuk load image
- Tombol untuk zoom in/out
- Tombol untuk rotate image

## 📚 Referensi dan Bacaan Lanjutan

Qt GUI programming adalah topik yang luas dan terus berkembang. Untuk pemahaman yang lebih mendalam, pembaca dapat merujuk pada:

- **Qt Documentation** - Dokumentasi resmi Qt[^1]: Qt Company. (2023). "Qt Documentation". https://doc.qt.io/
- **C++ GUI Programming with Qt 4** oleh Jasmin Blanchette[^1]: Blanchette, J., & Summerfield, M. (2006). "C++ GUI Programming with Qt 4". Prentice Hall.
- **Qt 5 C++ GUI Programming Cookbook** oleh Lee Zhi Eng[^1]: Eng, L. Z. (2016). "Qt 5 C++ GUI Programming Cookbook". Packt Publishing.
- **Qt Quick** - Framework modern untuk UI[^1]: Qt Company. (2023). "Qt Quick". https://doc.qt.io/qt-6/qtquick-index.html

## 🎉 Kesimpulan

Pemrograman GUI dengan Qt membuka dunia kemungkinan untuk membuat aplikasi desktop yang powerful dan user-friendly. Dengan memahami konsep widget, signal-slot, layout management, dan event handling, Anda dapat membuat aplikasi GUI yang profesional.

<div align="center">
**Selamat! Anda telah menguasai dasar-dasar GUI Programming dengan Qt** 🎨
</div>




<div align="center">
*--- Bab selanjutnya: File, Stream, dan XML ---*
</div>

