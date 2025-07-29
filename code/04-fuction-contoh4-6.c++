#include <QtCore/QCoreApplication>
#include <iostream>
int volume(int,int=1,int=1); /*prototype*/
int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication a(argc, argv);
  int panjang,lebar,tinggi;
  panjang = 10;
  lebar = 15;
  tinggi = 25;
  /*menghitun volume*/
  cout << "Volume 1 --> " << volume(panjang,lebar,tinggi)<< endl;
  cout << "Volume 2 --> " << volume(panjang,lebar)<< endl;
  cout << "Volume 3 --> " << volume(panjang)<< endl;
  return a.exec();
  }
  /*---Fungsi volume---*/
  int volume(int p, int l, int t)
  {
  return p * l * t;
}