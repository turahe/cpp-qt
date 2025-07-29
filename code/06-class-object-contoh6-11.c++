#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Contoh{
private:
int x;
int y;
int z;
public:
Contoh():x(0),y(2),z(4){
}
void tampilInfo(){
cout<<"x="<<x<<" y="<<y<<" z="<<z;
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Contoh aa;
aa.tampilInfo();
return a.exec();
}