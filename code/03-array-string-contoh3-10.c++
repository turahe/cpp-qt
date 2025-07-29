#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int matriks[3][5] = {{5,12,17,10,7},
  {15,6,25,2,19},
  {4,9,1,5,2}};
  for(int i=0;i<3;i++){
    for(int j=0;j<5;j++){
      cout<<matriks[i][j]<<"\t";
    }
      cout<<endl;
    }
  return a.exec();
}