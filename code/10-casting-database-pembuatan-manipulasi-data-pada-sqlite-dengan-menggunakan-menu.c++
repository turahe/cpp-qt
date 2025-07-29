#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QtSql/QtSql>
#include <iostream>
#include <conio.h>
using namespace std;
class Tabel{
private:
QString namadb;
QString namatabel;
QString strquery;
QSqlDatabase db;
public:
//konstruktor
Tabel(QString namadb, QString namatabel){
this->namadb = namadb;
this->namatabel = namatabel;
}
bool connect(){
this->db = QSqlDatabase::addDatabase("QSQLITE");
this->db.setDatabaseName(this->namadb);
if(!this->db.open())
{
qDebug() << "No";
return false;
} else {
qDebug() << "Yes";
return true;
}
}
bool jalanQuery(QString query){
this->strquery = query;
bool hasil = false;
if(this->db.isOpen()){
QSqlQuery myq(this->db);
hasil = myq.exec(this->strquery);
}
return hasil;
}
void ambilData(QString query){
this->strquery = query;
if(this->db.isOpen()){
QSqlQuery myq(this->db);
myq.exec(this->strquery);
QSqlRecord rec = myq.record();
int cols = rec.count();
QString temp;
for( int c=0; c<cols; c++ )
temp += rec.fieldName(c) + ((c<cols-1)?"\t":"");
qDebug() << temp;
while( myq.next() )
{
temp = "";
for( int c=0; c<cols; c++ )
temp += myq.value(c).toString() + ((c<cols-1)?"\t":"");
qDebug() << temp;
}
}
}
QString getNamaTabel(){
return this->namatabel;
}
QString getNamaDb(){
return this->namadb;
}
QSqlDatabase getDb(){
return this->db;
}
};
void tambahData(Tabel t){
string nim,nama,ipk;
getline(cin,nim);
cout << "NIM: "; getline(cin,nim);
cout << "Nama: "; getline(cin,nama);
cout << "IPK: "; getline(cin,ipk);
QString s = "insert into "+t.getNamaTabel()+" values
('"+nim.c_str()+"','"+nama.c_str()+"',"+ipk.c_str()+")";
bool hasil = t.jalanQuery(s);
if(hasil) qDebug() << "Penambahan berhasil"; else qDebug() << "Penambahan gagal";
}
void hapusData(Tabel t){
string nim;
getline(cin,nim);
cout << "NIM yang akan dihapus: "; getline(cin,nim);
QString s = "delete from "+t.getNamaTabel()+" where nim='"+nim.c_str()+"'";
bool hasil = t.jalanQuery(s);
if(hasil) qDebug() << "Penghapusan berhasil"; else qDebug() << "Penghapusan
gagal";
}
void tampilData(Tabel t){
QString s = "select * from "+t.getNamaTabel()+" order by nim asc";
t.ambilData(s);
}
void cariNim(Tabel t){
string nim;
getline(cin,nim);
cout << "NIM yang akan dicari: "; getline(cin,nim);
QString s = "select * from "+t.getNamaTabel()+" where nim='"+nim.c_str()+"'";
t.ambilData(s);
}
void editData(Tabel t){
string nim,nama,ipk;
getline(cin,nim);
cout << "NIM yang akan diedit: "; getline(cin,nim);
cout << "Nama baru: "; getline(cin,nama);
cout << "IPK baru: "; getline(cin,ipk);
QString s = "update "+t.getNamaTabel()+" set
nama='"+nama.c_str()+"',ipk="+ipk.c_str()+" where nim='"+nim.c_str()+"'";
bool hasil = t.jalanQuery(s);
if(hasil) qDebug() << "Pengeditan berhasil"; else qDebug() << "Pengeditan gagal";
}
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
int pil;
Tabel t("testmhs.db","mahasiswa");
t.connect();
do {
system("cls");
cout << "MENU" <<endl;
cout << "1. Tambah data\n";
cout << "2. Tampil data\n";
cout << "3. Hapus data\n";
cout << "4. Cari nim\n";
cout << "5. Edit data\n";
cout << "6. Exit\n";
cout << "Pilihan : "; cin >> pil;
cout << endl;
switch (pil) {
case 1:
tambahData(t);break;
case 2:
tampilData(t);break;
case 3:
hapusData(t);break;
case 4:
cariNim(t);break;
case 5:
editData(t);
}
cout << "Tekan sembarang tombol..."; getch();
} while (pil >=1 && pil<=5);
cout << "Good bye";
return a.exec();
}