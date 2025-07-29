#include <QtCore/QCoreApplication>
#include <QObject>
#include <QDebug>
using namespace std;
class Mahasiswa : QObject
{
public:
Mahasiswa(const QString &nim,QObject *parent=0);
const QString &nim() const;
void setNim(const QString &nim);
int getNimLength() const;
private:
QString _nim;
};
Mahasiswa::Mahasiswa(const QString &nim, QObject *parent)
{
_nim = nim;
}
const QString &Mahasiswa::nim() const
{
return _nim;
}
void Mahasiswa::setNim(const QString &nim)
{
_nim = nim;
}
int Mahasiswa::getNimLength() const
{
return _nim.length();
}
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QObject parent;
Mahasiswa *objMhs1,*objMhs2,*objMhs3;
objMhs1 = new Mahasiswa("22002321", &parent);
objMhs2 = new Mahasiswa("22002322", &parent);
objMhs3 = new Mahasiswa("22002323", &parent);
qDebug() << objMhs1->nim() << " : " << objMhs1->getNimLength() << " kar";
objMhs1->setNim(objMhs2->nim());
objMhs2->setNim(objMhs3->nim());
qDebug() << objMhs1->nim() << " : " << objMhs1->getNimLength() << " kar";
qDebug() << objMhs2->nim() << " : " << objMhs2->getNimLength() << " kar";
qDebug() << objMhs3->nim() << " : " << objMhs3->getNimLength() << " kar";
return a.exec();
}