@echo off
echo ========================================
echo    C++ Qt Learning Book - System Test
echo ========================================
echo.

echo Running system test...
python test-build.py

echo.
echo ========================================
echo    Starting Web Preview Server
echo ========================================
echo.
echo The web preview will be available at:
echo http://localhost:8000
echo.
echo Press Ctrl+C to stop the server
echo.

python server.py

pause 