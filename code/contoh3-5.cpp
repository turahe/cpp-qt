#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int bil[7] = {2,5}; //inisialisasi dua elemen pertama
  for(int i=0;i<7;i++){
    cout<<"Elemen ke-"<<i<<": "<<bil[i]<<"\n";
  }
  return a.exec();
}