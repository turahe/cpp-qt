#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
int A[2][3]={{1,2,3},{4,5,6}};
for(int baris=0;baris<2;baris++){
for(int kolom=0;kolom<3;kolom++){
cout<<A[baris][kolom]<<"\t";
}
cout<<endl;
}
return a.exec();
}