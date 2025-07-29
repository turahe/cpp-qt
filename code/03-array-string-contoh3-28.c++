#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  string satu("Indonesia Raya");
  for(size_t i=0;i<satu.length();i++){
    cout<<satu[i]<<endl;
  }
  cout<<endl;
  cout<<"C-sytle: "<<satu.c_str();
  return a.exec();
}