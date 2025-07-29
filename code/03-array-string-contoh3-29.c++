#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  string strSample ("Kata pak Hari, \"hari ini matahari cerah sekali!\"");
  cout << "Contoh string adalah: " << endl;
  cout << strSample << endl << endl;
  // Temukan kata "hari"
  size_t nOffset = strSample.find ("hari", 0);
  // Cek apakah ketemu?
  if (nOffset != string::npos)
    cout << "Ketemu pertama kata \"hari\" pada offset " << nOffset;
  else
    cout << "Substring tidak ditemukan" << endl;
    cout << endl << endl;
    cout << "Mencari semua kata substring \"hari\"" << endl;
    size_t nSubstringOffset = strSample.find ("hari", 0);
  while (nSubstringOffset != string::npos)
  {
    cout << "Kata \"hari\" ada di offset " << nSubstringOffset << endl;
    // Pencarian dilanjutkan ke karakter berikutnya dst
    size_t nSearchOffset = nSubstringOffset + 1;
    nSubstringOffset = strSample.find ("hari", nSearchOffset);
  }
  cout << endl;
  cout << "Mencari semua karakter 'a'" << endl;
  const char chCharToSearch = 'a';
  size_t nCharacterOffset = strSample.find (chCharToSearch, 0);
  while (nCharacterOffset != string::npos)
  {
    cout << "'" << chCharToSearch << "' ditemukan";
    cout << " pada posisi " << nCharacterOffset << endl;
    //pencarian dilanjutkan
    size_t nCharSearchOffset = nCharacterOffset + 1;
    nCharacterOffset = strSample.find(chCharToSearch,nCharSearchOffset);
  }
  return a.exec();
}