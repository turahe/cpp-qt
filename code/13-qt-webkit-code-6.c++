void Dialog::on_backButton_clicked()
{
    ui->webView->back();
}

void Dialog::on_forwardButton_clicked()
{
    ui->webView->forward();
}

void Dialog::on_refreshButton_clicked()
{
    ui->webView->reload();
}

void Dialog::on_goButton_clicked()
{
    // We just type the domain without "http://"
    ui->webView->load(("http://"+ui->urlEdit->text()));
}

void Dialog::on_urlEdit_returnPressed()
{
    // Same as goButton click
    on_goButton_clicked();
}