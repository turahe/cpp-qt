**📋 Apa yang akan dipelajari**

Pada bab ini kita akan membahas tentang Casting dan Database dalam C++:

- Pengenalan casting dan tipe konversi
- Implicit dan explicit conversion
- Database connectivity
- SQL operations

\minitoc

## 🔄 Mengenal Casting<a name="mengenal-casting"></a>

### Apa itu Casting?

Casting adalah mekanisme dimana programmer dapat secara permanen atau temporary mengubah interpretasi compiler terhadap suatu objek. Perubahan ini tidak benar-benar terjadi, namun hanya cara pandang compiler saja yang diubah.

### Implementasi Casting

Casting diimplementasikan dalam bentuk "casting operator".

### Mengapa Butuh Casting?

- **Strong type language** - dalam dunia pemrograman yang semuanya jelas
- **Single language** - jika hanya menggunakan satu bahasa pemrograman seperti C++
- **Real world** - kenyataannya ada banyak bahasa pemrograman dan vendor berbeda
- **Compatibility** - compiler harus diubah interpretasinya untuk kompatibilitas

### Contoh Nyata: C vs C++

Contoh nyata terdapat pada bahasa C dan C++. Pada bahasa C tidak terdapat tipe data bool (boolean) sehingga kita harus menggunakan kata kunci typedef.

#### Kode C

\lstinputlisting[language=c++, numbers=none]{../code/casting-c-bool.cpp}

#### Problema Kompatibilitas

- Kita membuat tipe data baru bertipe unsigned int yang didefinisikan sebagai **BOOL**
- Jika dikembangkan dengan bahasa C++, kita harus melakukan konversi BOOL
- Bahasa C++ sudah ada tipe data bool yang berbeda "persepsi" dengan BOOL dari bahasa C
- Maka dari itu dilakukan casting

#### Contoh Casting

\lstinputlisting[language=c++, numbers=none]{../code/casting-explicit-example.cpp}

## 📊 Data Type Casting (Conversion)<a name="data-type-casting-conversion"></a>

### Apa itu Type Casting?

Mengubah sebuah ekspresi dari tipe yang diberikan dalam jenis lain dikenal sebagai tipe-casting.

### Jenis Konversi

Konversi tersebut ada dua jenis:

- **Implicit conversion** - konversi otomatis
- **Explicit conversion** - konversi manual

### 🔄 Implicit Conversion<a name="implicit-conversion"></a>

#### Karakteristik

- Tidak membutuhkan operator khusus
- Tipe data dengan jangkauan besar dapat dikonversi ke tipe data dengan jangkauan lebih kecil secara otomatis
- Pemotongan nilai dilakukan otomatis
- Variabel dengan tipe data jangkauan besar dapat menerima data dari variabel dengan tipe data jangkauan kecil

**Contoh:**

\lstinputlisting[language=c++, numbers=none]{../code/casting-implicit-example.cpp}

Pada contoh diatas, tipe data `short` yang berjarak jangkau kecil
dapat ditampung oleh tipe data `int` yang jarak jangkaunya lebih
besar, walaupun tipe datanya berbeda. Hal ini karena keduanya sama-sama
data numerik dan memang termasuk dalam konversi implisit. *Implisit
conversion* juga dapat diterpakan pada *constrctor* sebuah
*class*, sehingga ketika kita memanggil konstruktor tersebut, maka
konversi akan dilakukan. Contoh:

\lstinputlisting[language=c++, numbers=none]{../code/casting-constructor-example.cpp}

Proses instansiasi adalah:

\lstinputlisting[language=c++, numbers=none]{../code/casting-instantiation-example.cpp}

Pada contoh diatas, terlihat bahwa ketika kita membuat obyek class B,
maka otomatis konstruktor class B dijalankan dan menerima parameter
obyek A. Sehingga kita bisa memasukkan parameter bertipe class A kedalam
class B.

### Explicit conversion<a name="explicit-conversion"></a>

Konversi tipe ini harus dituliskan pada kode program dengan menggunakan
tanda kurung.

**Sintaks:**

\lstinputlisting[language=c++, numbers=none]{../code/casting-explicit-syntax.cpp}

**Contoh:**

```cpp
short a=2000;
int b;
b = (int) a; // c-like cast notation
b = int (a); // functional notation
```

Cara pertama dengan menegunakan *C-cast like notation*. Pada contoh
diatas, kita memaksa / mengcasting variabel a yang bertipe
`short` agar diperlakukan seperti tipe data `integer`
dengan cara memberi tanda kurung (int) sebelum variabel a. Dengan
demikian variabel a akan dianggap / diperlakukan oleh kompiler menjadi
tipe data integer dan bisa di assign ke dalam variabel b yang bertipe
integer.

Cara kedua adalah menggunakan *functional notation* dimana kita
bisa memaksa variabel a yang bertipe `short` diperlakukan menjadi
`integer` dengan cara menuliskan kata `int` kemudian
diberi tanda kurung pada variabel a sehingga variabel a bisa di assign
ke dalam variabel b yang bertipe integer.

#### Contoh Explicit Casting pada Tipe Data Numerik.

Tulislah kode berikut:

\lstinputlisting[language=c++, caption=Explicit Casting pada Tipe Data Numerik]{../code/10-casting-database-explicit-casting-pada-tipe-data-numerik.c++}

**Hasil:**

\begin{lcverbatim}
1. c=2
2. c=2
3. c=2
4. c=2
5. c=2
6. c=2
7. d=2
8. d=2.5
9. d=2.5
10. d=2.5
11. d=2
12. d=2.5
\end{lcverbatim}
**Keterangan:**

Mari kita analisa perbaris.

- Integer dibagi integer dan dimasukkan ke dalam variabel integer akan
menjadi integer, walaupun ada koma dibelakangnya, yaitu 0.5 tapi akan
dipotong, karena tipe data integer tidak mampu menerima koma, sehingga
akan dipotong.
- Walaupun kita casting ke dalam float, namun kenyataannya tidak
berhasil, karena tipe data integer lebih kecil lebar datanya daripada
tipe data float, sehingga ketika kita casting dalam float, datanya
sudah terlanjur terpotong, sehingga tidak ada perubahan
- Perintah ketiga sama Keterangan:nya dengan no 2.
- C bertipe integer, sehingga walaupun x dan y float dan ada koma, namun
ketika disimpan didalam integer akan terpotong menjadi bilangan bulat
- Sudah jelas, karena x dicasting ke integer dan y juga, berarti semua
menjadi integer
- Keterangan: sama dengan alasan no 2
- D bertipe float namun karena aa dan bb bertipe integer, maka hasilnya
integer juga dan nilainya sudah terpotong, sehingga ketika disimpan
kedalam tipe float sudah terlanjur terpotong nilainya.
- Variabel aa dan bb yang bertipe integer dipaksa menjadi float, dan
karena disimpan dalam variabel d yang bertipe float, maka hasilnya
float
- Variabel aa dan bb yang bertipe integer dipaksa menjadi float
masing-masing sehingga akan menjadi float, dan disimpan didalam
variabel float d.
- Sudah jelas, float dibagi float dan disimpan dalam tipe float sehingga
sudah benar tampil sebagai float
- Variabel x dan y yang bertipe float dipaksa menjadi tipe data yang
lebih kecil, yaitu integer, kemudian baru disimpan dalam tipe data
integer sehingga hasil akhirnya integer.
- Variabel yang dicasting hanya variabel x sehingga variabel y dan d
masih float. Tipe data x (integer) dibagi float makan akan tetap
menjadi float, karena float tipe datanya lebih besar lebar datanya
daripada integer.

\begin{quotation}

{\LARGE \ding{46}} **TIPS** 

Untuk melakukan casting yang benar, maka casting akan valid jika kita mengcasting tipe data yang berukuran lebih besar menjadi tipe data yang berukuran lebih kecil. Misalnya float dicast menjadi int.
\end{quotation}

## Casting Operator pada C++<a name="casting-operator-pada-c"></a>

C++ memiliki cara pengcastingan yang baru, yaitu:

- static_cast
- dynamic_cast
- reinterpret_cast
- const_cast

Bentuk umum untuk semuanya adalah:

```cpp
tipe_tujuan hasil = tipe_casting <tipe_tujuan> (obyek_yg_mau_dicasting);
```

### Pengunaan static_cast<a name="pengunaan-staticux5fcast"></a>

*Static_cast* adalah mekanisme yang dapat digunakan untuk
mengkonversi pointer diantara tipe data/class terkait dan melakukan
konversi tipe data tersebut secara eksplisit untuk tipe data standar
yang jika tidak dilakukan konversi akan terjadi secara otomatis
(implisit). Dengan menggunakan konsep pointer, `static_cast`
menerapkan pengecekan casting pada saat compile-time dengan melakukan
pemeriksaan untuk memastikan bahwa pointer dicasting ke tipe yang
benar/sesuai. Hal Ini merupakan perbaikan dari casting yang berjenis
C-style, dimana memungkinkan casting ke obyek yang tidak ada relasinya
sama sekali. Dengan menggunakan `static_cast`, pointer bisa
dicaskting ke class induknya atau dapat down-case menjadi class
turunannya. Berikut contohnya:

```cpp
CInduk* pInduk = new CTurunan (); // membuat obyek Cturunan dari Cinduk (polymorfisme)
CTurunan* pTurunan = static_cast<CTurunan*>(pInduk); // mengcasting pInduk menjadi Cturunan, valid!
// CTdkAdaHubungan merupakan class yang tidak ada hubungannya dengan CInduk melalui inheritance
CTdkAdaHubungan* pTdkHub = static_cast<CTdkAdaHubungan*>(pInduk); // Error
//karena casting tidak diperbolehkan, tidak ada hubungan class!
```

**Keterangan:**

- Pada contoh diatas terlihat bahwa class anak dapat dibuat dari class
induk karena ada hubungan pewarisan. Konsep ini merupakan konsep
polimorfisme. Kemudian untuk memastikan agar tipe data pInduk
benar/valid untuk dimasukkan ke pTurunan yang merupakan obyek
CTurunan, maka dilakukan casting dengan static_casting.
- Kemudian pada bagian kedua, terlihat bahwa jika kita membuat class
yang tidak ada hubungan apapun dengan class Induk maka kita tidak bisa
melakukan static_casting.
- Dengan demikian, static_casting digunakan untuk meyakinkan validitas
suatu obyek pointer bahwa obyek tersebut ada hubungan dengan obyek
yang dicastingnya. Pengcastingan dilakukan dengan mengubah class Induk
menjadi class Anak, bukan sebaliknya.

Bagi para programmer C yang beralih ke C++, static casting sangat mirip
dengan C-style casting dan sangat disarankan untuk mengganti C-style
casting karena static casting lebih aman dan tampak tertulis dengan
jelas. Kita dapat melakukan `static_casting` pada tipe data
biasa agar programmer dapat melihat

secara eksplisit tipe data yang dicastingnya. Sintaks umunya adalah:

```cpp
static_cast<<type>>(<value>);
```

**Berikut contohnya:**

```cpp
double myphi = 3.14;
int angka = static_cast<int>(myphi);
```

### Penggunaan dynamic_cast<a name="penggunaan-dynamicux5fcast"></a>

Fungsi dynamic_cast merupakan kebalikan dari static_cast, hal ini
karena proses pengcastingan terjadi saat runtime. Casing jenis ini
sangat tepat untuk digunakan pada class yang memiliki sifat
polimorfisme. Casting ini dapat digunakan untuk melakukan casting secara
aman pada pointer superclass menjadi sebuah pointer subclass dalam
sebuah hierarki kelas. Jika ternyata casting invalid karena tipe obyek
yang dicasting tidak setipe dengan class supernya, maka casting akan
gagal. Agar lebih aman, penggunaan dynamic_cast sebaiknya digunakan
dalam blok try\ldots{}catch.

**Bentuk umumnya adalah:**

```cpp
tipe_tujuan* pTujuan = dynamic_cast <tipe_class*> (pSumber);
if (pTujuan) // apakah proses casting sukses?
pTujuan->CallFunc ();
```

**Contoh penggunaan:**

```cpp
CInduk* pInduk = new CTurunan();
// Melakukan down casting
CTurunan* pTurunan = dynamic_cast <CTurunan*> (pInduk);
if (pTurunan) // cek apakah sukses?
pTurunan->CallFungsiClassTurunan ();
```

**Keterangan:**

Pada contoh diatas, kita membuat obyek class Turunan dari class Induk,
kemudian kita melakukan casting ke class Turunan untuk memastikan
validitas obyeknya, kemudian karena sifat pengecekan compiler bersifat
runtime, maka kita bisa memeriksa apakah proses castingnya telah
berjalan dengan sukses atau tidak.

Dynamic_cast juga dapat digunakan untuk referensi pointer. Caranya
dengan menggunakan tanda &.

Casting ini tidak boleh menghasilkan kembalian NULL. Sintaksnya:

```cpp
<type> subclass = dynamic_cast<<type> &>( ref_obj );
```

**Contoh:**

```cpp
class CBase { };
class CDerived: public CBase { };
CBase b; CBase* pb;
CDerived d; CDerived* pd;
pb = dynamic_cast<CBase*>(&d); // ok: derived-to-base
pd = dynamic_cast<CDerived*>(&b); // wrong: base-to-derived
```

#### Contoh Dynamic Casting.

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Contoh Dynamic Casting]{../code/10-casting-database-contoh-dynamic-casting.c++}

**Hasil:**

\begin{lcverbatim}
Penggunaan dynamic_cast untuk menentukan jenis Animal 1
Binatang Dog!
Dog: Kibas-kibas ekor!
Penggunaan dynamic_cast untuk menentukan jenis Animal 2
Binatang kucing!
Cat: tikus tertangkap!
Verifikasi tipe: Animal 1 Besuara!
Dog: Guk-guk!
Verifikasi tipe: Animal 2 Besuara!
Cat: Meong!
\end{lcverbatim}
**Keterangan:**

Kelas abstrak Canimal diturunkan pada dua class, yaitu CDog dan CCat
sehingga memiliki function Berbicara() dimana Dog menggunakannya untuk
menggonggong dan Cat menggunakannya untuk mengeong. Fungsi yang
digunakan adalah dynamic_cast yang akan menentukan mana method
Berbicara() yang diimplementasikan. Dog akan mengimplementasikan
menggonggong, sedangkan Cat akan mengimplementasikan mengeong. Setelah
mengetahui fungsi mana yang diimplementasikan, method TentukanTipe juga
dapat menggunakan pointernya untuk memanggil method pada class
turunannya sesuai dengan jenis classnya. Untuk class Dog memanggil
method KibasEkor(), sedangkan class Cat memanggil method TangkapTikus().

### Penggunaan reinterpret_cast<a name="penggunaan-reinterpretux5fcast"></a>

Penggunaan casting ini benar-benar tidak memungkinkan programmer untuk
mengcasting dari satu obyek ke jenis obyek lain, terlepas dari apakah
jenis obyeknya berhubungan atau tidak. Casting ini tidak boleh digunakan
untuk melakukan down casting pada hierarki kelas atau untuk menghapus
const volatile. Sintaks:

```cpp
reinterpret_cast<<type>>( <val> );
```

**Contoh:**

```cpp
reinterpret_cast<int*>(100);
```

Reinterpret_cast pada class menggunakan syntax sebagai berikut:

```cpp
CInduk * pInduk = new CInduk ();
CTdkAdaHubungan * pTdkHubung = reinterpret_cast<CTdkAdaHubungan*>(pInduk);
// program diatas bisa dikompile tapi sangat tidak disarankan karena class CtdkAdaHubungan bukanlah turunan dari Cinduk.
```

Casting model ini sebenarnya memaksa compiler untuk menerima situasi
dimana pada static_cast tidak diijinkan. Casting model ini biasanya
ditemukan pada pemrograman aplikasi tingkat rendah tertentu (seperti
driver) dimana harus dilakukan konversi ke tipe sederhana dimana API
dapat menerimanya.

```cpp
CSomeClass* pObject = new CSomeClass ();
// harus dikirimkan dalam bentuk byte (unsigned char)
unsigned char* pBytes = reinterpret_cast <unsigned char*>(pObject);
```

**Contoh lain:**

```cpp
class A {};
class B {};
A * a = new A;
B * b = reinterpret_cast<B*>(a);
```

\begin{quotation}
{\LARGE \ding{46}}  **TIPS** 

Sebisa
mungkin reinterpret_cast tidak digunakan jika tidak terpaksa karena
tidak aman.
\end{quotation}

### Penggunaan const_cast<a name="penggunaan-constux5fcast"></a>

Const_cast digunakan untuk menghilangkan sifat const-ness atau sifat
volatile-an dari sebuah variabel. Const_cast harus digunakan dengan
tepat. Salah satu contoh penggunaan yang sah dari const_cast adalah
untuk menghilangkan sifat const-an dari sebuah pointer agar dapat lulus
menjadi fungsi ketika kita yakin fungsi tersebut tidak akan memodifikasi
variabel tetapi fungsi itu didesain untuk tidak menentukan inputan
sebagai konstanta.

**Sintaks:**

```cpp
const_cast<<type>>(<value>);
```

**Contoh:**

```cpp
void func(char *);
const char *x = "abcd";
func(const_cast<char *>(x));
```

const_cast juga memungkinkan kita untuk menonaktifkan method const pada
suatu objek. Mengapa diperlukan? Karena kadang-kadang programmer
melupakan penggunaan const pada method yang seharusnya berjenis const
method. Contoh:

```cpp
ContohClass
{
public:
// ...
void tampilkanAnggota (); // method ini berjenis const
};
void tampilkanData (const ContohClass& mData)
{
mData.tampilkanAnggota (); // compile error, karena "call to a non-const member using
a const reference"
}
```

Kita dapat menggunakan const_cast untuk mengubah a adalah:

```cpp
void tampilkanData (const ContohClass& mData)
{
ContohClass& refData = const_cast <ContohClass&>(mData);
refData.tampilkanAnggota(); // OK!
}
```

Kita juga dapat menggunakan pointer:

```cpp
void tampilkanData (const ContohClass* pData)
{
// pData->DisplayMembers(); Error: attempt to invoke a non-const function!
CSomeClass* pCastedData = const_cast <CSomeClass*>(pData);
pCastedData->DisplayMembers(); // Allowed!
}
```

Contoh lain:

```cpp
// const_cast
#include <iostream>
using namespace std;
void print (char * str)
{
cout << str << endl;
}
int main () {
const char * c = "sample text";
print ( const_cast<char *> (c) );
return 0;
}
```

## Pemrograman Basisdata dengan QtConsole Application<a name="pemrograman-basisdata-dengan-qtconsole-application"></a>

Pada bagian kedua ini kita akan berkenalan dengan bagaimana mengakses
basisdata dengan menggunakan Qt. Basis data adalah suatu kumpulan
tabel-tabel yang berisi data-data yang saling berelasi satu sama lain
secara logika. Basis data tersusun dari tabel, sedangkan tabel tersusun
dari baris record-record yang memiliki atribut (kolom) dan nilainya.
Gambaran basis data pada Qt Creator seperti gambar [fig:basis-data-qt](#fig:basis-data-qt)

\begin{figure}
\centering
\shadowimage[width=8cm]{basis-data-qt}
\caption{Pemrograman Basis data Qt Creator}
<a name="fig:basis-data-qt"></a>
\end{figure}

Pada contoh diatas, terdapat sebuah basisdata perkuliahan, dimana
terdapat 5 buah tabel. Tabel yang ada memiliki field (atribut/kolom).
Field pada masing-masing tabel sangat berasosiasi dengan tabelnya,
artinya kodemk, nama, dan sks pada tabel matkuliah sangat spesifik
menggambarkan tabel matakuliah, demikian juga yang lainnya.

Kita tidak akan membahas lebih lanjut tentang basisdata. Pada basis data
kita juga mengenal SQL (Structured Query Language). SQL merupakan bahasa
untuk mengakses dan memanipulasi basis data terutama isi record-record
pada tabel.

### Koneksi Qt dengan Basisdata<a name="koneksi-qt-dengan-basisdata"></a>

Untuk melakukan koneksi pada basis data, Qt menyediakan dukungan pada
beberapa basis data yang terkenal, misalnya
\href{https://www.sqlite.org/about.html}{Sqlite},
\href{https://en.wikipedia.org/wiki/Oracle_Database}{Oracle},
\href{https://www.mysql.com/about/}{MySQL}, Db2[^1]: \href{https://en.wikipedia.org/wiki/IBM_DB2{IBM
DB2} adalah produk database server yang dikembangkan oleh IBM.
Produk-produk ini mendukung sistem manajemen basis data relasional
(relational DBMS), namun belakangan ini sudah mendukung pula sistem
manajemen basis data berbasis object-relational (object-relational
DBMS) dan juga non-relational seperti XML.}, ODBC[^1]: Open
Database Connectivity (ODBC) adalah Application Programming interface
(API) database yang khusus digunakan untuk mengakses database
relasional. ODBC terdapat dalam setiap komputer yang menggunakan
sistem operasi windows, karena ODBC merupakan bagian dari Windows Open
System Architecture (WOSA). Dalam ODBC disediakan berbagai Application
Programming Interface (API) yang berguna untuk menyediaan dan
memberikan stkitar bagi berbagai kegiatan pemrograman. Keuntungan
utama menggunakan ODBC ini adalah fleksibilitas, fleksibel disini
artinya pengubahan jenis database yang dipergunakan oleh sebuah
aplikasi tidak akan mempengaruhi kode program aplikasi tersebut., dan
\href{https://id.wikipedia.org/wiki/PostgreSQL}{Postgresql}. Secara
default basis data yang didukung adalah Sqlite dan ODBC saja, sedangkan
untuk basis data lainnya harus menggunakan driver yang biasanya harus
didownload pada situsnya secara langsung.

Pada Qt kita dapat membuat aplikasi console yang terkoneksi dengan basis
data. Koneksi terhadap kedua database tersebut tidak perlu melakukan
konfigurasi dan mendownload driver tertentu. Pada tulisan ini kita akan
menggunakan basis data Sqlite.

### Koneksi Qt dengan MySQL dan menampilkan
datanya<a name="koneksi-qt-dengan-mysql-dan-menampilkan-datanya"></a>

\href{https://www.mysql.com/}{MySQL} merupakan database yang sudah
disupport oleh Qt. Untuk membuat database MySQL.

Untuk melakukan koneksi QtConsole dengan MySQL, maka lakukan Contoh
berikut:

#### Contoh Percobaan koneksi MySQL dengan QtConsole

- Buatlah sebuah database pada MySQL dengan nama: testmhs
- Gunakan gunakan PHPmyAdmin untuk membuat tabel database.

\shadowimage[width=8cm]{phpmyadmin}

- Isilah datanya sebagai berikut:

\begin{longtable}[]{@{}lll@{}}
\toprule
NIM & Nama & IPK\tabularnewline
\midrule
\endhead
011041 & Wachid & 3.6\tabularnewline
012042 & Arif & 3.6\tabularnewline
011012 & Eko & 3.4\tabularnewline
\bottomrule
\end{longtable}

Hasil:

\shadowimage[width=8cm]{database-mhs}

- Tulis kode berikut ini:

\lstinputlisting[language=c++, caption=Percobaan koneksi MySQL dengan QtConsole]{../code/10-casting-database-percobaan-koneksi-mysql-dengan-qtconsole.c++}

- Pada file project yang berekstensi .pro, tambahkan linking ke library
sql sebagai berikut:

```cpp
#-------------------------------------------------
#
# Project created by QtCreator 2016-01-03T19:58:33
#
#-------------------------------------------------
QT += core
QT += gui
Qt += sql
TARGET = databases
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp
```
- Kemudian run dan hasilnya adalah sebagai berikut:

\begin{lcverbatim}
("QSQLITE", "QMYSQL", "QODBC3", "QODBC")
Koneksi sukses
"11041"
"Wachid"
"3.6"
"12042"
"Arif"
"3.6"
"11012"
"Eko"
"3.4"
\end{lcverbatim}

**Keterangan:**

- Program diatas dapat menampilkan driver database yang terinstall dan
dapat dikenali oleh system Qt, yaitu QSQLITE, QMYSQL, QODBC3, dan
QODBC. Berarti sistem QT dapat mendukung basisdata Sqlite, MySQL, dan
ODBC dari Microsoft.
- Kemudian langkah pertama yang harus dilakukan adalah membuat
QsqlDatabase yang akan meload basis data yang dipilih beserta dengan
drivernya. Setelah itu kita harus menentukan nama database yang akan
diakses, user, password, dan host lokasi MySQL server.
- Kemudian akan diperiksa apakah database yang terpilih dapat dibuka
atau tidak dengan method open(). Jika berhasil maka akan dilanjutkan,
jika tidak maka akan ditampilkan error yang terjadi dengan menggunakan
method dari database, yaitu lastError().
- Langkah berikutnya adalah melakukan query dengan menggunakan method
query(). Setelah perintah SQL dijalankan maka record-record yang
dihasilkan dari perintah select tersebut akan diloop satu persatu
dengan method next() dari query, dan ditampilkan hasilnya dilayar.

### Koneksi Qt dengan SQLite<a name="koneksi-qt-dengan-sqlite"></a>

SQLite merupakan database yang sudah disupport secara native oleh Qt.
Untuk membuat database SQLite, kita membutuhkan tool yang dapat
digunakan untuk mengelola databasenya dengan mudah, silahkan gunakan
sqliteadmin[^1]: http://www.sqliteexpert.com/ yang berbasis desktop.

Yang perlu diperhatikan ketika kita membuat koneksi dengan basisdata
SQLite adalah:

- Jika basis data SQLite akan dibuat langsung dari program, maka file
database hasil pembuatan tersebut akan berada di folder simulator pada
project kita.
- Jika kita sudah memiliki file database SQLite, maka file tersebut
harus diletakkan (dikopikan) ke folder simulator atau simulator \textfractionsolidus debug
- File SQLite yang dibuat harus berjenis SQLite 3 agar bisa diakses.

Untuk melakukan koneksi QtConsole dengan SQLite, maka lakukan Contoh
berikut:

#### Contoh Percobaan koneksi SQLite dengan QtConsole

- Buatlah sebuah database pada Sqlite dengan nama: testmhs.db, ingat
harus berjenis SQLite3.

\shadowimage[width=8cm]{sqlite-expert}

- Gunakan Sqlite Expert untuk membuatnya
- Pilih menu File >{} New Database

\shadowimage[width=8cm]{file-new-database}

- Simpan dengan nama testmhs.db (pilih tipe sqlite 3 database), simpan
pada folder project yang akan dibuat.
- Kemudian buat tabel baru dengan klik menu table >{} New Table,
kemudian isikan data berikut:

Nama tabel: mahasiswa

Field:

- NIM tipe VARCHAR(8), primary key, not null, unique
- Nama tipe VARCHAR(30), not null
- IPK tipe FLOAT

- Kemudian isi data sebagai berikut:

\begin{longtable}[]{@{}lll@{}}
\toprule
NIM & Nama & IPK\tabularnewline
\midrule
\endhead
011041 & Wachid & 3.6\tabularnewline
012042 & Arif & 3.6\tabularnewline
011012 & Eko & 3.4\tabularnewline
\bottomrule
\end{longtable}

- Setelah itu buatlah project baru pada QtConsole application, dan
tulislah kode program berikut:

\lstinputlisting[language=c++, caption=Percobaan koneksi SQLite dengan QtConsole]{../code/10-casting-database-percobaan-koneksi-sqlite-dengan-qtconsole.c++}

- Pada project, pilihlah file berekstensi .pro, kemudian bukalah file
tersebut dan tambahkanlah bagian kode berikut:

```cpp
#-------------------------------------------------
#
# Project created by QtCreator 2016-01-03T19:58:33
#
#-------------------------------------------------
QT += core
QT += gui
Qt += sql
TARGET = databases
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp
```

- Build dan run

\begin{lcverbatim}
("QSQLITE")
Koneksi berhasil
\end{lcverbatim}

**Keterangan:**

- Baris pertama output adalah daftar driver yang didukung oleh Qt dan
QtCreator.
- Baris kedua adalah menggambarkan bahwa koneksi terhadap database
Sqlite berhasil!
- Program diatas mengharuskan adanya urutan perintah yang harus
dilakukan ketika kita akan melakukan koneksi ke database Sqlite,
yaitu: 

- Load driver SQLITE Tambahkan bagian ini
- setDatabaseName sesuai dengan nama file Sqlite yang akan diakses 
- Kemudian open koneksi dengan memanggil method open 
- Jika ada error tampilkan errornya, jika tidak tampilkan bahwa koneksi berhasil

### Membaca data pada tabel SQLITE

Cara membaca data pada tabel Sqlite adalah dengan menggunakan perintah
query SQL SELECT. Sintaksnya adalah
`SELECT\ <{`field,\ field,\ field>{}\ FROM\ <{}nama_tabel>{}\ WHERE\ <{}kondisi>{}}
Perintah diatas bisa menghasilkan record atau malah salah sekali tidak
menghasilkan record apapun. Jika menghasilkan record, maka record yang
dihasilkan bisa satu atau lebih dari satu.

Pada Qt cara yang digunakan untuk membaca data adalah dengan menggunakan
class QSqlQuery dan method query seperti berikut ini:

```cpp
QSqlQuery query("SELECT * FROM mahasiswa");
while (query.next()) {
QString nim = query.value(0).toString();
qDebug() << nim;
}
```

Kita ingat bahwa tabel mahasiswa memiliki 3 kolom: NIM, Nama, dan IPK.

Perintah diatas menggunakan QsqlQuery yang menerima parameter Qstring.
Setelah query dijalankan maka akan dilakukan proses looping untuk
mengambil data-data per baris record dengan menggunakan method next()
dari query. Di dalam looping kita mengambil variabel nim pada kolom
pertama (dalam hal ini digunakan indeks 0). Untuk mengambil field
tertentu pada tabel, misalnya ipk, maka hanya perlu mengganti indeksnya
menjadi 2 saja.

#### ContohMembaca data pada Sqlite.

Tulislah program berikut:

\lstinputlisting[language=c++, caption= Membaca data pada Sqlite]{../code/10-casting-database-membaca-data-pada-sqlite.c++}

**Hasil:**

\begin{lcverbatim}
("QSQLITE")
Koneksi berhasil
true
"11041""Wachid"
"12042""Arif"
"11012""Eko"
\end{lcverbatim}

**Keterangan:**

- Program diatas melakukan koneksi ke SQLite dan kemudian mengirimkan
query untuk mengambil data-data dari tabel mahasiswa dengan
menggunakan query SQL select.
- Untuk mendapatkan hasil dari query kita gunakan perulangan dari
variabel query dan method next(). Didalam perulangan kita ambil
masing-masing nilai dari tiap-tiap kolom untuk setiap recordnya dengan
menggunakan query.value().toString()
- Perintah diatas berarti kita mengambil indeks sesuai dengan kolom yang
diambil dari SQL, yaitu kolom 0 untuk nim, 1 untuk nama dan
seterusnya.

### Menambah data pada tabel SQLITE<a name="menambah-data-pada-tabel-sqlite"></a>

Cara menambah data pada tabel Sqlite adalah dengan menggunakan perintah
query SQL INSERT. Sintaksnya adalah
`INSERT\ INTO\ <{`namatabel>{}\ (<{}kolom1>{},<{}kolom2>{},\ dst)\ VALUES\ (<{}nilai1>{},\ <{}nilai2>{}},
dst) Perintah diatas tidak menghasilkan record sama sekali, namun dapat
menghasilkan berapa jumlah record yang terpengaruh (affected rows) dan
juga mengembalikan nilai bool yang akan bernilai true atau false. Nilai
true jika menambahan data berhasil, nilai false jika penambahan data
gagal.

Pada Qt cara yang digunakan untuk menambah data adalah dengan
menggunakan class QSqlQuery dan method query seperti berikut ini:

```cpp
QSqlQuery query;
bool hasil = query.exec("INSERT INTO mahasiswa (nim, nama,ipk) VALUES
('22113344','anton', 3.4)");
if(hasil) qDebug() << "Berhasil"; else qDebug << "gagal";
```

Perintah diatas menggunakan QsqlQuery yang menerima parameter sql dalam
tipe data Qstring. Setelah query dijalankan maka akan diperiksa hasil
dari akibat penambahan datanya. Jika berhasil maka akan mengembalikan
nilai true, sedangkan jika gagal maka akan menghasilkan nilai false.

#### ContohMenambahkan data pada SQLite.

Buatlah program berikut:

\lstinputlisting[language=c++, caption= Menambahkan data pada SQLite]{../code/10-casting-database-menambahkan-data-pada-sqlite.c++}

**Hasil:**

\begin{lcverbatim}
("QSLITE")
Koneksi berhasil
Berhasil ditambahkan
\end{lcverbatim}

**Keterangan:**

- Pada awalnya data pada tabel mahasiswa hanya berjumlah 3 buah data,
ketika program dijalankan maka data baru bernama ``mhs baru'' berhasil
ditambahkan dan mengubah jumlah record pada tabel sehingga menjadi 4
buah. Tampilan perubahan adalah sebagai berikut:

| \hline
NIM | Nama | IPK |
|---|---|---|
| \hline
011041 | Wachid | 3.1 |
| \hline
012042 | Arif | 3.6 |
| \hline
011041 | Eko | 3.4 |
| \hline
012011 | Alif | 3.3 |
| \hline
013021 | Ananda | 3.8 |
| \hline |
- Cara menambahkan record pada SQLite sangat mudah, yaitu dengan
menggunakan SQL insert into yang harus disesuaikan dengan jumlah field
yang ada pada tabel. Setelah itu query akan dijalankan dengan method
exec dari obyek QsqlQuery.
- Hasil kembalian dari method exec ini adalah bool yang menghasilkan
nilai true atau false. Jika menghasilkan nilai true maka record
berhasil ditambahkan, jika false maka record tidak berhasil
ditambahkan!
- Jika program diatas dieksekusi sekali lagi (diulangi) maka akan
menampilkan tulisan Gagal ditambahkan. Hal ini dikarenakan kita
menambahkan record yang sama persis dengan ebelumnya padahal kita
sudah menset bahwa field nim bersifat primary, yang artinya tidak
boleh ada data nim yang kembar. Hal inilah yang menyebabkan data Gagal
ditambahkan.
\begin{lcverbatim}
("QSLITE")
Koneksi berhasil
gagalditambahkan
\end{lcverbatim}

- Jika kita hendak membaca data pada SQLite, maka tambahkan kode berikut:

\lstinputlisting[language=c++, caption=Membaca data pada SQLite]{../code/10-casting-database-membaca-data-pada-sqlite.c++}

- Sehingga akan dihasilkan:

\begin{lcverbatim}
"012011""Alif""3.3"
"013021""Ananda""3.8" 
"011041" "Wachid""3.1" 
"012042""Arif""3.6" 
"011012""Eko""3.4" 

\end{lcverbatim}

### Mengedit data pada tabel SQLITE<a name="mengedit-data-pada-tabel-sqlite"></a>

Cara mengedit data pada tabel Sqlite adalah dengan menggunakan perintah
query SQL UPDATE. Sintaksnya adalah
`UPDATE\ <{`namatabel>{}\ SET\ <{}kolom1>{}=<{}nilaikolom1>{},<{}kolom2>{}=<{}nilaikolom2>{}},
dst `WHERE\ <{`kriteri} Perintah diatas tidak
menghasilkan record sama sekali, namun dapat menghasilkan berapa jumlah
record yang terpengaruh (affected rows) dan juga mengembalikan nilai
bool yang akan bernilai true atau false. Nilai true jika pengeditan data
berhasil, nilai false jika pengeditan data gagal.

Pada Qt cara yang digunakan untuk mengedit data adalah dengan
menggunakan class QSqlQuery dan method query seperti berikut ini:

\lstinputlisting[language=c++, caption=menggunakan class QSqlQuery dan method query]{../code/10-casting-database-menggunakan-class-qsqlquery-dan-method-query.c++}

Perintah diatas menggunakan QsqlQuery yang menerima parameter sql dalam
tipe data Qstring. Setelah query dijalankan maka akan diperiksa hasil
dari akibat pengeditan datanya. Jika berhasil maka akan mengembalikan
nilai true, sedangkan jika gagal maka akan menghasilkan nilai false.

#### Contoh Mengedit data pada SQLite.

- Kondisi awal tabel:

| \hline
NIM | Nama | IPK |
|---|---|---|
| \hline
011041 | Wachid | 3.1 |
| \hline
012042 | Arif | 3.6 |
| \hline
011041 | Eko | 3.4 |
| \hline
012011 | Alif | 3.3 |
| \hline
013021 | \colorbox{red}{Ananda} | 3.8 |
| \hline |

Kita akan mengedit nim 013021 menjadi bernama Aryo

- Buatlah program berikut:

\lstinputlisting[language=c++, caption=Mengedit data pada SQLite]{../code/10-casting-database-mengedit-data-pada-sqlite.c++}

- **Hasil:**
\begin{lcverbatim}
("QSLITE")
Koneksi berhasil
Berhasil diedit
Jumlah record yang diedit : 1
\end{lcverbatim}
- Kondisi akhir tabel:

| \hline
013021 | Ananda | 3.8 |
|---|---|---|
| \hline
NIM | Nama | IPK |
| \hline
011041 | Wachid | 3.1 |
| \hline
012042 | Arif | 3.6 |
| \hline
011041 | Eko | 3.4 |
| \hline
012011 | Alif | 3.3 |
| \hline |

**Keterangan:**

- Program diatas masih sama menggunakan obyek QsqlQuery dan method
exec(). Hanya SQL query nya saja yang berbeda dengan Contoh sebelumnya
saat penambahan data. SQL query pada saat pengeditan menggunakan SQL
UPDATE SET.
- Untuk mengetahui berapa jumlah record yang terupdate digunakan method
numRowsAffected() dari obyek QsqlQuery.

### Menghapus data pada tabel SQLITE<a name="menghapus-data-pada-tabel-sqlite"></a>

Cara menghapus data pada tabel Sqlite adalah dengan menggunakan perintah
query SQL UPDATE. Sintaksnya adalah DELETE FROM WHERE <{}kriteri
Perintah diatas tidak menghasilkan record sama sekali, namun dapat
menghasilkan berapa jumlah record yang terpengaruh (affected rows) dan
juga mengembalikan nilai bool yang akan bernilai true atau false. Nilai
true jika penghapusan data berhasil, nilai false jika penghapusan data
gagal.

Pada Qt cara yang digunakan untuk menghapus data adalah dengan
menggunakan class QSqlQuery dan method query seperti berikut ini:

\lstinputlisting[language=c++, caption=menghapus data adalah dengan menggunakan class QSqlQuery dan method query]{../code/10-casting-database-menghapus-data-adalah-dengan-menggunakan-class-qsqlquery-dan-method-query.c++}

Perintah diatas menggunakan QsqlQuery yang menerima parameter sql dalam
tipe data Qstring. Setelah query dijalankan maka akan diperiksa hasil
dari akibat penghapusan datanya. Jika berhasil maka akan mengembalikan
nilai true, sedangkan jika gagal maka akan menghasilkan nilai false.

#### ContohMenghapus data pada SQLite.

- Kondisi awal tabel:

| \hline
NIM | Nama | IPK |
|---|---|---|
| \hline
011041 | Wachid | 3.1 |
| \hline
012042 | Arif | 3.6 |
| \hline
011041 | Eko | 3.4 |
| \hline
012011 | Alif | 3.3 |
| \hline
013021 | \colorbox{red}{Ananda} | 3.8 |
| \hline |

Kita akan menghapus data ``Ananda''.

- Buatlah program sebagai berikut:

\lstinputlisting[language=c++, caption= Menghapus data pada SQLite]{../code/10-casting-database-menghapus-data-pada-sqlite.c++}

- **Hasil:**

\begin{lcverbatim}
("QSLITE")
Koneksi berhasil
Berhasil diedit
Jumlah record yang dihapus : 1
\end{lcverbatim}

- Kondisi akhir tabel:

| \hline
NIM | Nama | IPK |
|---|---|---|
| \hline
011041 | Wachid | 3.1 |
| \hline
012042 | Arif | 3.6 |
| \hline
011041 | Eko | 3.4 |
| \hline
012011 | Alif | 3.3 |
| \hline |

**Keterangan:**

Program diatas mampu menghapus data pada suatu record tertentu dengan
menggunakan perintah SQL DELETE FROM. Program diatas tidak ada perubahan
dari Contoh sebelumnya kecuali bagian perintah SQL nya.

Demikianlah kita sudah berlatih sejumlah manipulasi data pada tabel
SQLite dengan menggunakan QtSql. Pada databse lain misalnya MySQL semua
perintah --perintah yang sudah dipelajari dapat digunakan dan hanya
perlu disesuaikan pada bagian koneksi pada databasenya. Pemrograman
basis data pada Qt termasuk mudah.

Pada bagian berikutnya kita akan mencoba membuat program untuk
memanipulasi data pada tabel mahasiswa dengan menggunakan menu. Pada
menu akan ditampilkan beberapa pilihan seperti:

- Tambah data
- Tampil data
- Hapus data
- Cari nim
- Edit data
- Exit

Penjelasan:

- Menu 1 akan digunakan untuk menambah data mahasiswa
- Menu 2 akan digunakan untuk menampilkan data semua mahasiswa
- Menu 3 akan digunakan untuk menghapus data seorang mahasiswa
berdasarkan nimnya
- Menu 4 akan digunakan untuk mencari data seorang mahasiswa berdasarkan
nimnya
- Menu 5 akan digunakan untuk mengedit data seorang mahasiswa
berdasarkan nimnya

Cara yang digunakan adalah dengan membuat sebuah class yang akan
digunakan untuk mengakses semua fungsi yang berhubungan dengan
manipulasi data pada basis data SQLite. Method pada class adalah connect
untuk koneksi database, sebuah konstruktor dan method untuk mengambil
nama tabel serta nama database SQLitenya. Kemudian akan dibuat
fungsi-fungsi lain diluar class yang digunakan untuk melakukan
fungsi-fungsi sesuai dengan 5 fungsi yang didefinisikan pada menu. Untuk
lebih jelasnya silahkan dicoba pada Contoh berikut ini.

#### ContohPembuatan manipulasi data pada SQLite dengan menggunakan menu

- Tulislah program berikut:

\lstinputlisting[language=c++, caption= Pembuatan manipulasi data pada SQLite dengan menggunakan menu]{../code/10-casting-database-pembuatan-manipulasi-data-pada-sqlite-dengan-menggunakan-menu.c++}

**Hasil:**

- Tampilan menu:

 \begin{lcverbatim}
MENU:
1. Tambah data
2. Tampil data
3. Hapus data
4. Cari nim
5. Edit data
6. Exit
Pilihan:
 \end{lcverbatim}

- Menu tambah data dan tampil data:

 \begin{lcverbatim}
 MENU:
 1. Tambah data
 2. Tampil data
 3. Hapus data
 4. Cari nim
 5. Edit data
 6. Exit
 Pilihan: 1
 NIM: 013012
 Nama: Ramadhani
 Penambahan berhasil
 Tekan sembarang tombol . . .
 \end{lcverbatim}

\begin{lcverbatim}
"NIMNamaIPK" 
"011041Wachid3.1" 
"012042Arif3.6 "
"011041Eko3.4"
"012011Alif3.3" 
"013012 Ramadhani 3.8" 
\end{lcverbatim}
- Menu hapus data dan tampil data:

 \begin{lcverbatim}
MENU:
1. Tambah data
2. Tampil data
3. Hapus data
4. Cari nim
5. Edit data
6. Exit
Pilihan: 3
NIM yang akan dihapus: 011041
Penghapusan berhasil
Tekan sembarang tombol . . .
\end{lcverbatim}
\begin{lcverbatim}
"NIMNamaIPK" 
"012042Arif3.6 "
"011041Eko3.4"
"012011Alif3.3" 
"013012 Ramadhani 3.8" 
\end{lcverbatim}
 
- Menu edit data dan tampil data: 

Mengedit 011041 menjadi bernama
Nur Wachid dan IPK menjadi 3.01

\begin{lcverbatim}
MENU:
1. Tambah data
2. Tampil data
3. Hapus data
4. Cari nim
5. Edit data
6. Exit
Pilihan: 5
NIM yang akan diedit: 011042
Nama baru: Arif H
IPK: 3.01
Tekan sembarang tombol . . .
\end{lcverbatim}

\begin{lcverbatim}
"NIMNamaIPK" 
"012042Arif H3.6 "
"011041Eko3.4"
"012011Alif3.3" 
"013012 Ramadhani 3.8" 
\end{lcverbatim}
- Menu cari data:

\begin{lcverbatim}
MENU:
1. Tambah data
2. Tampil data
3. Hapus data
4. Cari nim
5. Edit data
6. Exit
Pilihan: 4
NIM yang akan dicari: 011042
"NIMNamaIPK" 
"012042Arif H3.6 "
Tekan sembarang tombol . . .
\end{lcverbatim}
- Menu Exit

\begin{lcverbatim}
MENU:
1. Tambah data
2. Tampil data
3. Hapus data
4. Cari nim
5. Edit data
6. Exit
Pilihan: 6
Tekan sembarang tombol . . .Good bye
\end{lcverbatim}

**Keterangan:**

- Program diatas merupakan program yang cukup banyak dan kompleks.
Program ini dibuat dengan prinsip perulangan. Kita akan mengulang
terus menerus bagian menu 1-6 sampai pengguna menginputkan angka yang
bukan diantara 1-5. Jika pengguna memasukkan angka 1 maka dipanggil
menu pertama, dan seterusnya. Jika pengguna memasukkan angka 6 maka
program akan menampilkan Good Bye.
- Pada awal program kita membuat sebuah class bernama Tabel yang
digunakan untuk mengelola data-data pada tabel mahasiswa. Class Tabel
harus diinisialisasi terlebih dahulu pada method int main() dengan
mengiputkan nama database dan nama tabelnya. Setelah diinisialisai
maka class Tabel harus melakukan method connect agar database SQLite
terbuka (open).
- Ketika menu penambahan data dipilih, maka method tambahData akan
dipanggil dan membutuhkan parameter Tabel yang sudah dibuat dan
diinisialisasi terlebih dahulu sebelumnya. Setelah itu berdasarkan
obyek Tabel yang sudah dibuat, kita akan menggunakannya untuk
memasukkan data.
- Pada menu tambah, program akan meminta inputan nim, nama, dan ipk
kepada pengguna. Setelah pengguna mengiputkan data dengan lengkap,
maka method tambahData() akan dipanggil sehingga data dapat masuk ke
tabel. Proses memasukkan data dilakukan dengan menggunakan query
INSERT.
- Demikian pula dengan menu tampil data, method yang digunakan sama pada
contoh-contoh sebelumnya, namun ditambah dengan cara membaca
kolom-kolom pada tabel dan menampilkan semua recordnya satu persatu
dengan perulangan.
- Pada menu hapus data, perintah yang digunakan juga hanya mengubah
query SQLnya.
- Pada menu cari data, kita juga menggunakan SQL select seperti pada
menampilkan data. Perbedaannya hanyalah kondisi where yang digunakan.
Pada menu pencarian data, kita mencari satu buah record mahasiswa saja
berdasarkan nimnya.
- Pada menu edit data, kita juga menggunakan SQL update yang dapat
digunakan untuk mengubah data pada tabel. Pada menu edit ini, kita
mencari terlebih dahulu nim mahasiswa yang akan diedit baru
mengeditnya.

\begin{quotation}

{\LARGE \ding{46}} **TIPS:** 

Untuk
mengkonversi dari tipe data string menuju ke Qstring, digunakan
`<{`variabel\ string\ bias.c_str()} Perintah cin tidak
bisa digunakan setelah fungsi getline, karena akan membuat inputan
menjadi bertumpuk seperti pada contoh ini:

```cpp
int main(){
int id, age;
string name, address;
cout<<"Enter ID : "; cin>>id;
cout<<"Enter Name: "; getline(cin,name);
cout<<"Enter Address : "; getline(cin, address);
cout<<"Enter Age: "; cin>>age;
}
```

**Hasil:**

\begin{lcverbatim}
Enter ID: 23
Enter Name: Enter Address : Yogyakarta
Enter Age : 45
\end{lcverbatim}

Terlihat bahwa Enter Name dan Enter Address tergabung dan menjadi satu.
Untuk mencegahnya kita bisa menukar posisi bahwa cin diletakkan dibawah
getline, seperti berikut:

```cpp
int main(){
 int id, age;
 string name, address;
 cout<<"Enter Name: "; getline(cin,name);
 cout<<"Enter Address : "; getline(cin, address);
 cout<<"Enter ID : "; cin>>id;
 cout<<"Enter Age: "; cin>>age;
 }
```

**Sehingga tampilan:**

\begin{lcverbatim}
Enter Name: Yanuar Adi
Enter Address : Yogyakarta
Enter ID: 23
Enter Age: 43
\end{lcverbatim}

Jika cin tetap harus didahulukan sebelum getline, maka bisa dilakukan
dengan cara:

```cpp
int main(){
int id, age;
string name, address;
cout<<"Enter ID : "; cin>>id;
getline(cin,name);
cout<<"Enter Name: "; getline(cin,name);
cout<<"Enter Address : "; getline(cin, address);
cout<<"Enter Age: "; cin>>age;
}
```

**Sehingga tampilan:**

\begin{lcverbatim}
Enter ID : 23
Enter Name : Yanuar Adi
Enter Address : Yogyakarta
Enter Age : 32
Terimakasih.
\end{lcverbatim}
\end{quotation}

