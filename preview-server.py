#!/usr/bin/env python3
"""
Standalone LaTeX Preview Server
Works without Docker or LaTeX installation
"""

import os
import json
import threading
import time
from http.server import HTTPServer, BaseHTTPRequestHandler
from urllib.parse import urlparse
import mimetypes
import webbrowser

class LaTeXPreviewHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        """Handle GET requests"""
        parsed_url = urlparse(self.path)
        path = parsed_url.path
        
        # Serve static files
        if path == '/':
            path = '/preview.html'
        
        # Map paths to files
        file_paths = {
            '/preview.html': 'preview.html',
            '/output/book.pdf': 'output/book.pdf',
            '/favicon.ico': None,  # Ignore favicon requests
            '/api/status': None,   # Handle status API
        }
        
        if path == '/api/status':
            self.send_status_response()
        elif path in file_paths:
            file_path = file_paths[path]
            if file_path and os.path.exists(file_path):
                self.serve_file(file_path)
            else:
                self.send_error(404, "File not found")
        else:
            self.send_error(404, "Not found")
    
    def do_POST(self):
        """Handle POST requests for build operations"""
        content_length = int(self.headers.get('Content-Length', 0))
        if content_length > 0:
            post_data = self.rfile.read(content_length)
            try:
                data = json.loads(post_data.decode('utf-8'))
                build_type = data.get('type', 'all')
                self.handle_build_request(build_type)
            except Exception as e:
                self.send_error(500, f"Build error: {str(e)}")
        else:
            self.send_error(400, "No data received")
    
    def send_status_response(self):
        """Send system status"""
        status = {
            'latex_installed': self.check_latex_installation(),
            'pdf_exists': os.path.exists('output/book.pdf'),
            'build_ready': True,
            'message': 'Preview system ready'
        }
        
        self.send_response(200)
        self.send_header('Content-type', 'application/json')
        self.end_headers()
        self.wfile.write(json.dumps(status).encode())
    
    def check_latex_installation(self):
        """Check if LaTeX is installed"""
        try:
            import subprocess
            result = subprocess.run(['pdflatex', '--version'], 
                                  capture_output=True, text=True, timeout=5)
            return result.returncode == 0
        except:
            return False
    
    def handle_build_request(self, build_type):
        """Handle build requests"""
        latex_installed = self.check_latex_installation()
        
        if not latex_installed:
            response = {
                'status': 'error',
                'message': 'LaTeX not installed. Use Docker or install LaTeX locally.',
                'suggestions': [
                    'Install MiKTeX (Windows): https://miktex.org/download',
                    'Install MacTeX (macOS): brew install --cask mactex',
                    'Install TeX Live (Linux): sudo apt-get install texlive-full',
                    'Use Docker: docker-compose up latex-simple'
                ]
            }
        else:
            # Start build in background thread
            thread = threading.Thread(target=self.build_latex, args=(build_type,))
            thread.daemon = True
            thread.start()
            
            response = {
                'status': 'building',
                'message': f'Started {build_type} build'
            }
        
        self.send_response(200)
        self.send_header('Content-type', 'application/json')
        self.end_headers()
        self.wfile.write(json.dumps(response).encode())
    
    def serve_file(self, file_path):
        """Serve a file with appropriate MIME type"""
        try:
            with open(file_path, 'rb') as f:
                content = f.read()
            
            # Determine MIME type
            mime_type, _ = mimetypes.guess_type(file_path)
            if mime_type is None:
                mime_type = 'application/octet-stream'
            
            self.send_response(200)
            self.send_header('Content-type', mime_type)
            self.send_header('Content-length', str(len(content)))
            self.end_headers()
            self.wfile.write(content)
            
        except Exception as e:
            self.send_error(500, f"Error serving file: {str(e)}")
    
    def build_latex(self, build_type):
        """Build LaTeX document in background"""
        try:
            print(f"Starting {build_type} build...")
            
            # Create output directory if it doesn't exist
            os.makedirs('output', exist_ok=True)
            
            # Run build command
            if build_type == 'all':
                cmd = ['make', 'all']
            elif build_type == 'index':
                cmd = ['make', 'index']
            elif build_type == 'bib':
                cmd = ['make', 'bib']
            elif build_type == 'clean':
                cmd = ['make', 'clean']
            else:
                print(f"Unknown build type: {build_type}")
                return
            
            # Run the command
            import subprocess
            result = subprocess.run(cmd, capture_output=True, text=True, cwd=os.getcwd())
            
            if result.returncode == 0:
                print(f"{build_type} build completed successfully")
            else:
                print(f"{build_type} build failed: {result.stderr}")
                
        except Exception as e:
            print(f"Build error: {str(e)}")
    
    def log_message(self, format, *args):
        """Custom logging"""
        print(f"[{time.strftime('%Y-%m-%d %H:%M:%S')}] {format % args}")

def main():
    """Main function to start the server"""
    port = 8000
    server_address = ('', port)
    
    print("🚀 LaTeX Preview Server")
    print("=" * 50)
    print(f"Starting server on port {port}")
    print(f"Open http://localhost:{port} in your browser")
    print("Press Ctrl+C to stop the server")
    print("=" * 50)
    
    # Create output directory
    os.makedirs('output', exist_ok=True)
    
    try:
        httpd = HTTPServer(server_address, LaTeXPreviewHandler)
        
        # Try to open browser automatically
        try:
            webbrowser.open(f'http://localhost:{port}')
            print("🌐 Browser opened automatically")
        except:
            pass
        
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("\n🛑 Shutting down server...")
        httpd.shutdown()
    except Exception as e:
        print(f"❌ Server error: {str(e)}")

if __name__ == '__main__':
    main() 