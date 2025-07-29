#!/bin/bash

# Build script for LaTeX document
# This script compiles the main LaTeX document and generates a PDF

set -e  # Exit on any error

echo "Building LaTeX document..."

# Change to the latex directory
cd latex

# Check if required files exist
if [ ! -f "book.tex" ]; then
    echo "Error: book.tex not found!"
    exit 1
fi

# Create output directory if it doesn't exist
mkdir -p ../output

# Compile the document multiple times to resolve references
echo "First compilation..."
pdflatex -interaction=nonstopmode -output-directory=../output book.tex

echo "Second compilation (for references)..."
pdflatex -interaction=nonstopmode -output-directory=../output book.tex

echo "Third compilation (for final references)..."
pdflatex -interaction=nonstopmode -output-directory=../output book.tex

# Generate index if makeindex is available
if command -v makeindex &> /dev/null; then
    echo "Generating index..."
    makeindex -o ../output/book.ind ../output/book.idx
    pdflatex -interaction=nonstopmode -output-directory=../output book.tex
fi

echo "Build completed successfully!"
echo "PDF file generated at: ../output/book.pdf"

# Check if PDF was created
if [ -f "../output/book.pdf" ]; then
    echo "✅ PDF successfully generated!"
    echo "📄 File location: ../output/book.pdf"
    echo "📊 File size: $(du -h ../output/book.pdf | cut -f1)"
else
    echo "❌ Error: PDF was not generated!"
    exit 1
fi 