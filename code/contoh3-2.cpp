#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int bil[7],i;
  cout<<"elemen ke-1 ? "; cin>>bil[0];
  bil[1] = 5;
  bil[2] = bil[1] + 20;
  for(i=4;i<7;i++)
    bil[i] = i*10;
    bil[3] = bil[bil[1]];
  for(i=0;i<7;i++)
    cout<<"bil["<<i<<"] = "<<bil[i]<<" dan alamatnya: "<<&bil[i]<<"\n";
  return a.exec();
}