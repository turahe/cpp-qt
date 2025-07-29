#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication a(argc, argv);
  int bil = 14;
  int &rBil = bil;
  cout << "rBil : " << rBil << endl;
  int bil2 = 19;
  rBil = bil2; //tebak hasilnya !
  cout << "rBil : " << rBil << endl;
  cout << "bil : " << bil << endl;
  return a.exec();
}