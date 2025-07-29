# C++ dan Qt Programming Guide

[![Build PDF](https://github.com/your-username/cpp-qt/actions/workflows/build-pdf.yml/badge.svg)](https://github.com/your-username/cpp-qt/actions/workflows/build-pdf.yml)
[![Markdown Validation](https://github.com/your-username/cpp-qt/actions/workflows/build-markdown.yml/badge.svg)](https://github.com/your-username/cpp-qt/actions/workflows/build-markdown.yml)
[![Test Build](https://github.com/your-username/cpp-qt/actions/workflows/test-build.yml/badge.svg)](https://github.com/your-username/cpp-qt/actions/workflows/test-build.yml)

📚 **Buku panduan lengkap untuk belajar C++ dan Qt Framework**

## 🎯 Tentang Buku Ini

Buku ini dirancang khusus untuk pemula yang ingin menguasai pemrograman C++ dan pengembangan aplikasi dengan Qt Framework. Dengan pendekatan pembelajaran bertahap dan contoh kode yang lengkap, Anda akan belajar dari dasar hingga mahir.

## 🚀 Fitur Utama

- **📖 Pembelajaran Bertahap** - Dari dasar hingga lanjutan
- **💻 333+ Contoh Kode** - Siap jalankan dengan Qt Creator
- **🎨 GUI Programming** - Membuat aplikasi dengan antarmuka grafis
- **🗄️ Database Integration** - SQLite dan MySQL
- **🌐 Web Integration** - Qt WebKit untuk browser
- **🐛 Debugging Guide** - Teknik debugging yang efektif
- **🏗️ Design Patterns** - Singleton, Observer, MVC
- **📱 Cross-Platform** - Windows, macOS, Linux

## 📖 Struktur Buku

### Part I: Dasar Pemrograman C++
- **Pengenalan C++ dan Qt Creator** - Sejarah dan setup
- **Tipe Data dan Operator** - Fondasi programming
- **Control Statement** - Struktur kontrol (if, switch, loop)
- **Array dan String** - Koleksi data dan manipulasi teks
- **Fungsi** - Modularisasi program
- **Pointer dan References** - Memory management
- **Debugging** - Teknik debugging

### Part II: Object-Oriented Programming
- **Class dan Object** - OOP fundamentals
- **Inheritance** - Pewarisan sifat
- **Operator Overloading** - Custom operators
- **Polymorphism** - Fleksibilitas objek
- **Design Patterns** - Solusi terbukti
- **Casting dan Database** - Konversi dan data

### Part III: Qt Library dan Komponen
- **Qt Library** - Library fundamentals
- **File, Stream, dan XML** - Data handling
- **Qt WebKit** - Web integration

### Part IV: Antarmuka Pengguna
- **GUI dengan Qt** - Antarmuka grafis

## 🛠️ Cara Menggunakan

### 📖 Membaca Buku

#### **Format LaTeX (PDF)**
```bash
# Build PDF locally
cd latex
pdflatex book.tex
# PDF akan tersedia di latex/book.pdf
```

#### **Format Markdown**
```bash
# Baca file Markdown di folder manuscript/
open manuscript/book.md
```

### 💻 Menjalankan Contoh Kode

1. **Install Qt Creator**
   ```bash
   # Download dari https://www.qt.io/download
   # Atau gunakan package manager
   ```

2. **Clone repository**
   ```bash
   git clone https://github.com/your-username/cpp-qt.git
   cd cpp-qt
   ```

3. **Buka contoh kode**
   ```bash
   # Contoh kode tersedia di folder code/
   # Buka dengan Qt Creator
   ```

## 🔧 Development

### 📋 Requirements

- **Qt Creator 5.15+** atau Qt 6.x
- **C++ compiler** (GCC, MSVC, Clang)
- **Python 3.9+** (untuk script konversi)
- **TeX Live** (untuk build PDF)

### 🚀 Setup Development

```bash
# Clone repository
git clone https://github.com/your-username/cpp-qt.git
cd cpp-qt

# Install Python dependencies
pip install pathlib

# Sync LaTeX to Markdown
python latex_to_markdown_enhanced.py
python embed_code_final.py
```

### 📝 Menambah Konten

1. **Edit file LaTeX** di folder `latex/`
2. **Jalankan sync script** untuk update Markdown
3. **Commit perubahan**
4. **Push ke repository**

```bash
# Edit LaTeX file
vim latex/01-pengenalan.tex

# Sync to Markdown
python latex_to_markdown_enhanced.py
python embed_code_final.py

# Commit changes
git add .
git commit -m "Update chapter 1"
git push
```

## 🔄 CI/CD Pipeline

### 📊 GitHub Actions Workflows

#### **1. Build PDF (`build-pdf.yml`)**
- **Trigger**: Push tags (v*)
- **Action**: Build PDF from LaTeX
- **Output**: Create GitHub release with PDF attachment

#### **2. Markdown Validation (`build-markdown.yml`)**
- **Trigger**: Push to main/master
- **Action**: Validate Markdown files
- **Output**: Generate documentation

#### **3. LaTeX to Markdown Sync (`sync-latex-markdown.yml`)**
- **Trigger**: Changes in latex/ or code/
- **Action**: Auto-sync LaTeX to Markdown
- **Output**: Updated Markdown files

#### **4. Test Build (`test-build.yml`)**
- **Trigger**: Push/PR to main/master
- **Action**: Validate project structure
- **Output**: Test report

### 🏷️ Creating Releases

#### **Automatic Release (Recommended)**
```bash
# Create and push tag
git tag -a v1.0.0 -m "Release v1.0.0"
git push origin v1.0.0

# GitHub Actions will automatically:
# 1. Build PDF
# 2. Create release
# 3. Attach PDF to release
```

#### **Manual Release**
```bash
# Use the release script
chmod +x scripts/create-release.sh
./scripts/create-release.sh v1.0.0 "Initial release"
```

### 📋 Release Process

1. **Update version** in LaTeX files
2. **Create git tag** with version
3. **Push tag** to trigger workflow
4. **GitHub Actions** builds PDF
5. **Release created** with PDF attachment
6. **Share release** with community

## 📁 Project Structure

```
cpp-qt/
├── 📄 latex/                 # LaTeX source files
│   ├── book.tex             # Main book file
│   ├── 01-pengenalan.tex   # Chapter files
│   └── ...
├── 📝 manuscript/           # Markdown files
│   ├── README.md           # Book documentation
│   ├── book.md             # Main book structure
│   ├── 01-pengenalan.md    # Chapter files
│   └── ...
├── 💻 code/                # Code examples
│   ├── contoh-a.cpp        # Example files
│   ├── contoh-b.cpp
│   └── ...
├── 🔧 .github/workflows/   # CI/CD workflows
│   ├── build-pdf.yml       # PDF build workflow
│   ├── build-markdown.yml  # Markdown validation
│   └── ...
├── 📜 scripts/             # Utility scripts
│   └── create-release.sh   # Release script
└── 📋 README.md            # This file
```

## 🎯 Learning Path

### 🚀 Untuk Pemula
1. **Baca Prakata** - `manuscript/00-prakata.md`
2. **Install Qt Creator** - Setup development environment
3. **Ikuti Bab 1** - Pengenalan C++ dan Qt Creator
4. **Praktik Kode** - Jalankan contoh di setiap bab

### 🎯 Untuk Intermediate
1. **Review OOP** - Part II chapters
2. **Praktik Design Patterns** - Bab 11
3. **Buat Project GUI** - Part IV
4. **Integrasi Database** - Bab 10

### 🏆 Untuk Advanced
1. **Custom Qt Components** - Extend Qt
2. **Performance Optimization** - Advanced C++
3. **Cross-Platform Development** - Multi-platform apps
4. **Contribute to Qt** - Open source contribution

## 📚 Referensi

### 🔗 Link Penting
- **[Qt Documentation](https://doc.qt.io/)** - Official Qt docs
- **[C++ Reference](https://en.cppreference.com/)** - C++ standard library
- **[Qt Creator](https://www.qt.io/product/development-tools)** - IDE download

### 📖 Buku Pendukung
- "The C++ Programming Language" - Bjarne Stroustrup
- "Qt 5.9 C++ Development Guide" - The Qt Company
- "Effective C++" - Scott Meyers

## 👨‍💻 Tentang Penulis

**Nur Wachid** - Head of Software Engineering di PT. Lingkar Kreasi Teknologi

- **🌐 Website**: https://www.wach.id
- **📧 Email**: [email protected]
- **💼 LinkedIn**: [LinkedIn Profile]

## 🤝 Kontribusi

### 📝 Cara Berkontribusi
1. **Fork repository** ini
2. **Buat branch** untuk fitur baru
3. **Edit LaTeX files** untuk konten
4. **Jalankan sync script** untuk update Markdown
5. **Commit dan push** perubahan
6. **Buat Pull Request**

### 🐛 Melaporkan Bug
- Buat issue baru di repository
- Jelaskan masalah dengan detail
- Sertakan screenshot jika diperlukan

### 💡 Saran Fitur
- Buat issue dengan label "enhancement"
- Jelaskan fitur yang diinginkan
- Berikan contoh use case

## 📄 Lisensi

Buku ini menggunakan lisensi **Creative Commons Attribution-NonCommercial 4.0 International License**.

### 📋 Lisensi Detail
- **✅ Boleh**: Copy, distribute, adapt, remix
- **❌ Tidak boleh**: Commercial use
- **📝 Wajib**: Attribution to author

## 🎉 Acknowledgments

- **Qt Company** - Untuk framework yang luar biasa
- **C++ Community** - Untuk bahasa pemrograman yang powerful
- **Open Source Contributors** - Untuk kontribusi dan feedback
- **Readers** - Untuk dukungan dan semangat belajar

---

## 🚀 Quick Start

```bash
# Clone repository
git clone https://github.com/your-username/cpp-qt.git
cd cpp-qt

# Install Qt Creator
# Download dari https://www.qt.io/download

# Baca buku
open manuscript/book.md

# Jalankan contoh
# Buka code/contoh-a.cpp di Qt Creator
```

**Selamat belajar dan happy coding! 🎉**

---

*"Programming is not about typing, it's about thinking."* - Rich Hickey