# LaTeX Preview System Setup Guide

This guide will help you set up the LaTeX preview system for the C++ Qt Learning Book.

## 🚀 Quick Start

### Option 1: Web Preview (Recommended)

1. **Start the preview server:**
   ```bash
   # Windows
   start-preview.bat
   
   # Linux/macOS
   ./start-preview.sh
   
   # Or manually
   python server.py
   ```

2. **Open your browser:**
   - Go to `http://localhost:8000`
   - You'll see the preview interface with build options

3. **Build the document:**
   - Click on any build option in the web interface
   - The PDF will be generated in the `output/` directory
   - Click "Open Book PDF" to view the result

### Option 2: Command Line

1. **Build the document:**
   ```bash
   # Simple build
   make all
   
   # Build with index
   make index
   
   # Build with bibliography
   make bib
   
   # Clean auxiliary files
   make clean
   ```

2. **View the PDF:**
   ```bash
   # Open the PDF
   make open
   
   # Or manually open output/book.pdf
   ```

## 📋 Prerequisites

### Required Software

1. **Python 3.6+** (for the preview server)
2. **LaTeX Distribution** (one of the following):
   - **TeX Live** (recommended for Linux/macOS)
   - **MiKTeX** (recommended for Windows)
   - **MacTeX** (for macOS)

### LaTeX Packages

The following LaTeX packages are required:

```bash
# Ubuntu/Debian
sudo apt-get install texlive-full texlive-latex-extra texlive-fonts-extra texlive-lang-indonesian texlive-bibtex-extra biber makeindex latexmk

# macOS (with Homebrew)
brew install --cask mactex

# Windows
# Install MiKTeX and ensure all packages are installed
```

## 🔧 Installation Steps

### Step 1: Install LaTeX

#### Windows
1. Download and install MiKTeX from https://miktex.org/
2. During installation, choose "Install missing packages on-the-fly = Yes"
3. Add MiKTeX to your PATH environment variable

#### macOS
```bash
# Using Homebrew
brew install --cask mactex

# Or download from https://www.tug.org/mactex/
```

#### Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install texlive-full texlive-latex-extra texlive-fonts-extra texlive-lang-indonesian texlive-bibtex-extra biber makeindex latexmk
```

### Step 2: Install Python Dependencies

```bash
# The server uses only Python standard library
# No additional packages required
```

### Step 3: Verify Installation

```bash
# Check LaTeX installation
pdflatex --version

# Check Python installation
python --version

# Test build
make all
```

## 🐳 Docker Alternative

If you prefer using Docker:

```bash
# Start the Docker environment
docker-compose up -d

# Access the web interface
# Open http://localhost:8443 in your browser
# Login with password: secret

# Build from within the container
docker exec latex-full make all
```

## 📁 Project Structure

```
cpp-qt/
├── latex/                    # LaTeX source files
│   ├── book.tex             # Main document
│   ├── 01-pengenalan.tex    # Chapter files
│   └── ...
├── output/                  # Generated PDF and auxiliary files
├── preview.html             # Web preview interface
├── server.py                # Python web server
├── build-latex.sh          # Build script
├── Makefile                # Build automation
├── start-preview.bat       # Windows startup script
├── start-preview.sh        # Unix startup script
└── README.md               # Main documentation
```

## 🛠️ Build Commands

### Using Makefile
```bash
make all          # Build the PDF document
make index        # Build with index
make bib          # Build with bibliography
make clean        # Clean auxiliary files
make distclean    # Clean everything including PDF
make open         # Open the generated PDF
make watch        # Watch for changes and rebuild
make help         # Show help message
```

### Using Build Script
```bash
./build-latex.sh  # Build the complete document
```

### Manual LaTeX Commands
```bash
cd latex
pdflatex -interaction=nonstopmode -output-directory=../output book.tex
pdflatex -interaction=nonstopmode -output-directory=../output book.tex
makeindex -o ../output/book.ind ../output/book.idx
pdflatex -interaction=nonstopmode -output-directory=../output book.tex
```

## 🔍 Troubleshooting

### Common Issues

1. **"pdflatex: command not found"**
   ```bash
   # Install LaTeX distribution
   # See installation steps above
   ```

2. **Missing LaTeX packages**
   ```bash
   # Install additional packages
   sudo apt-get install texlive-lang-indonesian
   sudo apt-get install texlive-fonts-extra
   ```

3. **Font issues**
   ```bash
   # Install Libertine font
   sudo apt-get install texlive-fonts-extra
   ```

4. **Image not found**
   - Ensure images are in `manuscript/images/`
   - Check image file names match LaTeX references

5. **Bibliography issues**
   ```bash
   # Use biber instead of bibtex
   biber book
   ```

6. **Permission denied**
   ```bash
   # Fix file permissions
   chmod +x build-latex.sh start-preview.sh
   ```

### Build Errors

1. **Check LaTeX log files:**
   ```bash
   # Look for errors in output/book.log
   cat output/book.log | grep -i error
   ```

2. **Clean and rebuild:**
   ```bash
   make clean
   make all
   ```

3. **Check file paths:**
   - Ensure all `\input{}` files exist
   - Check image paths are correct

### Web Server Issues

1. **Port already in use:**
   ```bash
   # Change port in server.py
   port = 8001  # or any available port
   ```

2. **Python not found:**
   ```bash
   # Use python3 instead
   python3 server.py
   ```

## 📚 Additional Resources

- [LaTeX Documentation](https://www.latex-project.org/help/documentation/)
- [TeX Live Installation](https://www.tug.org/texlive/)
- [MiKTeX Installation](https://miktex.org/howto/install-miktex)
- [LaTeX Workshop Extension](https://marketplace.visualstudio.com/items?itemName=James-Yu.latex-workshop)

## 🤝 Support

If you encounter issues:

1. Check the troubleshooting section above
2. Look at the LaTeX log files in the `output/` directory
3. Ensure all prerequisites are installed
4. Try the Docker alternative if local installation fails

---

Happy LaTeX compiling! 📚✨ 