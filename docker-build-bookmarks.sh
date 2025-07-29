#!/bin/bash
set -e

echo "🐳 Building LaTeX document with bookmarks using Docker..."

# Check if Docker container is running
if ! docker ps | grep -q "latex"; then
    echo "❌ Docker container 'latex' is not running."
    echo "💡 Start it with: docker-compose up -d latex"
    exit 1
fi

# Clean previous build
echo "🧹 Cleaning previous build..."
docker exec latex rm -rf /workspace/output/*
docker exec latex mkdir -p /workspace/output

# Build the document multiple times to ensure proper bookmarks
echo "📖 First compilation..."
docker exec latex bash -c "cd /workspace/latex && pdflatex -interaction=nonstopmode -output-directory=../output book.tex"

echo "📖 Second compilation (for references)..."
docker exec latex bash -c "cd /workspace/latex && pdflatex -interaction=nonstopmode -output-directory=../output book.tex"

echo "📖 Third compilation (for bookmarks)..."
docker exec latex bash -c "cd /workspace/latex && pdflatex -interaction=nonstopmode -output-directory=../output book.tex"

# Generate index
echo "📋 Generating index..."
docker exec latex bash -c "cd /workspace/latex && makeindex -o ../output/book.ind ../output/book.idx"

echo "📖 Final compilation with index..."
docker exec latex bash -c "cd /workspace/latex && pdflatex -interaction=nonstopmode -output-directory=../output book.tex"

echo "✅ Build with bookmarks completed successfully!"
echo "📄 PDF generated at: output/book.pdf"
echo "🔖 Bookmarks should now be visible in the PDF viewer"

# Check if PDF was created
if [ -f "output/book.pdf" ]; then
    echo "✅ PDF file exists and is ready!"
    ls -la output/book.pdf
else
    echo "❌ PDF file was not created. Check for errors above."
    exit 1
fi 