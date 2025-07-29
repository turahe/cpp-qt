**📋 Apa yang akan dipelajari**

Pada bab ini kita akan mempelajari tentang Control Statement (Struktur Kendali) dalam C++:

- Percabangan (if, if-else, switch)
- Perulangan (for, while, do-while)
- Kata kunci break dan continue

\minitoc

## 🎯 Pengenalan Control Statement

Program tidak selalu berjalan secara berurutan dari atas ke bawah. Kadang-kadang kita perlu:

- **Percabangan** - memilih jalur program berdasarkan kondisi
- **Perulangan** - mengulang perintah tertentu
- **Kombinasi** - menggabungkan percabangan dan perulangan

Control statement adalah konsep fundamental dalam pemrograman yang memungkinkan program untuk membuat keputusan dan mengulang operasi[^1]: Dijkstra, E. W. (1968). "Go To Statement Considered Harmful". Communications of the ACM..

Control Statement adalah pengatur aliran program yang memungkinkan kita:

- Mengulang perintah jika kondisi tertentu terpenuhi
- Melanjutkan program jika kondisi terpenuhi
- Memilih dari beberapa alternatif berdasarkan kondisi

## 🔄 Percabangan (Conditional Statements)<a name="percabangan"></a>

Percabangan adalah perintah yang memungkinkan program memilih jalur yang berbeda berdasarkan kondisi tertentu. 

### Apa itu Percabangan?

Percabangan memungkinkan program untuk:

- Menjalankan kode tertentu jika kondisi terpenuhi
- Menjalankan kode lain jika kondisi tidak terpenuhi
- Memilih dari beberapa alternatif berdasarkan nilai tertentu

### Jenis-jenis Percabangan dalam C++

C++ memiliki tiga jenis perintah percabangan:

- **if** - menjalankan kode jika kondisi benar
- **if-else** - menjalankan kode berbeda berdasarkan kondisi
- **switch** - memilih dari beberapa alternatif berdasarkan nilai

### 🔀 Percabangan dengan if<a name="percabangan-dengan-if"></a>

Percabangan **if** adalah yang paling sederhana. Program akan menjalankan kode di dalam blok if jika kondisi bernilai benar (true). Konsep ini pertama kali diperkenalkan dalam bahasa ALGOL 60[^1]: Naur, P. (1960). "Report on the Algorithmic Language ALGOL 60". Communications of the ACM..

#### Sintaks if

\lstinputlisting[language=c++, numbers=none]{../code/control-if-syntax.cpp}

#### Cara Kerja if

- Program mengecek kondisi dalam kurung
- Jika kondisi **benar** (true), kode dalam blok dijalankan
- Jika kondisi **salah** (false), kode dalam blok dilewati
- Program melanjutkan ke baris setelah blok if

Flowchart untuk statment percabangan if seperti pada gambar berikut

\begin{tikzpicture}[node distance = 2cm, auto]
\node [ling] (init){start};
\node [decision, below of=init] (decide) {<{}ekspresi _bool>{}};
\node [block, below of=decide, node distance=3cm] (statement) {Statement};
\node [ling, below of=statement] (stop) {stop};

%garis
\path [line] (init) -- (decide);
\path [line] (init) -- (decide);
\path [line] (decide) -- node {Yes}(statement);
%\path [line] (statement) |- node [near start] {No} (decide);
\path[line] (statement) -- (stop);
\end{tikzpicture}

### 💡 Contoh Percabangan dengan if

- Buka Qt Creator dan buat project Qt Console Application baru dengan nama "contoh"
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Contoh percabangan dengan if, label=contoh2-3]{../code/contoh2-3.cpp}

- Jalankan program dengan menekan Ctrl + R. Outputnya:

\begin{lcverbatim}
Masukan nomor: 15
15 lebih besar dari 10
\end{lcverbatim}

#### Penjelasan Program

- Program meminta input angka dari pengguna
- Jika angka > 10, program menampilkan pesan "lebih besar dari 10"
- Jika angka ≤ 10, program tidak menampilkan apa-apa

### 🔄 Percabangan dengan if-else<a name="percabangan-dengan-if-..-else"></a>

Percabangan **if-else** memungkinkan program menjalankan kode yang berbeda berdasarkan kondisi.

#### Sintaks if-else

```cpp
if (kondisi) {
    // kode yang dijalankan jika kondisi benar
} else {
    // kode yang dijalankan jika kondisi salah
} 
```

#### Cara Kerja if-else

- Program mengecek kondisi dalam kurung
- Jika kondisi **benar**, kode dalam blok if dijalankan
- Jika kondisi **salah**, kode dalam blok else dijalankan
- Program selalu menjalankan salah satu blok (if atau else)

Flowchart untuk statment ini adalah :

\begin{quotation}
{\LARGE \ding{45}} **💡 CATATAN PENTING**

Di dalam blok `if()` maupun `else` bisa diisi dengan perintah `if()` lagi. Bentuk `if()` dalam `if()` ini sering disebut dengan **nested if** (if bersarang).
\end{quotation}

\begin{tikzpicture}[node distance = 2cm, auto]
\node [ling] (init){start};
\node [decision, below of=init, node distance=2cm] (decide) {<{}ekspresi _bool>{}};
\node [block, below of=decide, node distance=3cm] (statement) {Statement};
\node [block, right of=decide, node distance=3cm] (statement2) {Statement2};
\node [ling, below of=statement, node distance=2cm] (stop) {stop};

%garis
\path [line] (init) -- (decide);
\path [line] (init) -- (decide);
\path [line] (decide) -- node {Ya}(statement);
%\path [line] (statement) |- node [near start] {No} (decide);
\path[line] (statement) -- (stop);
\path[line] (statement) -| node {tidak}(statement2);
\path[line] (statement2) -- (decide);
\end{tikzpicture}

#### 💡 Contoh Program if-else

- Edit contoh [contoh2-3](#contoh2-3) dengan menambahkan kode berikut:

\lstinputlisting[language=c++, firstline=13, lastline=14, caption=Contoh percabangan if-else, label=contoh2-4]{../code/contoh2-4.cpp}

- Jalankan program dengan menekan Ctrl + R. Outputnya:

\begin{lcverbatim}
Masukan nomor: 4
4 kurang besar dari 10
\end{lcverbatim}

#### Penjelasan Program

- Jika angka > 10, program menampilkan "lebih besar dari 10"
- Jika angka ≤ 10, program menampilkan "kurang besar dari 10"
- Program selalu memberikan respons, tidak ada kondisi yang dilewati

### 🔄 Percabangan dengan if Bersarang (Nested if)

If bersarang adalah kondisi if yang berada di dalam blok if atau else lainnya. Ini memungkinkan kita membuat percabangan yang lebih kompleks.

#### Cara Kerja Nested if

- Program mengecek kondisi if pertama
- Jika benar, program mengecek kondisi if kedua
- Jika salah, program bisa mengecek kondisi if lain atau menjalankan else
- Bisa dibuat bertingkat sesuai kebutuhan

Flowchart untuk statement if bersarang:

\begin{tikzpicture}[node distance = 1cm, auto]
\node [ling] (init){start};
\node [decision, below of=init, node distance=3cm] (decide) {<{}ekspresi _bool>{}};
\node [block, below of=decide, node distance=3cm] (statement) {Statement};

\node [decision, right of=decide, node distance=3cm] (decide1) {<{}ekspresi _bool>{}};
\node [block, below of=decide1, node distance=3cm] (statement1) {Statement1};

\node [block, right of=decide1, node distance=6cm] (statement2) {Statement2};
\node [ling, below of=statement, node distance=2cm] (stop) {stop};

%garis
\path [line] (init) -- (decide);
\path [line] (decide) -- node{Tidak}(decide1);
\path [line,dashed](decide1) -- node{tidak\dots dst \dots tidak }(statement2);
\path [line] (decide) -- node{Ya}(statement);
\path [line] (decide1) -- node {Ya} (statement1);
\path[line] (statement) -- (stop);

\path[line] (statement2) |- (stop);
\path[line] (statement1) |- (stop);
\path [line] (decide) -- node {Ya}(statement);

\end{tikzpicture}

### 🔀 Percabangan dengan switch<a name="percabangan-dengan-switch"></a>

Percabangan **switch** digunakan sebagai alternatif dari `if-else` ketika kita memiliki banyak pilihan berdasarkan nilai tertentu. Switch statement diperkenalkan dalam bahasa C dan kemudian diadopsi oleh C++[^1]: Kernighan, B. W., & Ritchie, D. M. (1988). "The C Programming Language" (2nd ed.). Prentice Hall..

#### Kapan Menggunakan switch

- Ketika ada banyak pilihan berdasarkan nilai yang sama
- Lebih efisien daripada if-else bertingkat
- Hanya bisa membandingkan nilai yang sama (==), bukan operator pembanding (<, >, dll)
- Ekspresi harus menghasilkan nilai bulat (int, char, enum)

#### Keuntungan switch

- Lebih mudah dibaca untuk banyak pilihan
- Lebih efisien dalam eksekusi
- Struktur yang lebih rapi

#### Sintaks switch

\lstinputlisting[language=c++, numbers=none]{../code/control-switch-syntax.cpp}

#### Cara Kerja switch

- Program mengevaluasi **ekspresi** dalam switch
- Membandingkan hasil dengan nilai di setiap **case**
- Jika ada yang cocok, menjalankan pernyataan di case tersebut
- **break** menghentikan eksekusi switch
- Jika tidak ada yang cocok, menjalankan **default**

#### Pentingnya break

- **break** menghentikan eksekusi switch
- Tanpa break, program akan melanjutkan ke case berikutnya
- Ini bisa menyebabkan eksekusi yang tidak diinginkan

Flowchart untuk statement ini adalah :

\begin{tikzpicture}[node distance = 1cm, auto]
\node [blok] (ekspresi) {<{}nilai_ekspresi1>{}};
\node [blok,below of=ekspresi] (ekspresi1) {<{}nilai_ekspresi2>{}};
\node [blok,below of=ekspresi1] (ekspresi2) {<{}nilai_ekspresi3>{}};
\node [blok,below of=ekspresi2] (ekspresi3) {<{}nilai_ekspresi4>{}};
\node [blok,below of=ekspresi3, node distance=2cm] (ekspresi4) {<{}nilai_lainya>{}};

\node [titik, left of=ekspresi2, node distance=2cm] (titik) {};
\node [decision, left of=titik, node distance=2cm] (decide) {<{}ekspresi>{}};

\node [blok, right of=ekspresi, node distance=4cm] (statement) {<{}statement1>{}};
\node [blok,below of=statement] (statement1) {<{}statement2>{}};
\node [blok,below of=statement1] (statement2) {<{}statement3>{}};
\node [blok,below of=statement2] (statement3) {<{}statement4>{}};
\node [blok,below of=statement3, node distance=2cm] (statement4) {<{}statement>{}};

\node [ling, above of=decide, node distance=3cm] (start) {start};
\node [ling, right of=statement4, node distance=3cm] (stop) {stop};

\path[line](start) -- (decide);
\path[line](titik) |- (ekspresi);
\path[line](titik) |- (ekspresi1);
\path[line](titik) |- (ekspresi2);
\path[line](titik) |- (ekspresi3);
\path[line](titik) |- (ekspresi4);
\path[line,dashed](ekspresi3) -- node{dst}(ekspresi4);

\path[line](ekspresi) -- (statement);
\path[line](ekspresi1) -- (statement1);
\path[line](ekspresi2) -- (statement2);
\path[line](ekspresi3) -- (statement3);
\path[line](ekspresi4) -- (statement4);
\path[line,dashed](statement3) -- node{dst}(statement4);

\path[line](statement) -| (stop);
\path[line](statement1) -| (stop);
\path[line](statement2) -| (stop);
\path[line](statement3) -| (stop);
\path[line](statement4) -- (stop);

\path[line](decide) -- (titik);
\end{tikzpicture}

### 💡 Contoh Program switch

- Buka Qt Creator dan buat project Qt Console Application baru dengan nama "contoh"
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Contoh program switch, label=contoh2-2]{../code/contoh2-2.cpp}

- Jalankan program dengan menekan Ctrl + R. Outputnya:

\begin{lcverbatim}
sabtu
\end{lcverbatim}

#### Penjelasan Program

- Variabel `hari` dideklarasikan bertipe `int` dengan nilai `6`
- Program mengevaluasi nilai `hari` dalam switch
- Karena nilai = 6, program menjalankan `case 6`
- Program menampilkan "sabtu" ke layar

## 🔄 Perulangan (Loops)<a name="perulangan"></a>

Perulangan digunakan untuk mengulang suatu perintah sebanyak yang diinginkan tanpa harus menulis ulang kode yang sama.

### Apa itu Perulangan?

Perulangan memungkinkan program untuk:

- Mengulang kode tertentu berkali-kali
- Menjalankan kode sampai kondisi tertentu terpenuhi
- Menghemat penulisan kode yang berulang

### Jenis-jenis Perulangan dalam C++

C++ memiliki tiga jenis perintah perulangan:

- **for** - perulangan dengan jumlah yang diketahui
- **while** - perulangan selama kondisi benar
- **do-while** - perulangan yang minimal dijalankan sekali

### 🔄 Perulangan dengan for<a name="perulangan-dengan-for"></a>

Perulangan **for** digunakan ketika kita sudah mengetahui berapa kali perulangan akan dijalankan. For loop adalah salah satu konstruksi perulangan yang paling umum digunakan dalam pemrograman[^1]: Knuth, D. E. (1997). "The Art of Computer Programming, Volume 1: Fundamental Algorithms" (3rd ed.). Addison-Wesley..

#### Kapan Menggunakan for

- Jumlah perulangan sudah diketahui
- Perulangan dengan counter yang teratur
- Iterasi melalui array atau range tertentu

#### Sintaks for

\lstinputlisting[language=c++, numbers=none]{../code/control-for-syntax.cpp}

#### Komponen for

- **nilai_awal** - inisialisasi variabel counter
- **kondisi** - syarat untuk melanjutkan perulangan
- **perubahan** - cara mengubah nilai counter (biasanya increment/decrement)

\begin{figure}[htbp]
\centering
![Capture2-8](images/Capture2-8)
\caption{flowchart perulangan dengan for}
\end{figure}

### 🔄 Perulangan dengan while<a name="perulangan-dengan-while"></a>

Perulangan **while** digunakan untuk mengulangi perintah selama kondisi masih bernilai benar.

#### Kapan Menggunakan while

- Jumlah perulangan tidak diketahui
- Perulangan berdasarkan kondisi tertentu
- Perulangan yang berhenti ketika kondisi menjadi salah

#### Sintaks while

\lstinputlisting[language=c++, numbers=none]{../code/control-while-syntax.cpp}

#### Cara Kerja while

- Program mengecek kondisi sebelum masuk perulangan
- Jika kondisi benar, kode dalam blok dijalankan
- Setelah kode selesai, kondisi dicek lagi
- Perulangan berhenti ketika kondisi menjadi salah

\begin{figure}[htbp]
\centering
![Capture2-9](images/Capture2-9)
\caption{flowchart perulangan dengan while}
\end{figure}

### 🔄 Perulangan dengan do-while<a name="perulangan-dengan-do-while"></a>

Perulangan **do-while** mirip dengan while, tetapi kondisi dicek di akhir perulangan. Ini berarti kode minimal akan dijalankan sekali.

#### Kapan Menggunakan do-while

- Ketika kode minimal harus dijalankan sekali
- Perulangan yang kondisi pengecekannya di akhir
- Menu atau input yang perlu diproses minimal sekali

#### Sintaks do-while

\lstinputlisting[language=c++, numbers=none]{../code/control-do-while-syntax.cpp}

#### Cara Kerja do-while

- Program menjalankan kode dalam blok do terlebih dahulu
- Setelah kode selesai, kondisi dicek
- Jika kondisi benar, perulangan dilanjutkan
- Jika kondisi salah, perulangan berhenti

\begin{figure}[htbp]
\centering
![Capture2-10](images/Capture2-10)
\caption{flowchart perulangan dengan do\dots while}
\end{figure}

### 📊 Perbandingan while vs do-while

<div align="center">
| \hline
**Aspek** | **while** | **do-while** |
|---|---|---|
| \hline
Pengecekan kondisi | Di awal | Di akhir |
| \hline
Minimal eksekusi | 0 kali | 1 kali |
| \hline
Kapan digunakan | Kondisi mungkin salah di awal | Kode harus dijalankan minimal sekali |
| \hline |
</div>

#### Perbedaan Utama

- **while**: kondisi dicek sebelum masuk perulangan
- **do-while**: kondisi dicek setelah menjalankan kode
- **while**: mungkin tidak menjalankan kode sama sekali
- **do-while**: minimal menjalankan kode sekali

### ⏭️ Kata Kunci break dan continue<a name="kata-kunci-continue-dan-break"></a>

Kata kunci **break** dan **continue** digunakan untuk mengontrol aliran perulangan.

#### Kata Kunci break

- **break** menghentikan perulangan secara total
- Program keluar dari perulangan dan melanjutkan ke baris setelah perulangan
- Bisa digunakan dalam for, while, do-while, dan switch

#### Kata Kunci continue

- **continue** melompati iterasi saat ini
- Program melanjutkan ke iterasi berikutnya
- Kode setelah continue dalam iterasi yang sama tidak dijalankan

#### Sintaks break dan continue

```cpp
while(kondisi1) {
    statements1;
    if(kondisi2)
        continue;  // lompat ke iterasi berikutnya
    statements2;   // tidak dijalankan jika continue dieksekusi
}
```

### 💡 Contoh Program break dan continue

- Buka Qt Creator dan buat project Qt Console Application baru dengan nama "contoh"
- Tulis kode berikut:

\lstinputlisting[language=c++, caption=Contoh penggunaan break dan continue, label=contoh2-5]{../code/contoh2-5.cpp}

- Jalankan program dengan menekan Ctrl + R. Outputnya:

\begin{lcverbatim}
1 2 3 4 6 7 8 9 10
Loop berhenti karena break
\end{lcverbatim}

#### Penjelasan Program

- Program menggunakan perulangan for dari 1 sampai 10
- Jika i == 5, program menggunakan continue untuk melompati angka 5
- Jika i == 10, program menggunakan break untuk menghentikan perulangan
- Hasilnya: angka 1-4, 6-9 ditampilkan, lalu loop berhenti

## 🎯 Praktik Terbaik Control Statement

### 💡 Tips Menulis Control Statement yang Baik

- **Gunakan kondisi yang jelas** - Hindari kondisi yang membingungkan
- **Tulis kode yang mudah dibaca** - Gunakan indentasi yang konsisten
- **Hindari nested if yang terlalu dalam** - Maksimal 3-4 tingkat
- **Gunakan switch untuk banyak pilihan** - Lebih efisien daripada if-else bertingkat
- **Selalu gunakan kurung kurawal** - Meskipun hanya satu baris kode

### ⚠️ Kesalahan Umum yang Harus Dihindari

- **Lupa break dalam switch** - Bisa menyebabkan fall-through
- **Infinite loop** - Perulangan yang tidak pernah berhenti
- **Kondisi yang selalu benar/salah** - Perulangan atau percabangan yang tidak efektif
- **Indentasi yang salah** - Membuat kode sulit dibaca

## 📊 Ringkasan Control Statement

### 🔄 Jenis-jenis Control Statement

<div align="center">
| \hline
**Jenis** | **Kegunaan** | **Contoh** |
|---|---|---|
| \hline
if | Percabangan sederhana | if (x > 0) |
| \hline
if-else | Percabangan dengan alternatif | if (x > 0) else |
| \hline
switch | Banyak pilihan | switch (x) case 1: |
| \hline
for | Perulangan dengan counter | for (int i=0; i<n; i++) |
| \hline
while | Perulangan dengan kondisi | while (x > 0) |
| \hline
do-while | Perulangan minimal sekali | do { } while (x > 0) |
| \hline
break | Menghentikan perulangan | break; |
| \hline
continue | Melompati iterasi | continue; |
| \hline |
</div>

### 🎯 Kapan Menggunakan Setiap Jenis

- **if**: Ketika ada satu kondisi yang perlu dicek
- **if-else**: Ketika ada dua alternatif yang berbeda
- **switch**: Ketika ada banyak pilihan berdasarkan nilai yang sama
- **for**: Ketika jumlah perulangan sudah diketahui
- **while**: Ketika jumlah perulangan tidak diketahui
- **do-while**: Ketika kode minimal harus dijalankan sekali
- **break**: Ketika perlu menghentikan perulangan secara paksa
- **continue**: Ketika perlu melompati iterasi tertentu

## 🔍 Latihan dan Soal

### 📝 Latihan 1: Program Kalkulator Sederhana

Buat program kalkulator sederhana yang menerima dua angka dan operator (+, -, *, /) dari pengguna, kemudian menampilkan hasilnya.

### 📝 Latihan 2: Program Menentukan Grade

Buat program yang menerima nilai (0-100) dan menampilkan grade:

- A: 90-100
- B: 80-89
- C: 70-79
- D: 60-69
- E: 0-59

### 📝 Latihan 3: Program Menampilkan Pola

Buat program yang menampilkan pola bintang seperti berikut:
\begin{lcverbatim}
*
**
***
****
*****
\end{lcverbatim}

## 📚 Referensi dan Bacaan Lanjutan

Control statement adalah konsep fundamental dalam pemrograman yang telah dikembangkan sejak awal era komputer. Konsep ini pertama kali diperkenalkan dalam bahasa pemrograman FORTRAN pada tahun 1957[^1]: Backus, J. W. (1957). "The FORTRAN Automatic Coding System". Proceedings of the Western Joint Computer Conference. dan kemudian dikembangkan lebih lanjut dalam bahasa ALGOL[^1]: Naur, P. (1960). "Report on the Algorithmic Language ALGOL 60". Communications of the ACM..

Dalam konteks C++, control statement mengikuti tradisi bahasa C yang dikembangkan oleh Dennis Ritchie di Bell Labs pada tahun 1972[^1]: Ritchie, D. M. (1993). "The Development of the C Language". ACM SIGPLAN Notices.. Bjarne Stroustrup kemudian mengembangkan C++ dengan menambahkan fitur object-oriented programming sambil mempertahankan sintaks control statement yang familiar[^1]: Stroustrup, B. (1994). "The Design and Evolution of C++". Addison-Wesley..

Untuk pemahaman yang lebih mendalam tentang control statement dalam C++, pembaca dapat merujuk pada:

- **The C++ Programming Language** oleh Bjarne Stroustrup[^1]: Stroustrup, B. (2013). "The C++ Programming Language" (4th ed.). Addison-Wesley.
- **Effective C++** oleh Scott Meyers[^1]: Meyers, S. (2005). "Effective C++" (3rd ed.). Addison-Wesley.
- **C++ Primer** oleh Stanley Lippman[^1]: Lippman, S. B., Lajoie, J., & Moo, B. E. (2012). "C++ Primer" (5th ed.). Addison-Wesley.

## 🎉 Kesimpulan

Control statement adalah alat fundamental yang memungkinkan program untuk membuat keputusan dan mengulang operasi. Dengan menguasai konsep ini, Anda telah memiliki fondasi yang kuat untuk mengembangkan program yang lebih kompleks dan dinamis.

<div align="center">
**Selamat! Anda telah menguasai dasar-dasar Control Statement dalam C++** 🎯
</div>




<div align="center">
*--- Bab selanjutnya: Array dan String ---*
</div>