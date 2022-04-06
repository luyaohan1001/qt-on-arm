/******************************************************************
* @project		qt-arm-led-toggle
* @brief        mainwindow.h
* @author       Luyao Han
* @email        luyaohan1001@gmail.com
* @date         2022-04-05
*******************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFile>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // point to a bush button
    QPushButton *pushButton;

    // file, used to point to sysfs file
    QFile file;

    // LED setter
    void setLedState();

    // LED getter
    bool getLedState();

private slots:
    void pushButtonClicked();
};
#endif // MAINWINDOW_H
