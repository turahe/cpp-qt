#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication a(argc, argv);
  const int ARRAY_LENGTH = 5;
  int numbers[ARRAY_LENGTH] = {100,200,222,111,777};
  //mengakses alamat pertama dari array (numbers[0])
  cout << "Alamat numbers[0] : " << numbers << endl;
  //mengakses nilai dari elemen pertama array (numbers[0])
  cout << "Nilai numbers[0] : " << *numbers << endl;
  //mengakses alamat numbers[4]
  cout << "Alamat numbers[4] : " << numbers+4 << endl;
  //mengakses nilai dari numbers[4]
  cout << "Nilai numbers[4] : " << *(numbers+4) << endl;
  const int *pNumber = numbers;
  //menggunakan pointer untuk mencetak semua elemen array
  for(int i=0; i<ARRAY_LENGTH; i++)
  {
    cout << "numbers[" << i << "] = " << *(pNumber+i) << endl;
  }
  return a.exec();
}