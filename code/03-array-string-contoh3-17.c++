#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  char buffer[50] = {'\0'};
  cout << "Isi data string: ";
  cin >> buffer;
  cout << "Hasil data string: " << buffer << endl;
  return a.exec();
}