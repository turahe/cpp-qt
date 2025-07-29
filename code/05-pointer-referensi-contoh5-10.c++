#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
void Tukar(int *x, int *y);
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  int x=12, y=21;
  cout << "main func, x=" << x << ", y=" << y << endl;
  Tukar(&x,&y);
  cout << "main func, x=" << x << ", y=" << y << endl;
  return a.exec();
}
  void Tukar(int *x, int *y)
{
  int tampung;
  cout << "Pada fungsi, sebelum ditukar x=" << *x << ",y=" << *y << endl;
  tampung = *x;
  *x = *y;
  *y = tampung;
  cout << "Pada fungsi, sesudah ditukar x=" << *x << ",y=" << *y << endl;
}