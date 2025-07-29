#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Mahasiswa
{
public:
Mahasiswa();
~Mahasiswa();
private:
float ipk;
};
Mahasiswa::Mahasiswa()
{
cout << "Konstruktor dipanggil.." << endl;
ipk=3.5;
}
Mahasiswa::~Mahasiswa()
{
cout << "Destruktor dipanggil.." << endl;
}
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
cout << "Deklarasi object tanpa pointer " << endl;
Mahasiswa mhs1;
cout << "Mengalokasikan heap memory untuk menyimpan objek " << endl;
Mahasiswa *mhs2 = new Mahasiswa;
cout << "Delete objek di memory " << endl;
delete mhs2;
mhs2 = 0; //null pointer
return a.exec();
}