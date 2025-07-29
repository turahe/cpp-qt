QSqlQuery query;
bool hasil = query.exec("UPDATE mahasiswa SET nama='Antonius Rachmat C' WHERE
nim='2200259');
if(hasil) qDebug() << "Berhasil"; else qDebug << "gagal";