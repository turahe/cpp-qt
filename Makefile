# Makefile for LaTeX document compilation (full Docker)

# Variables
LATEX_DIR = latex
OUTPUT_DIR = output
MAIN_FILE = book.tex
PDF_FILE = $(OUTPUT_DIR)/book.pdf

# Docker: full TeX Live — no host pdflatex required
DOCKER_IMAGE ?= danteev/texlive:latest
DOCKER_WORKDIR = /workspace
DOCKER_USER = $(shell id -u):$(shell id -g)
DOCKER_RUN = docker run --rm \
	-u $(DOCKER_USER) \
	-v "$(CURDIR):$(DOCKER_WORKDIR)" \
	-w $(DOCKER_WORKDIR)/$(LATEX_DIR) \
	$(DOCKER_IMAGE)

# latexmk drives pdflatex / makeindex / biber with correct -outdir paths
LATEXMK = latexmk -pdf -f -interaction=nonstopmode \
	-outdir=../$(OUTPUT_DIR) \
	-pdflatex="pdflatex -interaction=nonstopmode %O %S"

# Default target
all: $(PDF_FILE)

# Create output directory
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Ensure Docker image is available
.PHONY: docker-pull
docker-pull:
	@echo "Pulling Docker image $(DOCKER_IMAGE)..."
	docker pull $(DOCKER_IMAGE)

# Build the PDF (Docker + latexmk)
# Document has known pdflatex Unicode warnings; succeed if PDF is produced.
$(PDF_FILE): $(OUTPUT_DIR) $(LATEX_DIR)/$(MAIN_FILE)
	@echo "Building LaTeX document (Docker: $(DOCKER_IMAGE))..."
	-$(DOCKER_RUN) $(LATEXMK) $(MAIN_FILE)
	@test -f $(PDF_FILE) || (echo "❌ PDF was not generated"; exit 1)
	@echo "✅ PDF generated successfully at $(PDF_FILE)"
	@ls -lh $(PDF_FILE)

# Build with index (same full pipeline; latexmk runs makeindex)
index: $(PDF_FILE)
	@echo "✅ PDF with index ready at $(PDF_FILE)"

# Build with bibliography (latexmk runs biber when needed)
bib: $(PDF_FILE)
	@echo "✅ PDF with bibliography ready at $(PDF_FILE)"

# Build with bookmarks (clean rebuild so outlines settle)
bookmarks: clean $(PDF_FILE)
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
		$(MAKE) all; \
	done

# Help
help:
	@echo "Available targets (all builds use Docker: $(DOCKER_IMAGE)):"
	@echo "  all         - Build the PDF document"
	@echo "  index       - Build with index"
	@echo "  bib         - Build with bibliography"
	@echo "  bookmarks   - Clean rebuild (bookmarks/outlines)"
	@echo "  docker-pull - Pre-pull the TeX Live image"
	@echo "  clean       - Clean auxiliary files"
	@echo "  distclean   - Clean everything including PDF"
	@echo "  open        - Open the generated PDF"
	@echo "  watch       - Watch for changes and rebuild"
	@echo "  help        - Show this help message"

.PHONY: all index bib clean distclean open watch help bookmarks docker-pull
