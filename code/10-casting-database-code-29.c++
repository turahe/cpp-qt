QSqlQuery query;
bool hasil = query.exec("INSERT INTO mahasiswa (nim, nama,ipk) VALUES
('22113344','anton', 3.4)");
if(hasil) qDebug() << "Berhasil"; else qDebug << "gagal";