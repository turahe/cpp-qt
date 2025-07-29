#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int matriks[3][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
  int matrikshasil[15];
  int counter=-1;
  for(int i=0;i<3;i++){
    for(int j=0;j<5;j++){
      counter++;
      matrikshasil[counter] = matriks[i][j];
    }
  }
  for(int i=0;i<15;i++){
    cout<<matrikshasil[i]<<endl;
  }
  return a.exec();
}