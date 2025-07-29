#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
int aa=5;
int bb=2;
float x = 5.0;
float y = 2.0;
int c=aa/bb;
cout<<"1. c="<<c<<endl;
c = (float) aa/bb;
cout<<"2. c="<<c<<endl;
c = (float) aa / (float) bb;
cout<<"3. c="<<c<<endl;
c = x / y;
cout<<"4. c="<<c<<endl;
c = (int) x / (int) y;
cout<<"5. c="<<c<<endl;
c = (float) x/y;
cout<<"6. c="<<c<<endl;
float d=aa/bb;
cout<<"7. d="<<d<<endl;
d = (float) aa/bb;
cout<<"8. d="<<d<<endl;
d = (float) aa / (float) bb;
cout<<"9. d="<<d<<endl;
d = x / y;
cout<<"10. d="<<d<<endl;
d = (int) x/ (int) y;
cout<<"11. d="<<d<<endl;
d = (int) x/y;
cout<<"12. d="<<d<<endl;
return a.exec();
}