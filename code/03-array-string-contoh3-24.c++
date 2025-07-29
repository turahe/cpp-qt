#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  char string1[100]="Kami kelompok ";
  char string2[]=" belajar Qt C++";
  strcat(string1,string2);
  cout<<"Jadi gabungannya adalah: "<<string1;
  return a.exec();
}