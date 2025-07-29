#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int A[6]={1,2,3,4,5,6};
  int B[6];
  B = A;
  return a.exec();
}