#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Lingkaran{
public:
virtual float getLuas(){
cout << "Luas Lingkaran" << endl;
return 0;
}
};
class Silinder : public Lingkaran{
public:
float getLuas(){
cout << "Luas Silinder" << endl;
return 0;
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Lingkaran *objek1; //<-- variabel pointer bertipe kelas dasar
objek1 = new Silinder(); //<-- objek bertipe kelas turunan
objek1->getLuas(); //<-- memanggil metode yang dioverride
return a.exec();
}