# Pengenalan

##Pengantar Bahasa C dan C++

Bahasa C merupakan bahasa pemrograman tingkat menengah. Pada tahun 1972 bahasa C pertama kali dirancang oleh [**Dennis M Ritchie**](https://id.wikipedia.org/wiki/Dennis_Ritchie) di Bell Laboratories. Kemudian tahun 1978 Dennis dan [Brian W. Kernighan](https://id.wikipedia.org/wiki/Brian_Kernighan) mempublikasikan bahasa C melalui “[The C Programming Language](https://id.wikipedia.org/wiki/The_C_Programming_Language)” sehingga bahasa C dikenal banyak orang. Selanjutnya pada tahun 1989, akhirnya bahasa C distandardisasi [ANSI](https://id.wikipedia.org/wiki/ANSI_C) (American National Standard Institute) sehingga bahasa C menjadi bahasa pemrograman standar hingga saat ini dan bisa dibuat kompilernya pada beberapa platform yang berbeda-beda.

Bahasa C dikatakan sebagai bahasa pemrograman terstruktur, fungsional karena strukturnya menggunakan fungsi-fungsi sebagai program-program bagian (subroutine/ module). Fungsi-fungsi selain fungsi utama disebut `subroutine/ module` dan ditulis setelah fungsi utama (main) atau diletakkan pada file pustaka (library). Jika fungsi-fungsi diletakkan pada file *pustaka* dan akan dipakai disuatu program, maka nama file *header*-nya harus dilibatkan dalam program menggunakan preprocessor directive `#include`.

Kemudian bahasa C dikembangkan oleh Bjarne Stroustrup at Bell Labs menjadi bahasa C++. Pada bulan Oktober 1985 munculah buku The C + + Programming Language yang membahas tentang bahasa pemrograman itu langsung dari penciptanya sendiri. Bahasa C++ mengalami dua tahap evolusi.

- Pertama, dirilis oleh [** AT&T Laboratories**](https://id.wikipedia.org/wiki/Bell_Laboratories), dinamakan [**cfront**](https://en.wikipedia.org/wiki/Cfront). C++ versi ini hanya berupa kompiler yang menterjemahkan bahasa C++ menjadi bahasa C untuk dieksekusi
- Kedua, [**Borland International Inc**](https://en.wikipedia.org/wiki/Borland). mengembangkan kompiler C++ menjadi sebuah kompiler yang mampu mengubah C++ langsung menjadi bahasa mesin (assembly). Tahun 1990, C++ mulai diarahkan ke pengembangan [**Pemrograman Berorientasi Obyek**](https://id.wikipedia.org/wiki/Pemrograman_berorientasi_objek).

Beberapa keunggulan C++ dibandingkan dengan bahasa C adalah sebagai berikut.

Object-oriented programming
: Bahasa pemrograman ini sangat mendukung pemrograman berorientasi obyek yang melihat permasalahan secara obyek dan bukan prosedural.

Portability
: Kita dapat mengkompilasi C++ kode yang sama di hampir semua jenis komputer dan sistem operasi tanpa membuat perubahan apapun. C++ adalah bahasa pemrograman yang paling sering digunakan di dunia.

Brevity
: Karena bahasa C++ merupakan bahasa tingkat tinggi, maka bahasa yang ditulis dengan bahasa
C++ termasuk ringkas dan pendek dibandingkan bahasa-bahasa sejamannya pada waktu itu.Bahasa C++ termasuk bahasa pemrograman tua yang sudah mendukung berbagai macam kata
kunci yang mampu menyingkat proses penulisan kode program.

Modular programming
: Tubuh program pada bahasa C++ dapat terdiri dari beberapa file source code yang disusun secara terpisah dan kemudian dihubungkan secara bersama-sama. Kemampuan ini jelas menghemat waktu karena tidak perlu mengkompilasi ulang aplikasi yang lengkap ketika membuat satu perubahan, tetapi hanya file yang berisi perubahan itu saja. Selain itu, karakteristik ini memungkinkan kita untuk menghubungkan kode C++ dengan kode yang dibuat oleh bahasa lain, seperti bahasa Assembly dan C dan dapat digunakan kembali (reuseable).

C Compatibility
: C++ sangat backward compatible dengan bahasa C, sehingga aplikasi / kode program yang ditulis dengan bahasa C dapat digabungkan dengan bahasa C++ dengan sangat mudah, bahkan hampir tidak perlu mengubah kodenya.

Speed
: Kode yang dihasilkan dari kompilasi C++ sangat efisien, karena C++ mendukung prinsip dualitas bahwa dia mendukung bahasa tingkat tinggi dan bahasa tingkat rendah sehingga dapat mengurangi ukuran hasil kompiliasi dari bahasa itu.