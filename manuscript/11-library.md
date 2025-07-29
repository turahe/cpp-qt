**📋 Apa yang akan dipelajari**

Pada bab ini kita akan mempelajari tentang Qt Library dan class-class penting yang disediakan oleh Qt:

- Qt Core Module dan class-class dasarnya
- QObject dan automatic memory management
- QString dan manipulasi string
- Collection classes (QList, QMap, QStack, QQueue)
- Iterator dan cara mengakses data

\minitoc

## 📚 Pengenalan Qt Library

### Apa itu Qt Library?

Qt Library adalah kumpulan class-class C++ yang disediakan oleh Qt untuk mempercepat pengembangan aplikasi. Library ini menyediakan berbagai fitur siap pakai seperti:

- **GUI Components** - Widget untuk membuat antarmuka grafis
- **Network Programming** - Class untuk komunikasi jaringan
- **Database Access** - Class untuk mengakses database
- **File I/O** - Class untuk membaca dan menulis file
- **Data Structures** - Collection classes untuk menyimpan data

### Keunggulan Qt Library

- **Cross-platform** - Sama di Windows, Mac, Linux
- **Type-safe** - Mencegah kesalahan tipe data
- **Memory Management** - Otomatis mengelola memory
- **Rich Features** - Banyak fitur siap pakai
- **Documentation** - Dokumentasi lengkap dan contoh

### Qt Core Module

Qt Core Module adalah library dasar yang dibutuhkan oleh setiap aplikasi Qt. Module ini berisi:

- **Basic Data Types** - QString, QByteArray, QChar
- **Data Structures** - QList, QVector, QHash, QMap
- **I/O Classes** - QIODevice, QTextStream, QFile
- **Object System** - QObject, QCoreApplication
- **Threading** - QThread untuk pemrograman multi-thread

## 🏗️ QObject - Base Class Penting

### Apa itu QObject?

QObject adalah base class yang sangat penting dalam Qt. Hampir semua class Qt diturunkan dari QObject. Class ini menyediakan:

- **Automatic Memory Management** - Otomatis menghapus objek
- **Signal-Slot Mechanism** - Komunikasi antar objek
- **Object Tree** - Hierarki parent-child
- **Event System** - Sistem event handling
- **Property System** - Sistem properti dinamis

### Class Hierarchy Qt

<div align="center">
| \hline
**Class** | **Inherits from** | **Purpose** |
|---|---|---|
| \hline
QObject | - | Base class untuk semua objek Qt |
| \hline
QWidget | QObject | Base class untuk GUI widgets |
| \hline
QString | - | Class untuk string handling |
| \hline
QList | - | Template class untuk list |
| \hline
QMap | - | Template class untuk map |
| \hline |
</div>

### Keuntungan Menggunakan QObject

- **Memory Safety** - Tidak perlu manual delete
- **Object Tree** - Parent-child relationship
- **Signal-Slot** - Event-driven programming
- **Properties** - Dynamic property system
- **Events** - Event handling system

## 🧠 Automatic Memory Management

### Masalah Memory Management

Dalam C++ tradisional, programmer harus manual mengelola memory:

- **Memory Leak** - Lupa delete objek
- **Dangling Pointer** - Pointer ke objek yang sudah dihapus
- **Double Delete** - Menghapus objek yang sudah dihapus
- **Complex Management** - Sulit dalam aplikasi besar

### QObject Memory Management

QObject menyediakan automatic memory management:

- **Parent-Child Relationship** - Objek child dihapus otomatis
- **Object Tree** - Hierarki objek yang terorganisir
- **Automatic Cleanup** - Tidak perlu manual delete
- **Stack-based Parent** - Parent disimpan di stack

### Contoh Memory Management

#### ❌ Tanpa QObject (Manual Management)

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Alokasi memory dinamis tanpa QObject, label=contoh11-1]{../code/11-library-contoh11-1.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
22002321 : 8 kar
22002322 : 8 kar
22002323 : 8 kar
22002323 : 8 kar
destroy object
destroy object
destroy object
\end{lcverbatim}

**Analisis Program:**

- Class Mahasiswa tidak diturunkan dari QObject
- Harus manual delete setiap objek
- Risk memory leak jika lupa delete
- Sulit dalam aplikasi kompleks

#### ✅ Dengan QObject (Automatic Management)

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Alokasi memory dinamis dengan QObject, label=contoh11-2]{../code/11-library-contoh11-2.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
"22002321"  :  8  kar
"22002322"  :  8  kar
"22002323"  :  8  kar
"22002323"  :  8  kar
\end{lcverbatim}

**Analisis Program:**

- Class Mahasiswa diturunkan dari QObject
- Memory dihapus otomatis saat program selesai
- Tidak perlu manual delete
- Lebih aman dan mudah

### Parent-Child Relationship

QObject menggunakan sistem parent-child untuk memory management:

- **Parent** - Objek yang memiliki child
- **Child** - Objek yang dimiliki parent
- **Automatic Deletion** - Child dihapus saat parent dihapus
- **Object Tree** - Hierarki objek yang terorganisir

## 📝 QString - String Handling

### Mengapa Menggunakan QString?

QString adalah class untuk menangani string dalam Qt. Keunggulannya:

- **Unicode Support** - Mendukung semua bahasa
- **Rich Features** - Banyak method untuk manipulasi
- **Cross-platform** - Sama di semua platform
- **Type-safe** - Mencegah kesalahan tipe data
- **Performance** - Optimized untuk Qt

### Perbandingan QString vs std::string

<div align="center">
| \hline
**Aspek** | **QString** | **std::string** |
|---|---|---|
| \hline
Unicode | Full support | Limited |
| \hline
Qt Integration | Native | Requires conversion |
| \hline
Platform | Cross-platform | Platform dependent |
| \hline
Features | Rich | Basic |
| \hline
Performance | Optimized | Standard |
| \hline |
</div>

### Basic String Operations

#### Checking String Properties

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Cek apakah nilai QString Null atau Empty, label=contoh11-3]{../code/11-library-contoh11-3.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
"Erick Kurniawan"
Ukuran string  15
test not null
test empty
testing null
\end{lcverbatim}

**Method yang Digunakan:**

- **size()** - Mendapatkan panjang string
- **isNull()** - Cek apakah string belum diinisialisasi
- **isEmpty()** - Cek apakah string kosong
- **length()** - Mendapatkan jumlah karakter

#### String Extraction

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan Fungsi Left Mid Right, label=contoh11-4]{../code/11-library-contoh11-4.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
firstName :  "Erick"
lastName :  "Kurniawan"
midName :  "Kurni"
\end{lcverbatim}

**Method yang Digunakan:**

- **left(n)** - Ambil n karakter dari kiri
- **right(n)** - Ambil n karakter dari kanan
- **mid(pos, n)** - Ambil n karakter dari posisi pos
- **mid(pos)** - Ambil semua karakter dari posisi pos

#### String Concatenation

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggabungkan String, label=contoh11-5]{../code/11-library-contoh11-5.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
Nama :  "Pak. Slamet ,BA"
"Pak. Slamet ,BA ,SE"
\end{lcverbatim}

**Method yang Digunakan:**

- **append(str)** - Tambah string di akhir
- **prepend(str)** - Tambah string di awal
- **insert(pos, str)** - Sisip string di posisi tertentu
- **operator+()** - Gabung string dengan operator +

#### String Reversal

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Membalik String, label=contoh11-6]{../code/11-library-contoh11-6.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
Balik :  "dihcaW ruN"
\end{lcverbatim}

**Method yang Digunakan:**

- **operator[]()** - Akses karakter dengan index
- **size()** - Mendapatkan panjang string
- **Manual Loop** - Loop untuk membalik string

### Advanced String Operations

#### String Conversion

- **toStdString()** - Konversi ke std::string
- **fromStdString()** - Konversi dari std::string
- **toInt()** - Konversi ke integer
- **toDouble()** - Konversi ke double
- **toLower()** - Konversi ke huruf kecil
- **toUpper()** - Konversi ke huruf besar

#### String Searching

- **contains()** - Cek apakah string mengandung substring
- **indexOf()** - Cari posisi substring
- **lastIndexOf()** - Cari posisi terakhir substring
- **startsWith()** - Cek apakah string dimulai dengan substring
- **endsWith()** - Cek apakah string diakhiri dengan substring

## 📦 Collection Classes

### Apa itu Collection Classes?

Collection classes adalah class-class untuk menyimpan dan mengelola kumpulan data. Qt menyediakan berbagai collection yang type-safe dan optimized.

### Jenis Collection Classes

- **QList** - Dynamic array, paling umum digunakan
- **QVector** - Array dengan akses cepat
- **QLinkedList** - Linked list untuk operasi insert/delete
- **QMap** - Key-value pair, terurut
- **QHash** - Key-value pair, tidak terurut, lebih cepat
- **QSet** - Set of unique values
- **QStack** - LIFO (Last In First Out)
- **QQueue** - FIFO (First In First Out)

### QList - Dynamic Array

QList adalah collection yang paling sering digunakan. Keunggulannya:

- **Dynamic Size** - Ukuran berubah otomatis
- **Fast Access** - Akses elemen dengan index
- **Type-safe** - Mencegah kesalahan tipe data
- **Rich API** - Banyak method untuk manipulasi

#### Basic QList Operations

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan QList, label=contoh11-7]{../code/11-library-contoh11-7.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
"Erick"
"Erick"
"Anton"
"Katon"
"Budi"
\end{lcverbatim}

**Method yang Digunakan:**

- **append()** - Tambah elemen di akhir
- **prepend()** - Tambah elemen di awal
- **insert()** - Sisip elemen di posisi tertentu
- **foreach** - Loop untuk mengakses semua elemen

### Iterator - Mengakses Data

Iterator adalah cara untuk mengakses data dalam collection secara berurutan.

#### QListIterator - Read-only Iterator

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan object Iterator, label=contoh11-8]{../code/11-library-contoh11-8.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
12
24
36
48
60
12
24
36
48
60
\end{lcverbatim}

**Method Iterator:**

- **hasNext()** - Cek apakah masih ada elemen berikutnya
- **next()** - Pindah ke elemen berikutnya
- **hasPrevious()** - Cek apakah masih ada elemen sebelumnya
- **previous()** - Pindah ke elemen sebelumnya

#### QMutableListIterator - Modifiable Iterator

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan Iterator untuk memodifikasi data di list, label=contoh11-9]{../code/11-library-contoh11-9.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
"update data.."
"Anton"
"Katon"
"update data.."
\end{lcverbatim}

**Method Mutable Iterator:**

- **setValue()** - Ubah nilai elemen saat ini
- **insert()** - Sisip elemen baru
- **remove()** - Hapus elemen saat ini

### Adding Data to List

Ada berbagai cara untuk menambahkan data ke QList:

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Beberapa cara menambahkan data ke list, label=contoh11-10]{../code/11-library-contoh11-10.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
"anton"
"erick"
"budi"
"katon"
"naren"
\end{lcverbatim}

**Cara Menambah Data:**

- **append()** - Tambah di akhir list
- **prepend()** - Tambah di awal list
- **insert()** - Sisip di posisi tertentu
- **operator<<()** - Operator untuk append
- **push_back()** - Tambah di akhir (STL style)

### QStringList - Special String List

QStringList adalah class khusus untuk list of strings. Class ini diturunkan dari QList dan memiliki method tambahan untuk manipulasi string.

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan QStringList, label=contoh11-11]{../code/11-library-contoh11-11.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
"Jogjakarta,Jakarta,Bandung,Semarang"
"Jogjakarta"
"Jakarta"
"Bandung"
"Semarang"
"Jogjaaakaaartaaa"
"Jaaakaaartaaa"
"Baaandung"
"Semaaaraaang"
\end{lcverbatim}

**Method QStringList:**

- **split()** - Pecah string berdasarkan delimiter
- **join()** - Gabung list menjadi string
- **replaceInStrings()** - Ganti substring dalam semua elemen
- **filter()** - Filter elemen berdasarkan kondisi

## 🗂️ Stack dan Queue

### Stack - LIFO (Last In First Out)

QStack adalah collection yang menggunakan prinsip LIFO. Elemen terakhir yang masuk akan keluar pertama.

### Queue - FIFO (First In First Out)

QQueue adalah collection yang menggunakan prinsip FIFO. Elemen pertama yang masuk akan keluar pertama.

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan Stack dan Queue, label=contoh11-12]{../code/11-library-contoh11-12.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
Stack LIFO : 
"budi"
"katon"
"anton"
"17rick"
Queue FIFO : 
"17rick"
"anton"
"katon"
"budi"
\end{lcverbatim}

**Perbedaan Stack dan Queue:**

<div align="center">
| \hline
**Aspek** | **QStack (LIFO)** | **QQueue (FIFO)** |
|---|---|---|
| \hline
Prinsip | Last In First Out | First In First Out |
| \hline
Add | push() | enqueue() |
| \hline
Remove | pop() | dequeue() |
| \hline
Peek | top() | head() |
| \hline
Use Case | Undo/Redo | Task Queue |
| \hline |
</div>

## 🗺️ QMap - Key-Value Pair

### Apa itu QMap?

QMap adalah collection yang menyimpan data dalam bentuk key-value pair. Setiap elemen memiliki key unik dan value yang terkait.

### Keunggulan QMap

- **Key-Value Pair** - Data terorganisir dengan key
- **Ordered** - Data terurut berdasarkan key
- **Fast Lookup** - Akses cepat dengan key
- **Type-safe** - Mencegah kesalahan tipe data

- Buka Qt Creator dan buat project Qt Console Application baru
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan QMap, label=contoh11-13]{../code/11-library-contoh11-13.c++}

- Jalankan program dan perhatikan output:

\begin{lcverbatim}
erick age :  29
menampilkan semua data yg ada di map :
"anton"  :  29
"erick"  :  29
"katon"  :  42
Mengakses data menggunakan iterator
"anton"  :  29
"erick"  :  29
"katon"  :  42
\end{lcverbatim}

**Method QMap:**

- **insert(key, value)** - Tambah key-value pair
- **operator[]()** - Akses value dengan key
- **contains()** - Cek apakah key ada
- **keys()** - Dapatkan semua key
- **values()** - Dapatkan semua value
- **remove()** - Hapus key-value pair

## 🔧 Best Practices Qt Library

### Tips Menggunakan Qt Library

- **Gunakan QString** - Jangan campur dengan std::string
- **Pilih Collection yang Tepat** - QList untuk umum, QMap untuk key-value
- **Gunakan Iterator** - Untuk akses berurutan dan modifikasi
- **Memory Management** - Manfaatkan QObject automatic memory
- **Type Safety** - Gunakan template dengan tipe yang tepat

### Kesalahan Umum

- **Mixing STL and Qt** - Campur std::string dengan QString
- **Wrong Collection** - Gunakan QList untuk key-value
- **Manual Memory** - Lupa manfaatkan QObject
- **Type Mismatch** - Masukkan tipe data salah ke collection
- **Inefficient Access** - Tidak gunakan iterator untuk loop

## 📚 Referensi dan Bacaan Lanjutan

Qt Library adalah topik yang luas dan terus berkembang. Untuk pemahaman yang lebih mendalam, pembaca dapat merujuk pada:

- **Qt Documentation** - Dokumentasi resmi Qt[^1]: Qt Company. (2023). "Qt Core Module". https://doc.qt.io/qt-6/qtcore-index.html
- **C++ GUI Programming with Qt 4** oleh Jasmin Blanchette[^1]: Blanchette, J., & Summerfield, M. (2006). "C++ GUI Programming with Qt 4". Prentice Hall.
- **Qt 5 C++ GUI Programming Cookbook** oleh Lee Zhi Eng[^1]: Eng, L. Z. (2016). "Qt 5 C++ GUI Programming Cookbook". Packt Publishing.
- **Qt Core Module** - Module dasar Qt[^1]: Qt Company. (2023). "Qt Core Module". https://doc.qt.io/qt-6/qtcore-index.html

## 🎉 Kesimpulan

Qt Library menyediakan class-class yang powerful dan type-safe untuk pengembangan aplikasi. Dengan memahami QObject, QString, dan collection classes, Anda dapat membuat aplikasi yang robust dan maintainable.

<div align="center">
**Selamat! Anda telah menguasai dasar-dasar Qt Library** 📚
</div>




<div align="center">
*--- Bab selanjutnya: File, Stream, dan XML ---*
</div>
