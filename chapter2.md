Program Bahasa C/C++ tidak mengenal aturan penulisan di kolom/baris tertentu, jadi bisa dimulai dari kolom/baris manapun.Namun demikian, untuk mempermudah pembacaan program dan untukkeperluan dokumentasi, sebaiknya penulisan program di bahasa C/C++ diatur sedemikian rupa sehingga mudah dan enak dibaca.
Berikut adalah struktur dasar program yang dibuat dengan bahasa C++:

	#include <header>  
	using namespace std;    
	int main(int argc, char *argv[]) 
	{  
	deklarasi variabel;   
	deklarasi konstanta;  
	perintah âperintah;  
	//komentar  
	return 0;  
	}  

**Penjelasan :** 

#### 1. &#35; include &#60;header&#62;
 
`#include` adalah salah satu pengarah preprocessor directive yang tersedia pada C++. Preprocessor selalu dijalankan terlebih dahulu pada saat proses kompilasi terjadi. Bentuk umumnya:

	# include <nama_file>

Bagian tersebut tidak diakhiri dengan tanda semicolon, karena bentuk tersebut bukanlah suatu bentuk pernyataan, tetapi merupakan preprocessor directive. Baris tersebut menginstruksikan kepada kompiler untuk menyisipkan file lain dalam hal ini file yang berakhiran .h (file header) yaitu file yang berisi C++ standard library. Pada C++ ekstensi .h tidak dituliskan.

Beberap contoh pengikutsertaan berkas adalah:

- `#include <iostream>` : diperlukan pada program yang melibatkan objek `cout` dan `cin`
- `#include <conio>`: diperlukan bila melibatkan `clrscr()`, yaitu perintah untuk membersihkan layar dan fungsi `getch()` untuk menerima sembarang input keyboard dari user.
- `#include <iomanip>` : diperlukan bila melibatkan `setw()` yang bermanfaat untuk mengatur lebar dari suatu tampilan data.
- `#include <math>` : diperlukan pada program yang menggunakan operasi `sqrt()` yang bermanfaat untuk operasi matematika kuadrat.
	
#### 2.	using namespace std;

Semua elemen standard C++ library dinyatakan dalam apa yang disebut namespace, namespace tersebut bernama std. Jadi artinya untuk mengakses semua fungsionalitas std kita menuliskan bahwa kita menggunakan namespace std.

#### 3.	int main ()

Program C++ terdiri dari satu atau lebih fungsi, dan di antara salah satunya harus ada fungsi main dan hanya boleh ada satu main pada tiap program C++. Setiap program C++ akan dan pasti akan memulai eksekusi programnya pada fungsi main ini, meskipun main bukan fungsi yang pertama ditulis di program.
Melihat bentuk seperti itu dapat kita ambil kesimpulan bahwa batang tubuh program utama berada didalam fungsi main(). Berarti dalam setiap pembuatan program utama, maka dapat dipastikan seorangpemrogram menggunakan minimal sebuah fungsi.

Tanda { dan pada akhir program terdapat tanda }. Tanda { harus ada pada setiap awal dari sebuah fungsi dan tentu saja harus diakhiri dengan tanda }. Tanda ini digunakan untuk menunjukkan cakupan(scope) dari sebuah fungsi,dimana untukmenunjukkan fungsi ini dimulai danberakhir.

#### 4.	Komentar

Komentar tidak pernah dicompile oleh compiler. Dalam C++ terdapat 2 jenis komentar, yaitu:

1.	/* Komentar anda diletakkan di dalam ini bisa mengapit lebih dari satu baris */
2.	// Komentar anda diletakkan disini ( hanya bisa sebaris )
	
Programmer sering sekali memasukkan komentar di dalam code agar program lebih mudah dibaca. Komentar juga membantu orang lain untuk membaca dan mengerti isi dari code. Komentar tidak menyebabkan komputer melakukan suatu instruksi ketika program dijalankan.

#### 5.	Tanda Semicolon (;)
Tanda semicolon “ `;` ” digunakan untuk mengakhiri sebuah pernyataan. Setiap pernyataan harus diakhiri dengan sebuah tanda semicolon.

#### 9.	return 0
Pernyataan return menyebabkan fungsi utama untuk menyelesaikan kegiatannya lalu mengembalikanhasil dari fungsi utama. Kode kembalian biasanya angka 0 atau 1. Jika angka yang dikembalikan 0 berartiprogram berakhir dengan tidak ada error, sedangkan jika 1 maka program berakhir dengan error.

Contoh 1.	Structur program C++
Untuk lebih jelasnya silahkan coba ketik program berikut pada project baru.

	#include <QtCore/QCoreApplication>  
	#include <iostream>  
	using namespace std;  
	int main (int argc, char *argv [])  
	{  
	QCoreApplication a (argc, argv);  
	cout<<"Hello World"<<endl;  
	cout<<"Selamat Belajar C/C++ ";  
	cout<<"enter my World";  
	return a.exec ();  
	} 

Kemudian jalankan dengan menekan tombol Run (CTRL + R)

	Hello world
	
	Selamat belajar C/C++ enter my world

Tampilan Hello World diakhiri dengan tanda enter baru kemudian dilanjutkan dengan tulisan berikutnya yaitu Selamat Belajar C/C++ enter my World. Artinya perintah `endl` merupakan perintah untuk memberi tanda enter.
Sedangkan untuk tulisan Selamat Belajar C/C++ dan tulisan enter my World yang pada source code terpisah dengan perintah `cout`, pada tampilan hasil program tetap sama dan tidak ada enter diantaranya. Hal ini karena tidak ada perintah untuk menampilkan enter diantara kedua kalimat tersebut. Penulisan pada kode tidak akan mempengaruhi hasil output program.
