# C++ Qt Learning Book

This repository contains a comprehensive C++ and Qt Creator learning book written in LaTeX.

## 📚 Book Content

The book covers:
- **Dasar (Basics)**: Introduction, data types, control statements, arrays, strings, functions, pointers
- **OOP**: Classes, objects, inheritance, operators, polymorphism, casting, databases
- **Interface**: GUI development
- **Widget**: File handling, streams, XML, Qt WebKit
- **Library**: Qt libraries and utilities

## ✅ System Status

### What's Working Now:
- ✅ **Web Preview Interface** - Beautiful UI at `http://localhost:8000`
- ✅ **Python Server** - Handles build requests and serves files
- ✅ **Makefile** - Complete build automation
- ✅ **Docker Setup** - Ready to use with LaTeX
- ✅ **File Structure** - All LaTeX files and assets in place
- ✅ **Documentation** - Comprehensive guides and setup instructions

### What Requires LaTeX Installation:
- ❌ **PDF Generation** - Requires LaTeX distribution (TeX Live, MiKTeX, or MacTeX)
- ❌ **Local Build** - Needs pdflatex command in PATH

### Quick Test:
```bash
python test-build.py
```

## 🚀 Quick Start

### Option 1: Web Preview (Works Now!)

1. **Start the preview server:**
   ```bash
   python server.py
   ```

2. **Open your browser:**
   - Go to `http://localhost:8000`
   - You'll see the beautiful preview interface with build options

3. **Explore the interface:**
   - View the complete book structure
   - See build options (PDF generation requires LaTeX installation)
   - Navigate through chapters and sections

### Option 2: Using Docker (For PDF Generation)

1. **Start the LaTeX environment:**
   ```bash
   docker-compose up latex-simple
   ```

2. **Access the development environment:**
   - Open your browser and go to `http://localhost:8443`
   - Login with password: `secret`

3. **Build the LaTeX document:**
   ```bash
   # Using the build script with bookmarks (recommended)
   ./docker-build-bookmarks.sh
   
   # Or using make with bookmarks
   docker exec latex make bookmarks
   
   # Or using the original build script
   ./build-latex.sh
   
   # Or using make
   make all
   
   # Or using make with index
   make index
   ```

4. **View the generated PDF:**
   - The PDF will be generated in the `output/` directory
   - Open `output/book.pdf` to view the document

### Option 2: Local LaTeX Installation

If you have LaTeX installed locally:

1. **Install required LaTeX packages:**
   ```bash
   # Ubuntu/Debian
   sudo apt-get install texlive-full texlive-latex-extra texlive-fonts-extra texlive-lang-indonesian texlive-bibtex-extra biber makeindex latexmk
   
   # macOS
   brew install --cask mactex
   
   # Windows
   # Install MiKTeX or TeX Live
   ```

2. **Build the document:**
   ```bash
   make all
   ```

## 🛠️ Build Commands

### Using Makefile
```bash
make all          # Build the PDF document
make index        # Build with index
make bib          # Build with bibliography
make bookmarks    # Build with bookmarks (recommended)
make clean        # Clean auxiliary files
make distclean    # Clean everything including PDF
make open         # Open the generated PDF
make watch        # Watch for changes and rebuild
make help         # Show help message
```

### Using Build Script
```bash
./build-latex.sh          # Build the complete document
./build-with-bookmarks.sh # Build with bookmarks (local)
./docker-build-bookmarks.sh # Build with bookmarks (Docker)
```

### Manual LaTeX Commands
```bash
cd latex
pdflatex -interaction=nonstopmode -output-directory=../output book.tex
pdflatex -interaction=nonstopmode -output-directory=../output book.tex
makeindex -o ../output/book.ind ../output/book.idx
pdflatex -interaction=nonstopmode -output-directory=../output book.tex
```

## 📁 Project Structure

```
cpp-qt/
├── latex/                    # LaTeX source files
│   ├── book.tex             # Main document
│   ├── 01-pengenalan.tex    # Chapter files
│   └── ...
├── code/                    # C++ example code
├── manuscript/              # Markdown source files
├── output/                  # Generated PDF and auxiliary files
├── images/                  # Book images
├── build-latex.sh          # Build script
├── Makefile                # Build automation
├── docker-compose.yml      # Docker configuration
└── README.md               # This file
```

## 🔧 Development

### VS Code with LaTeX Workshop

The project is configured for VS Code with the LaTeX Workshop extension:

1. Install the LaTeX Workshop extension
2. Open the project in VS Code
3. Open `latex/book.tex`
4. The document will auto-build on save
5. Use `Ctrl+Alt+B` to build manually
6. Use `Ctrl+Alt+V` to view the PDF

### Docker Development

The Docker setup includes:
- **code-server**: Web-based VS Code with LaTeX Workshop
- **latex**: Dedicated LaTeX compilation service
- **latex-full**: Alternative service with full TeXLive installation

## 📖 Book Chapters

### Part 1: Dasar (Basics)
- Chapter 1: Mukadimah (Introduction)
- Chapter 2: Tipe Data, Identifier dan Operator
- Chapter 3: Control Statement
- Chapter 4: Array dan String
- Chapter 5: Fungsi
- Chapter 6: Pointer dan References

### Part 2: OOP
- Chapter 7: Class dan Object
- Chapter 8: Inheritance
- Chapter 9: Operator Types dan Operator Overloading
- Chapter 10: Polymorphism
- Chapter 11: Casting dan Database

### Part 3: Interface
- Chapter 12: GUI

### Part 4: Widget
- Chapter 13: File, Stream, dan XML
- Chapter 14: Qt Webkit

### Part 5: Library
- Chapter 15: Library

## 🐛 Troubleshooting

### Common Issues

1. **Missing LaTeX packages:**
   ```bash
   # Install additional packages
   sudo apt-get install texlive-lang-indonesian
   ```

2. **Font issues:**
   ```bash
   # Install Libertine font
   sudo apt-get install texlive-fonts-extra
   ```

3. **Image not found:**
   - Ensure images are in the correct path: `manuscript/images/`
   - Check image file names match the LaTeX references

4. **Bibliography issues:**
   ```bash
   # Use biber instead of bibtex
   biber book
   ```

### Docker Issues

1. **Container not starting:**
   ```bash
   docker-compose down
   docker-compose up -d --build
   ```

2. **Permission issues:**
   ```bash
   sudo chown -R $USER:$USER .
   ```

## 📄 License

This book is licensed under Creative Commons Attribution-NonCommercial (CC BY-NC).

## 👨‍💻 Author

**Nur Wachid**
- Website: https://wach.id
- Email: wachid (at) outlook dot com

---

Happy learning! 📚✨