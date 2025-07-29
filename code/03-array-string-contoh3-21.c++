#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  char data[100] = {'\0'};
  char data2[]="STRING";
  strcpy(data,data2);
  cout<<"string pertama: "<<data<<"\n";
  cout<<"string kedua : "<<data2;
  return a.exec();
}