QSqlQuery query;
bool hasil = query.exec("DELETE FROM mahasiswa WHERE nim='22334455');
if(hasil) qDebug() << "Berhasil"; else qDebug << "gagal";