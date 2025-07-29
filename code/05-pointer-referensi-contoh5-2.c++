#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication a(argc, argv);
  ushort umur;
  ushort *pUmur = 0;
  umur = 17;
  cout << "Umur : " << umur << endl;
  pUmur = &umur;
  cout << "pUmur : " << *pUmur << endl;
  cout << "Merubah nilai pUmur.." << endl;
  *pUmur = 28;
  cout << "Umur : " << umur << endl;
  cout << "pUmur : " << *pUmur << endl;
  cout << "Merubah nilai umur.." << endl;
  umur = 30;
  cout << "Umur : " << umur << endl;
  cout << "pUmur : " << *pUmur << endl;
  return a.exec();
}