QsqlQuery query.exec("select nim,nama,ipk from mahasiswa order by nim desc");
QString nim,nama;
float ipk;
while(query.next())
{
nim = query.value(0).toString();
nama = query.value(1).toString();
ipk = query.value(2).toFloat();
qDebug() << nim << " " << nama << " " << ipk;
}