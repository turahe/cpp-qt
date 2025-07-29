**📋 Apa yang akan dipelajari**

Pada bab ini kita akan mempelajari tentang debugging - seni menemukan dan memperbaiki bug dalam program:

- Jenis-jenis kesalahan dalam pemrograman
- Menggunakan debugger di Qt Creator
- Teknik debugging yang efektif
- Tips menemukan dan memperbaiki bug
- Best practices untuk debugging

\minitoc

## 🐛 Pengenalan Debugging

### Apa itu Debugging?

Debugging adalah proses menemukan, menganalisis, dan memperbaiki kesalahan (bug) dalam program komputer. Istilah "debugging" berasal dari tahun 1947 ketika Grace Hopper menemukan seekor ngengat (bug) yang menyebabkan komputer Harvard Mark II mengalami kerusakan.

> 
*"Debugging adalah dua kali lebih sulit daripada menulis kode. Jika Anda menulis kode secerdas mungkin, Anda tidak cukup pintar untuk debug-nya."* - Brian Kernighan

### Mengapa Debugging Penting?

- **Memastikan program berjalan dengan benar** - Program yang bebas bug
- **Meningkatkan kualitas kode** - Kode yang lebih robust
- **Menghemat waktu** - Mencegah bug di masa depan
- **Meningkatkan skill pemrograman** - Belajar dari kesalahan

## 🚨 Jenis-jenis Kesalahan dalam Pemrograman

### 1. Syntax Error (Kesalahan Sintaks)

Syntax error adalah kesalahan dalam penulisan kode yang melanggar aturan bahasa pemrograman.

#### Contoh Syntax Error

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World"  // Lupa semicolon
    int x = 5;
    if (x == 5 {          // Lupa kurung tutup
        cout << "x adalah 5";
    }
    return 0;
}
```

#### Cara Mengatasi Syntax Error

- **Baca pesan error** - Compiler akan memberitahu lokasi error
- **Periksa tanda baca** - Semicolon, kurung, kurawal
- **Periksa nama variabel** - Case sensitive
- **Periksa include** - Header yang diperlukan

### 2. Logic Error (Kesalahan Logika)

Logic error adalah kesalahan dalam logika program yang menyebabkan program berjalan tapi menghasilkan hasil yang salah.

#### Contoh Logic Error

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 5;
    int hasil = a - b;  // Seharusnya a + b
    
    cout << "Hasil: " << hasil << endl;  // Output: 5 (salah)
    return 0;
}
```

#### Cara Mengatasi Logic Error

- **Trace program** - Ikuti alur program step by step
- **Tambahkan output debug** - Print nilai variabel
- **Gunakan debugger** - Set breakpoint dan inspect
- **Review logika** - Periksa algoritma

### 3. Runtime Error (Kesalahan Waktu Jalankan)

Runtime error adalah kesalahan yang terjadi saat program sedang berjalan.

#### Jenis Runtime Error

- **Segmentation Fault** - Akses memory yang tidak valid
- **Division by Zero** - Pembagian dengan nol
- **Array Out of Bounds** - Akses array di luar batas
- **Null Pointer** - Akses pointer yang null

#### Contoh Runtime Error

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    cout << arr[10] << endl;  // Array out of bounds
    
    int x = 10, y = 0;
    int hasil = x / y;  // Division by zero
    
    return 0;
}
```

## 🔧 Menggunakan Debugger di Qt Creator

### Apa itu Debugger?

Debugger adalah tool yang memungkinkan kita untuk:

- **Menghentikan program** pada titik tertentu
- **Melihat nilai variabel** saat program berjalan
- **Mengikuti alur program** step by step
- **Mengidentifikasi lokasi bug** dengan tepat

### Debugger di Qt Creator

Qt Creator menyediakan debugger yang terintegrasi dengan fitur-fitur:

- **Breakpoint** - Titik berhenti program
- **Step Over** - Jalankan baris saat ini
- **Step Into** - Masuk ke dalam fungsi
- **Step Out** - Keluar dari fungsi
- **Continue** - Lanjutkan sampai breakpoint berikutnya

### Cara Menggunakan Debugger

#### Langkah 1: Set Breakpoint

- Buka file source code
- Klik di sebelah kiri nomor baris (area merah)
- Breakpoint akan muncul sebagai titik merah

#### Langkah 2: Jalankan Debug

- Klik tombol "Debug" (icon bug) atau tekan F5
- Program akan berhenti di breakpoint
- Panel debug akan muncul di bawah

#### Langkah 3: Inspect Variabel

- **Locals** - Lihat variabel lokal
- **Watch** - Tambahkan variabel untuk di-monitor
- **Call Stack** - Lihat fungsi yang dipanggil

### Contoh Program untuk Debug

```cpp
#include <iostream>
using namespace std;

int hitungFaktorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * hitungFaktorial(n - 1);
}

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    
    int hasil = hitungFaktorial(angka);
    cout << "Faktorial dari " << angka << " adalah: " << hasil << endl;
    
    return 0;
}
```

### Langkah Debug Program Faktorial

- **Set breakpoint** di baris `int hasil = hitungFaktorial(angka);`
- **Jalankan debug** dengan F5
- **Step Into** untuk masuk ke fungsi faktorial
- **Monitor variabel** n dan hasil rekursi
- **Step Over** untuk melihat alur rekursi

## 🔍 Teknik Debugging yang Efektif

### 1. Print Debugging

Menambahkan output untuk melihat nilai variabel:

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10, y = 5;
    
    cout << "DEBUG: x = " << x << ", y = " << y << endl;
    
    int hasil = x + y;
    cout << "DEBUG: hasil = " << hasil << endl;
    
    cout << "Hasil: " << hasil << endl;
    return 0;
}
```

### 2. Assert Statements

Menggunakan assert untuk memverifikasi kondisi:

```cpp
#include <iostream>
#include <cassert>
using namespace std;

int bagi(int a, int b) {
    assert(b != 0 && "Pembagian dengan nol!");
    return a / b;
}

int main() {
    int hasil = bagi(10, 2);
    cout << "Hasil: " << hasil << endl;
    
    // hasil = bagi(10, 0); // Akan crash dengan pesan assert
    return 0;
}
```

### 3. Logging

Menggunakan sistem logging untuk debug:

```cpp
#include <iostream>
#include <fstream>
using namespace std;

void logDebug(const string& message) {
    ofstream logFile("debug.log", ios::app);
    logFile << "[DEBUG] " << message << endl;
    logFile.close();
}

int main() {
    logDebug("Program dimulai");
    
    int x = 10;
    logDebug("x = " + to_string(x));
    
    int hasil = x * 2;
    logDebug("hasil = " + to_string(hasil));
    
    logDebug("Program selesai");
    return 0;
}
```

## 💡 Tips Menemukan dan Memperbaiki Bug

### Tips Umum

- **Baca pesan error dengan teliti** - Seringkali solusi ada di pesan error
- **Periksa kode secara sistematis** - Dari atas ke bawah
- **Gunakan pencarian** - Cari nama variabel atau fungsi
- **Periksa dokumentasi** - Baca manual fungsi yang digunakan
- **Tanya teman atau forum** - Fresh eyes sering menemukan bug

### Tips untuk Syntax Error

- **Periksa tanda baca** - Semicolon, kurung, kurawal
- **Periksa case** - C++ case sensitive
- **Periksa include** - Header yang diperlukan
- **Periksa namespace** - using namespace std

### Tips untuk Logic Error

- **Trace program** - Ikuti alur step by step
- **Tambahkan output debug** - Print nilai variabel
- **Gunakan debugger** - Set breakpoint dan inspect
- **Review algoritma** - Periksa logika program
- **Test dengan input sederhana** - Mulai dari kasus mudah

### Tips untuk Runtime Error

- **Periksa array bounds** - Jangan akses di luar batas
- **Periksa pointer** - Pastikan tidak null
- **Periksa division** - Jangan bagi dengan nol
- **Periksa memory** - Pastikan alokasi berhasil

## 🛠️ Best Practices untuk Debugging

### 1. Tulis Kode yang Bersih

```cpp
// Kode yang sulit di-debug
int x=5,y=10,z;z=x+y;cout<<z;

// Kode yang mudah di-debug
int x = 5;
int y = 10;
int hasil = x + y;
cout << "Hasil: " << hasil << endl;
```

### 2. Gunakan Nama Variabel yang Bermakna

```cpp
// Buruk
int a, b, c;

// Baik
int umur, tinggi, berat;
```

### 3. Tambahkan Komentar

```cpp
// Hitung rata-rata dari array
int hitungRataRata(int arr[], int ukuran) {
    int total = 0;
    
    // Jumlahkan semua elemen
    for(int i = 0; i < ukuran; i++) {
        total += arr[i];
    }
    
    // Bagi dengan jumlah elemen
    return total / ukuran;
}
```

### 4. Gunakan Version Control

- **Commit secara teratur** - Setiap fitur selesai
- **Tulis pesan commit yang jelas** - Jelaskan perubahan
- **Gunakan branch** - Pisahkan development dan bug fix
- **Review kode** - Minta teman review kode Anda

## 🎯 Latihan Debugging

### Latihan 1: Debug Program Sederhana

Debug program berikut yang memiliki beberapa bug:

```cpp
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    
    if (angka > 0) {
        cout << "Angka positif" << endl;
    } else if (angka < 0) {
        cout << "Angka negatif" << endl;
    } else {
        cout << "Angka nol" << endl;
    }
    
    return 0;
}
```

### Latihan 2: Debug Program Array

Debug program array berikut:

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Hitung rata-rata
    int total = 0;
    for(int i = 0; i <= 5; i++) {  // Bug: seharusnya < 5
        total += arr[i];
    }
    
    int rataRata = total / 5;
    cout << "Rata-rata: " << rataRata << endl;
    
    return 0;
}
```

## 📚 Referensi dan Bacaan Lanjutan

Untuk pemahaman yang lebih mendalam tentang debugging, pembaca dapat merujuk pada:

- **Qt Creator Debugging Manual** - Dokumentasi resmi Qt[^1]: Qt Company. (2023). "Debugging in Qt Creator". https://doc.qt.io/qtcreator/creator-debugging.html
- **GDB Manual** - GNU Debugger documentation[^1]: Free Software Foundation. (2023). "GDB: The GNU Project Debugger". https://www.gnu.org/software/gdb/
- **Effective C++ Debugging** - Best practices[^1]: Meyers, S. (2005). "Effective C++: 55 Specific Ways to Improve Your Programs and Designs". Addison-Wesley.
- **Debugging Techniques** - Artikel online[^1]: Stack Overflow. (2023). "Debugging Techniques". https://stackoverflow.com/questions/tagged/debugging

## 🎉 Kesimpulan

Debugging adalah skill penting yang harus dikuasai oleh setiap programmer. Dengan memahami jenis-jenis kesalahan dan menggunakan tools debugging yang tepat, Anda dapat menjadi programmer yang lebih efektif dan produktif.

<div align="center">
**Ingat: Debugging adalah bagian dari proses pemrograman, bukan tanda kegagalan!** 🐛✨
</div>




<div align="center">
*--- Bab selanjutnya: Array dan String ---*
</div> 