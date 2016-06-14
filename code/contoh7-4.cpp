#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kelasku{
public:
Kelasku(){
cout << "Konstruktor Kelas Dasar dijalankan..." << endl;
}
public:
void hai(){
cout << "Hai, apa khabar...?" << endl;
}
};
class Turunan : public Kelasku{
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Turunan test; //<-- membuat objek dari kelas Turunan saja
return a.exec();
}