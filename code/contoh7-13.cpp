#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Lingkaran{
public:
float getLuas(){
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
    Silinder* s = new Silinder(); //<-- objek bertipe Silinder
    Lingkaran* objek1 = s; //<-- variabel pointer bertipe kelas dasar
    Lingkaran& objek2 = *s; //<-- variabel referensi bertipe kelas dasar
    Lingkaran objek3 = *s; //<-- variabel nilai bertipe kelas dasar
    cout << "Pointer : " ;
    objek1->getLuas(); //<-- memanggil dai variabel pointer
    cout << "Referensi : " ;
    objek2.getLuas(); //<-- memanggil dai variabel referensi
    cout << "Nilai : " ;
    objek3.getLuas(); //<-- memanggil dai variabel nilai
    return a.exec();
}
