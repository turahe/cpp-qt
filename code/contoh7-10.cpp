#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Dasar{
public:
void hallo() const{
cout << "Hallo" << endl;
}
void hallo(string kata) const{
cout << "Hallo " << kata << endl;
}
void hallo (string kata, string nama) const{
cout << "Hallo " << kata << " nama saya " << nama << endl;
}
};
    class Turunan : public Dasar{
public:
void hallo() const{ //<-- override terhadap salah satu metode
cout << "Ni hao ma" << endl;
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Turunan agus;
agus.hallo();
agus.hallo("apa kahabar");
agus.hallo("apa kahabar","Agus");
return a.exec();
}