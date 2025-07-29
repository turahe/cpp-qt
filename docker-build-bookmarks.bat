@echo off
echo 🐳 Building LaTeX document with bookmarks using Docker...

REM Check if Docker container is running
docker ps | findstr "latex" >nul
if errorlevel 1 (
    echo ❌ Docker container 'latex' is not running.
    echo 💡 Start it with: docker-compose up -d latex
    pause
    exit /b 1
)

REM Clean previous build
echo 🧹 Cleaning previous build...
docker exec latex rm -rf /workspace/output/*
docker exec latex mkdir -p /workspace/output

REM Build the document multiple times to ensure proper bookmarks
echo 📖 First compilation...
docker exec latex bash -c "cd /workspace/latex && pdflatex -interaction=nonstopmode -output-directory=../output book.tex"

echo 📖 Second compilation (for references)...
docker exec latex bash -c "cd /workspace/latex && pdflatex -interaction=nonstopmode -output-directory=../output book.tex"

echo 📖 Third compilation (for bookmarks)...
docker exec latex bash -c "cd /workspace/latex && pdflatex -interaction=nonstopmode -output-directory=../output book.tex"

REM Generate index
echo 📋 Generating index...
docker exec latex bash -c "cd /workspace/latex && makeindex -o ../output/book.ind ../output/book.idx"

echo 📖 Final compilation with index...
docker exec latex bash -c "cd /workspace/latex && pdflatex -interaction=nonstopmode -output-directory=../output book.tex"

echo ✅ Build with bookmarks completed successfully!
echo 📄 PDF generated at: output/book.pdf
echo 🔖 Bookmarks should now be visible in the PDF viewer

REM Check if PDF was created
if exist "output\book.pdf" (
    echo ✅ PDF file exists and is ready!
    dir output\book.pdf
) else (
    echo ❌ PDF file was not created. Check for errors above.
    pause
    exit /b 1
)

pause 