**📋 Apa yang akan dipelajari**

Pada bab ini kita akan mempelajari tentang Tipe Data dan Identifier dalam C++:

- Pengenalan tipe data dan identifier
- Jenis-jenis tipe data dalam C++
- Variabel dan konstanta
- Operator dan ekspresi

\minitoc

## 🎯 Tipe Data dan Identifier<a name="tipe-data-dan-identifier"></a>

### Apa itu Program?

Program adalah kumpulan instruksi yang disusun dengan urutan logis yang tepat untuk menyelesaikan suatu masalah. Dalam buku ini, kita menggunakan bahasa pemrograman C++.

### Apa itu Data?

Segala sesuatu yang diproses oleh program adalah **data**. Data adalah elemen-elemen yang memiliki nilai atau besaran, misalnya:

- **Umur** - bisa berupa angka 42.5 (42½ tahun)
- **Golongan** - bisa berupa karakter 'A'
- **Nama** - bisa berupa teks "John Doe"

### Penyimpanan Data

C++ menyimpan data di memori utama untuk dikelola oleh program. Untuk mengatur penggunaan memori, C++ menggunakan konsep:

- **Tipe Data** - menentukan jenis dan ukuran data
- **Variabel** - tempat menyimpan data yang bisa berubah
- **Konstanta** - tempat menyimpan data yang tetap

### Apa itu Identifier?

Identifier (pengenal) adalah nama yang digunakan program untuk merujuk ke lokasi memori tertentu agar nilai pada lokasi tersebut dapat diakses.

#### Mengapa Perlu Identifier?

- Alamat memori sebenarnya berupa angka heksadesimal yang sulit diingat
- C++ menggunakan identifier berupa huruf atau kata sebagai label
- Dengan identifier, kita tidak perlu mengetahui alamat memori yang sebenarnya
- Identifier membuat program lebih mudah dibaca dan dipahami

## 📊 Tipe Data Bahasa C++<a name="tipe-data-bahasa-c"></a>

### Apa itu Tipe Data?

Data yang dapat dikelola program bisa bermacam-macam:

- Bilangan bulat (integer)
- Bilangan desimal (floating point)
- Karakter (character)
- Dan lainnya

### Mengapa Perlu Tipe Data?

Ketika menyimpan nilai di memori, diperlukan 2 hal:

- **Identifier** - nama untuk mengakses lokasi memori
- **Tipe Data** - menentukan jenis dan ukuran memori yang dialokasikan

### Pentingnya Tipe Data

- Sekali identifier dialokasikan dengan tipe data tertentu, ukuran ruang tidak bisa diubah
- Tipe data menentukan operasi apa yang bisa dilakukan
- Tipe data mempengaruhi efisiensi penggunaan memori

\begin{longtable}[]{@{}lll@{}}
\toprule
Tipe Data & Ukuran & Jangkauan Nilai Yang dapat Ditampung\tabularnewline
\midrule
\endhead
bool & 1 byte & True or false\tabularnewline
unsigned short int & 2 bytes & 0 to 65,535\tabularnewline
short int & 2 bytes & --32,768 to 32,767\tabularnewline
unsigned long int & 4 bytes & 0 to 4,294,967,295\tabularnewline
long int & 4 bytes & --2,147,483,648 to 2,147,483,647\tabularnewline
int (16 bit) & 2 bytes & --32,768 to 32,767\tabularnewline
int (32 bit) & 4 bytes & --2,147,483,648 to 2,147,483,647\tabularnewline
unsigned int (16 bit) & 2 bytes & 0 to 65,535\tabularnewline
unsigned int (32 bit) & 4 bytes & 0 to 4,294,967,295\tabularnewline
char & 1 byte & 256 character values\tabularnewline
float & 4 bytes & 1.2e--38 to 3.4e38\tabularnewline
double & 8 bytes & 2.2e--308 to 1.8e308\tabularnewline
\bottomrule

\end{longtable}

## 🔧 Variabel dan Konstanta<a name="variabel-dan-konstanta"></a>

### Apa itu Variabel dan Konstanta?

Nilai yang tersimpan di memori dan dikenal melalui identifier terdiri dari variabel dan konstanta.

### Perbedaan Variabel dan Konstanta

- **Variabel** - nilainya dapat diubah-ubah saat program dieksekusi
- **Konstanta** - nilainya tidak dapat diubah (tetap/konstan)

### Analoginya

- **Variabel** seperti kotak yang bisa diisi dengan barang berbeda
- **Konstanta** seperti kotak yang hanya bisa diisi dengan satu barang tertentu

Sebelum suatu variabel atau konstanta dapat digunakan, tempat pada
memori harus dipesan terlebih dahulu, mekanisme ini dinamalan deklarasi.
Deklarasi dilakukan dengan cara menuliskan tipe data (ukuran memori yang
dibutuhkan) dan diikuti dengan nama pengenal (nama variabel), jika
dikehendaki bisa juga suatu variabel langsung diinisialisasi dengan
suatu nilai. Pengenal (identifier) bisa terdiri dari sebuah huruf atau
kombinasi antara huruf dengan angka dengan syarat.

- Harus diawali dengan huruf
- Tidak boleh memakai karakter khusus kecuali $ dan garis bawah (_)
- Tidak boleh sama dengan kata kunci yang digunakan pada C++
- Bersifat case sensitif (huruf besar dan kecil dibedakan)

Walaupun demikian, sebaiknya memberikan nama pengenal variabel sesuai
dengan isi dari variabel tersebut, sebab walaupun nama variabel
``**c21i8k**'' untuk menyimpan nama mahasiswa adalah valid
(diperbolehkan), namun akan lebih mudah dimengerti jika identifier yang
dipilih adalah ``**nama**''.

Konstanta mirip dengan variabel, hanya saja nilainya konstan, tidak
dapat diubah-ubah. Untuk dapat membuat konstanta diperlukan inisialisasi
ketika konstanta dibuat dan setelah itu nilainya tidak dapat diubah. C++
mempunyai 2 macam konstanta, yaitu konstanta literal dan konstanta
simbolik. Berikut ini adalah contoh deklarasi variabel:

```cpp
int harga;
```

Yang dimaksud dengan konstanta literal adalah suatu nilai yang ditulis
pada kode program. Sebagai contoh misalnya :

```cpp
int usiaku = 42;
```

Nilai 42 tidak dapat menerima nilai lain dan nilai tersebut bersifat
tetap. Perhatikan dalam hal ini identifier ``usiaku'' adalah variabel
(bukan konstanta), yang dinamakan konstanta literal adalah nilai ``42''
tersebut.

Konstanta simbolik adalah konstanta yang direpresentasikan dengan suatu
nama, sama seperti variabel, namun berbeda dengan variabel setelah suatu
konstanta diinisialisasi dengan suatu nilai maka nilainya tidak dapat
diubah. Ada 2 cara untuk mendeklarasikan konstanta simbolik, yaitu
dengan menggunakan preprocessor directive `#define` dan yang
kedua adalah dengan memakai kata kunci `const`. Berikut ini
contoh mendeklarasikan dan menginisialisasi konstanta :

```cpp
#define kapasitas 15
```

Perhatikan bahwa `kapasitas` tidak mempunyai tipe data tertentu
(int, char dsb.). Preprosessor akan melakukan substitusi berupa teks,
setiap ada akses terhadap kata `kapasitas`, akan digantikan
dengan teks 15. Karena preprosesor bekerja sebelum kompiler, kompiler
tidak mengenal konstanta `kapasitas`, yang dikenal hanyalah
bilangan 15.

\begin{quotation}
{\LARGE \ding{46}}**TIPS** 

Walaupun
dengan memakai preprocessor directive `#define` tampak mudah,
namun sebaiknya cara ini tidak digunakan, karena sudah dinyatakan usang
pada standard C++ .
\end{quotation}
 

Cara yang kedua untuk menginisialisasi sebuah konstanta adalah dengan
memakai kata kunci const seperti berikut :

```cpp
const int usiaku = 42;
```

Contoh diatas adalah mendeklarasikan konstanta simbolik bernama usiaku
bertipe int dan diinisialisasi dengan nilai 42. Setelah baris ini simbol
(identifier) bernama usiaku tidak dapat diubah-ubah nilainya. Keuntungan
pembuatan konstanta dengan cara ini adalah lebih mudah dipelihara dan
mencegah adanya kesalahan dan yang paling penting adalah bahwa konstanta
ini mempunyai tipe data dan kompiler dapat mengharuskan konstanta ini
diperlakukan sebagai tipe data tersebut.

#### Contoh Tipe data dan Identifier.

- Buka Qt Creator dan buat project Qt Console Application baru dengan
  nama contoh [contoh2-1](#contoh2-1), kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption=Tipe data dan Identifier, label=contoh2-1]{../code/contoh2-1.cpp}

- Kemudian jalankan kode diatas dengan menekan tombol Ctrl+R, outputnya
  adalah sebagai berikut.

\begin{lcverbatim}
Panjang =15
lebar =12
\end{lcverbatim}

#### Keterangan

- Pada program di atas variabel panjang dan lebar dideklarasikan bertipe
  int.
- Kemudian variabel panjang diberi nilai 15 (integer) dan lebar diberi
  nilai 12 (integer), tampak bahwa nilai dari variabel tersebut dapat
  diubah.
- Pada baris berikutnya nilai dari variabel dapat diakses untuk dicetak
  ke layar.

## Statement<a name="statement"></a>

Dalam bahasa C++, sebuah statement mengontrol urutan pengerjaan
eksekusi, mengevaluasi ekspresi atau tidak mengejakan apapun (*null
statement*). Semua statement C++ diakhiri dengan titik koma (;), sebagai
contoh misalnya :

```cpp
x = a + b;
```

Pernyataan tersebut bukanlah suatu pernyataan persamaan aljabar dalam
matematika yang artinya x sama dengan a + b, melainkan memberi nilai x
dengan hasil penjumlahan a dengan b. Pada statement ini terjadi 2 urutan
pengerjaan, yaitu pertama menambahkan a dengan b, kemudian yang kedua
memberikan hasil perhitungan tersebut ke variabel x dengan operator
pengerjaan (=). Walaupun pada pernyataan tersebut terdapat 2 pekerjaan,
namun merupakan sebuah statement dan oleh karena itu diakhiri hanya
dengan sebuah titik koma (;) saja. Hasil penjumlahan a dengan b ini
disebut ekspresi, sedangkan sama dengan (=) dan plus (+) dinamakan
operator yang akan dibahas berikut ini.

\begin{quotation}
 {\LARGE \ding{45}} **CATATAN**
 
 Operator pengerjaan = akan mengambil nilai apapun yang ada disebelah
 kanannya kenudian memberikannya kepada apapun yang berada di sebelah
 kirinya. C++ mengenal juga operator pembanding == yang mempunyai
 arti berbeda dengan operator sama dengan =, akan dibahas lebih
 detail pada sub bab berikut ini.
\end{quotation}

## Operator dan Ekspresi<a name="operator-dan-ekspresi"></a>

Operator adalah suatu simbol yang digunakan untuk melakukan suatu
operasi. Operator mempunyai beberapa kategori, antara lain : Aritmatika,
Pengerjaan, Hubungan dan Logika. Operator Aritmatika adalah operator
yang digunakan untuk melakukan operasi aritmatika seperti misalnya
penjumlahan, pengurangan, perkalian dan pembagian. Simbol untuk operator
aritmatika ini adalah : +, -, *, / dan %. Berikut ini adalah
operator-operator yang dikenal pada bahasa pemrograman C++.

\begin{longtable}[]{@{}llll@{}}
\toprule
\begin{minipage}[b]{0.52\columnwidth}\raggedright\strut
Kategori
\strut\end{minipage} &
\begin{minipage}[b]{0.17\columnwidth}\raggedright\strut
Operator
\strut\end{minipage} &
\begin{minipage}[b]{0.14\columnwidth}\raggedright\strut
Arah Proses
\strut\end{minipage} &
\begin{minipage}[b]{0.05\columnwidth}\raggedright\strut
Jenjang
\strut\end{minipage}\tabularnewline
\midrule
\endhead
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Kurung, indeks larik dan elemen struktur data
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
() {[}{]} . ->{}
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri - Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
1
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Unary
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
! ~{} - ++ --
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kanan -- Kiri
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
2
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Aritmatika Perkalian, Pembagian dan Sisa Pembagian
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
* / %
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
3
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator aritmatika Pertambahan dan Pengurangan
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
+ -
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
4
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Bitwise Pergeseran Bit
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
<{}<{} >{}>{}
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
5
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Hubungan
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
<{} <{}= >{} >{}=
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
6
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Hubungan Kesamaan dan Ketidaksamaan
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
== !=
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
7
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Bitwise AND
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
&
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
8
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Bitwise XOR
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
^{}
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
9
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Bitwise OR
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
`|{`}
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
10
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Kondisi AND
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
&&
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
11
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Kondisi OR
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
`|{`|{}}
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
12
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Ternary ?
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
`|{`}
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kanan -- Kiri
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
13
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Pengerjaan Aritmatika
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
= += -= *= /= %=
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kanan -- Kiri
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
14
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Pengerjaan Bitwise
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
`&=\ ^{`=\ |{}=\ <{}<{}=\ >{}>{}=}
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kanan -- Kiri
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
15
\strut\end{minipage}\tabularnewline
\begin{minipage}[t]{0.52\columnwidth}\raggedright\strut
Operator Koma
\strut\end{minipage} &
\begin{minipage}[t]{0.17\columnwidth}\raggedright\strut
,
\strut\end{minipage} &
\begin{minipage}[t]{0.14\columnwidth}\raggedright\strut
Kiri -- Kanan
\strut\end{minipage} &
\begin{minipage}[t]{0.05\columnwidth}\raggedright\strut
16
\strut\end{minipage}\tabularnewline
\bottomrule
\end{longtable}

Ekspresi adalah suatu peryataan yang menghasilkan suatu nilai, bisa
berasal dari sebuah variabel maupun kumpulan variabel-variabel yang
dioperasikan dengan suatu operator, jadi hasil akhir dari suatu ekspresi
adalah suatu nilai yang mempunyai besaran dan tipe data tertentu.

Pernyataan berikut ini yang disebut ekspresi adalah 15, 12 dan ``panjang
* lebar'' yang menghasilkan nilai 15, 12 dan 180:

```cpp
panjang = 15;
lebar = 12;
luas = panjang * lebar ;
```

**Keterangan :**

- Pada baris pertama dan kedua di atas digunakan hanya sebuah operator
  `=` (yaitu jenjang ke 14), arah proses dari kanan ke kiri,
  sehingga yang dilakukan :
- Ekspresi : `15`, diberikan kepada variabel `panjang`
  (dibaca dari kanan ke kiri).
- Ekspresi : `12`, diberikan kepada variabel `lebar`
  (dibaca dari kanan ke kiri).
- Pada baris ketiga terdapat 2 operator, yaitu operator =  (jenjang
  ke 14) dan `*` operator = (yaitu jenjang ke 3).
  Jenjang menunjukkan operator yang akan dikerjakan terlebih dahulu,
  jika dalam sebuah ungkapan terdapat lebih dari satu jenis operator.
  Jenjang nomor 1 adalah jenjang yang paling tinggi, maka pada
  pernyataan di atas yang akan dikerjakan terlebih dahulu adalah orator
  `*` baru kemudian operator =, sehingga yang dilakukan:
  - Ekspresi : `panjang\ *\ lebar` , berarti `panjang`
  dikalikan `lebar` (dibaca dari kiri ke kanan), menghasilkan
  nilai integer `180`. - Berikutnya operator = mengoperasikan
  hasil ekspresi tersebut, yaitu nilai integer `180` diberikan
  kepada variabel `luas` (dibaca dari kanan ke kiri).

\begin{quotation}
{\LARGE \ding{46}} **TIPS**

Operator
( dan ) dapat dipakai untuk merubah jenjang suatu ekspresi
menjadi jenjang tertinggi, sehingga akan diproses terlebih dahulu.
\end{quotation}

###  Operator Unary<a name="a-operator-unary"></a>

Operator unary adalah operator yang hanya menggunakan sebuah operand
saja, operator unary yang dipakai pada kebanyakan bahasa pemrograman
adalah operator unary minus (-). Operator unary ditulis sebelum operand,
operator unary ``-'' berbeda dengan operator aritmatika ``-'' yang
membutuhkan dua operand. Dalam bahasa C++ disediakan bermacam-macam
operator unary.

\begin{longtable}[]{@{}ll@{}}
\toprule
Operator & Arti\tabularnewline
\midrule
\endhead
- & Unary minus\tabularnewline
++ & Peningkatan dengan nilai penambahan 1\tabularnewline
-- & Penurunan dengan nilai pengurangan 1\tabularnewline
! & Unary not\tabularnewline
~{} & Operator unary komplemen satu (bitwise
NOT)\tabularnewline
\bottomrule
\end{longtable}

### Operator Unary Minus<a name="b-operator-unary-minus"></a>

Operator ini dipakai untuk memberi nilai minus suatu nilai numerik
(bukan pengurangan). Misalnya ungkapan : `A\ +\ -\ B\ *\ C` akan
diartikan `A\ +\ (-B)\ *\ C`. Operator unary ``-'' ditulis di
depan operand.

### Operator Unary ++ dan --<a name="c-operator-unary-dan"></a>

Operator unary ``++'' dan ``--'' merupakan operator khusus yang ada di
bahasa C. Operator ``++'' akan menambahkan nilai 1 ke pengenal yang
menggunakannya sedangkan operator ``--'' akan mengurangi dengan nilai
numerik 1. Operator unary tersebut jika dituliskan sebelum operand
disebut *pre increment* sedangkan jika ditulis setelah operand
disebut *post increment*. Perhatikan perbedaannya pada contoh
dibawah ini :

\begin{longtable}[]{@{}ll@{}}
\toprule
Post Increment & Pre Increment\tabularnewline
\midrule
\endhead
x = 5; & x = 5;\tabularnewline
a = x++; & a = ++x;\tabularnewline
------------------- & ----------------\tabularnewline
**Hasil:** & **Hasil:**\tabularnewline
x = 6 dan a = 5 & x = 6 dan a = 6\tabularnewline
\bottomrule
\end{longtable}

### Operator Pengerjaan<a name="d-operator-pengerjaan"></a>

Operator pengerjaan atau disebut assignment operator, digunakan untuk
menempatkan nilai dari suatu ekspresi ke suatu pengenal. Operator yang
umum dipakai pada bahasa pemrograman adalah operator pengerjaan ``=''.
Selain operator pengerjaan ``='', bahasa C++ menyediakan beberapa
operator pengerjaan yang lain seperti tabel di bawah ini.

\begin{longtable}[]{@{}lll@{}}
\toprule
Operator & Contoh & Maksud/ Ekuivalen dengan\tabularnewline
\midrule
\endhead
= & a = b + c & Mengerjakan b+c ke a\tabularnewline
+= & a += 1 & a = a + 1\tabularnewline
-= & a -= b & a = a -- b\tabularnewline
*= & a *= b & a = a * b\tabularnewline
/= & a /= b & a = a / b\tabularnewline
%= & a %= b & a = a % b\tabularnewline
\bottomrule
\end{longtable}

Tabel berikut ini memberikan contoh pemakaian operator-operator di atas,
misalnya variabel a dan b bernilai 10.

\begin{longtable}[]{@{}lll@{}}
\toprule
Statement & Ekuivalen dengan & Hasil Ungkapan\tabularnewline
\midrule
\endhead
a += 3 & a = a + 3 & a = 10 + 3 = 13\tabularnewline
a -= 2 & a = a - 2 & a = 10 -- 2 = 8\tabularnewline
a *= b/2 & a = a * (b/2) & a = 10 * (10/2) = 50\tabularnewline
a /= b -- 8 & a = a / (j -- 8) & a = 10 / (10-8) = 5\tabularnewline
\bottomrule
\end{longtable}

Dari contoh di atas terlihat bahwa operator pengerjaan mempunyai jenjang
yang lebih rendah dibanding operator aritmatika, sehingga operator
aritmatika dikerjakan terlebih dahulu.

C++ mengijinkan operator pengerjaan ditulis lebih dari satu kali pada
sebuah statement, misalnya :

```cpp
x = y = a * b;
```

Dalam hal ini yang dikerjakan adalah a dikalikan b terlebih dahulu
meudian hasilnya diberikan kepada variabel y dan hasil ekspresi y = a *
b diberikan kepada variabel x. sehingga misalnya a bernilai 8 dan b
bernilai 7, maka baik variabel x maupun y keduanya bernilai 15.

### Operator Hubungan<a name="e-operator-hubungan"></a>

Operator hubungan (*relational operator*) digunakan untuk
menunjukkan hubungan antara dua buah operand, hasil dari operator ini
adalah True atau False.

\begin{longtable}[]{@{}lll@{}}
\toprule
Operator & Jenjang & Arti\tabularnewline
\midrule
\endhead
<{} & 6 & Lebih kecil dari\tabularnewline
<{}= & 6 & Lebih kecil atau sama dengan\tabularnewline
>{} & 6 & Lebih besar dari\tabularnewline
>{}= & 6 & Lebih besar atau sama dengan\tabularnewline
== & 7 & Sama dengan\tabularnewline
!= & 7 & Tidak sama dengan\tabularnewline
\bottomrule
\end{longtable}

Berikut ini contoh hasil ekspresi jika a bernilai 5, b bernilai 7 dan c
bernilai `a'

\begin{longtable}[]{@{}lll@{}}
\toprule
Ungkapan Hubungan & Hasil & Nilai\tabularnewline
\midrule
\endhead
a == 5 & Benar & 1\tabularnewline
a == b & Salah & 0\tabularnewline
b <{} 7 & Salah & 0\tabularnewline
a <{}= 7 & Benar & 1\tabularnewline
(a+b) != 35 & Benar & 1\tabularnewline
c != `A' & Benar & 1\tabularnewline
c <{}= `z' & Benar & 1\tabularnewline
\bottomrule
\end{longtable}

### Operator Logika<a name="f-operator-logika"></a>

Jika operator hubungan membandingkan hubungan antara dua buah operand,
maka operator logika (*logical operator*) digunakan untuk
menggabungkan logika hasil dari operator-operator hubungan. Operator
logika menggabungkan **dua buah** nilai logika. Nilai logika adalah
nilai benar (True) atau salah (False).

\begin{longtable}[]{@{}lll@{}}
\toprule
Operator & Jenjang & Arti\tabularnewline
\midrule
\endhead
&& & 11 & Logika DAN (AND)\tabularnewline
`|{`|{}} & 12 & Logika ATAU (OR)\tabularnewline
\bottomrule
\end{longtable}

Selain dua operator logika ini, operator unary "left ! "right (logika NOT) dapat digunakan untuk operasi logika.

\begin{longtable}[]{@{}lllll@{}}
\toprule
x & y & x && y & x `|{`|{}} y & !x\tabularnewline
\midrule
\endhead
TRUE & TRUE & TRUE & TRUE & FALSE\tabularnewline
TRUE & FALSE & FALSE & TRUE & FALSE\tabularnewline
FALSE & TRUE & FALSE & TRUE & TRUE\tabularnewline
FALSE & FALSE & FALSE & FALSE & TRUE\tabularnewline
\bottomrule
\end{longtable}

Contoh : Misalnya A bernilai 5, B bernilai 7 dan C bernilai "left a "right maka ungkapan dibawah ini mempunyai hasil akhir benar (True).

```cpp
A < B || B == 7 && C > 'z'
```

Hasil akhir benar (True) dari ekspresi logika tersebut didapat dari
langkah-langkah sebagai berikut:

- Jenjang operator hubungan lebih tinggi dibandingkan dengan operator
  logika, jadi operator hubungan dikerjakan terlebih dahulu.
- Operator logika ``&&'' mempunyai jenjang lebih tinggi dari operator
  ``|{}|{}'', sehingga operator ``&&'' dikerjakan
  terlebih dahulu.
- Bagian yang paling akhir dikerjakan adalah operator
  ``|{}|{}'', sehingga hasil akhir logika bernilai logika
  benar atau True.

