#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
class Buku{
private:
int jmlhal;
string pengarang;
string judul;
public:
Buku(string pengarang="unknown", string judul="unknown",int jmlhal=1){
Buku::jmlhal = jmlhal;
Buku::pengarang = pengarang;
Buku::judul = judul;
}
void tampilInfo(){
cout<<"Judul: "<<Buku::judul<<endl;
cout<<"Pengarang: "<<Buku::pengarang<<endl;
cout<<"Jumlah halaman: "<<Buku::jmlhal<<endl;
}
};
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
Buku b1;
Buku b2("Antonius");
Buku b3("Robert","Membuat aplikasi C++");
Buku b4("Walter","Pemrograman C",100);
    b1.tampilInfo();
b2.tampilInfo();
b3.tampilInfo();
b4.tampilInfo();
return a.exec();
}