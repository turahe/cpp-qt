#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Set window properties
    setWindowTitle("Aplikasi GUI Sederhana");
    setFixedSize(400, 300);

    // Create central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Create buttons
    buttonA = new QPushButton("Tampilkan Gambar A", this);
    buttonB = new QPushButton("Tampilkan Gambar B", this);

    // Create image label
    imageLabel = new QLabel("Klik tombol untuk menampilkan gambar", this);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setStyleSheet("QLabel { border: 2px solid gray; padding: 10px; }");

    // Add widgets to layout
    mainLayout->addWidget(buttonA);
    mainLayout->addWidget(buttonB);
    mainLayout->addWidget(imageLabel);

    // Connect signals to slots
    connect(buttonA, SIGNAL(clicked()), this, SLOT(onButtonAClicked()));
    connect(buttonB, SIGNAL(clicked()), this, SLOT(onButtonBClicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::onButtonAClicked()
{
    imageLabel->setText("Gambar A ditampilkan");
    imageLabel->setStyleSheet("QLabel { border: 2px solid blue; padding: 10px; background-color: lightblue; }");
}

void MainWindow::onButtonBClicked()
{
    imageLabel->setText("Gambar B ditampilkan");
    imageLabel->setStyleSheet("QLabel { border: 2px solid red; padding: 10px; background-color: lightcoral; }");
} 