Array dan String
================

Array
-----

Array adalah suatu tipe data terstuktur yang berupa sejumlah data sejenis
(bertipe data sama) yang jumlahnya tetap dan diberi suatu nama tertentu.
Elemen-elemen array tersusun secara sekuensial di dalam memori sehingga memiliki
alamat yang berdekatan. Array dapat berupa array 1 dimensi, 2 dimensi, bahkan
n-dimensi. Elemen-elemen array bertipe data sama tapi bisa bernilai sama atau
berbeda-beda. Array digunakan untuk menyimpan data-data yang diinputkan
masing-masing kedalam memory komputer. Jadi jumlah datanya banyak namun satu
jenis.

Array dapat digunakan untuk menyimpan data yang cukup banyak namun memiliki tipe
yang sama. Bagaimana array melakukan penyimpanan datanya di memory komputer?
Ilustrasi array satu dimensi pada memory komputer adalah sebagai berikut:

![Ilustrasi Array](images/capture3-1.png)

Array menyimpan data secara berurutan pada memory komputer. Sekali array
dideklarasikan (dibuat), maka akan dialokasikan sejumlah tempat di memory
komputer yang selalu letaknya berdekatan (bersebelahan). Array memiliki indeks
dan nilai data itu sendiri. Sedangkan jarak antar elemen pada array disesuaikan
dengan lebar data untuk masing-masing tipe data array. Misalnya pada tipe data
integer, maka jarak antar elemennya bernilai 2 s/d 4 byte. Indeks array pada C++
selalu dimulai dari indeks ke 0, dan seterusnya indeks ke-1, 2, 3, dan lain-lain

Array 1 Dimensi
---------------

Elemen-elemen array dapat diakses oleh program menggunakan suatu indeks
tertentu. Pengaksesan elemen array dapat dilakukan berurutan atau random
berdasarkan indeks tertentu secara langsung. Pengisian dan pengambilan nilai
pada indeks tertentu dapat dilakukan dengan mengeset nilai atau menampilkan
nilai pada indeks yang dimaksud.

### Deklarasi Array satu Dimensi

Bentuk umum deklarasi array satu dimensi:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
tipe_data nama_var_array;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Dimana:

tipe\_data : menyatakan jenis tipe data elemen larik (int, char, float, dll)

nama\_var\_array : menyatakan nama variabel yang dipakai.

ukuran : menunjukkan jumlah maksimal elemen larik.

Contoh:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
char huruf[9];
int umur[10];
int kondisi[2] = {0,1};
int arr_dinamis[] = {1,2,3};
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Artinya:

-   **char huruf[9]:** berarti akan memesan tempat di memori komputer sebanyak 9
    tempat dengan indeks dari 0-8, dimana semua elemennya bertipe data karakter
    semuanya. Kalau satu karakter berukuran 1 byte, berarti membutuhkan memori
    sebesar 9 byte.

-   **int umur[10]:** berarti akan memesan tempat di memori komputer sebanyak 10
    tempat dengan indeks dari 0-9, dimana semua elemennya bertipe data integer
    semuanya. Kalau satu integer berukuran 4 bytes, berarti membutuhkan memori
    sebesar 4 x 10 = 20 bytes.

-   **int kondisi[2]:** berarti akan memesan tempat di memori komputer sebanyak
    2 tempat dengan indeks 0-1, dimana semua elemennya bertipe data integer
    semuanya. Dan pada contoh di atas isi elemen-elemennya yang sebanyak 2 buah
    diisi sekaligus (diinisialisasi) yaitu pada elemen kondisi[0] bernilai 0,
    dan elemen kondisi[1] bernilai 1.

-   **int arr\_dinamis[]:** berarti mendeklarasikan array dengan ukuran maksimum
    array tidak diketahui, namun ukuran tersebut diketahui berdasarkan
    inisialisasi yaitu sebanyak 3 elemen, yang isinya 1,2, dan 3. Ingat bahwa
    array dinamis tidak bisa dibuat tanpa inisialisasi.

Tanda [] disebut juga “elemen yang ke- “. Misalnya “kondisi[0]“ berarti elemen
yang ke nol. Array yang sudah dipesan, misalnya 10 tempat tidak harus diisi
semuanya, bisa saja hanya diisi 5 elemen saja, baik secara berurutan maupun
tidak. Namun pada kondisi yang tidak sepenuhnya terisi tersebut, tempat
pemesanan di memori tetap sebanyak 10 tempat, jadi tempat yang tidak terisi
tetap akan terpesan dan dibiarkan kosong.

**Contoh 1. Contoh Input dan Output Array**

Buatlah project baru dan tulis kode berikut:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int nilai[5], x;
    cout<<"Memasukkan nilai"<<endl;
    for(x=0;x<5;x++)
    {
        cout<<"Nilai Angka ke - "<<x+1<< ": ";
        cin>>nilai[x];
    }
    cout<<endl;
    cout<<"Membaca nilai :\n";
    for(x=0;x<5;x++)
    {
        cout<<"Nilai Angka : "<<nilai[x]<<endl;
    }
    return a.exec();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Hasil:**

![contoh Input Output Array](images/capture3-2.png)

**Analisa**

-   Pada program diatas, kita membuat sebuah variabel `array` bernama nilai yang
    berisi 5 elemen bertipe `integer`. Kemudian untuk memasukkan nilai ke
    masing-masing elemen, digunakan perintah perulangan untuk mengakses
    indeksnya yang dimulai dari indeks ke 0. Perulangan dilakukan dari indeks ke
    0 sampai dengan indeks ke 4 (dalam hal ini x \< 5). Mengapa sampai dengan
    indeks ke 4? Hal ini karena 5 elemen array yang kita deklarasikan dimulai
    dari indeks ke 0. Terdapat 5 elemen array, berarti indeks ke 0, 1, 2, 3, dan
    4.

-   Setelah kita masukkan nilai ke masing-masing elemen, maka kita hanya perlu
    membaca datanya lagi, yaitu dengan melakukan perulangan kembali dengan cara
    mengakses indeks elemenelemennya seperti pada saat kita memasukkan
    elemen-elemen tersebut kedalam array. Perulangan untuk membaca isi elemen
    array juga diulang dari 0 sampai 4, yang artinya juga 5 elemen. Pada
    masing-masing perulangan tersebut, ditampilkan isi elemen ke layar dengan
    perintah `cout<<`.

**Contoh 2. Contoh Manipulasi Array**

Buatlah project baru dan tulis kode berikut:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
int bil[7],i;
cout<<"elemen ke-1 ? "; cin>>bil[0];
bil[1] = 5;
bil[2] = bil[1] + 20;
for(i=4;i<7;i++)
bil[i] = i*10;
bil[3] = bil[bil[1]];
for(i=0;i<7;i++)
cout<<"bil["<<i<<"] = "<<bil[i]<<" dan alamatnya: "<<&bil[i]<<"\n";
return a.exec();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Hasil**

![Contoh Manipulasi array](images/capture3-3.png)

**keterangan:**

-   Program diatas memasukkan nilai-nilai integer kedalam array bernama bil yang
    berisi 7 elemen (dari indeks 0-6).

-   Dalam array satu dimensi, suatu elemen array dapat diisi dengan isi elemen
    array pada indeks tertentu seperti pada contoh bil[2] = bil[1] + 20;. Pada
    contoh diatas, bil[2] diisi dengan bil[1] yang berisi 25 ditambah dengan 20,
    yaitu 55.

-   Pada program bil[3] = bil[bil[1]], artinya bilangan elemen ke-3 diisi dengan
    elemen array yang ke – bil[1]. Bilangan elemen ke-1, bernilai 5, yang
    berarti bil[3] = bil[5]. Bil[5] bernilai 50, berarti bil[3] = 50 juga.

-   Terlihat bahwa jarak antar elemen array bil berjarak 4 bytes.

-   Cara untuk menampilkan alamat array adalah dengan menggunakan operator &

>   **TIPS**

>   Dalam bahasa C++, tidak terdapat error handling terhadap batasan nilai
>   indeks, apakah indeks tersebut berada di dalam indeks array yang sudah
>   didefinisikan atau belum. Hal ini merupakan tanggung jawab programmer.
>   Sehingga jika programmer mengakses indeks yang salah, maka nilai yang
>   dihasilkan akan berbeda atau rusak karena mengakses alamat memori yang tidak
>   sesuai.

**Contoh 3. Penanganan Batas Indeks Elemen Array**

Buatlah program beikut ini:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
int angka[5];
angka[0] = 0; //batas bawah array
angka[4] = 4; //batas atas array
angka[5] = 5; //indeks melebihi batas
//program akan HANG
cout<<angka[5];
return a.exec();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Hasil:**

![Contoh Penanganan batas indeks array](images/capture3-4.png)

**Ketrangan:**

-   Progarm akan HANG-UP. Hal ini terjadi karena compiler tidak bertanggungjawab
    dengan pengaksesan indeks array yang melebihi batas yang dipesankan di
    memory.

-   Mengapa kompiler tidak menampilkan error pada saat kompilasi? Hal ini karena
    secara sintaks, program diatas tidaklah memiliki error penulisan. Error yang
    terjadi pada program diatas adalah runtime error, yaitu error yang terjadi /
    yang bisa dideteksi saat program sudah berjalan!

### Inisialisasi Array Satu Dimensi

Array satu dimensi dapat diisi secara langsung ditulis pada program. Pengisian
data seperti itu sering disebut dengan inisialisasi data array. Cara
menginisialisasi data pada array adalah dengan menuliskannya secara langsung
pada source code program. Berikut contohnya:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// An array of 5 integers, all elements initialized to 0
int IntegerArray[5] = {0};
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Pada contoh diatas, semua elemen array bertipe integer yang berjumlah 5 buah
tersebut diisi dengan nilai 0 semuanya. Cara lain menginisialisasi array satu
dimensi adalah sebagai berikut:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// An array of 5 integers initialized to zero
int IntegerArray[5] = { 0, 0, 0, 0, 0 };
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Nah, bagaimana jika kita ingin menginisialisasi elemen terakhirnya saja? Kita
tidak bisa melakukannya secara langsung. Yang harus dilakukan adalah dengan
menginisialisasinya satu-persatu seperti contoh berikut:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// An array of 5 integers initialized to zero
int IntegerArray[5] = { 0, 0, 0, 0, 6 };
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Pada contoh diatas, elemen terakhir diinilisasi dengan nilai 6. Kita tidak bisa
langsung mengisi dengan cara `int IntegerArray[5] = {6}`, karena jika diisi
dengan cara demikian, maka isi elemen indeks ke-0 bernilai 6, sedangkan elemen
lainnya bernilai 0.

**Contoh 4. Inisialisasi Array dengan nilai 0**

Buatlah program berikut:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int bil[7] = {0}; //inisialisasi 0
    for(int i=0;i<7;i++){
        cout<<"Elemen ke-"<<i<<": "<<bil[i]<<"\n";
    }
    return a.exec();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Hasil:**

![Contoh Inisialisasi Array dengan nilai 0](images/capture3-5.png)

**Keterangan:**

Pada program diatas elemen array bernama bil yang dipesan sebanyak 7 elemen,
diinisialisasi dengan nilai 0. Setelah diinisialisasi dengan nilai 0, maka semua
elemen array tersebut juga akan berisi dengan nilai 0. Hal ini dibuktikan dengan
cara perulangan semua elemen array dan ditampilkan dengan `cout`.

**Contoh 5. Inisialisasi Array dua nilai elemen pertama**

Buatlah program berikut ini:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
int bil[7] = {2,5}; //inisialisasi dua elemen pertama
for(int i=0;i<7;i++){
cout<<"Elemen ke-"<<i<<": "<<bil[i]<<"\n";
}
return a.exec();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Hasil:**

![Contoh Inisialisasi Array dua nilai elemen pertama](images/capture3-6.png)

**Keterangan:**

Inisialisasi elemen array dapat dilakukan hanya pada dua elemen pertama saja,
hal ini dilakukan dengan cara memberikan dua nilai pertama, selanjutnya semua
elemen lainnya yang tidak diinisialisasi secara otomatis bernilai 0.

>   TIPS

>   Untuk semua array pada C++, inisialisasi satu buah elemen saja pada array
>   akan membuat semua elemen array lainnya berisi nilai 0. Contoh: `int
>   angka[100] = {1};` Maka hasilnya adalah: angka[0] = 1, angka[1] s/d
>   angka[99] = 0

Pada array satu dimensi, kita tidak dapat melakukan inisialisasi pada array
melebihi batas jumlah elemen array yang dipesan.

Pada array satu dimensi, kita juga dapat membuat array 1 dimensi tanpa
menyebutkan jumlah elemen array yang dipesan. Namun perlu diingat bahwa semua
elemen harus diinisialisai terlebih dahulu.

**Contoh:**

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int data[5] = {1,2,3,4,5,6}; //error
int data2[] = {10,20}; //terpesan 2 tempat dimemory
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Contoh 6. Tanpa inisialisasi, array langsung ditampilkan**

Tulislah program berikut ini:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
char h[5];
for(int i=0;i<5;i++){
cout<<"Elemen ke "<<i<<" = "<<h[i]<<endl;
}
return a.exec();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Hasil:**

![Contoh Inisialisasi Array dua nilai elemen pertama](images/capture3-7.png)

**Keterangan:**

Pada program C++, elemen array yang sudah dipesan dimemory pasti sudah berisi
data. Namun nilai datanya bersifat acak. Sehingga jika kita mendeklarasikan
sebuah elemen array tanpa diinisialisasi, maka nilai masing-masing elemen akan
bersifat acak juga seperti pada hasil program diatas. Untuk itulah inisialisasi
elemen array sangatlah penting.

>   **TIPS**

>   Inisialisasi pada elemen array yang dideklarsikan **SANGATLAH PENTING**
>   untuk menghindari nilai **ACAK**!

**Contoh 7. Penggunaan tipe data enum pada Array satu dimensi**

Buatlah program berikut:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
enum Hari { Minggu, Senin, Selasa, Rabu, Kamis, Jumat, Sabtu };
int ArrayHari[7] = { 10, 20, 30, 40, 50, 60, 70 };
cout << "Nilai Hari Selasa adalah: " << ArrayHari[Selasa];
return a.exec();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Hasil:**

![Contoh Penggunaan tipe data enum pada Array satu dimensi](images/capture3-9.png)

**Keterangan:**

-   Pada program diatas, kita membuat sebuah tipe data enum bernama Hari yang
    memiliki 7 elemen. Masing-masing elemen enum sama saja seperti indeks array
    yaitu 0-6. Kemudian kita membuat sebuah array bernama ArrayHari yang berisi
    7 elemen juga dan berisi nilai 10-70. Karena kita memanggil
    ArrayHari[Selasa] berarti sama artinya dengan ArrayHari[2]. Mengapa 2?
    Karena indeks Selasa adalah 2. Sehingga muncullah output berupa 30, karena
    30 berada pada indeks ke-2 dari ArrayHari.

-   Arti dari program diatas menunjukkan kita dapat mengakses indeks array
    dengan menggunakan tipe data enum, karena tipe data enum pada kenyataannya
    akan dikonversikan kedalam nilai integer, mulai dari 0.

### Pengalamatan dan Pengkopian Array 1 Dimensi

Array tidak bisa disalin begitu saja antara array satu yang ada nilainya ke
array lain yang kosong. Hal ini dikerenakan array bukanlah tipe data primitif
biasa. Array merupakan tipe data referensi dimana data yang berada didalam
elemen array berjumlah lebih dari satu buah dan diakses dengan menggunakan
alamat memory. Compiler C++ akan mencatat alamat pertama dari indeks pertama
array yang kita deklarasikan.

Contoh:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int data[5] = {1,2,3,4,5};
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Maka variabel array data tersebut akan dicatat alamat elemen data[0] pada
memory. Jika kita mengakses elemen keduanya, yaitu data[1], maka compiler akan
melakukan kalkulasi untuk mendapatkan alamat data[1], yaitu dengan cara
menambahkan alamat data[0] dengan lebar tipe data array yang kita deklarasikan.
Pada contoh diatas, kita membuat array bertipe integer. Karena integer berukuran
4 byte, maka jika data[0] beralamat di alamat 1000, maka data[1] beralamat di
1000 + 4 = 1004 dan seterusnya.

Lalu bagaimana cara mengkopikan isi elemen array dari satu variabel ke variable
array 1 dimensi lainnya? Kita harus menggunakan cara manual, yaitu mengkopikan
masing-masing elemennya satu persatu dengan perulangan manual sesuai dengan
jumlah elemen array yang dibuat.

**Contoh 8. Percobaan Penyalinan Array 1 dimensi**

Buatlah program berikut:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
int A[6]={1,2,3,4,5,6};
int B[6];
B = A;
return a.exec();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Hasil:**

![Contoh Percobaan Penyalinan Array 1 dimensi](images/capture3-8.png)

**Keterangan:**

Program tidak bisa dijalankan karena terdapat error, bahwa array tidak bisa
dilakukan operasi assigment. Artinya kita tidak bisa mengkopi antar array begitu
saja.

**Contoh 9. Penyalinan Array 1 dimensi dengan Perulangan**

Buatlah program berikut ini:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
int A[6]={1,2,3,4,5,6};
int B[6];
for(int i=0;i<6;i++){
B[i]=A[i];
}
for(int j=0;j<6;j++){
cout<<B[j]<<endl;
}
return a.exec();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

**Hasil:**

![Contoh Penyalinan Array 1 dimensi dengan Perulangan](images/capture3-10.png)

**Keterangan:**

-   Cara penyalinan array adalah dengan melakukan perulangan sebanyak elemen
    array yang akan disalin dan menyalinnya secara manual satu-persatu pada
    indeks yang sama.

-   Kemudian ditampilkan sesuai dengan indeksnya. Elemen array yang dikopikan
    masih tetap memiliki array yang asli. Untuk menghapusnya, maka harus
    dilakukan secara manual.

## Array Multi Dimensi
-------------------

Array multi dimensi berarti array yang kita deklasaikan dapat dikembangkan ke
array dimensi 2 dan seteruanya. Array multi dimensi merupakan topik yang menarik
dalam matematika. Setiap dimensi dalam array direpresentasikan sebagai sub
bagian dalam array. Oleh karena itu, array dua dimensi array memiliki dua sub
bagian, sebuah array tiga-dimensi memiliki tiga sub bagian dan sebagainya.
Sebuah contoh bentuk nyata yang baik dari array dua dimensi adalah sebuah papan
catur. Satu dimensinya merupakan delapan baris, sedangkan dimensi lainnya
merupakan delapan kolom.

Contoh deklarasi array dua dimensi yang menggambarkan papan catur adalah:

	int papan[8][8];

yang digambarkan dalam bentuk:  


![ILustrasi array multi dimensi](images/capture3-11.png)

Array dua dimensi sering kali digambarkan/dianalogikan sebagai sebuah matriks atau bentuk grid. Jika array berdimensi satu hanya terdiri dari 1 baris dan banyak kolom, array berdimensi dua terdiri dari banyak baris dan banyak kolom yang bertipe sama. Ilustrasi array dua dimensi dapat dilihat sebagai berikut.

Berikut adalah gambar array berdimensi (baris x kolom = 3 x 4)

![Array dimensi 3 x 4](images/capture3-12.png)

## Deklarasi Array 2 dimensi

	tipe_data nama_var_array[batas_baris][batas_kolom];

Contoh:

	int matriks[3][4];
	int matriks2[3][4] = { {5,20,1,11}, {4,7,67,-9}, {9,0,45,3} };

Array dua dimensi dapat mewakili bentuk suatu matriks, contoh matriks:

	x =

selanjutnya dapat dideklarasikan sebagai berikut:

	int x[2][4];

atau diklarasikan dengan langsung menginisialisasi nilai elemen-elemen-nya sebagai berikut:

	int x[2][4]= {{8, 5, 9, 8},{8, 2, 1, 0}}

Selanjutnya larik dua dimensi x dapat digambarkan sebagai berikut:

	x[0][0]=8 x[0][1]=5 x[0][2]=9 x[0][3]=8
	x[1][0]=8 x[1][1]=2 x[1][2]=1 x[1][3]=0

Array dua dimensi dapat digunakan untuk menampung tipe data numerik atau non numerik. Berikut adalah berbagai bentuk pembuatan array dua dimensi dengan tipe data numerik ataupun non numerik.

Array dua dimensi bertipe data numerik

	int matriks[3][5] = {{5,12,17,10,7},
						{15,6,25,2,19},
						{4,9,20,22,11}};

Jika data array integer yang diinputkan kurang dari deklarasi

	int matriks[3][5] = {{5,12,17,10,7},
						{15,6,25,2,19},
						{4,9 }}; //kurang 3 angka

Maka tiga data yang kurang akan diisi dengan angka 0

Array 2 dimensi dapat juga digunakan untuk menyimpan data karakter (character). Pendeklarasian array 2 dimensi character adalah sebagai berikut:

	char matriks[3][5] = {{’A’,’B’,’C’,’D’,’E’},
						{’F’,’G’,’H’,’I’,’J’},
						{’K’,’L’,’M’,’N’,’O’}};
						char matriks[3][5] = {“ABCDE“,
						“FGHIJ“,
						“KLMNO“};
