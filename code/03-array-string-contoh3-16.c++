#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  char string[6]="String";
  int K;
  for(K=0;string[K]!='\0';K++)
    cout<<string[K];
  return a.exec();
}