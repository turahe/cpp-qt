#!/usr/bin/env python3
"""
Embed Code in Markdown
Embeds actual code content from code files into Markdown files
"""

import os
import re
import glob
from pathlib import Path

class CodeEmbedder:
    def __init__(self):
        self.markdown_dir = "manuscript"
        self.code_dir = "code"
        
    def embed_code_in_markdown(self, markdown_file):
        """Embed actual code content into Markdown file"""
        with open(markdown_file, 'r', encoding='utf-8') as f:
            content = f.read()
        
        # Find all code block patterns
        content = self.embed_code_blocks(content)
        
        return content
    
    def embed_code_blocks(self, content):
        """Embed actual code content into code blocks"""
        
        # Pattern to find code blocks with file references
        pattern = r'```cpp\n// File: ([^\n]+)\n```'
        
        def replace_code_block(match):
            file_path = match.group(1)
            
            # Clean up the file path
            if file_path.startswith('../code/'):
                file_path = file_path[8:]  # Remove '../code/'
            elif file_path.startswith('code/'):
                file_path = file_path[5:]   # Remove 'code/'
            
            # Construct full path
            full_path = os.path.join(self.code_dir, file_path)
            
            if os.path.exists(full_path):
                try:
                    with open(full_path, 'r', encoding='utf-8') as f:
                        code_content = f.read()
                    
                    return f'```cpp\n{code_content}\n```'
                except Exception as e:
                    print(f"Error reading {full_path}: {e}")
                    return match.group(0)
            else:
                print(f"File not found: {full_path}")
                return match.group(0)
        
        # Replace all code blocks
        content = re.sub(pattern, replace_code_block, content)
        
        return content
    
    def process_all_markdown_files(self):
        """Process all Markdown files to embed code"""
        
        # Get all .md files
        md_files = glob.glob(os.path.join(self.markdown_dir, "*.md"))
        
        for md_file in md_files:
            filename = os.path.basename(md_file)
            print(f"Processing {filename}...")
            
            try:
                updated_content = self.embed_code_in_markdown(md_file)
                
                with open(md_file, 'w', encoding='utf-8') as f:
                    f.write(updated_content)
                
                print(f"✓ Successfully updated {filename}")
                
            except Exception as e:
                print(f"✗ Error processing {filename}: {e}")

def main():
    embedder = CodeEmbedder()
    
    print("🔄 Starting code embedding in Markdown files...")
    print("=" * 50)
    
    # Process all Markdown files
    embedder.process_all_markdown_files()
    
    print("=" * 50)
    print("✅ Code embedding completed!")
    print("\n📁 Check the 'manuscript' directory for updated files with embedded code.")

if __name__ == "__main__":
    main() 