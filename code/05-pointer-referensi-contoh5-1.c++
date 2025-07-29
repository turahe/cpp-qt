#include <QtCore/QCoreApplication>
#include <iostream>
int main(int argc, char *argv[])
{
  using namespace std;
  QCoreApplication a(argc, argv);
  unsigned short bil1 =20;
  ulong bil2 = 200000;
  long bil3 = -670000;
  cout << "bil1 = " << bil1 << " address = " << &bil1 << endl;
  cout << "bil2 = " << bil2 << " address = " << &bil2 << endl;
  cout << "bil3 = " << bil3 << " address = " << &bil3 << endl;
  return a.exec();
}