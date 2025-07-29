#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  char h[5];
  for(int i=0;i<5;i++){
    cout<<"Elemen ke "<<i<<" = "<<h[i]<<endl;
  }
  return a.exec();
  }