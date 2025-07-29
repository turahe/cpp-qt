#!/usr/bin/env python3
"""
Script to extract embedded code from LaTeX files and move them to code/ directory
"""

import os
import re
import glob

def extract_code_from_latex(latex_file):
    """Extract code blocks from LaTeX file and save them to code/ directory"""
    
    with open(latex_file, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Find all lstlisting blocks
    pattern = r'\\begin\{lstlisting\}(?:\[([^\]]*)\])?\s*\n(.*?)\\end\{lstlisting\}'
    matches = re.findall(pattern, content, re.DOTALL)
    
    extracted_files = []
    
    for i, (options, code) in enumerate(matches):
        # Parse options to get language and caption
        language = 'cpp'
        caption = ''
        label = ''
        
        if options:
            # Extract language
            lang_match = re.search(r'language=([^,\]]+)', options)
            if lang_match:
                language = lang_match.group(1)
            
            # Extract caption
            caption_match = re.search(r'caption=([^,\]]+)', options)
            if caption_match:
                caption = caption_match.group(1).strip('"{}')
            
            # Extract label
            label_match = re.search(r'label=([^,\]]+)', options)
            if label_match:
                label = label_match.group(1).strip('"{}')
        
        # Generate filename
        base_name = os.path.splitext(os.path.basename(latex_file))[0]
        if label:
            filename = f"{base_name}-{label}.{language}"
        elif caption:
            # Clean caption for filename
            clean_caption = re.sub(r'[^\w\s-]', '', caption).strip().replace(' ', '-').lower()
            filename = f"{base_name}-{clean_caption}.{language}"
        else:
            filename = f"{base_name}-code-{i+1}.{language}"
        
        # Save code to file
        code_path = os.path.join('code', filename)
        with open(code_path, 'w', encoding='utf-8') as f:
            f.write(code.strip())
        
        extracted_files.append((filename, code.strip()))
        
        # Replace in LaTeX content
        replacement = f'\\lstinputlisting[language={language}'
        if caption:
            replacement += f', caption={caption}'
        if label:
            replacement += f', label={label}'
        replacement += f']{{../code/{filename}}}'
        
        # Create a safe replacement pattern
        old_block = f'\\begin{{lstlisting}}'
        if options:
            old_block += f'[{options}]'
        old_block += f'\n{code.strip()}\n\\end{{lstlisting}}'
        
        content = content.replace(old_block, replacement)
    
    # Write updated LaTeX content
    with open(latex_file, 'w', encoding='utf-8') as f:
        f.write(content)
    
    return extracted_files

def main():
    """Main function to process all LaTeX files"""
    
    # Create code directory if it doesn't exist
    os.makedirs('code', exist_ok=True)
    
    # Find all LaTeX files
    latex_files = glob.glob('latex/*.tex')
    
    total_extracted = 0
    
    for latex_file in latex_files:
        print(f"Processing {latex_file}...")
        try:
            extracted_files = extract_code_from_latex(latex_file)
            if extracted_files:
                print(f"  Extracted {len(extracted_files)} code files:")
                for filename, code in extracted_files:
                    print(f"    - {filename}")
                    total_extracted += 1
            else:
                print("  No code blocks found")
        except Exception as e:
            print(f"  Error processing {latex_file}: {e}")
    
    print(f"\nTotal extracted files: {total_extracted}")

if __name__ == "__main__":
    main() 