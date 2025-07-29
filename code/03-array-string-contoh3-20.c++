#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  string data2;
  cout<<"Masukkan kalimat apapun yang anda sukai (max 100 huruf): ";
  getline(cin,data2);
  cout<<"panjang huruf adalah: "<<data2.length()<<" karakter";
  return a.exec();
}