#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
  class Mahasiswa
  {
    public:
    Mahasiswa();
    Mahasiswa(Mahasiswa&);
    ~Mahasiswa();
  };
    Mahasiswa::Mahasiswa()
  {
    classout << "Memanggil Mahasiswa Konstruktor " << endl;
  }
    Mahasiswa::Mahasiswa(Mahasiswa &)
  {
    cout << "Memanggil Copy Konstruktor " << endl;
  }
    Mahasiswa::~Mahasiswa()
  {
    cout << "Memanggil Mahasiswa Destruktor " << endl;
  }
  Mahasiswa &FunctionMhs(Mahasiswa &objMhs);
  int main(int argc, char *argv[])
  {
    QCoreApplication a(argc, argv);
    cout << "Membuat object mahasiswa " << endl;
    Mahasiswa objMhs1;
    FunctionMhs(objMhs1);
    return a.exec();
    }
      Mahasiswa &FunctionMhs(Mahasiswa &objMhs)
    {
      cout << "Mengembalikan FunctionMhs .." << endl;
    return objMhs;
}