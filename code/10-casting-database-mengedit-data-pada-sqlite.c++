#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QtSql/QtSql>
#include <iostream>
using namespace std;
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
bool hasil = query.exec("update mahasiswa set nama='Antonius Rachmat C' where
nim='22002529'");
if(hasil) qDebug() << "Berhasil diedit"; else qDebug() << "Gagal diedit";
qDebug() << "Jumlah record yang diedit: " << query.numRowsAffected();
return a.exec();
}