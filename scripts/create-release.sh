#!/bin/bash

# Create Release Script
# This script helps create a new release with proper tagging

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Check if version is provided
if [ $# -eq 0 ]; then
    print_error "Usage: $0 <version> [message]"
    echo "Example: $0 v1.0.0 'Initial release'"
    exit 1
fi

VERSION=$1
MESSAGE=${2:-"Release $VERSION"}

print_status "Creating release $VERSION..."

# Validate version format
if [[ ! $VERSION =~ ^v[0-9]+\.[0-9]+\.[0-9]+$ ]]; then
    print_error "Version must be in format vX.Y.Z (e.g., v1.0.0)"
    exit 1
fi

# Check if we're in a git repository
if ! git rev-parse --git-dir > /dev/null 2>&1; then
    print_error "Not in a git repository"
    exit 1
fi

# Check if there are uncommitted changes
if ! git diff-index --quiet HEAD --; then
    print_warning "You have uncommitted changes. Please commit or stash them first."
    read -p "Continue anyway? (y/N): " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        exit 1
    fi
fi

# Check if tag already exists
if git tag -l | grep -q "^$VERSION$"; then
    print_error "Tag $VERSION already exists"
    exit 1
fi

print_status "Building PDF..."

# Check if we have the necessary files
if [ ! -f "latex/book.tex" ]; then
    print_error "latex/book.tex not found"
    exit 1
fi

# Try to build PDF if pdflatex is available
if command -v pdflatex >/dev/null 2>&1; then
    print_status "Building PDF with pdflatex..."
    cd latex
    pdflatex -interaction=nonstopmode book.tex
    if [ -f "book.pdf" ]; then
        print_success "PDF built successfully"
        cd ..
    else
        print_warning "PDF build failed, continuing without PDF"
        cd ..
    fi
else
    print_warning "pdflatex not found, skipping PDF build"
fi

print_status "Creating git tag..."

# Create and push tag
git tag -a "$VERSION" -m "$MESSAGE"
git push origin "$VERSION"

print_success "Tag $VERSION created and pushed"

print_status "Creating GitHub release..."

# Create GitHub release using gh CLI if available
if command -v gh >/dev/null 2>&1; then
    if [ -f "latex/book.pdf" ]; then
        gh release create "$VERSION" \
            --title "C++ dan Qt Programming Guide $VERSION" \
            --notes-file - \
            latex/book.pdf << EOF
# C++ dan Qt Programming Guide $VERSION

## 📚 Tentang Buku Ini

Buku panduan lengkap untuk belajar C++ dan Qt Framework. Dirancang khusus untuk pemula yang ingin menguasai pemrograman C++ dan pengembangan aplikasi dengan Qt.

## 🎯 Fitur Utama

- **Pembelajaran Bertahap** - Dari dasar hingga lanjutan
- **Contoh Kode Lengkap** - 333+ contoh program siap jalankan
- **Qt Creator Integration** - IDE modern untuk development
- **GUI Programming** - Membuat aplikasi dengan antarmuka grafis
- **Database Integration** - SQLite dan MySQL
- **Web Integration** - Qt WebKit untuk browser
- **Debugging Guide** - Teknik debugging yang efektif
- **Design Patterns** - Singleton, Observer, MVC

## 📖 Struktur Buku

### Part I: Dasar Pemrograman C++
- Pengenalan C++ dan Qt Creator
- Tipe data, variabel, dan operator
- Control statement (if, switch, loop)
- Array dan string manipulation
- Fungsi dan modularisasi
- Pointer dan references
- Debugging techniques

### Part II: Object-Oriented Programming
- Class dan object
- Inheritance dan polymorphism
- Operator overloading
- Design patterns
- Casting dan database

### Part III: Qt Library dan Komponen
- Qt Library fundamentals
- File, stream, dan XML
- Qt WebKit integration

### Part IV: Antarmuka Pengguna
- GUI programming dengan Qt
- Signal dan slot
- Layout management
- Modern UI development

## 🚀 Cara Menggunakan

1. **Download PDF** - Baca buku dalam format PDF
2. **Install Qt Creator** - IDE untuk development
3. **Praktik Kode** - Jalankan contoh program
4. **Buat Project** - Terapkan konsep dalam project nyata

## 💻 Requirements

- Qt Creator 5.15+ atau Qt 6.x
- C++ compiler (GCC, MSVC, Clang)
- Minimal 4GB RAM
- Windows 10+, macOS 10.14+, atau Linux

## 📚 Referensi

- [Qt Documentation](https://doc.qt.io/)
- [C++ Reference](https://en.cppreference.com/)
- [Qt Creator](https://www.qt.io/product/development-tools)

## 👨‍💻 Tentang Penulis

**Nur Wachid** - Head of Software Engineering di PT. Lingkar Kreasi Teknologi

- Website: https://www.wach.id
- LinkedIn: [LinkedIn Profile]

## 📄 Lisensi

Creative Commons Attribution-NonCommercial 4.0 International License

---

*Selamat belajar dan happy coding! 🚀*
EOF
    else
        gh release create "$VERSION" \
            --title "C++ dan Qt Programming Guide $VERSION" \
            --notes-file - << EOF
# C++ dan Qt Programming Guide $VERSION

## 📚 Tentang Buku Ini

Buku panduan lengkap untuk belajar C++ dan Qt Framework. Dirancang khusus untuk pemula yang ingin menguasai pemrograman C++ dan pengembangan aplikasi dengan Qt.

## 🎯 Fitur Utama

- **Pembelajaran Bertahap** - Dari dasar hingga lanjutan
- **Contoh Kode Lengkap** - 333+ contoh program siap jalankan
- **Qt Creator Integration** - IDE modern untuk development
- **GUI Programming** - Membuat aplikasi dengan antarmuka grafis
- **Database Integration** - SQLite dan MySQL
- **Web Integration** - Qt WebKit untuk browser
- **Debugging Guide** - Teknik debugging yang efektif
- **Design Patterns** - Singleton, Observer, MVC

## 📖 Struktur Buku

### Part I: Dasar Pemrograman C++
- Pengenalan C++ dan Qt Creator
- Tipe data, variabel, dan operator
- Control statement (if, switch, loop)
- Array dan string manipulation
- Fungsi dan modularisasi
- Pointer dan references
- Debugging techniques

### Part II: Object-Oriented Programming
- Class dan object
- Inheritance dan polymorphism
- Operator overloading
- Design patterns
- Casting dan database

### Part III: Qt Library dan Komponen
- Qt Library fundamentals
- File, stream, dan XML
- Qt WebKit integration

### Part IV: Antarmuka Pengguna
- GUI programming dengan Qt
- Signal dan slot
- Layout management
- Modern UI development

## 🚀 Cara Menggunakan

1. **Download PDF** - Baca buku dalam format PDF
2. **Install Qt Creator** - IDE untuk development
3. **Praktik Kode** - Jalankan contoh program
4. **Buat Project** - Terapkan konsep dalam project nyata

## 💻 Requirements

- Qt Creator 5.15+ atau Qt 6.x
- C++ compiler (GCC, MSVC, Clang)
- Minimal 4GB RAM
- Windows 10+, macOS 10.14+, atau Linux

## 📚 Referensi

- [Qt Documentation](https://doc.qt.io/)
- [C++ Reference](https://en.cppreference.com/)
- [Qt Creator](https://www.qt.io/product/development-tools)

## 👨‍💻 Tentang Penulis

**Nur Wachid** - Head of Software Engineering di PT. Lingkar Kreasi Teknologi

- Website: https://www.wach.id
- LinkedIn: [LinkedIn Profile]

## 📄 Lisensi

Creative Commons Attribution-NonCommercial 4.0 International License

---

*Selamat belajar dan happy coding! 🚀*
EOF
    fi
    
    print_success "GitHub release created"
else
    print_warning "GitHub CLI (gh) not found. Please install it or create release manually."
    print_status "You can create a release manually at: https://github.com/$(git config --get remote.origin.url | sed 's/.*github.com[:/]\([^/]*\/[^/]*\).*/\1/')/releases/new"
fi

print_success "Release $VERSION created successfully!"
print_status "Next steps:"
echo "  1. Check the GitHub release page"
echo "  2. Verify the PDF attachment (if available)"
echo "  3. Share the release with your community" 