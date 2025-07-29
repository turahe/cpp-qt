#include <QtCore/QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  //buat var nama dgn C-style string
  char nama[10] = "Halooooooo";
  //buat var string dan diisi nilai dari var nama
  string nama_copy(nama);
  cout<<nama_copy<<endl;
  //buat var nama2 dan kopikan isinya ke nama2_copy melalui konstruktor
  string nama2 = "saya belajar";
  string nama2_copy(nama2);
  cout<<nama2_copy<<endl;
  //buat var nama35 yg diisi nilai dari nama tapi hanya 5 huruf saja
  string nama35(nama,5);
  cout<<nama35<<endl;
  //buat var ulang yg diisi huruf 'C' sebanyak 10 buah
  string ulang(10,'a');
  cout<<ulang;
  return a.exec();
}