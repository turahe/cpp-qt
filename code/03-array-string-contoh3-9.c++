#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int A[6]={1,2,3,4,5,6};
  int B[6];
  for(int i=0;i<6;i++){
    B[i]=A[i];
  }
  for(int j=0;j<6;j++){
    cout<<B[j]<<endl;
  }
  return a.exec();
}