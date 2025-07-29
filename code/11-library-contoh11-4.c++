#include <QtCore/QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QString nama = "Erick Kurniawan";
//menggunakan fungsi left, mid, dan right
QString firstName = nama.left(5);
qDebug() << "firstName : " << firstName;
QString lastName = nama.right(9);
qDebug() << "lastName : " << lastName;
QString midName = nama.mid(6,5);
qDebug() << "midName : " << midName;
return a.exec();
}