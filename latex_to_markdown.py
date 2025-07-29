#!/usr/bin/env python3
"""
LaTeX to Markdown Converter
Converts LaTeX files to Markdown format with proper formatting
"""

import os
import re
import glob
from pathlib import Path

class LatexToMarkdown:
    def __init__(self):
        self.latex_dir = "latex"
        self.markdown_dir = "manuscript"
        
    def convert_latex_to_markdown(self, latex_file):
        """Convert a single LaTeX file to Markdown"""
        with open(latex_file, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Convert LaTeX commands to Markdown
        content = self.convert_latex_commands(content)
        
        return content
    
    def convert_latex_commands(self, content):
        """Convert LaTeX commands to Markdown equivalents"""
        
        # Remove LaTeX document structure
        content = re.sub(r'\\documentclass.*?\n', '', content)
        content = re.sub(r'\\usepackage.*?\n', '', content)
        content = re.sub(r'\\begin\{document\}', '', content)
        content = re.sub(r'\\end\{document\}', '', content)
        
        # Convert chapters and sections
        content = re.sub(r'\\chapter\*?\{([^}]+)\}', r'# \1', content)
        content = re.sub(r'\\section\*?\{([^}]+)\}', r'## \1', content)
        content = re.sub(r'\\subsection\*?\{([^}]+)\}', r'### \1', content)
        content = re.sub(r'\\subsubsection\*?\{([^}]+)\}', r'#### \1', content)
        
        # Convert parts
        content = re.sub(r'\\part\*?\{([^}]+)\}', r'# \1', content)
        
        # Convert emphasis and formatting
        content = re.sub(r'\\textbf\{([^}]+)\}', r'**\1**', content)
        content = re.sub(r'\\textit\{([^}]+)\}', r'*\1*', content)
        content = re.sub(r'\\texttt\{([^}]+)\}', r'`\1`', content)
        content = re.sub(r'\\underline\{([^}]+)\}', r'<u>\1</u>', content)
        
        # Convert quotes
        content = re.sub(r'\\begin\{quote\}', '> ', content)
        content = re.sub(r'\\end\{quote\}', '', content)
        
        # Convert itemize and enumerate
        content = self.convert_lists(content)
        
        # Convert code listings
        content = self.convert_code_listings(content)
        
        # Convert images
        content = self.convert_images(content)
        
        # Convert tables
        content = self.convert_tables(content)
        
        # Convert mathematical expressions
        content = self.convert_math(content)
        
        # Convert footnotes
        content = self.convert_footnotes(content)
        
        # Convert references
        content = self.convert_references(content)
        
        # Convert spacing and newlines
        content = self.convert_spacing(content)
        
        # Convert special characters
        content = self.convert_special_chars(content)
        
        return content
    
    def convert_lists(self, content):
        """Convert LaTeX lists to Markdown lists"""
        
        # Convert itemize
        content = re.sub(r'\\begin\{itemize\}', '', content)
        content = re.sub(r'\\end\{itemize\}', '', content)
        content = re.sub(r'\\item\s*', '- ', content)
        
        # Convert enumerate
        content = re.sub(r'\\begin\{enumerate\}', '', content)
        content = re.sub(r'\\end\{enumerate\}', '', content)
        content = re.sub(r'\\item\s*', '1. ', content)
        
        return content
    
    def convert_code_listings(self, content):
        """Convert LaTeX code listings to Markdown code blocks"""
        
        # Convert lstlisting environments
        content = re.sub(
            r'\\begin\{lstlisting\}\[([^\]]*)\](.*?)\\end\{lstlisting\}',
            r'```cpp\2```',
            content,
            flags=re.DOTALL
        )
        
        # Convert lstinputlisting commands
        content = re.sub(
            r'\\lstinputlisting\[language=c\+\+\]\{([^}]+)\}',
            r'```cpp\n# File: \1\n```',
            content
        )
        
        # Convert lstinputlisting with caption
        content = re.sub(
            r'\\begin\{lstlisting\}\[language=c\+\+, caption=([^\]]+)\]\s*\\lstinputlisting\[language=c\+\+\]\{([^}]+)\}\s*\\end\{lstlisting\}',
            r'```cpp\n# \1\n# File: \2\n```',
            content
        )
        
        return content
    
    def convert_images(self, content):
        """Convert LaTeX images to Markdown images"""
        
        # Convert includegraphics
        content = re.sub(
            r'\\includegraphics\[([^\]]*)\]\{([^}]+)\}',
            r'![\2](\2)',
            content
        )
        
        # Convert shadowimage
        content = re.sub(
            r'\\shadowimage\{([^}]+)\}',
            r'![\1](\1)',
            content
        )
        
        return content
    
    def convert_tables(self, content):
        """Convert LaTeX tables to Markdown tables"""
        
        # Simple table conversion
        content = re.sub(
            r'\\begin\{table\}.*?\\end\{table\}',
            r'[Table removed - convert manually]',
            content,
            flags=re.DOTALL
        )
        
        return content
    
    def convert_math(self, content):
        """Convert LaTeX math to Markdown math"""
        
        # Convert inline math
        content = re.sub(r'\$([^$]+)\$', r'$\1$', content)
        
        # Convert display math
        content = re.sub(r'\\\[(.*?)\\\]', r'$$\1$$', content, flags=re.DOTALL)
        
        return content
    
    def convert_footnotes(self, content):
        """Convert LaTeX footnotes to Markdown footnotes"""
        
        content = re.sub(r'\\footnote\{([^}]+)\}', r'[^1]: \1', content)
        
        return content
    
    def convert_references(self, content):
        """Convert LaTeX references to Markdown links"""
        
        # Convert \ref to links
        content = re.sub(r'\\ref\{([^}]+)\}', r'[\1](#\1)', content)
        
        # Convert \label to anchors
        content = re.sub(r'\\label\{([^}]+)\}', r'<a name="\1"></a>', content)
        
        return content
    
    def convert_spacing(self, content):
        """Convert LaTeX spacing to Markdown spacing"""
        
        # Remove excessive newlines
        content = re.sub(r'\n{3,}', '\n\n', content)
        
        # Convert LaTeX spacing commands
        content = re.sub(r'\\vspace\{([^}]+)\}', '\n', content)
        content = re.sub(r'\\hspace\{([^}]+)\}', ' ', content)
        
        return content
    
    def convert_special_chars(self, content):
        """Convert LaTeX special characters to Markdown"""
        
        # Convert LaTeX special characters
        replacements = {
            '\\%': '%',
            '\\$': '$',
            '\\{': '{',
            '\\}': '}',
            '\\_': '_',
            '\\#': '#',
            '\\&': '&',
            '\\~': '~',
            '\\^': '^',
            '\\textbackslash': '\\',
            '\\textquotesingle': "'",
            '\\textquotedbl': '"',
            '\\textless': '<',
            '\\textgreater': '>',
            '\\textbar': '|',
            '\\textasciitilde': '~',
            '\\textasciicircum': '^',
            '\\textbackslash': '\\',
            '\\textquotesingle': "'",
            '\\textquotedbl': '"',
            '\\textless': '<',
            '\\textgreater': '>',
            '\\textbar': '|',
            '\\textasciitilde': '~',
            '\\textasciicircum': '^',
        }
        
        for latex, markdown in replacements.items():
            content = content.replace(latex, markdown)
        
        return content
    
    def sync_all_files(self):
        """Sync all LaTeX files to Markdown"""
        
        # Ensure markdown directory exists
        os.makedirs(self.markdown_dir, exist_ok=True)
        
        # Get all .tex files
        tex_files = glob.glob(os.path.join(self.latex_dir, "*.tex"))
        
        for tex_file in tex_files:
            filename = os.path.basename(tex_file)
            name_without_ext = os.path.splitext(filename)[0]
            markdown_file = os.path.join(self.markdown_dir, f"{name_without_ext}.md")
            
            print(f"Converting {filename} to {os.path.basename(markdown_file)}")
            
            try:
                markdown_content = self.convert_latex_to_markdown(tex_file)
                
                with open(markdown_file, 'w', encoding='utf-8') as f:
                    f.write(markdown_content)
                
                print(f"✓ Successfully converted {filename}")
                
            except Exception as e:
                print(f"✗ Error converting {filename}: {e}")
    
    def create_book_markdown(self):
        """Create a main book.md file that includes all chapters"""
        
        # Read the book.tex to understand the structure
        book_tex_path = os.path.join(self.latex_dir, "book.tex")
        
        if not os.path.exists(book_tex_path):
            print("book.tex not found, skipping book creation")
            return
        
        with open(book_tex_path, 'r', encoding='utf-8') as f:
            book_content = f.read()
        
        # Extract chapter order from book.tex
        chapters = []
        
        # Find all \input commands
        input_pattern = r'\\input\{([^}]+)\}'
        matches = re.findall(input_pattern, book_content)
        
        for match in matches:
            if match.endswith('.tex'):
                chapters.append(match)
            else:
                chapters.append(f"{match}.tex")
        
        # Create book.md
        book_md_path = os.path.join(self.markdown_dir, "book.md")
        
        with open(book_md_path, 'w', encoding='utf-8') as f:
            f.write("# C++ dan Qt Programming Guide\n\n")
            f.write("Buku panduan lengkap untuk belajar C++ dan Qt Framework.\n\n")
            
            for chapter in chapters:
                chapter_name = os.path.splitext(chapter)[0]
                chapter_md = f"{chapter_name}.md"
                
                if os.path.exists(os.path.join(self.markdown_dir, chapter_md)):
                    f.write(f"- [{chapter_name}]({chapter_md})\n")
        
        print("✓ Created book.md with chapter links")

def main():
    converter = LatexToMarkdown()
    
    print("🔄 Starting LaTeX to Markdown conversion...")
    print("=" * 50)
    
    # Sync all files
    converter.sync_all_files()
    
    print("=" * 50)
    print("📚 Creating book structure...")
    
    # Create book.md
    converter.create_book_markdown()
    
    print("=" * 50)
    print("✅ LaTeX to Markdown sync completed!")
    print("\n📁 Check the 'manuscript' directory for converted files.")
    print("📖 Open 'manuscript/book.md' to see the complete book structure.")

if __name__ == "__main__":
    main() 