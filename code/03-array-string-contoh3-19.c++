#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  char data[100];
  cout<<"Masukkan kalimat apapun yang anda sukai (max 100 huruf): ";
  cin.get(data,99);
  cout<<"panjang huruf adalah: "<<strlen(data)<<" karakter";
  return a.exec();
}