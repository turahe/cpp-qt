#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QXmlStreamWriter>
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
QFile file("simple.xml");
if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
{
qDebug() << "File tidak ditemukan..";
return a.exec();
}
QXmlStreamWriter writer(&file);
writer.setAutoFormatting(true);
writer.writeStartDocument();
writer.writeStartElement("Books");
writer.writeStartElement("Book");
writer.writeStartElement("Author");
writer.writeAttribute("Name","Erick Kurniawan");
writer.writeAttribute("Title","Qt Programming");
writer.writeEndDocument();
file.close();
qDebug() << "File sudah berhasil dibuat !";
return a.exec();
}