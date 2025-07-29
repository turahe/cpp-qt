#include <QtCore/QCoreApplication>
#include <QtSql/QtSql>
#include <QtDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
qDebug() << QSqlDatabase::drivers();
QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
db.setDatabaseName( "testmhs" );
db.setHostName("localhost");
db.setUserName("root");
db.setPassword("");
if( !db.open() )
{
qDebug() << db.lastError();
qFatal( "Failed to connect." );
} else {
qDebug() << "Koneksi sukses";
QSqlQuery query(db);
query.exec("SELECT * FROM mahasiswa");
while (query.next()) {
qDebug() << query.value(0).toString();
qDebug() << query.value(1).toString();
qDebug() << query.value(2).toString();
}
}
return a.exec();
}