#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int angka[5];
  angka[0] = 0; //batas bawah array
  angka[4] = 4; //batas atas array
  angka[5] = 5; //indeks melebihi batas
  //program akan HANG
  cout<<angka[5];
  return a.exec();
}