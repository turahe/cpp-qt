#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  char data[6] = {'\0'};
  char data2[]="STRINGKU";
  strncpy(data,data2,5);
  cout<<"string pertama: "<<data<<"\n";
  cout<<"string kedua : "<<data2;
  return a.exec();
}