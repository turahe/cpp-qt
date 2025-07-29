#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QtSql/QtSql>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
qDebug() << QSqlDatabase::drivers();
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("testmhs.db");
if(!db.open())
{
qDebug() << db.lastError();
qFatal( "Failed to connect." );
} else qDebug() << "Koneksi berhasil";
QSqlQuery query;
bool hasil = query.exec("insert into mahasiswa(nim,nama,ipk) values
('22334455','mhs baru',3.12)");
if(hasil) qDebug() << "Berhasil ditambahkan"; else qDebug() << "Gagal
ditambahkan";
return a.exec();
}