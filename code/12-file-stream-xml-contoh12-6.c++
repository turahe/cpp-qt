#include <QtCore/QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDomDocument>
#include <QDomElement>
#include <QDomText>
#include <QDebug>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QFile file("simple.xml");
if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
{
qDebug() << "File " << file.fileName() << " tidak ditemukan";
return a.exec();
}
QDomDocument dokumen;
if(!dokumen.setContent(&file))
{
qDebug() << "Gagal untuk parsing ke DOM tree";
file.close();
return a.exec();
}
QDomElement dokumenElemen = dokumen.documentElement();
QDomNode node = dokumenElemen.firstChild();
while(!node.isNull())
{
if(node.isElement())
{
QDomElement element = node.toElement();
qDebug() << "Element " << element.tagName();
qDebug() << "Atribut nama " << element.attribute("nama","tidak ada
attribute");
}
if(node.isText())
{
QDomText teks = node.toText();
qDebug() << teks.data();
}
node = node.nextSibling();
}
return a.exec();
}