#!/usr/bin/env python3
"""
Simple web server for LaTeX document preview and build system
"""

import os
import subprocess
import json
import threading
import time
from http.server import HTTPServer, BaseHTTPRequestHandler
from urllib.parse import urlparse, parse_qs
import mimetypes

class LaTeXBuildHandler(BaseHTTPRequestHandler):
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
            '/favicon.ico': None  # Ignore favicon requests
        }
        
        if path in file_paths:
            file_path = file_paths[path]
            if file_path and os.path.exists(file_path):
                self.serve_file(file_path)
            else:
                self.send_error(404, "File not found")
        else:
            self.send_error(404, "Not found")
    
    def do_POST(self):
        """Handle POST requests for build operations"""
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        
        try:
            data = json.loads(post_data.decode('utf-8'))
            build_type = data.get('type', 'all')
            
            # Start build in background thread
            thread = threading.Thread(target=self.build_latex, args=(build_type,))
            thread.daemon = True
            thread.start()
            
            self.send_response(200)
            self.send_header('Content-type', 'application/json')
            self.end_headers()
            response = {'status': 'building', 'message': f'Started {build_type} build'}
            self.wfile.write(json.dumps(response).encode())
            
        except Exception as e:
            self.send_error(500, f"Build error: {str(e)}")
    
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
    
    print(f"Starting LaTeX preview server on port {port}")
    print(f"Open http://localhost:{port} in your browser")
    print("Press Ctrl+C to stop the server")
    
    try:
        httpd = HTTPServer(server_address, LaTeXBuildHandler)
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("\nShutting down server...")
        httpd.shutdown()

if __name__ == '__main__':
    main() 