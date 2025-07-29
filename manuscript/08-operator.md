**📋 Apa yang akan dipelajari**

Pada bab ini kita akan membahas tentang Operator Types dan Operator Overloading dalam C++:

- Pengenalan operator overloading
- Unary dan binary operators
- Cara membuat operator custom
- Contoh penggunaan operator

\minitoc

## ⚙️ Operator pada C++<a name="operator-pada-cpp"></a>

### Apa itu Operator Overloading?

Pada bab awal kita sudah mempelajari berbagai macam operator (+, -, /, >, <) yang dapat digunakan pada tipe data yang sudah ada di C++ seperti `int`, `float`, `bool`, dll.

Namun jika Anda ingin menggunakan operator tersebut pada tipe data yang Anda definisikan sendiri seperti tipe data Class, maka Anda dapat menggunakan keyword **operator**.

### Sintaks Operator Overloading

```cpp
return_type operator operator_symbol (...parameter list...);
```

### Mengapa Perlu Operator Overloading?

Penggunaan keyword operator mirip dengan fungsi, tetapi Anda dapat menggunakan operator symbol seperti (+, -, >, <, =, dll).

Mungkin Anda bertanya: "Kenapa harus menggunakan keyword operator jika bisa menggunakan fungsi?"

Ilustrasi di bawah ini akan menunjukkan mengapa kita membutuhkan operator overloading.

### Contoh Perbandingan

```cpp
CKataString strKata1("Hello");
CKataString strKata2("World");
```

Jika Anda ingin menggabungkan kedua kata tersebut, Anda dapat membuat function `Concatenate`:

```cpp
CKataString strGabung;
strGabung = strKata1.Concatenate(strKata2);
```

Atau dengan operator overloading, lebih natural:

```cpp
CKataString strGabung;
strGabung = strKata1 + strKata2;
```

### Keunggulan Operator Overloading

- **Intuitif** - penggunaan operator + untuk menggabungkan string lebih mudah dipahami
- **Natural** - kode terlihat lebih alami dan mudah dibaca
- **Konsisten** - menggunakan operator yang sudah familiar

### Jenis Operator

Ada 2 macam operator yang terdapat di C++:

- **Unary** - operator dengan satu operand
- **Binary** - operator dengan dua operand

### 🔢 Unary Operator<a name="unary-operator"></a>

Unary operator hanya mempunyai satu operand saja.

#### Sintaks Unary Operator

```cpp
return_type operator operator_type (parameter_type)
{
    // ... implementation
}
```

#### Jenis Unary Operator

\begin{longtable}[]{@{}ll@{}}
\toprule
**Operator** & **Name** 

\midrule
\endhead
++ & Increment 

-- & Decrement 

* & Pointer Dereference 

-> & Member Selection 

! & Logika NOT 

& & Address-of 

~{} & One's Complement 

+ & Unary Plus 

- & Unary Negation 

\bottomrule
\end{longtable}

### Contoh Penggunaan Increment Operator

Pada contoh di bawah ini kita akan membuat Class Kalender yang mempunyai tiga class member yang merepresentasikan hari, bulan, dan tahun (tipe integer). Anda dapat menggunakan operator ++ untuk menambahkan hari.

#### 💡 Contoh Increment Operator (Notasi prefix)

- Buka Qt Creator dan buat project Qt Console Application baru dengan nama "contoh"
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Menggunakan Increment Operator (Notasi prefix), label=contoh8-1]{../code/contoh8-1.cpp}

- Kemudian jalankan kode diatas dengan menekan tombol Ctrl+R, outputnya
  adalah sebagai berikut.

\begin{lcverbatim}
Membuat object kalender dan memberi inisialisasi
23 / 10 / 2010

Tanggal setelah notasi prefik dijalankan
24 / 10 / 2010
\end{lcverbatim}

#### Keterangan

- Class Kalender berisi tiga member variabel yaitu `_hari`,
  `_bulan`, dan `_tahun` yang merepresentasikan waktu
  tertentu.
- operator `++` digunakan untuk menambahkan 1 hari kedalam objek
  Kalender, dengan menggunakan operator `++` penulisan menjadi
  lebih intuitif dan mudah dipahami, misal untuk menambahkan 1 hari
  kedalam objek Kalender anda dapat menuliskan `++objKal`.
- Untuk memanggil operator `++` pada program diatas digunakan
  notasi prefix (tanda ++ dituliskan sebelum nama objek).
- Karena kode diatas menggunakan notasi prefix maka pada operator ++
  akan mengakses objek by reference.

Ada perbedaan penulisan notasi prefix dan postfix, sebagai contoh anda
dapat melihat kode dibawah ini.

```cpp
int bil1 = 22;
int bil2 = bil1++;
//mengcopy nilai lama dari bil1
cout << "bil2 : " << bil2;
//nilai bil1 setelah di increment
cout << "bil1 : " << bil1;
```

Nilai `bil2` adalah `22`, karena yang dimasukan kedalam
`bil2` adalah nilai lama dari `bil1`, baru setelah itu
`bil1` di increment.

Untuk contoh [contoh8-2](#contoh8-2) dibawah ini kita akan mencoba menggunakan notasi
`postfix`, dengan notasi `postfix` yang dilakukan adalah
menduplikat objek yang diinputkan, melakukan increment dan mengembalikan
objek tersebut by value.

#### Contoh  Menggunakan Operator Increment (notasi postfix).

- Buka Qt Creator dan buat project Qt Console Application baru dengan
  nama contoh [contoh8-2](#contoh8-2), kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption=Menggunakan Operator Increment (notasi postfix), label=contoh8-2]{../code/contoh8-2.cpp}

- Kemudian jalankan kode diatas dengan menekan tombol Ctrl+R, outputnya
  adalah sebagai berikut.

\begin{lcverbatim}
Membuat object kalender dan memberi inisialisasi
23 / 10 / 2010

Menggunakan notasi postfix
objLama : 23 / 10 / 2010
objKal : 24 / 10 / 2010
\end{lcverbatim}

#### Keterangan

- Output yang dihasilkan akan sama dengan kode sebelumnya, hanya saja
  penulisan operator `++` menggunakan notasi `postfix`.
- Karena menggunakan `postfix` maka yang dilakukan pada operator
  `++` adalah mengkopi objek yang lama, menambahkan data,
  kemudian mengembalikan objek tersebut by value.

## Conversion Operator<a name="conversion-operator"></a>

Bagaimana jika anda menginginkan statement
`int\ bil\ =\ Kalender(23,10,2010)` memiliki arti? Untuk itu anda
perlu mengkonversi dari objek Kalender menjadi tipe data integer, dengan
demikian anda akan dengan mudah mengirimkan data Kalender ke module lain
yang hanya menerima parameter bertipe integer.

Anda dapat melakukan konversi diatas dengan menggunakan conversion
operator yang mempunyai syntax sebagai berikut:

```cpp
operator conversion_type();
```

Jadi jika anda menghendaki mengkonversi tipe Kalender menjadi int anda
dapat menggunakan operator berikut.

```cpp
operator int()
{
// implementation
return intValue;
}
```

Contoh [contoh8-3](#contoh8-3) dibawah ini akan menunjukan bagaimana penggunaan conversion
operator untuk mengkonversi tipe Kalender menjadi int.

#### Contoh Conversion Operator untuk konversi class Kalender ke integer.

Buka Qt Creator dan buat project Qt Console Application baru dengan nama
contoh [contoh8-3](#contoh8-3), kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption=Conversion Operator untuk konversi class Kalender ke integer, label=contoh8-3]{../code/contoh8-3.cpp}

**Hasilnya**
\begin{lcverbatim}
Inisialisasi data :
23 / 10 / 2010

Integer yang sesuai dengan data 2011023
\end{lcverbatim}

#### Keterangan

- Pada operator `int()`, `variabel` `_tahun`,
  `_bulan`, dan `_hari` dikalikan dengan bilangan
  tertentu sehingga menghasilkan kembalian berupa `int`.
- Statement int `nData\ =\ objKal` akan menjalankan operator
  `int` dan mengembalikan nilai integer dari objek Kalender.
- Dengan menggunakan operator int akan lebih mudah membandingkan dua
  objek Kalender, karena objek tersebut dapat mengembalikan satu nilai
  integer.

### Binary Operator<a name="binary-operator"></a>

Operator yang mengoperasikan dua operand disebut dengan binary operator,
cara penulisan binary operator sama dengan penulisan oprator yang
sebelumnya.

```cpp
return_type operator_type (parameter);
```

Ada beberapa macam binary operator yang dapat digunakan pada C++,
diantaranya :

\begin{longtable}[]{@{}ll@{}}
\toprule
Operator & Name\tabularnewline
\midrule
\endhead
+ & Addition\tabularnewline
+= & Addition/Assigment\tabularnewline
- & Substraction\tabularnewline
-= & Substraction/Assigment\tabularnewline
<{} & Less Than\tabularnewline
>{} & Greater Than\tabularnewline
<{}= & Less thar or equal to\tabularnewline
>{}= & Greater than or equal to\tabularnewline
== & Equal to\tabularnewline
!= & Inequality\tabularnewline
\bottomrule
\end{longtable}

Contoh [contoh8-4](#contoh8-4) program dibawah ini menggunakan operator Addition (+) untuk
menambahkan hari pada objek kalender, anda dapat menambahkan beberapa
hari kedepan, misal 5 atau 10 hari dari tanggal sekarang.

#### Contoh  Menggunakan Binary Addition Operator.

- Buka Qt Creator dan buat project Qt Console Application baru dengan
  nama contoh [contoh8-4](#contoh8-4), kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption=Menggunakan Binary Addition Operator, label=contoh8-4]{../code/contoh8-4.cpp}

- Kemudian jalankan kode diatas dengan menekan tombol Ctrl+R, outputnya
  adalah sebagai berikut.

\begin{lcverbatim}
Inisialisasi Data

23 / 10 / 2011 Menambahkan 25 hari kedepan
Hasil setelah ditambahkan 25 hari 18 / 11 / 2011 
13 / 11 / 2011
\end{lcverbatim}

#### Keterangan

- Dengan menggunakan operator + anda dapat menambahkan hari pada objek
  Kalender, jumlah hari yang ditambahkan tergantung dari nilai yang
  diinputkan pada parameter.
- Anda dapat menambah hari dengan menggunakan operator + pada objek
  Kalender, misal: `objKal\ =\ objKal\ +\ 25` atau dengan membuat
  objek baru untuk menampung nilai hasil penambahan Kalender
  `objKalBaru(objKal+20)`

## Addition-Assignment
Operator<a name="addition-assignment-operator"></a>

Dengan menggunakan Addition-Assignment operator anda dapat menuliskan
sintaks a += b, yang sama artinya dengan a = a + b. Pada contoh program
dibawah ini operator *Addition-Assignment* akan digunakan untuk
menambahkan hari pada objek Kalender.

#### Contoh  Menggunakan Addition Assigment Operator dan Substraction Assigment Operator.

- Buka Qt Creator dan buat project Qt Console Application baru dengan
  nama contoh [contoh8-5](#contoh8-5), kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption= Menggunakan Addition Assigment Operator dan Substraction
Assigment Operator, label=contoh8-5]{../code/contoh8-5.cpp}

- Kemudian jalankan kode diatas dengan menekan tombol Ctrl+R, outputnya
  adalah sebagai berikut.

\begin{lcverbatim}
Inisialisasi Data
23/10/2011
Menambahkan 25 hari kedepan
Hasil setelah ditambahkan 25 hari
18/11/2011
\end{lcverbatim}

#### Keterangan

Pada kode diatas anda dapat menggunakan operator Addition-Assignment
pada objek Kalender, misal anda ingin menambahkan 25 hari pada objek
Kalender, anda dapat menuliskan kode `objKal\ +=\ 25;`

## Comparison Operator<a name="comparison-operator"></a>

Pada kasus tertentu dimana anda ingin membandingkan dua objek bertipe
Kalender ada dapat menggunakan comparison operator.

```cpp
if (objKal1 == objKal2)
{
// Do something
}
else
{
// Do something else
}
```

Anda dapat menggunakan equality operator (==) atau inequality operator
(!=). Anda juga dapat membuat lebih dari satu equality atau inequality
operator yang mempunyai return value atau parameter yang berbeda, ini
disebut dengan overloading operator.

#### Contoh  Overloading Comparison Operator (Equality dan Inequality).

- Buka Qt Creator dan buat project Qt Console Application baru dengan
  nama contoh [contoh8-6](#contoh8-6), kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption=Overloading Comparison Operator (Equality dan Inequality, label=contoh8-6]{../code/contoh8-6.cpp}

- Kemudian jalankan kode diatas dengan menekan tombol Ctrl+R, outputnya
  adalah sebagai berikut.

\begin{lcverbatim}
Inisialisasi Kalender 1
23 / 10 / 2010

Inisialisasi Kalender 2
23 / 10 / 2011

kalender1 dan kalender2 tidak sama !
Inisialisasi Kalender 3
23 / 10 / 2010

kalender1 dan kalender3 sama !
nilai integer yang ekuivalen dengan objKal3 adalah 20101023
Nilai integer dari objKal3 dan intKal3 sama
Nilai integer dari objKal2 dan intKal3 tidak sama
\end{lcverbatim}

#### Keterangan

- Pada kode diatas terdapat 4 comparison operator yang berbeda, walaupun
  masing-masing ada 2 *inequality* dan *equality* operator
  namun parameternya berbeda ini disebut sebagai *overloading
  operator*.
- Pada operator equality (==) yang pertama membandingkan dua objek
  Kalender dengan cara membandingkan member variabel hari, bulan, tahun
  pada masing-masing objek yang dibandingkan, sedangkan operator == yang
  kedua membandingkan objek Kalender yang terlebih dahulu sudah
  dikonversi menjadi int.
- Anda dapat melihat bahwa kedua operator comparison diatas sama-sama
  dapat membandingkan isi dari 2 objek Kalender, baik dengan cara
  membandingkan member variabel maupun membandingkan nilai int (hasil
  konversi dari objek Kalender).

## Overloading Operator <{, >{}, <{}=, >{}=}<a name="overloading-operator"></a>

Seperti pada contoh [contoh8-6](#contoh8-6) sebelumnya anda juga dapat menggunakan operator
<{}, >{}, <{}=, >{}= untuk
membandingkan objek Kalender. Agar mudah untuk dibandingkan maka objek
Kalender dikonversi terlebih dahulu menjadi tipe int.

#### Contoh  Menggunakan Operator <{. >{}, <{}=, >{}=.}

- Buka Qt Creator dan buat project Qt Console Application baru dengan
  nama contoh [contoh8-7](#contoh8-7), kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption=Menggunakan Operator Overloading, label=contoh8-7]{../code/contoh8-7.cpp}

- Kemudian jalankan kode diatas dengan menekan tombol Ctrl+R, outputnya
  adalah sebagai berikut.

\begin{lcverbatim}
objKal1 berisi :
23 / 10 / 2010

objKal2 berisi :
16 / 10 / 1980

objKal3 berisi :
23 / 10 / 2010

objKal1 < objKal2 = false
objKal1 > objKal2 = true
objKal1 <= objKal3 = true
objKal1 >= objKal3 = true
\end{lcverbatim}

#### Keterangan

- Pada program diatas penggunaan operator <{}, >{},
  <{}=, >{}= digunakan untuk membandingkan dua objek
  Kalender yang berbeda.
- Untuk mempermudah membandingkan dua objek Kalender maka objek Kalender
  tersebut dikonversi terlebih dahulu menjadi `int`.

## Subscript Operator<a name="subscript-operator"></a>

Subscript operator dapat digunakan jika anda ingin mengakses class
seperti ketika anda mengakses array, anda dapat menambahkan operator
`{[`{]}} pada objek yang anda buat untuk mengakses nilai dengan
index tertentu dari objek. Contoh dibawah ini akan menjelaskan
penggunaan subscript operator untuk membuat array yang dinamis.

#### Contoh  Subscript Operator untuk Dynamic Array.

- Buka Qt Creator dan buat project Qt Console Application baru dengan
  nama contoh [contoh8-8](#contoh8-8), kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption=Subscript Operator untuk Dynamic Array, label=contoh8-8]{../code/contoh8-8.cpp}

- Kemudian jalankan kode diatas dengan menekan tombol Ctrl+R, outputnya
  adalah sebagai berikut.

\begin{lcverbatim}
The content array are : {23 16 9 20 55 }
\end{lcverbatim}

#### Keterangan

Dengan menggunakan subscript operator anda dapat mengakses member
variable yang bertipe array pada class dengan menggunakan array-like
syntax (nama objek diikuti dengan tanda {[}{]}), misal:
`namaObjek{[`index{]}}.

## Function operator()<a name="function-operator"></a>

Function operator digunakan jika anda ingin membuat objek bekerja
seperti function. Untuk lebih jelasnya penggunaan function
`operator()` anda dapat mencoba program dibawah ini.

#### Contoh  Menggunakan operator() untuk membuat function object.

- Buka Qt Creator dan buat project Qt Console Application baru dengan
  nama contoh [contoh8-9](#contoh8-9), kemudian tulis kode berikut.

\lstinputlisting[language=c++, caption=Menggunakan operator() untuk membuat function object, label=contoh8-9]{../code/contoh8-9.cpp}

- Kemudian jalankan kode diatas dengan menekan tombol Ctrl+R, outputnya
  adalah sebagai berikut.

\begin{lcverbatim}
Hello Function Operator !
\end{lcverbatim}

#### Analisis

- Dengan membuat function operator maka anda dapat menggunakan objek
  seperti ketika anda menggunakan function.
- Pada program diatas objek objTampil dapat dipanggil seperti function.

