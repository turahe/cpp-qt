#!/usr/bin/env python3
"""
Test script to verify LaTeX build system
"""

import os
import subprocess
import sys

def test_latex_installation():
    """Test if LaTeX is installed"""
    print("🔍 Testing LaTeX installation...")
    
    try:
        result = subprocess.run(['pdflatex', '--version'], 
                              capture_output=True, text=True)
        if result.returncode == 0:
            print("✅ LaTeX is installed")
            return True
        else:
            print("❌ LaTeX is not installed or not in PATH")
            return False
    except FileNotFoundError:
        print("❌ LaTeX is not installed or not in PATH")
        return False

def test_make():
    """Test if make is available"""
    print("🔍 Testing make availability...")
    
    try:
        result = subprocess.run(['make', '--version'], 
                              capture_output=True, text=True)
        if result.returncode == 0:
            print("✅ Make is available")
            return True
        else:
            print("❌ Make is not available")
            return False
    except FileNotFoundError:
        print("❌ Make is not available")
        return False

def test_python():
    """Test if Python is available"""
    print("🔍 Testing Python availability...")
    
    try:
        result = subprocess.run([sys.executable, '--version'], 
                              capture_output=True, text=True)
        if result.returncode == 0:
            print(f"✅ Python is available: {result.stdout.strip()}")
            return True
        else:
            print("❌ Python is not available")
            return False
    except FileNotFoundError:
        print("❌ Python is not available")
        return False

def test_file_structure():
    """Test if required files exist"""
    print("🔍 Testing file structure...")
    
    required_files = [
        'latex/book.tex',
        'Makefile',
        'build-latex.sh',
        'server.py',
        'preview.html'
    ]
    
    missing_files = []
    for file_path in required_files:
        if os.path.exists(file_path):
            print(f"✅ {file_path}")
        else:
            print(f"❌ {file_path}")
            missing_files.append(file_path)
    
    return len(missing_files) == 0

def test_build():
    """Test the build process"""
    print("🔍 Testing build process...")
    
    # Create output directory
    os.makedirs('output', exist_ok=True)
    
    try:
        # Run a simple build test
        result = subprocess.run(['make', 'all'], 
                              capture_output=True, text=True, timeout=60)
        
        if result.returncode == 0:
            print("✅ Build completed successfully")
            
            # Check if PDF was created
            if os.path.exists('output/book.pdf'):
                size = os.path.getsize('output/book.pdf')
                print(f"✅ PDF created: {size} bytes")
                return True
            else:
                print("❌ PDF was not created")
                return False
        else:
            print(f"❌ Build failed: {result.stderr}")
            return False
            
    except subprocess.TimeoutExpired:
        print("❌ Build timed out")
        return False
    except Exception as e:
        print(f"❌ Build error: {str(e)}")
        return False

def main():
    """Main test function"""
    print("🚀 LaTeX Build System Test")
    print("=" * 40)
    
    tests = [
        ("LaTeX Installation", test_latex_installation),
        ("Make Availability", test_make),
        ("Python Availability", test_python),
        ("File Structure", test_file_structure),
        ("Build Process", test_build)
    ]
    
    results = []
    
    for test_name, test_func in tests:
        print(f"\n📋 {test_name}")
        print("-" * 20)
        try:
            result = test_func()
            results.append((test_name, result))
        except Exception as e:
            print(f"❌ Test failed with error: {str(e)}")
            results.append((test_name, False))
    
    # Summary
    print("\n" + "=" * 40)
    print("📊 Test Summary")
    print("=" * 40)
    
    passed = 0
    total = len(results)
    
    for test_name, result in results:
        status = "✅ PASS" if result else "❌ FAIL"
        print(f"{test_name}: {status}")
        if result:
            passed += 1
    
    print(f"\nOverall: {passed}/{total} tests passed")
    
    if passed == total:
        print("🎉 All tests passed! Your LaTeX build system is ready.")
        print("\nNext steps:")
        print("1. Run: python server.py")
        print("2. Open: http://localhost:8000")
        print("3. Click build options to generate PDF")
    else:
        print("⚠️  Some tests failed. Please check the issues above.")
        print("\nTroubleshooting:")
        print("1. Install LaTeX distribution (TeX Live, MiKTeX, or MacTeX)")
        print("2. Ensure all required files are present")
        print("3. Check file permissions")
        print("4. Try the Docker alternative: docker-compose up latex-simple")

if __name__ == '__main__':
    main() 