#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication a(argc, argv);
  ushort umur1 = 17, umur2 = 28;
  ushort *pUmur = &umur1; //ganti referensi
  cout << "umur1 : " << umur1 << " alamat : " << &umur1 << endl;
  cout << "pUmur : " << *pUmur << " alamat : " << pUmur << endl;
  pUmur = &umur2;
  cout << "umur2 : " << umur2 << " alamat : " << &umur2 << endl;
  cout << "pUmur : " << *pUmur << " alamat : " << pUmur << endl;
  return a.exec();
}