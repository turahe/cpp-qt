#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDomDocument>
#include <QDomElement>
#include <QDomText>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QFile fileAsli("simple.xml");
if(!fileAsli.open(QIODevice::ReadOnly | QIODevice::Text))
{
qDebug() << "File " << fileAsli.fileName() << " tidak ditemukan";
return a.exec();
}
QDomDocument dokumen;
if(!dokumen.setContent(&fileAsli))
{
qDebug() << "Gagal parsing file ke DOM tree";
fileAsli.close();
return a.exec();
}
fileAsli.close();
QDomElement elemenDokumen = dokumen.documentElement();
QDomNodeList elemen = elemenDokumen.elementsByTagName("Mahasiswa");
if(elemen.size() == 0)
{
QDomElement mhs = dokumen.createElement("Mahasiswa");
elemenDokumen.insertBefore(mhs,QDomNode());
}
else
{
QDomElement mhs = elemen.at(0).toElement();
QDomElement nama = dokumen.createElement("Nama");
QDomText textNama = dokumen.createTextNode("Erick Kurniawan");
nama.appendChild(textNama);
mhs.appendChild(nama);
}
QFile fileModif("simplemodif.xml");
if(!fileModif.open(QIODevice::WriteOnly | QIODevice::Text))
{
qDebug() << "Gagal untuk membaca file xml";
return a.exec();
}
QTextStream stream(&fileModif);
stream << dokumen.toString();
qDebug() << "File berhasil dimodifikasi dan disimpan pada file simplemodif.xml";
fileModif.close();
//membaca isi dari file simplemodif.xml
qDebug() << "Setelah dimodifikasi isi dari simplemodif.xml adalah";
if(!fileModif.open(QIODevice::ReadOnly | QIODevice::Text))
{
qDebug() << "Gagal membaca file xml";
return a.exec();
}
qDebug() << fileModif.readAll();
fileModif.close();
return a.exec();
}