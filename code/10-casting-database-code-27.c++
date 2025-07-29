QSqlQuery query("SELECT * FROM mahasiswa");
while (query.next()) {
QString nim = query.value(0).toString();
qDebug() << nim;
}