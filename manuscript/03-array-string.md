**📋 Apa yang akan dipelajari**

Pada bab ini kita akan mempelajari tentang Array dan String dalam C++:

- Pengenalan Array dan cara kerjanya
- Array 1 dimensi dan multi-dimensi
- String dan operasinya
- Manipulasi array dan string

\minitoc

## 📊 Array (Larik)<a name="array"></a>

### Apa itu Array?

Array adalah tipe data terstruktur yang menyimpan sejumlah data dengan tipe yang sama dalam satu nama variabel.

### Karakteristik Array

- **Tipe data sama** - semua elemen memiliki tipe data yang sama
- **Jumlah tetap** - ukuran array ditentukan saat deklarasi
- **Indeks** - setiap elemen diakses melalui indeks
- **Memori berurutan** - elemen tersusun berurutan di memori

### Analoginya

Array seperti **lemari dengan laci-laci**:

- Lemari = nama array
- Laci = elemen array
- Nomor laci = indeks array
- Isi laci = nilai elemen

### Cara Kerja Array di Memori

Array menyimpan data secara berurutan di memori komputer. Ketika array dideklarasikan, komputer mengalokasikan tempat yang berdekatan di memori.

#### Ilustrasi Array di Memori

Ilustrasi array satu dimensi pada memori komputer seperti gambar [gambar3-1](#gambar3-1).

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{Capture3-1}
<a name="gambar3-1"></a>
\caption{Ilustrasi array satu dimensi pada memori komputer}
\end{figure}

#### Karakteristik Penyimpanan

- **Berurutan** - elemen tersusun berurutan di memori
- **Berdekatan** - alamat memori yang bersebelahan
- **Jarak tetap** - jarak antar elemen sesuai ukuran tipe data
- **Indeks dimulai dari 0** - elemen pertama memiliki indeks 0

#### Contoh Ukuran Memori

- **int** - jarak antar elemen 2-4 byte
- **char** - jarak antar elemen 1 byte
- **double** - jarak antar elemen 8 byte

### 📊 Array 1 Dimensi<a name="array-1-dimensi"></a>

Array 1 dimensi adalah array yang memiliki satu indeks untuk mengakses elemennya.

#### Cara Mengakses Array

- **Berurutan** - mengakses elemen satu per satu
- **Random** - mengakses elemen berdasarkan indeks tertentu
- **Pengisian** - menyimpan nilai ke indeks tertentu
- **Pengambilan** - membaca nilai dari indeks tertentu

#### Analoginya

Array 1 dimensi seperti **deretan kotak**:

- Setiap kotak memiliki nomor (indeks)
- Kotak bisa diisi dengan barang (nilai)
- Kita bisa mengambil barang dari kotak tertentu
- Kita bisa mengisi barang ke kotak tertentu

#### Deklarasi Array 1 Dimensi<a name="deklarasi-array-satu-dimensi"></a>

#### Sintaks Deklarasi

```cpp
tipe_data nama_array[ukuran];
```

#### Komponen Deklarasi

- **tipe_data** - jenis tipe data elemen array (int, char, float, dll)
- **nama_array** - nama variabel array
- **ukuran** - jumlah maksimal elemen array

#### Contoh Deklarasi Array

```cpp
char huruf[9];
int umur[10];
int kondisi[2] = {0,1};
int arr_dinamis[] = {1,2,3};
```

#### Penjelasan Contoh

\begin{description}
- [`char huruf[9]`] 
Array karakter dengan 9 elemen (indeks 0-8), membutuhkan 9 byte memori

- [`int umur[10]`] 
Array integer dengan 10 elemen (indeks 0-9), membutuhkan 40 byte memori

- [`int kondisi[2] = {0,1\`}] 
Array integer dengan 2 elemen yang langsung diinisialisasi:

- kondisi[0] = 0
- kondisi[1] = 1

- [`int arr_dinamis[] = {1,2,3\`}] 
Array dinamis dengan ukuran otomatis berdasarkan inisialisasi (3 elemen)
\end{description}

Tanda `{[`{]}} disebut juga ``elemen yang ke- ''. Misalnya
`kondisi{[`0{]}} berarti elemen yang ke nol. Array yang sudah
dipesan, misalnya 10 tempat tidak harus diisi semuanya, bisa saja hanya
diisi 5 elemen saja, baik secara berurutan maupun tidak. Namun pada
kondisi yang tidak sepenuhnya terisi tersebut, tempat pemesanan di
memori tetap sebanyak 10 tempat, jadi tempat yang tidak terisi tetap
akan terpesan dan dibiarkan kosong.

#### Contoh  Input dan Output Array

Buatlah project baru dan tulis kode berikut:

\lstinputlisting[language=c++, caption=Input dan Output Array, label=contoh3-1]{../code/contoh2-1.cpp}

**Hasil:**
\begin{lcverbatim}
Memasukan nilai
Nilai Angka ke - 1 : 1
Nilai Angka ke - 2 : 2
Nilai Angka ke - 3 : 3
Nilai Angka ke - 4 : 4
Nilai Angka ke - 5 : 5
Membaca nilai:
Nilai Angka : 1
Nilai Angka : 2
Nilai Angka : 3
Nilai Angka : 4
Nilai Angka : 5
\end{lcverbatim}

#### Keterangan

- Pada program diatas, kita membuat sebuah variabel array bernama
  `nilai` yang berisi `5` elemen bertipe `integer`.
  Kemudian untuk memasukkan nilai ke masing-masing elemen, digunakan
  perintah perulangan untuk mengakses indeksnya yang dimulai dari indeks
  ke `0`. Perulangan dilakukan dari indeks ke `0` sampai
  dengan indeks ke `4` (dalam hal ini
  `x\ <{`\ 5}). Mengapa sampai dengan indeks ke
  `4`? Hal ini karena `5` elemen array yang kita
  deklarasikan dimulai dari indeks ke `0`. Terdapat `5`
  elemen array, berarti indeks ke `0`, `1`, `2`,
  `3`, dan `4`.
- Setelah kita masukkan nilai ke masing-masing elemen, maka kita hanya
  perlu membaca datanya lagi, yaitu dengan melakukan perulangan kembali
  dengan cara mengakses indeks elemen-elemennya seperti pada saat kita
  memasukkan elemen-elemen tersebut kedalam *array*. Perulangan
  untuk membaca isi elemen array juga diulang dari 0 sampai 4, yang
  artinya juga 5 elemen. Pada masing-masing perulangan tersebut,
  ditampilkan isi elemen ke layar dengan perintah
  `cout<{`<{}}.

#### Contoh  Manipulasi Array

Buatlah project baru dan tulis kode berikut:

\lstinputlisting[language=c++, caption=Manipulasi Array, label=contoh3-2]{../code/contoh3-2.cpp}

**Hasil:**

\begin{lcverbatim}
elemen ke-1 ? 1
bil[0] = 1 dan alamatnya: 0x28fe68
bil[1] = 5 dan alamatnya: 0x28fe6c
bil[2] = 25 dan alamatnya: 0x28fe70
bil[3] = 50 dan alamatnya: 0x28fe74
bil[4] = 40 dan alamatnya: 0x28fe78
bil[5] = 50 dan alamatnya: 0x28fe7c
bil[6] = 60 dan alamatnya: 0x28fe80
\end{lcverbatim}

#### Keterangan

- Program [contoh3-2](#contoh3-2) memasukkan nilai-nilai integer kedalam array bernama
  bil yang berisi `7` elemen (dari indeks `0-6`).
- Dalam array satu dimensi, suatu elemen array dapat diisi dengan isi
  elemen array pada indeks tertentu seperti pada contoh
  `bil{[`2{]}\ =\ bil{[}1{]}\ +\ 20;}. Pada contoh [contoh3-2](#contoh3-2),
  `bil{[`2{]}} diisi dengan `bil{[`1{]}} yang berisi
  `25` ditambah dengan `20`, yaitu `55`.
- Pada program `bil{[`3{]}\ =\ bil{[}bil{[}1{]}{]}}, artinya
  bilangan elemen ke-3 diisi dengan elemen array yang ke --
  `bil{[`1{]}}. Bilangan elemen ke-1, bernilai 5, yang berarti
  `bil{[`3{]}\ =\ bil{[}5{]}}. `Bil{[`5{]}} bernilai
  `50`, berarti `bil{[`3{]}\ =\ 50} juga.
- Terlihat bahwa jarak antar elemen array `bil` berjarak
  `4\ bytes`.
- Cara untuk menampilkan alamat *array* adalah dengan menggunakan
  operator `&`.

\begin{quotation}
{\LARGE \ding{46}} **TIPS** 

Dalam
bahasa C++, tidak terdapat *error handling* terhadap batasan nilai
indeks, apakah indeks tersebut berada di dalam indeks array yang sudah
didefinisikan atau belum. Hal ini merupakan tanggung jawab programmer.
Sehingga jika programmer mengakses indeks yang salah, maka nilai yang
dihasilkan akan berbeda atau rusak karena mengakses alamat memori yang
tidak sesuai.
\end{quotation}
 

#### Contoh  Penanganan Batas Indeks Elemen Array

Buatlah program beikut ini:

\lstinputlisting[language=c++, caption=Penanganan Batas Indeks Elemen Array, label=contoh3-3]{../code/contoh3-3.cpp}

#### Hasil dan Keterangan.

- Progarm akan HANG-UP. Hal ini terjadi karena compiler tidak
  bertanggungjawab dengan pengaksesan indeks array yang melebihi batas
  yang dipesankan di memory.
- Mengapa kompiler tidak menampilkan error pada saat kompilasi? Hal ini
  karena secara sintaks, program diatas tidaklah memiliki error
  penulisan. Error yang terjadi pada program diatas adalah runtime
  error, yaitu error yang terjadi / yang bisa dideteksi saat program
  sudah berjalan!

### Inisialisasi Array Satu Dimensi<a name="inisialisasi-array-satu-dimensi"></a>

Array satu dimensi dapat diisi secara langsung ditulis pada program.
Pengisian data seperti itu sering disebut dengan inisialisasi data
array. Cara menginisialisasi data pada array adalah dengan menuliskannya
secara langsung pada source code program. Berikut contohnya:

```cpp
// An array of 5 integers, all elements initialized to 0
int IntegerArray[5] = {0};
```

Pada contoh diatas, semua elemen array bertipe integer yang berjumlah 5
buah tersebut diisi dengan nilai 0 semuanya. Cara lain menginisialisasi
array satu dimensi adalah sebagai berikut:

```cpp
// An array of 5 integers initialized to zero
int IntegerArray[5] = { 0, 0, 0, 0, 0 };
```

Nah, bagaimana jika kita ingin menginisialisasi elemen terakhirnya saja?
Kita tidak bisa melakukannya secara langsung. Yang harus dilakukan
adalah dengan menginisialisasinya satu-persatu seperti contoh berikut:

```cpp
// An array of 5 integers initialized to zero
int IntegerArray[5] = { 0, 0, 0, 0, 6 };
```

Pada contoh diatas, elemen terakhir diinilisasi dengan nilai 6. Kita
tidak bisa langsung mengisi dengan cara
`int\ IntegerArray{[`5{]}\ =\ {6}}, karena jika di isi dengan
cara demikian, maka isi elemen indeks ke-0 bernilai 6, sedangkan elemen
lainnya bernilai 0.

#### Contoh  Inisialisasi Array dengan nilai \{0}

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Inisialisasi Array dengan nilai \{}0, label=contoh3-4]{../code/contoh3-4.cpp}

**Hasil:**

\begin{lcverbatim}
Elemen ke-0: 0
Elemen ke-1: 1
Elemen ke-2: 2
Elemen ke-3: 3
Elemen ke-4: 4
Elemen ke-5: 5
Elemen ke-6: 6
\end{lcverbatim}

#### Keterangan

Pada program diatas elemen array bernama bil yang dipesan sebanyak 7
elemen, di inisialisasi dengan nilai 0. Setelah di inisialisasi dengan
nilai 0, maka semua elemen array tersebut juga akan berisi dengan nilai
0. Hal ini dibuktikan dengan cara perulangan semua elemen array dan
ditampilkan dengan `cout`.

#### Contoh  Inisialisasi Array dua nilai elemen pertama

Buka Qt Creator dan buat project Qt Console Application baru dengan
nama contoh [contoh3-1](#contoh3-1), kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption=Inisialisasi Array dua nilai elemen pertama, label=contoh3-5]{../code/contoh3-5.cpp}

**Hasil:**

\begin{lcverbatim}
Elemen ke-0: 2
Elemen ke-1: 5
Elemen ke-2: 0
Elemen ke-3: 0
Elemen ke-4: 0
Elemen ke-5: 0
Elemen ke-6: 0
\end{lcverbatim}

#### Keterangan

Inisialisasi elemen array dapat dilakukan hanya pada dua elemen pertama
saja, hal ini dilakukan dengan cara memberikan dua nilai pertama,
selanjutnya semua elemen lainnya yang tidak di inisialisasi secara
otomatis bernilai 0.

\begin{quotation}
{\LARGE \ding{46}} **TIPS**

Untuk
semua array pada C++, inisialisasi satu buah elemen saja pada array akan
membuat semua elemen array lainnya berisi nilai 0.
\end{quotation}
 

**Contoh:**

```cpp
int angka[100] = {1};
```

Maka hasilnya adalah:

```cpp
angka[0] = 1,
angka[1] s/d angka[99] = 0
```

Pada array satu dimensi, kita tidak dapat melakukan inisialisasi pada
array melebihi batas jumlah elemen array yang dipesan.

Pada array satu dimensi, kita juga dapat membuat array 1 dimensi tanpa
menyebutkan jumlah elemen array yang dipesan. Namun perlu di ingat bahwa
semua elemen harus di inisialisai terlebih dahulu.

Contoh:

```cpp
int data[5] = {1,2,3,4,5,6}; //error
int data2[] = {10,20}; //terpesan 2 tempat dimemory
```

#### Contoh  Tanpa inisialisasi, array langsung ditampilkan

Tulislah program berikut ini:

\lstinputlisting[language=c++, caption=Tanpa inisialisasi array langsung ditampilkan, label=contoh3-6]{../code/03-array-string-contoh3-6.c++}

**Hasil:**

\begin{lcverbatim}
Elemen ke-0: 2
Elemen ke-1: 5
Elemen ke-2: 0
Elemen ke-3: 0
Elemen ke-4: v
\end{lcverbatim}

#### Keterangan

Pada program C++, elemen array yang sudah dipesan dimemory pasti sudah
berisi data. Namun nilai datanya bersifat acak. Sehingga jika kita
mendeklarasikan sebuah elemen array tanpa di inisialisasi, maka nilai
masing-masing elemen akan bersifat acak juga seperti pada hasil program
diatas. Untuk itulah inisialisasi elemen array sangatlah penting.

\begin{quotation}
{\LARGE \ding{46}}  **TIPS**
 
 Inisialisasi pada elemen array yang dideklarsikan **SANGATLAH
 PENTING** untuk menghindari nilai **ACAK**!
\end{quotation}

#### Contoh  Penggunaan tipe data enum pada Array satu dimensi

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Penggunaan tipe data enum pada Array satu dimensi, label=contoh3-7]{../code/03-array-string-contoh3-7.c++}

**Hasil:**

\begin{lcverbatim}
Nilai hari selasa adalah = 30
\end{lcverbatim}

#### Keterangan.

Pada program diatas, kita membuat sebuah tipe data enum bernama Hari
yang memiliki 7 elemen. Masing-masing elemen `enum` sama saja
seperti indeks array yaitu `0-6`. Kemudian kita membuat sebuah
array bernama `ArrayHari` yang berisi 7 elemen juga dan berisi
nilai `10-70`. Karena kita memanggil 

`ArrayHari{[`Selasa{]}} berarti sama artinya dengan
`ArrayHari{[`2{]}}. Mengapa 2? Karena indeks Selasa adalah 2.
Sehingga muncullah output berupa 30, karena 30 berada pada indeks ke-2
dari `ArrayHari`.

Arti dari program diatas menunjukkan kita dapat mengakses indeks
*array* dengan menggunakan `tipe\ data\ enum`, karena tipe
data `enum` pada kenyataannya akan dikonversikan kedalam nilai
`integer`, mulai dari `0`.

### Pengalamatan dan Pengkopian Array 1 Dimensi<a name="pengalamatan-dan-pengkopian-array-1-dimensi"></a>

Array tidak bisa disalin begitu saja antara array satu yang ada nilainya
ke array lain yang kosong. Hal ini dikerenakan array bukanlah tipe data
primitif biasa. Array merupakan tipe data referensi dimana data yang
berada didalam elemen array berjumlah lebih dari satu buah dan diakses
dengan menggunakan alamat memory. Compiler C++ akan mencatat alamat
pertama dari indeks pertama array yang kita deklarasikan.

Contoh:

```cpp
int data[5] = {1,2,3,4,5};
```

Maka variabel array data tersebut akan dicatat alamat elemen
`data{[`0{]}} pada memory. Jika kita mengakses elemen keduanya,
yaitu `data{[`1{]}}, maka compiler akan melakukan kalkulasi untuk
mendapatkan alamat `data{[`1{]}}, yaitu dengan cara menambahkan
alamat `data{[`0{]}} dengan lebar tipe data array yang kita
deklarasikan. Pada contoh diatas, kita membuat array bertipe integer.
Karena integer berukuran 4 byte, maka jika `data{[`0{]}}
beralamat di alamat `1000`, maka `data{[`1{]}} beralamat
di `1000\ +\ 4\ =\ 1004` dan seterusnya.

Lalu bagaimana cara mengkopikan isi elemen array dari satu variabel ke
variable array 1 dimensi lainnya? Kita harus menggunakan cara manual,
yaitu mengkopikan masing-masing elemennya satu persatu dengan perulangan
manual sesuai dengan jumlah elemen array yang dibuat.

#### Contoh  Percobaan Penyalinan Array 1 dimensi

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Percobaan Penyalinan Array 1 dimensi, label=contoh3-8]{../code/03-array-string-contoh3-8.c++}

**Hasil:**

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{Capture3-8}

\end{figure}

#### Keterangan

Program tidak bisa dijalankan karena terdapat **error**, bahwa
array tidak bisa dilakukan operasi assigment. Artinya kita tidak bisa
mengkopi antar array begitu saja.

#### Contoh  Penyalinan Array 1 dimensi dengan Perulangan

Buatlah program berikut ini:

\lstinputlisting[language=c++, caption=Penyalinan Array 1 dimensi dengan Perulangan, label=contoh3-9]{../code/03-array-string-contoh3-9.c++}

**Hasil:**

\begin{lcverbatim}
1
2
3
4
5
6
\end{lcverbatim}

#### Keterangan

- Cara penyalinan array adalah dengan melakukan perulangan sebanyak
  elemen array yang akan disalin dan menyalinnya secara manual
  satu-persatu pada indeks yang sama.
- Kemudian ditampilkan sesuai dengan indeksnya. Elemen array yang
  dikopikan masih tetap memiliki array yang asli. Untuk menghapusnya,
  maka harus dilakukan secara manual.

### Array Multi Dimensi<a name="array-multi-dimensi"></a>

Array multi dimensi berarti array yang kita deklasaikan dapat
dikembangkan ke array dimensi 2 dan seteruanya. Array multi dimensi
merupakan topik yang menarik dalam matematika. Setiap dimensi dalam
array direpresentasikan sebagai sub bagian dalam array. Oleh karena itu,
array dua dimensi array memiliki dua sub bagian, sebuah array
tiga-dimensi memiliki tiga sub bagian dan sebagainya. Sebuah contoh
bentuk nyata yang baik dari array dua dimensi adalah sebuah papan catur.
Satu dimensinya merupakan delapan baris, sedangkan dimensi lainnya
merupakan delapan kolom.

Contoh deklarasi array dua dimensi yang menggambarkan papan catur
adalah:

```cpp
int papan[8][8];
```

yang digambarkan dalam bentuk gambar [fig:gambar3-2](#fig:gambar3-2).

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{Capture3-11}
\caption{Contoh deklarasi array dua dimensi yang menggambarkan papan catur}
<a name="fig:gambar3-2"></a>
\end{figure}

Array dua dimensi sering kali digambarkan/dianalogikan sebagai sebuah
matriks atau bentuk grid. Jika array berdimensi satu hanya terdiri dari
1 baris dan banyak kolom, array berdimensi dua terdiri dari banyak baris
dan banyak kolom yang bertipe sama. Ilustrasi array dua dimensi dapat
dilihat sebagai berikut.

Berikut adalah gambar array berdimensi (baris x kolom = 3 x 4)

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{Capture3-12}
<a name="gambar3-3"></a>
\caption{array dimensi 3 x 4}
\end{figure}

### Deklarasi Array Dua Dimensi<a name="deklarasi-array-dua-dimensi"></a>

```cpp
tipe_data nama_var_array[batas_baris][batas_kolom];
```

**Contoh:**

```cpp
int matriks[3][4];
int matriks2[3][4] = { {5,20,1,11}, {4,7,67,-9}, {9,0,45,3} };
```

Array dua dimensi dapat mewakili bentuk suatu matriks, contoh matriks:

$x=
\begin{bmatrix}
8 &5& 9 & 6 & 

8 & 2 & 1 & 0
\end{bmatrix}$

selanjutnya dapat dideklarasikan sebagai berikut:

```cpp
int x[2][4];
```

atau diklarasikan dengan langsung menginisialisasi nilai
elemen-elemen-nya sebagai berikut:

```cpp
int x[2][4]= {{8, 5, 9, 8},{8, 2, 1, 0}}
```

Selanjutnya larik dua dimensi x dapat digambarkan sebagai berikut:

```cpp
x[0][0]=8 x[0][1]=5 x[0][2]=9 x[0][3]=8
x[1][0]=8 x[1][1]=2 x[1][2]=1 x[1][3]=0
```

Array dua dimensi dapat digunakan untuk menampung tipe data numerik atau
non numerik.

Berikut adalah berbagai bentuk pembuatan array dua dimensi dengan tipe
data numerik ataupun non numerik.

Array dua dimensi bertipe data numerik

```cpp
int matriks[3][5] = {{5,12,17,10,7},
{15,6,25,2,19},
{4,9,20,22,11}};
```

Jika data array integer yang diinputkan kurang dari deklarasi

```cpp
int matriks[3][5] = {{5,12,17,10,7},
{15,6,25,2,19},
{4,9 }}; //kurang 3 angka
```

Maka tiga data yang kurang akan diisi dengan angka 0

Array 2 dimensi dapat juga digunakan untuk menyimpan data karakter
(character). Pendeklarasian array 2 dimensi character adalah sebagai
berikut:

```cpp
char matriks[3][5] = {{'A','B','C','D','E'},
{'F','G','H','I','J'},
{'K','L','M','N','O'}};
char matriks[3][5] = {"ABCDE",
"FGHIJ",
"KLMNO"};
```

Akan ditampilkan sebagai:

| \hline
A | B | C | D | E |
|---|---|---|---|---|
| \hline
F | G | H | I | J |
| \hline
K | L | M | N | O |
| \hline |

Array 2 dimensi juga dapat dideklarasikan sebagai berikut:

```cpp
char matriks[5][12] = {"Jakarta",
"Bandung",
"Surabaya",
"Semarang",
"Yogyakarta"};
```

Array diatas akan ditampilkan sebagai:

| \hline
J | a | k | a | r | t | a | \{0} |  |  |  |
|---|---|---|---|---|---|---|---|---|---|---|
| \hline
B | a | n | d | u | n | g | \{0} |  |  |  |
| \hline
S | u | r | a | b | a | y | a | \{0} |  |  |
| \hline
S | e | m | a | r | a | n | g | \{0} |  |  |
| \hline
Y | o | g | y | a | k | a | r | t | a | \{0} |
| \hline |

Jika jumlah nilai character lebih banyak daripada deklarasi

```cpp
char matriks2[2][2] = {'a','b','c','d','e'};
```

{\LARGE \ding{55}}  Akan terjadi ERROR!

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{Capture3-10}

\end{figure}

Jika data array character yang diinputkan kurang dari deklarasi

```cpp
char matriks[3][5] = {{'a','b','c','d','e'},
{'f','g','h','i','j'},
{'k','l' }}; //kurang 3 karakter
```

Maka tiga data yang kurang akan diisi dengan karakter NULL atau `\{}0'

Jika data array integer yang diinputkan lebih dari deklarasi

```cpp
int matriks[3][5] = {{5,12,17,10,7},
{15,6,25,2,19},
{4,9,20,22,11,14,19 }}; //lebih 2 angka
```

{\LARGE \ding{55}} Matriks yang jumlah datanya lebih akan menyebabkan ERROR

\begin{figure}
\centering
\shadowimage[width=8cm]{Capture3-9}
\end{figure}

Array 2 dimensi juga dapat dideklarasikan secara dinamis. Dinamis bisa
dilakukan pada baris array 2 dimensi. Namun kita tidak bisa
mendeklarasikan array 2 dimensi secara dinamis pada kolom. Contoh
pendeklarasian baris dinamis adalah :

```cpp
int matriks[][5] = {{5,12,17,10,7},
{15,6,25,2,19},
{4,9,20,22,11}};
```

Akan ditampilkan sebagai:

| \hline
5 | 12 | 17 | 10 | 7 |
|---|---|---|---|---|
| \hline
15 | 6 | 25 | 2 | 19 |
| \hline
4 | 9 | 20 | 22 | 11 |
| \hline |

Contoh matriks dengan deklarasi baris dinamis lainnya:

```cpp
int matriks[][5] = {5,12,17,10,7,
15,6,25,2,19,
4,9,20,22,11,77,88,99};
```

Pada contoh diatas, jika kita hitung jumlah datanya adalah 18 buah,
padahal jika kita bagi per lima kolom, maka data 18 akan lebih 3 buah
(18/5 = 3). Sehingga secara otomatis terdapat 3 baris dan sisa 3 buah
data berikutnya akan membuat baris baru. Array dua dimensi tersebut akan
ditampilkan sebagai:

| \hline
5 | 12 | 17 | 10 | 7 |
|---|---|---|---|---|
| \hline
15 | 6 | 25 | 2 | 19 |
| \hline
4 | 9 | 20 | 22 | 11 |
| \hline
77 | 88 | 99 | 0 | 0 |
| \hline |

#### Pengaksesan Array 2 Dimensi<a name="pengaksesan-array-2-dimensi"></a>

Pengaksesan elemen-elemen array 2 dimensi dilakukan dengan cara
perulangan. Perulangan yang dilakukan harus disesuaikan dengan jumlah
dimensinya. Maka array 2 dimensi berarti perulangan yang dilakukan harus
dua kali. Terdapat outer loop yang digunakan untuk mengakses baris array
2 dimensi, dan inner loop yang digunakan untuk mengakses kolom array 2
dimensi.

#### Contoh  Deklarasi dan Menampilkan Array 2 Dimensi

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Deklarasi dan Menampilkan Array 2 Dimensi, label=contoh3-10]{../code/03-array-string-contoh3-10.c++}

**Hasil:**

\begin{lcverbatim}
51217107
15625219
4 91 52
\end{lcverbatim}

#### Keterangan

Program diatas mendeklarasikan sebuah variabel array 2 dimensi bernama
matriks berukuran 3 baris dan 5 kolom. Kemudian matriks tersebut
langsung diinisialisasi dengan data integer sejumlah 15 data. Setelah
diinisialisasi kemudian dilakukan pengaksesan terhadap array 2 dimensi
tersebut dengan cara melakukan dua buah perulangan. Perulangan pertama
disebut outer loop yang digunakan untuk mengakses indeks baris variabel
matriks, sedangkan perulangan kedua disebut inner loop yang digunakan
untuk mengakses indeks kolom variabel matriks. Kemudian untuk
menampilkan data nya digunakan perintah cout dan untuk setiap data
elemen array diberikan karakter tab yang digunakan untuk memberi jarak
antar output data. Karakter tab pada bahasa C menggunakan escape
character `\{}t'.

#### Contoh  Penyalinan Array 2 Dimensi ke Array 2 Dimensi lainnya

Misalkan terdapat array 2 dimensi sebagai berikut
matriks`{[`3{]}{[}5{]}}

| \hline
1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|
| \hline
6 | 7 | 8 | 9 | 10 |
| \hline
11 | 12 | 13 | 14 | 15 |
| \hline |

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Penyalinan Array 2 Dimensi ke Array 2 Dimensi lainnya, label=contoh3-11]{../code/03-array-string-contoh3-11.c++}

**Hasil:**

\begin{lcverbatim}
12345
678910
1112131416
\end{lcverbatim}

#### Keterangan

Program diatas menyalin data dari matriks 2 dimensi ke matriks 2 dimensi
lainnya dengan menggunakan perulangan bertingkat. Perulangan bertingkat
memiliki 2 buah loop, yang pertama (*outer loop*) digunakan untuk
mengakses baris matriks, dan inner loop digunakan untuk mengakses kolom
matriks. Kemudian untuk masing-masing elemen matriks dimasukkan kedalam
variabel array matrikshasil tepat pada baris dan kolom yang sesuai.

#### Contoh  Penyalinan array 2 dimensi ke dalam array 1 dimensi.

Buatlah program berikut ini:

\lstinputlisting[language=c++, caption=Penyalinan array 2 dimensi ke dalam array 1 dimensi, label=contoh3-12]{../code/03-array-string-contoh3-12.c++}

**Hasil:**

\begin{lcverbatim}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
\end{lcverbatim}

#### Keterangan

- Untuk menyalin array 2 dimensi ke 1 dimensi, maka harus diperlukan
  sebuah array 1 dimensi baru yang berukuran total sesuai dengan hasil
  perkalian antara ukuran baris matriks dua dimensi dikalikan kolomnya.
  Misal array 2 dimensi berukuran 3 x 5, maka harus dibuat array 1
  dimensi berukuran minimal 15.
- Kemudian untuk mengkopikan dari array 2 dimensi matriks ke array 1
  dimensi matrikshasil, harus dilakukan perulangan sesuai dengan baris
  dan kolom matriks. Indeks array matrikshasil diperoleh dari penambahan
  nilai counter yang diinisialisasi dari -1, dan berjalan mulai dari 0
  sampai dengan 14.

### Akses Array 2 dimensi
 
Cara Pengaksesan Array dapat dilakukan dengan 2 cara:

- Pengaksesan Baris demi Baris

Cara ini menelusuri elemen array dua dimensi per dimulai dari baris
pertama lalu kekanan sesuai dengan jumlah kolomnya. Setelah eleman dalam
baris tersebut habis, maka penelusuran akan berganti baris ke baris
berikutnya dan demikian seterusnya. Cara ini membutuhkan 2 buah loop,
dimana outer loop digunakan untuk mengakses indeks baris, dan inner loop
digunakan untuk mengakses indeks kolom.

Berikut adalah contohnya:

\lstinputlisting[language=c++, caption=Pengaksesan Baris demi Baris, label=contoh3-13]{../code/03-array-string-contoh3-13.c++}

**Hasil:**

\begin{lcverbatim}
1 2 3
4 5 6
\end{lcverbatim}

- Pengaksesan Kolom demi Kolom

Cara ini menelusuri elemen array dua dimensi per dimulai dari kolom
pertama lalu kebawah sesuai dengan jumlah barisnya. Setelah eleman dalam
kolom tersebut habis, maka penelusuran akan berganti kolom ke kolom
berikutnya dan demikian seterusnya. Cara ini membutuhkan 2 buah loop,
dimana outer loop digunakan untuk mengakses indeks kolom, dan inner loop
digunakan untuk mengakses indeks baris.

**Contoh:**

\lstinputlisting[language=c++, caption=Pengaksesan Kolom demi Kolom, label=contoh3-14]{../code/03-array-string-contoh3-14.c++}

**Hasil:**

\begin{lcverbatim}
1 4
2 5
3 6
\end{lcverbatim}

## String<a name="string"></a>

\index{String}String adalah kumpulan dari nilai-nilai karakter yang berurutan dalam
bentuk satu dimensi, nilai string ini haruslah ditulis didalam tanda
petik dua (") misalnya: ``ini string''. Suatu nilai string disimpan di
memori dengan diakhiri oleh nilai ``\{}''0(null), misalnya nilai string
``ANTO'' disimpan dimemori dalam bentuk

| \hline
A | N | T | 0 | \{0} |
|---|---|---|---|---|
| \hline |

Dengan mengetahui nilai string diakhiri oleh nilai `\{}0', maka akhir
nilai dari suatu string dapat dideteksi.

Untuk mendeklarasikan sebuah string terdapat dua cara:

- Menggunakan \index{array of character}array of character yang sering disebut 
  \index{C-style}C-style string
- Menggunakan tipe data string pada C++

### Array of Character<a name="array-of-character"></a>

Cara menggunakan array of character sama seperti mendeklarasikan
variabel bertipe array namun bertipe data character seperti yang sudah
dijelaskan pada bagian-bagian sebelumnya. Array of character memiliki
sifat-sifat array lainnya yaitu bersifat statis dan letaknya berurutan
di dalam memory komputer. String berjenis array of character selalu
dibuat dengan menggunakan array satu dimensi yang dapat terdiri dari
karakter-karakter yang ditulis dengan menggunakan tanda petik tunggal
(') atau satu kesatuan string yang ditulis dengan tanda petik ganda
('').

#### Contoh pendeklarasian array of character

```cpp
char nama[6]; //tanpa inisialisasi
char nama2[6] = "anton"; //langsung diinisialisasi
char nama2[6] = {'a','n','t','o','n'}; //langsung diinisialisasi
```

Pada sebuah string, terdapat karakter `\{`0} yang
dapat digunakan untuk mengetahui kapan berakhirnya suatu string. Berikut
adalah contoh penggunaaanya.

#### Contoh  Penggunaan karakter \{0}

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Penggunaan karakter \{0, label=contoh3-15]{../code/03-array-string-contoh3-15.c++}

**Hasil:**

\begin{lcverbatim}
String
\end{lcverbatim}

#### Keterangan

Program diatas dapat mengetahui kapan berakhirnya suatu string, dalam
arti kita dapat mengetahui panjang suatu string dengan melakukan
perulangan untuk setiap karakter yang ada pada array sampai ditemukannya
katakter `\{}0'.

#### Contoh  String tanpa karakter \{0}

Buatlah program berikut:

\lstinputlisting[language=c++, caption=String tanpa karakter \{0, label=contoh3-16]{../code/03-array-string-contoh3-16.c++}

**Hasil:**

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{Capture2-7}

\end{figure}

#### Keterangan

Terlihat bahwa kita tidak bisa membuat array fa character tepat sesuai
dengan jumlah karakter yang kita inisialisasikan. Jika dilihat kata
``String'' berjumlah 6 huruf, sedangkan kita sudah mendeklarasikan
variabel `string{[`6{]}} namun ternyata jumlah elemennya masih
dianggap terlalu sedikit. Hal ini terjadi karena minimal kita harus
mengalokasikan sejumlah 7 buah elemen. Elemen ke-7 digunakan untuk
menyimpan tanda akhir string atau karakter \0 tersebut.

#### Contoh  Mengisi Array of Character

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Mengisi Array of Character, label=contoh3-17]{../code/03-array-string-contoh3-17.c++}

**Hasil:**
\begin{lcverbatim}
Isi data string: Wachid
hasil data string: Wachid
\end{lcverbatim}

#### Keterangan

- Pada program diatas kita mendeklarasikan variabel array of string
  bernama buffer yang berukuran 6 elemen. Variabel buffer diatas
  merupakan variabel berjenis string C-style yang diinisialisasi dengan
  karakter \{0} atau karakter\index{NULL} NULL.
- Problem lainnya adalah jika kita menginputkan data string yang
  mengandung spasi, maka cin hanya akan membaca data string sebelum
  spasi saja.

**Contoh:**

```cpp
Isi data string: Nur Wachid
hasil data string: Wachid
```

#### Contoh  Pengisian variabel array of character dengan maksimum jumlah karakter.

Tulislah program berikut:

\lstinputlisting[language=c++, caption=Pengisian variabel array of character dengan maksimum jumlah
karakter, label=contoh3-18]{../code/03-array-string-contoh3-18.c++}

**Hasil:**
\begin{lcverbatim}
Isi data string: Nur Wachid
hasil data string: Nur Wachid
\end{lcverbatim}

#### Keterangan

Pada contoh program diatas, kita menggunakan perintah
`cin.get(buffer,49)`. Perintah diatas ``memaksa'' agar perintah
`cin` mengambil semua data inputan ke dalam variabel buffer
sampai sejumlah 49 karakter. Jika karakter yang diinputkan lebih dari 50
karakter, maka otomatis karakter yang disimpan kedalam variabel buffer
hanyalah berjumlah 50 karakter pertama saja.

## Fungsi-fungsi String<a name="fungsi-fungsi-string"></a>

Bahasa C++ menggunakan fungsi-fungsi pustaka yang disediakan untuk
mengoperasikan suatu nilai string yang dimasukkan dalam file header
string.h. Beberapa fungsi string yang terdapat pada header string.h
adalah sebagai berikut:

```cpp
strlen()
```

Berfungsi untuk menentukkan panjang suatu nilai string.

Bentuk umum:
`int\ strlen(<{`identifier\ string>{});}

```cpp
length()
```

Berfungsi untuk menentukan panjang suatu nilai tipe data class string

Bentuk umum method:
`<{`nama_var_string>{}.length();}

#### Contoh  Penggunaan fungsi strlen()

Buatlah program berikut ini:

\lstinputlisting[language=c++, caption=Penggunaan fungsi strlen(), label=contoh3-19]{../code/03-array-string-contoh3-19.c++}

**Hasil:**

\begin{lcverbatim}
Masukkan kalimat apapun
yang anda sukai (max 100 huruf): Nur Wachid 
panjang huruf adalah: 10 karakter
\end{lcverbatim}
 

#### Keterangan

Fungsi strlen menerima satu parameter yang hanya bertipe array of
character. Fungsi ini tidak bisa menerima parameter berupa tipe data C++
string.

#### Contoh  Penggunaan fungsi length pada tipe data string C++

Buatlah program berikut ini:

\lstinputlisting[language=c++, caption=Penggunaan fungsi length pada tipe data string C++, label=contoh3-20]{../code/03-array-string-contoh3-20.c++}

**Hasil:**

\begin{lcverbatim}
Masukkan kalimat apapun yang anda sukai
(max 100 huruf): Nur Wachid 
panjang huruf adalah: 10 karakter
\end{lcverbatim}
 

#### Keterangan

- Program diatas tidak menggunakan array of character, melainkan
  menggunakan tipe data C++ `class\ string`. Tipe data ini
  spesial karena berupa tipe data object oriented. Untuk menggunakan
  tipe data ini kita harus menginclude-kan
  `#include\ <{`string>{}} pada bagian
  *preprocessor directive*.
- Kemudian untuk mengakses panjang karakternya digunakan method (fungsi)
  dari object string bernama `length()`. Fungsi `length`
  sama dengan fungsi `strlen` yaitu mengambil jumlah karakter
  dalam string tersebut.

### strcpy() dan strncpy()<a name="strcpy-dan-strncpy"></a>

Dalam bahasa C++, untuk menyalin nilai suatu string tidak dapat langsung
menuliskannya seperti halnya kompiler lain, sehingga proses menyalin
atau mengerjakan suatu nilai string ke variabel string yang lain
diperlukan suatu fungsi pustaka yang bernama `strcpy()`.

- Bentuk umum:
  `void\ strcpy(<{`stringhasil>{},<{}stringsumber>{});}
- Bentuk umum:
  `void\ strncpy(<{`stringhasil>{},<{}stringsumber>{});}

#### Contoh  Penggunaan fungsi strcpy()

Buatlah program berikut ini:

\lstinputlisting[language=c++, caption=Penggunaan fungsi strcpy(), label=contoh3-21]{../code/03-array-string-contoh3-21.c++}

**Hasil:**
\begin{lcverbatim}
String pertama : STRING
String Kedua : STRING
\end{lcverbatim}

#### Keterangan

- Program diatas digunakan untuk mengkopikan nilai dari array of
  character data ke data2 dengan menggunakan perintah `strcpy`.
  Hal itu terbukti dengan hasil akhir dimana string pertama dan kedua
  bernilai sama, yaitu ``STRING''.
- Jika variabel sesumber lebih besar daripada variabel hasil,
  `trcpy\ ()` akan error karena melebihi buffer. Untuk melindungi
  hal ini, digunakan fungsi `strncpy\ ()` Fungsi ini dapat
  memberikan parameter jumlah maksimum karakter untuk penyalinan.
  `strncpy\ ()` akan menyalin sampai karakter null pertama atau
  jumlah maksimum. Contoh Error:

  
  
  - `char\ data{[`5{]}\ =\ {'{}\{}0'{}};}
  - `char\ data2{[`{]}="STRING";}
  
- Hal ini terjadi karena data2 berjumlah 6 karakter, sedangkan data
  berjumlah 5 karakter. Jadi ketika data2 dikopikan ke data, maka akan
  terjadi error karena tempatnya kurang.

#### Contoh  Penggunaan fungsi strncpy()

Buatlah program beriku:

\lstinputlisting[language=c++, caption=Penggunaan fungsi strncpy(), label=contoh3-22]{../code/03-array-string-contoh3-22.c++}

**Hasil:**
\begin{lcverbatim}
 String pertama : STRING
 String Kedua : STRINGKU
\end{lcverbatim}

#### Keterangan

- Fungsi `strncpy` dapat digunakan untuk menyalin dari satu array
  of character ke array of character lainnya dengan memberikan penanda
  batas maksimal penyalinan. Pada contoh diatas, string ``STRINGKU''
  hendak disalin ke variabel data yang hanya berisi 6 elemen. Karena
  fungsi `strncpy` hanya dibatasi menyalin 5 karakter saja, maka
  yang tersalin adalah `STRIN` saja.
- Karakter ke-6 pada variabel data digunakan untuk menyimpan karakter
 NULL atau \0.

### strcat()<a name="strcat"></a>

**Bentuk umum**:
`strcat(<{`string\ hasil>{},\ <{}string\ sumber>{});}

String dalam C++ tidak bisa digabungkan begitu saja dengan menggunakan
operator + seperti pada bahasa pemrograman Pascal. Jika dipaksakan
menggunakan operator + akan ditampilkan pesan kesalahan sebagai berikut
ini.

#### Contoh  Penggunaan fungsi strcat()

Buatlah program beriku:

\lstinputlisting[language=c++, caption=Penggunaan fungsi strcat(), label=contoh3-23]{../code/03-array-string-contoh3-23.c++}

**Hasil:**

\begin{figure}[htbp]
\centering
\shadowimage[width=8cm]{Capture3-6}

\end{figure}

#### Keterangan

Opearator + tidak bisa digunakan untuk menggabungkan dua buah string.
Untuk menggabungkan dua string, digunakan fungsi `strcat()`.

#### Contoh  Penggunaan fungsi strcat()

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Penggunaan fungsi strcat(), label=contoh3-24]{../code/03-array-string-contoh3-24.c++}

**Hasil:**

\begin{lcverbatim}
Jadi gabungannya adalah:
Kami kelompok belajar Qt C++
\end{lcverbatim}

#### Keterangan

- Program diatas menggunakan fungsi `strcat` dimana fungsi
  tersebut akan menggabungkan dua buah string. Parameter string pertama
  juga digunakan untuk menampung string gabungan kedua string tersebut.
  Sehingga pada akhirnya variabel string1 lah yang ditampilkan ke layar.
- Variabel `string1` diberi ukuran 100 karena jika tidak diberi
  ukuran elemen maka `string1` tidak bisa memperbesar ukurannya
  di memory komputer sehingga akan menyebabkan program **HANG**.

\begin{quotation}
{\LARGE \ding{46}} **TIPS**

Beberapa fungsi yang `#include\ string.h` dan dapat digunakan
untuk memanipulasi *array of character* adalah:

*strrev()*

Bentuk umum: `strrev(string)`

Digunakan untuk membalik susunan string, misal: anton menjadi notna

*strlwr()*

Bentuk umum: `strlwr(string)`

Digunakan untuk mengubah string menjadi huruf kecil semua

*strupr*

Bentuk umum: `strupr(string)`

Digunakan untuk mengubah string menjadi huruf besar semua

*strchr()*

Bentuk umum: `strchr(stringsumber,karakter\ yang\ dicari)`

Dalam bahasa C++ disediakan suatu fungsi pustaka yaitu `strchr()`
untuk mencari nilai suatu karakter yang ada di suatu string. Hasil dari
fungsi ini adalah alamat letak dari karakter pertama di nilai string
yang sama dengan karakter yang dicari.

*strcmp()*

Bentuk umum: `strcmp(string1,string2);`

Untuk membandingkan dua nilai string tidak bisa menggunakan operator
hubungan, karena operator tersebut tidak untuk operasi string. Untuk
membandingkan dua nilai string kita gunakan fungsi pustaka
`strcmp()` dengan hasil sebagai berikut:

- Hasil <{} 0, Jika string1 <{} string2
- Hasil = 0, Jika string1 = string2
- Hasil >{} 0, Jika string1 >{} string2

\end{quotation}

### Fungsi mengubah string menjadi numerik dan sebaliknya<a name="fungsi-mengubah-string-menjadi-numerik-dan-sebaliknya"></a>

Pada bahasa C++ tipe data *array of character* bisa dikonversi
menjadi `numerik` dan sebaliknya numerik bisa dikonversi menjadi
`array\ of\ character`. Caranya adalah
`#include\ <{`stdlib>{}}. Fungsi-fungsi
konversi dari string ke numerik adalah:

```cpp
atoi() //untuk mengubah string menjadi int
atof() //untuk mengubah string menjadi float
atol() //untuk mengubah string menjadi long int
```

Sedangkan kebalikannya, fungsi untuk mengubah numerik menjadi string
adalah:

```cpp
itoa() //untuk mengubah int menjadi string
ltoa() //untuk mengubah long int menjadi string
ultoa() //untuk mengubah unsigned long menjadi string
```

Fungsi diatas menerima parameter
`<{`var\ numerik>{}},
`<{`var\ array\ of\ character>{}}, dan
`<{`basis\ bilangan>{}}

### Class string pada C++<a name="class-string-pada-c"></a>

C++ library standar memiliki kelas string yang membuat bekerja dengan
string lebih mudah dengan menyediakan satu set encapsulasi dari data,
dan fungsi untuk memanipulasi data \index{String}string. Kelas ini dikenal dengan
`std::` string yang dapat menangani rincian alokasi memori dan
membuat kopi string, atau menempatkan mereka di memory dengan lebih
mudah.

#### Contoh  Pembuatan variabel string C++, penyalinan string, dan
penggabungan string

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Pembuatan variabel string C++ penyalinan string dan
penggabungan string, label=contoh3-25]{../code/03-array-string-contoh3-25.c++}

**Hasil:**

\begin{lcverbatim}
Isi str1 : Ini string C++
Isi str1 : Ini string C++
Isi str1 : Ini string C++
Halo, Ini string C++
\end{lcverbatim}

#### Keterangan

- Tanpa perlu dipelajari lebih dalam, kita dapat melihat bahwa class
  string pada C++ jelas jauh lebih cepat penggunaannya dan mudah dalam
  pembuatan serta penyalinan seperti semudah mengoperasikan variabel
  bertipe integer saja. Demikian pula, *concatenating*
  (penggabungan) dua string dapat dilakukan dengan hanya menambahkan
  mereka, sama juga seperti kita akan melakukan penjumlahan dengan
  integer apapun.
- Syarat untuk dapat menggunakan class string adalah harus
  mengincludekan `#include\ <{`string>{}},
  seperti yang dapat dilihat pada kode program diatas.

\begin{quotation}
{\LARGE \ding{46}}  **TIPS** 
 
 Class
 string memiliki beberapa fitur / manfaat, yaitu: 

- Mengurangi kesulitan dalam upaya penciptaan dan
memanipulasi string
- Meningkatkan stabilitas aplikasi
yang sedang diprogram dalam pengelolaan dan alokasi memori internal
- Mudah dalam menyalin, memotong, menemukan, dan
penghapusan string
- Memberikan kesempatan pada
programmer untuk lebih fokus pada pengembangan aplikasi daripada
kesulitan dalam manipulasi string
 
 
\end{quotation}

#### Contoh  Penggunaan class string untuk manipulasi data

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Penggunaan class string untuk manipulasi data, label=contoh3-26]{../code/03-array-string-contoh3-26.c++}

**Hasil:**

 \begin{lcverbatim}
 Halooooooo
 saya belajar
 C
 \end{lcverbatim}

#### Keterangan

Dapat dilihat langsung pada baris komentar program diatas.

#### Contoh  Penggabungan string dengan menggunakan class string

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Penggabungan string dengan menggunakan class string, label=contoh3-27]{../code/03-array-string-contoh3-27.c++}

**Hasil:**
\begin{lcverbatim}
Percobaan 1 Percobaan 2
Percobaan 1 Percobaan 2 Percobaan 3 Percebaan tampung
\end{lcverbatim}

#### Keterangan

- Pada program diatas, terdapat dua buah variabel bertipe string, yaitu
  `satu` dan `dua`. Tipe data string tidak mendukung
  penggabungan string dengan mudah yaitu dengan menggunakan operator +.
  Pada contoh diatas, variabel satu ditambah isinya dengan variabel dua
  dan disimpan kembali pada variabel satu. Sehingga variabel satu berisi
  string gabungan ``Percobaan 1 Percobaan 2''.
- Kemudian dibuat suatu variabel tampung yang kemudian juga digabungkan
  kedalam variabel satu. Cara penggabungan (concatenation) string dapat
  dilakukan juga dengan cara kedua, yaitu dengan menggunakan
  `method\ append`. `Method\ append` ini dimiliki oleh
  semua variabel bertipe class string dan dapat langsung digunakan
  dengan memasukkan parameter bertipe string juga.

#### Contoh  Pengaksesan isi nilai class string

Buatlah program berikut:

\lstinputlisting[language=c++, caption=Pengaksesan isi nilai class string, label=contoh3-28]{../code/03-array-string-contoh3-28.c++}

**Hasil:**

\begin{lcverbatim}
I
n
d
o
n
e
s
i
a

R
a
y
a

C-style: Indonesia Raya
\end{lcverbatim}

#### Keterangan

- Variabel string yang bertipe class string juga memiliki sifat yang
  sama dengan variabel string dengan model C-string style. Keduanya
  merupakan gabungan dari karakter-karakter yang berbentuk array
  berdimensi satu. Sehingga jika kita memiliki variabel string satu
  seperti pada program, kita dapat mengakses semua elemen-elemen
  karakter penyusun string tersebut dengan menggunakan perulangan dan
  kemudian kita akses indeks dari masing-masing elemen array
  characternya.
- Pada bagian kedua, kita juga bisa mengkonversi dari tipe data class
  string menjadi tipe data array of character atau tipe data C-style
  string dengan menggunakan method dari class string, yaitu
  `c_str()`.

#### Contoh  Menemukan substring pada sebuah string besar

Tulislah program berikut ini:

\lstinputlisting[language=c++, caption=Menemukan substring pada sebuah string besar, label=contoh3-29]{../code/03-array-string-contoh3-29.c++}

**Hasil:**

\begin{lcverbatim}
Contoh string adalah:
Kata pak Hari, "hari ini matahari cerah sekali!"
Ketemu pertama kata "hari" pada offset 16
Mencari semua kata substring "hari"
Kata "hari" ada di offset 16
Kata "hari" ada di offset 29
Mencari semua karakter 'a'
'a' ditemukan pada posisi 1
'a' ditemukan pada posisi 3
'a' ditemukan pada posisi 6
'a' ditemukan pada posisi 10
'a' ditemukan pada posisi 17
'a' ditemukan pada posisi 26
'a' ditemukan pada posisi 28
'a' ditemukan pada posisi 30
'a' ditemukan pada posisi 37
'a' ditemukan pada posisi 43
\end{lcverbatim}

#### Keterangan

- Program diatas membuat sebuah variabel string bernama strSample yang
  diisi dengan kalimat : ``Kata pak Hari, ``hari ini matahari cerah
  sekali!''\,''. Kemudian program akan mencari kata ``hari'' yang
  pertama ditemukan pada kalimat tersebut dengan menggunakan method
  find(`<{`kata\ yang\ dicari>{}},`<{`posisi\ indeks\ dimulainya\ pencarian>{}}).
  Method ini bersifat case-sensitive sehingga kata ``Hari'' dengan
  ``hari'' berbeda. Pencarian dimulai dari huruf pertama, sehingga kata
  ``hari'' ditemukan pada huruf ke 16, bukan ke-9, karena karakter ke-9
  kata ``Hari'' menggunakan huruf besar.
- Pencarian berikutnya adalah pencarian semua kata ``hari''. Karena kata
  ``hari'' ada lebih dari satu buah, maka pencarian harus diloop, karena
  method find membutuhkan indeks mulainya pencarian. Untuk setiap kata
  ``hari'' yang ditemukan, kemudian ditampilkan posisi indeksnya ke
  layar.
- Selain dapat menerima parameter berupa substring, method find juga
  dapat menerima parameter berupa character dengan proses pencarian yang
  sama dengan proses pencarian dengan parameter substring.

#### Contoh  Membalik kata / kalimat.

Tulislah program berikut ini:

\lstinputlisting[language=c++, caption=Membalik kata / kalimat, label=contoh3-30]{../code/03-array-string-contoh3-30.c++}

**Hasil:**

\begin{lcverbatim}
String asli:
String ini akan dibalik!
Setelah dibalik:
!kilabid naka ini gnirtS
\end{lcverbatim}

#### Keterangan

Untuk membalik kalimat bertipe string, kita harus menggunakan \index{library}library
header \index{algoritm}algoritm, sehingga kita harus mengincludekan library tersebut
`#include\ <{`algorithm>{}}. Setelah itu
untuk menggunakannya kita gunakan perintah
*reverse*(`<{`indeks\ string\ pertam>{}},`<{`indeks\ string\ terakhir>{}}).
Perintah reverse tersebut akan benar-benar mengganti string asli menjadi
terbalik, sehingga variable string kita akan berubah berisi kalimat yang
sudah terbalik.

#### Contoh  Konversi huruf besar dan kecil.

Tulislah program berikut ini:

\lstinputlisting[language=c++, caption=Konversi huruf besar dan kecil, label=contoh3-31]{../code/03-array-string-contoh3-31.c++}

**Hasil:**

\begin{lcverbatim}
Masukkan sebuah string:
Ini KoK tulisaNya AlaY BaNGet yA!
Hasil konversi ke huruf besar:
INI KOK TULISANYA ALAY BANGET YA!

Hasil konversi ke huruf kecil:
ini kok tulisanya alay banget ya!
\end{lcverbatim}

#### Keterangan

Program diatas menunjukkan function transform pada library algoritm
dapat digunakan untuk mengkonversi string dari besar ke kecil dan dari
kecil ke besar.
