#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
class Mahasiswa
{
public:
Mahasiswa(const string &nim);
~Mahasiswa();
const string &nim() const;
void setNim(const string &nim);
int getNimLength() const;
private:
string _nim;
};
Mahasiswa::Mahasiswa(const string &nim)
{
_nim = nim;
}
Mahasiswa::~Mahasiswa()
{
cout << "destroy object" << endl;
}
const string &Mahasiswa::nim() const
{
return _nim;
}
void Mahasiswa::setNim(const string &nim)
{
_nim = nim;
}
int Mahasiswa::getNimLength() const
{
return _nim.length();
}
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Mahasiswa *objMhs1,*objMhs2,*objMhs3;
objMhs1 = new Mahasiswa("22002321");
objMhs2 = new Mahasiswa("22002322");
objMhs3 = new Mahasiswa("22002323");
cout << objMhs1->nim() << " : " << objMhs1->getNimLength() << " kar" << endl;
objMhs1->setNim(objMhs2->nim());
objMhs2->setNim(objMhs3->nim());
cout << objMhs1->nim() << " : " << objMhs1->getNimLength() << " kar" << endl;
cout << objMhs2->nim() << " : " << objMhs2->getNimLength() << " kar" << endl;
cout << objMhs3->nim() << " : " << objMhs3->getNimLength() << " kar" << endl;
delete objMhs1;
delete objMhs2;
delete objMhs3;
return a.exec();
}