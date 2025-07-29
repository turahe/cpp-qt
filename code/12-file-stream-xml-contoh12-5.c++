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
QDomDocument dokumen;
QDomElement mhs = dokumen.createElement("Mahasiswa");
mhs.setAttribute("Jurusan","TI");
QDomElement nim = dokumen.createElement("Nim");
QDomElement ipk = dokumen.createElement("Ipk");
QDomText nimtext = dokumen.createTextNode("22002321");
QDomText ipktext = dokumen.createTextNode("3.5");
dokumen.appendChild(mhs);
mhs.appendChild(nim);
nim.appendChild(nimtext);
mhs.appendChild(ipk);
ipk.appendChild(ipktext);
QFile file("simple.xml");
if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
{
qDebug() << "File tidak ditemukan !";
a.exit(-1);
return a.exec();
}
QTextStream stream(&file);
stream << dokumen.toString();
qDebug() << "File XML berhasil dibuat ..";
file.close();
return a.exec();
}