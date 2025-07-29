# Makefile for LaTeX document compilation

# Variables
LATEX_DIR = latex
OUTPUT_DIR = output
MAIN_FILE = book.tex
PDF_FILE = $(OUTPUT_DIR)/book.pdf

# Default target
all: $(PDF_FILE)

# Create output directory
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Build the PDF
$(PDF_FILE): $(OUTPUT_DIR) $(LATEX_DIR)/$(MAIN_FILE)
	@echo "Building LaTeX document..."
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "Second compilation (for references)..."
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "Third compilation (final)..."
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "✅ PDF generated successfully!"

# Build with index
index: $(OUTPUT_DIR) $(LATEX_DIR)/$(MAIN_FILE)
	@echo "Building with index..."
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "Generating index..."
	cd $(OUTPUT_DIR) && makeindex book.idx
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "✅ PDF with index generated successfully!"

# Build with bibliography
bib: $(OUTPUT_DIR) $(LATEX_DIR)/$(MAIN_FILE)
	@echo "Building with bibliography..."
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "Processing bibliography..."
	cd $(OUTPUT_DIR) && biber book
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "✅ PDF with bibliography generated successfully!"

# Build with bookmarks
bookmarks: clean
	@echo "🔧 Building LaTeX document with bookmarks..."
	@echo "📖 First compilation..."
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "📖 Second compilation (for references)..."
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "📖 Third compilation (for bookmarks)..."
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "📋 Generating index..."
	cd $(LATEX_DIR) && makeindex -o ../$(OUTPUT_DIR)/book.ind ../$(OUTPUT_DIR)/book.idx
	@echo "📖 Final compilation with index..."
	cd $(LATEX_DIR) && pdflatex -interaction=nonstopmode -output-directory=../$(OUTPUT_DIR) $(MAIN_FILE)
	@echo "✅ Build with bookmarks completed successfully!"
	@echo "📄 PDF generated at: $(PDF_FILE)"
	@echo "🔖 Bookmarks should now be visible in the PDF viewer"

# Clean auxiliary files
clean:
	@echo "🧹 Cleaning build files..."
	rm -rf $(OUTPUT_DIR)/*
	mkdir -p $(OUTPUT_DIR)

# Clean everything including PDF
distclean: clean
	@echo "Cleaning everything..."
	rm -f $(OUTPUT_DIR)/*.pdf
	@echo "✅ Everything cleaned!"

# Open PDF (platform specific)
open: $(PDF_FILE)
	@echo "📖 Opening PDF..."
	@if command -v xdg-open > /dev/null; then \
		xdg-open $(PDF_FILE); \
	elif command -v open > /dev/null; then \
		open $(PDF_FILE); \
	elif command -v start > /dev/null; then \
		start $(PDF_FILE); \
	else \
		echo "❌ No PDF viewer found. Please open $(PDF_FILE) manually."; \
	fi

# Watch for changes and rebuild
watch:
	@echo "Watching for changes in $(LATEX_DIR)..."
	@while true; do \
		inotifywait -r -e modify $(LATEX_DIR); \
		make all; \
	done

# Help
help:
	@echo "Available targets:"
	@echo "  all        - Build the PDF document"
	@echo "  index      - Build with index"
	@echo "  bib        - Build with bibliography"
	@echo "  bookmarks  - Build with bookmarks"
	@echo "  clean      - Clean auxiliary files"
	@echo "  distclean  - Clean everything including PDF"
	@echo "  open       - Open the generated PDF"
	@echo "  watch      - Watch for changes and rebuild"
	@echo "  help       - Show this help message"

.PHONY: all index bib clean distclean open watch help bookmarks 