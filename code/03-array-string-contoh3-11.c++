#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int matriks[3][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
  int matrikshasil[3][5];
  for(int i=0;i<3;i++){
    for(int j=0;j<5;j++){
      matrikshasil[i][j] = matriks[i][j];
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<5;j++){
      cout<<matrikshasil[i][j]<<"\t";
    }
    cout<<endl;
  }
  return a.exec();
}