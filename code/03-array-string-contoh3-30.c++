#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
string strSample ("String ini akan dibalik!");
cout << "String asli: " << endl;
cout << strSample << endl << endl;
reverse (strSample.begin (), strSample.end ());
cout << "Setelah dibalik: " << endl;
cout << strSample;
return a.exec();
}