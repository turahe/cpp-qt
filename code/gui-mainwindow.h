#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonAClicked();
    void onButtonBClicked();

private:
    QPushButton *buttonA;
    QPushButton *buttonB;
    QLabel *imageLabel;
};

#endif // MAINWINDOW_H 