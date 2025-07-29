#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication a(argc, argv);
  int bil = 20;
  //pointer yang menunjuk ke alamat lokal
  int *pBil = &bil;
  cout << "bil : " << bil << endl;
  cout << "pBil : " << *pBil << endl;
  //mengalokasikan memory di heap untuk menyimpan data integer
  int *pHeap = new int;
  //nilai 19 akan disimpan di heap yg sudah dialokasikan
  *pHeap = 19;
  cout << "Nilai pHeap : " << *pHeap << endl;
  delete pHeap;
  pHeap = 0; //null pointer
  //mengalokasikan memory
  pHeap = new int;
  *pHeap = 100;
  cout << "Nilai pHeap : " << *pHeap << endl;
  delete pHeap;
  return a.exec();
}