**📋 Apa yang akan dipelajari**

Pada bab ini kita akan mempelajari tentang Pointer dan Reference dalam C++:

- Pengenalan pointer dan cara kerjanya
- Memory komputer dan alamat memori
- Reference dan perbedaannya dengan pointer
- Penggunaan pointer dan reference

\minitoc

## 📍 Pointer (Penunjuk)<a name="apa-itu-pointer"></a>

### Apa itu Pointer?

Pointer adalah variabel yang dapat menyimpan alamat memori. Pointer memungkinkan kita mengakses dan memanipulasi data secara langsung di memori.

### Karakteristik Pointer

- **Menyimpan alamat** - pointer berisi alamat memori
- **Akses langsung** - dapat mengakses data di memori
- **Manipulasi memori** - dapat mengubah data di memori
- **Efisien** - lebih cepat untuk data besar

## 💾 Memory Komputer<a name="memory-komputer"></a>

### Struktur Memory

Memory komputer dibagi menjadi beberapa lokasi memori yang berurutan dan memiliki nomor tertentu. Setiap variabel disimpan di lokasi yang unik dalam memori yang disebut **alamat memori** (memory address).

### Ukuran Memory

- **1 lokasi** = 1 byte (8 bit)
- **unsigned long** = 4 bytes (32 bit)
- **int** = 2-4 bytes
- **char** = 1 byte

### Contoh Alamat Memory

Contoh pada gambar di bawah ini menunjukkan variabel dengan nama umur yang bertipe unsigned long. Byte pertama dari variabel umur disimpan pada alamat memori 102, maka alamat memori dari variabel umur adalah 102.

### 📍 Mengambil Alamat Memory dari Variabel<a name="mengambil-alamat-memory-dari-variabel"></a>

#### Operator Address-of (&)

Setiap komputer memiliki skema penomoran memori yang berbeda. Sebagai programmer, Anda tidak perlu tahu skema alamat dalam memori karena kompiler akan melakukan pekerjaan tersebut untuk Anda.

Jika Anda ingin mengetahui alamat memori tempat variabel disimpan, Anda dapat menggunakan operator **address-of (&)**.

#### Cara Kerja Operator &

- Operator & mengembalikan alamat memori dari variabel
- Format alamat biasanya dalam heksadesimal (0x...)
- Setiap variabel memiliki alamat yang unik

#### 💡 Contoh Menampilkan Alamat Memory

Buka Qt Creator dan buat project Qt Console Application baru dengan nama "contoh", kemudian tulis kode berikut:

\lstinputlisting[language=c++, caption=Menampilkan alamat memory menggunakan address-of operator, label=contoh5-1]{../code/05-pointer-referensi-contoh5-1.c++}

Jalankan program dengan menekan Ctrl + R. Outputnya:

\begin{lcverbatim}
bil1 = 20 address = 0x28fe96 
bil2 = 200000 address = 0x28fe90 
bil3 = -670000 address = 0x28fe8c
\end{lcverbatim}

#### Analisis Program

- Operator address-of (&) digunakan untuk mengetahui alamat memori tempat variabel disimpan
- Ketika mendeklarasikan variabel dengan tipe tertentu, kompiler akan menentukan ukuran memori yang diperlukan dan secara otomatis menetapkan alamat memori
- Setiap variabel memiliki alamat memori yang berbeda

### Menyimpan Alamat Variabel pada Pointer<a name="menyimpan-alamat-variabel-pada-pointer"></a>

Setiap variabel mempunyai alamat, bahkan jika anda tidak tau secara
spesifik alamat memory dari variabel tersebut, anda tetap dapat
menyimpan alamat variabel kedalam pointer. Sebagai contoh untuk
mendeklarasikan pointer yang menunjuk ke variabel tertentu yang bertipe
integer, anda dapat menuliskannya sebagai berikut.

```cpp
int *pBil = 0;
```

Statement diatas bertujuan untuk membuat pointer variabel yang menunjuk
ke alamat variabel bertipe integer. Tanda bintang (*) digunakan untuk
mendeklarasikan variabel pointer.

Pada contoh diatas pemberian nilai 0 berarti anda mendeklarasikan null
pointer, setiap pointer ketika dideklarasikan harus diinisialiasi
nilainya. Jika anda belum tahu alamat yang akan ditunjuk oleh pointer
maka anda dapat memberi nilai 0. Pointer yang tidak diinisialisasi
disebut dengan wild pointer karena bisa menunjuk ke alamat manapun, wild
pointer harus dihindari karena sangat berbahaya.

\begin{quotation}
{\LARGE \ding{46}}  **TIPS** 
	 
	 Selalu lakukan inisialisasi ketika membuat pointer.
\end{quotation}

### Memberi Nama Pointer<a name="memberi-nama-pointer"></a>

Karena pointer juga merupakan variabel maka aturan penamaan pointer juga
sama dengan aturan penamaan variabel biasa. Kesepakatan tidak tertulis
programmer dalam pemberian nama pointer adalah diawali dengan huruf p
misal (pBil, pUmur).

Contoh dibawah ini adalah cara deklarasi dan inisialiasi pointer.

```cpp
int *pBil = 0; //membuat variabel pointer dan inisialisasi null
int bil = 12; //deklarasi variabel
pBil = &bil; //menunjuk ke alamat variabel bil
```

Pada baris yang ketiga dapat anda lihat bahwa pointer pBil menunjuk ke
alamat dari variabel bil, tanda address-of (&) digunakan untuk
mengambil alamat memory dari variabel bil. Anda dapat menuliskan
statement diatas dengan lebih singkat sebagai berikut:

```cpp
int bil = 12; //deklarasi variable
int *pBil = &bil; //menunjuk ke alamat variabel bil
```

### Mengambil Nilai dari
Variabel<a name="mengambil-nilai-dari-variabel"></a>

Mengambil nilai dari variabel dengan menggunakan pointer disebut dengan
`indirection` karena anda secara tidak langsung mengakses nilai
dari variabel melalui `pointer`. Sebagai contoh anda dapat
mengakses nilai dari variabel bil diatas menggunakan pointer
`pBil.`

Operator *indirection (*)* disebut juga dengan operator
*dereferensi*, ketika pointer di dereferensi maka nilai dari
variabel yang alamatnya ditunjuk oleh pointer dapat diambil.

```cpp
int number = *pBil; //mengambil nilai variabel yg alamatnya disimpan padapointer pBil
```

Pada kode ditas dapat dilihat bahwa nilai dari `*pBil` akan sama
dengan nilai bil, karena pointer `pBil` mereferensi ke alamat
dimana variabel bil disimpan, maka number akan bernilai 12.

```cpp
*pBil = 20; //nilai dari variabel bil juga akan berubah menjadi 20
```

Pada kode diatas nilai dari variabel bil akan berubah menjadi 20, karena
variabel bil direferensi oleh pointer `pBil`.

#### Contoh  Memanipulasi data menggunakan Pointer

Buka Qt Creator, buat project Qt Console Application dengan nama contoh
[contoh5-2](#contoh5-2). Kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption=Memanipulasi data menggunakan Pointer, label=contoh5-2]{../code/05-pointer-referensi-contoh5-2.c++}

Tekan Ctrl+R untuk menjalankan kode diatas, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
Umur : 17
pUmur : 17
Merubah nilai pUmur..
Umur : 28
pUmur : 28
Merubah nilai umur..
Umur : 30
pUmur : 30
\end{lcverbatim}

#### Analisa Program

- Pada program diatas pointer `pUmur` mereferensi/menunjuk ke
  alamat dimana nilai variabel umur disimpan.
- Untuk mengakses nilai dari variabel umur lewat pointer dapat
  menggunakan dereference operator (*).
- Ketika nilai dereference pointer `*pUmur` diubah menjadi 28,
  maka akan mempengaruhi nilai pada variabel umur yang akan menjadi 28
  juga.
- Ketika nilai variabel umur diubah menjadi 30, dan anda mengakses
  nilainya dengan menggunakan pointer `*pUmur` maka nilainya juga
  akan berubah menjadi 30.

### Mengganti alamat yang direferensi oleh
Pointer<a name="mengganti-alamat-yang-direferensi-oleh-pointer"></a>

Anda juga dapat mengganti alamat variabel yang direferensi oleh pointer
tertentu tanpa harus mengetahui nilai dari variabel tersebut.

#### Contoh  Mengganti alamat yang di referensi oleh pointer

Buat project Qt Console Application baru, beri nama contoh [contoh5-3](#contoh5-3), kemudian
tulis kode berikut

\lstinputlisting[language=c++, caption=Mengganti alamat yang di referensi oleh pointer, label=contoh5-3]{../code/05-pointer-referensi-contoh5-3.c++}

Tekan Ctrl+R untuk menjalankan program diatas, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
umur1 : 17 alamat : 0x28fe92
pUmur : 17 alamat : 0x28fe92
umur2 : 28 alamat : 0x28fe90
pUmur : 28 alamat : 0x28fe90
\end{lcverbatim}

#### Analisa

- Pada program diatas dapat dilihat bahwa pertama kali pointer pUmur
  mereferensi pada alamat variabel `umur1`, sehingga ketika
  dicetak nilai dari `*pUmur` sama dengan nilai variabel
  `umur1`.
- Anda dapat mengganti referensi dari `pUmur` yang tadinya
  menunjuk ke alamat variabel `umur1` menjadi menunjuk ke alamat
  variabel `umur2`, sehingga ketika `*pUmur` dicetak
  menghasilkan nilai yang sama dengan variabel `umur2`.

## Pointer dan Array<a name="pointer-dan-array"></a>

Pada C++ nama dari array adalah konstan pointer yang menunjuk pada
elemen pertama dari array, misal untuk deklarasi array berikut

```cpp
int Numbers[5];
```

Numbers adalah pointer yang menunjuk alamat `&Numbers{[`0{]}}
yang merupakan alamat dari elemen pertama array diatas.

Anda dapat menggunakan nama array sebagai konstan pointer, misalnya
Numbers+3 adalah cara penulisan untuk mengakses pointer yang menunjuk ke
`Numbers{[`3{]}}.

#### Contoh  Pointer dan Array

Buat project Qt Console Application dengan nama contoh [contoh5-4](#contoh5-4), kemudian tulis
kode berikut.

\lstinputlisting[language=c++, caption=Pointer dan Array, label=pointer-dan-array]{../code/05-pointer-referensi-pointer-dan-array.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
Alamat numbers[0] : 0x28fe78
Nilai numbers[0] : 100
Alamat numbers[4] : 0x28fe88
Nilai numbers[4] : 777
numbers[0] = 100
numbers[1] = 200
numbers[2] = 222
numbers[3] = 111
numbers[4] = 777
\end{lcverbatim}

#### Keterangan

Nama dari array numbers merupakan konstan pointer yang menunjuk alamat
element pertama pada array (`numbers{[`0{]}}), jadi jika anda
ingin mengetahui nilai dari elemen pertama array anda dapat menggunakan
dereference operator `*numbers`.

Anda dapat menggunakan nama array `numbers+4` untuk menunjuk ke
alamat elemen `numbers{[`4{]}}, untuk menampilkan nilai
`numbers{[`4{]}} anda dapat menuliskan `*(numbers+4)`.

## Kapan kita menggunakan pointer?<a name="kapan-kita-menggunakan-pointer"></a>

Setelah kita mempelajari cara penggunaan pointer sekarang kita akan
melihat kapan pointer biasa digunakan dalam pemrograman.

- Pengaturan data pada free store / heap memory.
- Mengakses class member dan data function.
- Passing variabel dengan reference pada function.

### Mengalokasikan tempat dengan keyword new<a name="mengalokasikan-tempat-dengan-keyword-new"></a>

Anda dapat mengalokasikan memory pada free store / heap memory dengan
menggunakan keyword `new' diikuti dengan tipe data dari objek yang akan
anda simpan sehingga compiler dapat mengetahui berapa banyak memory yang
dibutuhkan untuk menyimpan data tersebut. Contoh penggunaan keyword
`new' dapat dilihat pada kode berikut:

```cpp
//mengalokasikan memory di heap untuk menyimpan data integer
int *pBil = new int;
//nilai 19 akan disimpan di heap yg sudah dialokasikan
*pBil = 19;
```

### Membersihkan memory dengan keyword delete<a name="membersihkan-memory-dengan-keyword-delete"></a>

Ketika anda sudah selesai menggunakan objek yang ada di memory, anda
harus mengosongkan kembali memory tersebut agar dapat digunakan kembali.
Anda dapat menggunakan keyword `delete' untuk mengembalikan memory yang
anda gunakan ke heap / free store.

Penting untuk anda ketahui bahwa memory yang dialokasikan menggunakan
keyword `new' tidak akan dibersihkan secara otomatis, maka sebagai
programmer anda harus disiplin untuk membebaskan memory yang sudah tidak
digunakan.

Ketika anda menghapus memory maka pointer tetap menunjuk ke alamat
memory yang sudah anda hapus, agar tidak terjadi kesalahan setelah
menghapus memory anda disarankan untuk memberi nilai null (0) pada
pointer.

#### Contoh  Mengalokasikan, menggunakan, dan mendelete Pointer

Buat project Qt Console Application dengan nama contoh [contoh5-5](#contoh5-5), kemudian tulis
kode berikut:

\lstinputlisting[language=c++, caption=Mengalokasikan menggunakan dan mendelete Pointer, label=contoh5-5]{../code/05-pointer-referensi-contoh5-5.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
bil : 20
pBil : 20
Nilai pHeap : 19
Nilai pHeap : 100
\end{lcverbatim}

#### Analisa:

- `pHeap` adalah pointer yang menunjuk ke alamat memory yang
  sudah dialokasikan dengan keyword `new', anda dapat menyimpan nilai
  kedalam memory yang dialokasikan dengan `*pHeap=19`
- Setelah selesai digunakan anda harus membersihkan memory dengan
  menggunakan keyword `delete', jangan lupa menginisialisasi pointer
  dengan null (0) agar tidak terus menunjuk ke alamat memory yang sudah
  dihapus.

 
 \begin{quotation}
 {\LARGE \ding{46}}  	 **TIPS**
 	 
 	 Setelah menghapus objek di memory dengan keyword delete anda harus
 	 menginisialisasi pointer yang sudah tidak digunakan dengan nilai null
 	 (0).
 \end{quotation} 

### Membuat objek pada heap<a name="membuat-objek-pada-heap"></a>

Selain tipe data primitive (int, float, byte, dll) anda juga dapat
menyimpan data bertipe class kedalam free store / heap, misal jika anda
ingin membuat objek bertipe class Mahasiswa anda dapat mendeklarasikan
pointer untuk class tersebut dan mengalokasikan memory di heap untuk
menyimpan objek tersebut. Sintaks penulisanya sama dengan sebelumnya.

```cpp
Mahasiswa *mhs = new Mahasiswa;
```

Ketika anda menggunakan keyword `new' untuk membuat pointer yang
menunjuk ke objek maka otomatis default konstruktor dari class tersebut
akan dipanggil.

Ketika anda menghapus pointer yang menunjuk ke objek dengan keyword
`delete', maka destruktor akan dipanggil, ini akan memberi kesempatan
bagi programmer untuk membersihkan heap memory dari variabel yang sudah
tidak digunakan.

#### Contoh  Membuat dan menghapus objek dari Heap

Buat project Qt Console Application dengan nama contoh [contoh5-6](#contoh5-6), kemudian tulis
kode berikut:

\lstinputlisting[language=c++, caption=Membuat dan menghapus objek dari Heap, label=contoh5-6]{../code/05-pointer-referensi-contoh5-6.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
Deklarasi object tanpa pointer
Konstruktor dipanggil..
Mengalokasikan heap memory untuk menyimpan objek
Konstruktor dipanggil..
Delete objek di memory
Destruktor dipanggil..
\end{lcverbatim}

#### Analisa

- Pada program diatas kita membuat class Mahasiswa yang mempunyai objek
  konstruktor dan destruktor.
- Pertama kali kita mendeklarasikan object mhs1 pada local variable
  (stack), pembuatan object ini menyebabkan konstruktor dipanggil.
- Kemudian dibuat pointer yang menunjuk ke objek di heap dengan nama
  mhs2, ketika objek mhs2 dibuat, objek konstruktor dipanggil. Ketika
  anda menghapus objek di heap menggunakan delete maka objek destruktor
  akan dipanggil.
- Objek desktruktor untuk mhs1 akan dipanggil ketika fungsi main
  berakhir.

### Menggunakan const Pointer<a name="menggunakan-const-pointer"></a>

Anda dapat menggunakan keyword `const' pada pointer dengan menuliskannya
sebelum atau sesudah tipe data, atau keduanya. Contoh deklarasi const
pointer dapat dilihat pada kode dibawah ini:

```cpp
const int * pBil1;
int * const pBil2;
const int * const pBil3;
```

Tiga statement diatas memiliki pengertian yang berbeda, yaitu:

- Statement pertama : `pBil1` adalah pointer yang menunjuk ke
  konstan integer, jadi nilai yang ditunjuk oleh pointer tidak dapat
  diubah.
- Statement kedua : `pBil2` adalah konstan pointer yang menunjuk
  ke variabel integer, nilai variabel integer dapat diubah namun pBil2
  tidak dapat menunjuk ke variabel lain.
- Statement ketiga : `pBil3` adalah konstan pointer yang menunjuk
  ke konstan variabel bertipe integer, nilai variabel tidak dapat diubah
  dan pointer `pBil3` tidak dapat menunjuk ke variabel lain.

\begin{quotation}
{\LARGE \ding{46}} 	**TIPS**
	
	Lihat
	letak penulisan keyword const, jika sebelum tipe data maka nilai
	konstan, jika setelah tipe data maka alamat pointer yang konstan.
\end{quotation}
 

## Apa itu Reference<a name="apa-itu-reference"></a>

Pada pembahasan sebelumnya kita membahas penggunaan pointer untuk
mengakses objek secara tidak langsung (indirect). Fungsi reference mirip
seperti \index{pointer}pointer namun dengan penulisan yang relatif lebih mudah.

Reference adalah alias, ketika anda membuat reference anda
menginisialisasi dengan nama dari objek yg dijadikan target. Reference
adalah alternatif nama dari objek target, jika anda merubah reference
maka objek target juga akan berubah.

Cara penulisan reference adalah menambahkan operator (&) didepan nama
variabel, contohnya :

```cpp
int &rBil = intBil;
```

Statement diatas dapat diartikan ``rBil adalah referensi dari variabel
intBil'', reference berbeda dengan variabel biasa karena reference harus
diinisialisasi ketika dibuat.

#### Contoh  Membuat dan Menggunakan Reference.

Buat project Qt Console Application dengan nama contoh [contoh5-7](#contoh5-7), kemudian tulis
kode berikut:

\lstinputlisting[language=c++, caption=Membuat dan Menggunakan Reference, label=contoh5-7]{../code/05-pointer-referensi-contoh5-7.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
Nilai bil1 : 18
Nilai &rBil : 18
Nilai bil1 : 19
Nilai &rBil : 19
Nilai bil1 : 33
Nilai &rBil : 33
Menampilkan alamat memory :
&bil1 : 0x28fe90
&rBil : 0x28fe90
\end{lcverbatim}

#### Analisa

- Pertama kita mendeklarasikan referensi `rBil=bil1`, maka ketika
  dicetak nilai `rBil` sama dengan nilai variabel `bil1`
  karena `rBil` merupakan reference / alias dari `bil1`.
- Ketika variabel `bil1` nilainya dirubah menjadi `19`,
  maka otomatis nilai dari `rBil` juga berubah menjadi
  `19`.
- Demikian pula ketika `rBil` nilainya dirubah menjadi
  `33`, maka nilai dari `bil1` juga ikut berubah.
- Anda juga dapat menampilkan alamat memory dari variabel dan variabel
  reference dengan menambahkan keyword (&) didepan variabel.

### Re-assign Reference Variable<a name="re-assign-reference-variable"></a>

Variabel reference tidak dapat di re-assign (ditetapkan ulang). Agar
lebih jelas perhatikan contoh dibawah ini:

#### Contoh  Re-assign Reference Value

Buat project Qt Console Application dengan nama contoh [contoh5-8](#contoh5-8), kemudian tulis
kode berikut:

\lstinputlisting[language=c++, caption=Re-assign Reference Value, label=contoh5-8]{../code/05-pointer-referensi-contoh5-8.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
rBil : 14
rBil : 19
bil : 19
\end{lcverbatim}

#### Analisa

Variabel reference `rBil` yang sudah diinisialisasi dengan
`bil1` coba di re-assign dengan `bil2` dan gagal, karena
`rBil=bil2` tidak menjadikan referensinya berubah tetapi nilai
`bil2` yang mengganti nilai `rBil` dan `bil1`.

### Passing function argument dengan reference<a name="passing-function-argument-dengan-reference"></a>

Pada chapter sebelumnya tentang `function`, kita sudah membahas
beberapa keterbatasan dari `function` diantaranya, argument hanya
dapat di-*passing by value*, dan return statement hanya dapat
mengembalikan satu nilai saja.

*Passing reference value* pada `function` dapat mengatasi
masalah diatas. Contoh dibawah ini akan menunjukan perbedaan penggunaan
passing by value dan passing by reference (dengan pointer dan variaabel
reference).

#### Contoh  Passing by Value.

Buat project Qt Console Application dengan nama contoh [contoh5-9](#contoh5-9), kemudian tulis
kode berikut:

\lstinputlisting[language=c++, caption=Passing by Value, label=contoh5-9]{../code/05-pointer-referensi-contoh5-9.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
Pada main, sebelum ditukar x=12, y=21
Pada fungsi, sebelum ditukar, x=12, y=21
Pada fungsi, Setelah ditukar, x=21, y=12
Pada main, setelah ditukar x=12, y=21
\end{lcverbatim}

#### Keterangan

Pada kode diatas dapat dilihat bahwa *passing by value* ke fungsi
`Tukar()` tidak akan mempengaruhi variabel `x` dan
`y` yang ada pada fungsi main, dan hanya berpengaruh pada scope
fungsi `Tukar()`. saja.

#### Contoh Passing by reference dengan pointer

Buat project Qt Console Application dengan nama contoh [contoh5-10](#contoh5-10), kemudian
tulis kode berikut:

\lstinputlisting[language=c++, caption=Passing by reference dengan pointer, label=contoh5-10]{../code/05-pointer-referensi-contoh5-10.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
main func, x=12, y=21
Pada fungsi, sebelum ditukar x=12,y=21
Pada fungsi, sesudah ditukar x=21,y=12
main func, x=21, y=11
\end{lcverbatim}

#### Analisa

Pada kode diatas kita melakukan passing by reference untuk passing
parameter ke fungsi `Tukar()` menggunakan pointer, dapat anda
lihat bahwa setelah fungsi `Tukar()` dijalankan variabel
`x` dan `y` di main function nilainya sudah berhasil
ditukar.

#### Contoh  Menjalankan fungsi Tukar() dengan reference

Buat project Qt Console Application dengan nama contoh [contoh5-11](#contoh5-11), kemudian
tulis kode berikut:

\lstinputlisting[language=c++, caption=Menjalankan fungsi Tukar() dengan reference, label=contoh5-11]{../code/05-pointer-referensi-contoh5-11.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
main func, sebelum ditukar x=12, y=21
Pada function, sebelum ditukar x=12, y=21
Sesudah function, sebelum ditukar x=21, y=12
main func, setelah ditukar x=21, y=11
\end{lcverbatim}

#### Analisa

Pada kode diatas kita juga berhasil menukar nilai x dan y menggunakan
fungsi tukar sama dengan kode sebelumnya. Ini karena passing parameter
menggunakan variabel reference.

### Function yang mengembalikan beberapa nilai<a name="function-yang-mengembalikan-beberapa-nilai"></a>

Seperti yang sudah kita bahas sebelumnya bahwa salah satu keterbatasan
dari function adalah hanya dapat mengembalikan satu nilai saja.
Bagaimana jika anda ingin mengembalikan lebih dari satu nilai pada
function? Untuk memecahkan masalah tersebut anda dapat menggunakan
function pass by reference. Karena function pass by reference dapat
memanipulasi objek asli. Agar lebih jelas coba kerjakan contoh dibawah
ini.

#### Contoh  Mengembalikan beberapa nilai dengan pointer

Buat project Qt Console Application dengan nama contoh [contoh5-12](#contoh5-12), kemudian
tulis kode berikut:

\lstinputlisting[language=c++, caption=Mengembalikan beberapa nilai dengan pointer, label=contoh5-12]{../code/05-pointer-referensi-contoh5-12.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
Masukan number : 5
Number : 5
pLuasPersegi : 25
pVolumeKubus : 125
\end{lcverbatim}

#### Analisa

- Inputan untuk variabel number harus lebih besar dari 0, jika tidak
  program akan menghasilkan pesan error.
- Dapat dilihat bahwa function `Hitung()` mengembalikan 3 nilai
  yaitu : nilai kembalian dari `function` itu sendiri yang
  bertipe `integer`, `pLuasPersegi`, dan
  `pVolumeKubus` yang merupakan parameter bertipe pointer.
- `pLuasPersegi` dan `pVolumeKubus` nilainya dapat bukan
  karena nilai kembalian dari function, tapi karena parameter by
  reference dari function yang berupa pointer, sehingga ketika nilai
  `pLuasPersegi` dan `pVolumeKubus` diubah di dalam
  function nilai variabel asli di main function juga berubah.

#### Contoh  Mengembalikan beberapa nilai dengan reference variabel

Buat project Qt Console Application dengan nama contoh [contoh5-13](#contoh5-13), kemudian
tulis kode berikut:

\lstinputlisting[language=c++, caption=Mengembalikan beberapa nilai dengan reference variabel, label=contoh5-13]{../code/05-pointer-referensi-contoh5-13.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
Masukan number : 5
Number : 5
pLuasPersegi : 25
pVolumeKubus : 125
\end{lcverbatim}

#### Analisa

- Hasil program diatas sama dengan contoh [contoh5-13](#contoh5-13) sebelumnya, namun
  perbedaannya adalah program diatas menggunakan parameter reference
  pada function `Hitung()` sehingga ketika variabel
  `rLuasPersegi` dan `rVolumeKubus` pada function diubah
  nilainya maka variabel di function main juga ikut berubah.
- Keyword enum digunakan untuk membuat objek enumerasi untuk mempermudah
  pembacaan program.

### Passing By Reference untuk Efisiensi<a name="passing-by-reference-untuk-efisiensi"></a>

Setiap kali anda melakukan passing objek by value, copy dari objek
tersebut akan dibuat kembali. Untuk tipe data objek yang besar (struct
atau class yang dibuat sendri oleh user) ini akan menurunkan performa
dari program. Untuk melakukan passing parameter objek melalui function
disarankan menggunakan reference pada objek.

#### Contoh  Passing Object By Value

Buat project Qt Console Application dengan nama contoh [contoh5-14](#contoh5-14), kemudian
tulis kode berikut:

\lstinputlisting[language=c++, caption=Passing Object By Value, label=contoh5-14]{../code/05-pointer-referensi-contoh5-14.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
Membuat object mahasiswa
Memanggil Mahasiswa Konstruktor
Memanggil Copy Konstruktor
Mengembalikan FunctionMhs ..
Memanggil Copy Konstruktor
Memanggil Mahasiswa Destruktor
Memanggil Mahasiswa Destruktor
\end{lcverbatim}

#### Analisa

- Dapat kita lihat diatas bahwa *passing object by value* tidak
  efisien karena setiap kali function dipanggil dan mengembalikan nilai
  harus melakukan copy terhadap objek objMhs1.
- Hal ini dapat dilihat dari output yang dihasilkan, copy konstruktor
  dipanggil sebanyak 2 kali, saat pemanggilan function dan pengembalian
  nilai function.
- Cara yang lebih efisien akan dibahas pada contoh program selanjutnya.

#### Contoh  Passing Object By Reference

Buat project Qt Console Application dengan nama contoh [contoh5-15](#contoh5-15), kemudian
tulis kode berikut:

\lstinputlisting[language=c++, caption=Passing Object By Reference, label=contoh5-15]{../code/05-pointer-referensi-contoh5-15.c++}

Tekan Ctrl+R untuk menjalankan program, outputnya adalah sebagai
berikut.

\begin{lcverbatim}
Membuat object mahasiswa
Memanggil Mahasiswa Konstruktor
Mengembalikan FunctionMhs ..
\end{lcverbatim}

#### Analisa

- Dengan menambahkan reference pada function dan parameter yang
  dikirimkan, performa aplikasi anda dapat lebih efektif karena objek
  tidak perlu dicopy ketika function dijalankan dan saat function
  tersebut mengembalikan nilai.
- Output yang dihasilkan lebih sedikit karena tidak perlu memanggil copy
  objek konstruktor.

