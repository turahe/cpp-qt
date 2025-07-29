#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  string satu("Percobaan 1 ");
  string dua("Percobaan 2 ");
  satu += dua;
  cout<<satu<<endl;
  string tampung = "Percobaan tampung";
  satu.append("Percobaan 3 ");
  satu.append(tampung);
  cout<<satu;
  return a.exec();
}