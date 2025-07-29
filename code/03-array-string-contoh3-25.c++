#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  string str1("Ini string C++");
  cout<<"Isi str1 = "<<str1<<endl;
  //salin isi str1 ke str2
  string str2;
  str2 = str1;
  cout<<"Isi str2 = "<<str2<<endl;
  //ubah str2
  str2 = "Hallo, ";
  //buat strhasil dan isi dgn gabungan dari str1 dan str2
  string strhasil;
  strhasil = str2 + str1;
  cout<<strhasil;
  return a.exec();
}