#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QtSql/QtSql>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
qDebug() << QSqlDatabase::drivers();
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName( "testmhs.db" );
if( !db.open() )
{
qDebug() << db.lastError();
qFatal( "Failed to connect." );
} else qDebug() << "Koneksi berhasil";
return a.exec();
}