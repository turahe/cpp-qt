#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int nilai[5], x;
  cout<<"Memasukkan nilai"<<endl;
  for(x=0;x<5;x++)
  {
    cout<<"Nilai Angka ke - "<<x+1<< ": ";
    cin>>nilai[x];
  }
  cout<<endl;
  cout<<"Membaca nilai :\n";
  for(x=0;x<5;x++)
  {
    cout<<"Nilai Angka : "<<nilai[x]<<endl;
  }
  return a.exec();
}