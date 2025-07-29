#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  char buffer[50] = {'\0'};
  cout << "Isi data string: ";
  cin.get(buffer,49); //ambil sebanyak 50 karakter atau diakhiri tanda enter
  cout << "Hasil data string: " << buffer << endl;
  return a.exec();
}