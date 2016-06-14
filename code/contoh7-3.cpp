#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Kelasku{
public:
Kelasku(){} //<-- konstruktor ini boleh tidak ditulis
public:
    void hai(){
cout << "Hai, apa khabar...?" << endl;
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Kelasku test;
test.hai();
return a.exec();
}