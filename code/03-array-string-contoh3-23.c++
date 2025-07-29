#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  char str[6] = "anton";
  char str2[7];
  char str3[14];
  str3 = str + str2;
  return a.exec();
}