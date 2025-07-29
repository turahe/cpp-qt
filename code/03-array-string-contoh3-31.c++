#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  cout << "Masukkan sebuah string: " << endl;
  string strInput;
  getline (cin, strInput);
  transform(strInput.begin(),strInput.end(),strInput.begin(),(int(*)(int))toupper);
  cout << "Hasil konversi ke huruf besar: " << endl;
  cout << strInput << endl << endl;
  transform
  (strInput.begin(),strInput.end(),strInput.begin(),(int(*)(int))tolower);
  cout << "Hasil konversi ke huruf kecil: " << endl;
  cout << strInput << endl << endl;
  return a.exec();
}