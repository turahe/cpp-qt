# 🚀 Quick Start Guide

## Option 1: Web Preview (Works Now!)

Since LaTeX isn't installed locally, let's use the web preview system:

1. **Start the preview server:**
   ```bash
   python server.py
   ```

2. **Open your browser:**
   - Go to `http://localhost:8000`
   - You'll see the beautiful preview interface

3. **Note:** The build buttons will show "Build failed" until LaTeX is installed, but the interface is fully functional!

## Option 2: Docker (Recommended for LaTeX)

### Quick Docker Setup:
```bash
# Start the simple LaTeX environment
docker-compose up latex-simple

# Access at http://localhost:8443
# Password: secret
```

### Alternative Docker Commands:
```bash
# Build and run the simple container
docker-compose build latex-simple
docker-compose up latex-simple

# Or use the standalone LaTeX container
docker-compose up latex
```

## Option 3: Install LaTeX Locally

### Windows:
1. Download MiKTeX: https://miktex.org/download
2. Install with "Install missing packages on-the-fly = Yes"
3. Add to PATH environment variable

### macOS:
```bash
brew install --cask mactex
```

### Linux (Ubuntu/Debian):
```bash
sudo apt-get update
sudo apt-get install texlive-full texlive-latex-extra texlive-fonts-extra texlive-lang-indonesian texlive-bibtex-extra biber makeindex latexmk
```

## What's Working Right Now ✅

- ✅ **Web Preview Interface** - Beautiful UI at `http://localhost:8000`
- ✅ **Python Server** - Handles build requests
- ✅ **Makefile** - Complete build automation
- ✅ **Docker Setup** - Ready to use
- ✅ **File Structure** - All files in place
- ✅ **Documentation** - Comprehensive guides

## What Needs LaTeX Installation ❌

- ❌ **PDF Generation** - Requires LaTeX distribution
- ❌ **Local Build** - Needs pdflatex command

## Test Your Setup

Run the test script to see what's working:
```bash
python test-build.py
```

## Next Steps

1. **For immediate use:** Start the web server and explore the interface
2. **For PDF generation:** Use Docker or install LaTeX locally
3. **For development:** The web interface shows the complete book structure

---

🎉 **The preview system is ready!** Just need LaTeX for PDF generation. 