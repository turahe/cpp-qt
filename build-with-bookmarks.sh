#!/bin/bash
set -e

echo "🔧 Building LaTeX document with bookmarks..."

# Clean previous build
echo "🧹 Cleaning previous build..."
rm -rf output/*
mkdir -p output

# Build the document multiple times to ensure proper bookmarks
echo "📖 First compilation..."
cd latex
pdflatex -interaction=nonstopmode -output-directory=../output book.tex

echo "📖 Second compilation (for references)..."
pdflatex -interaction=nonstopmode -output-directory=../output book.tex

echo "📖 Third compilation (for bookmarks)..."
pdflatex -interaction=nonstopmode -output-directory=../output book.tex

# Generate index if makeindex is available
if command -v makeindex &> /dev/null; then
    echo "📋 Generating index..."
    makeindex -o ../output/book.ind ../output/book.idx
    echo "📖 Final compilation with index..."
    pdflatex -interaction=nonstopmode -output-directory=../output book.tex
fi

echo "✅ Build completed successfully!"
echo "📄 PDF generated at: output/book.pdf"
echo "🔖 Bookmarks should now be visible in the PDF viewer" 