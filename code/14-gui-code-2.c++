// Menangani klik mouse
connect(widget, SIGNAL(clicked()), this, SLOT(onClicked()));

// Menangani perubahan teks
connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));