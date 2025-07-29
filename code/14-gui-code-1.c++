// Menghubungkan signal dengan slot
connect(sender, SIGNAL(signalName()), receiver, SLOT(slotName()));

// Contoh: Menghubungkan klik tombol dengan fungsi
connect(button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));