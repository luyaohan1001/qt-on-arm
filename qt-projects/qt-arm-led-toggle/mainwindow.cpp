/******************************************************************
* @project		qt-arm-led-toggle
* @brief        mainwindow.cpp
* @author       Luyao Han
* @email        luyaohan1001@gmail.com
* @date         2022-04-05
*******************************************************************/

#include "mainwindow.h"
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>
#include <QRect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Get the resolution of the screen, so the application can work with different sizes of screens.
    QList <QScreen *> list_screen =  QGuiApplication::screens();

    // Change the size of the screen if it is on arm platform.
#if __arm__
    this->resize(list_screen.at(0)->geometry().width(),
                 list_screen.at(0)->geometry().height());
    // sys/class/leds/usr-led/trigger stores how led is triggered, by default it is heart-beat, change to none so we can control it.
    system("echo none > /sys/class/leds/usr-led/trigger");
#else
    // by default set mainwindow size 800 x 480
    this->resize(800, 480);
#endif

    pushButton = new QPushButton(this);

    // Display the button in the middle
    pushButton->setMinimumSize(200, 50);
    pushButton->setGeometry((this->width() - pushButton->width()) /2 ,
                            (this->height() - pushButton->height()) /2,
                            pushButton->width(),
                            pushButton->height()
                            );
    // LED brightness control is a file in sysfs
    file.setFileName("/sys/devices/platform/leds/leds/usr-led/brightness");

    if (!file.exists())
        // set default text on the button
        pushButton->setText("未获取到LED设备！");

    // get LED initial state
    getLedState();

    // connect pushButton event to callback function: pushButtonClicked().
    connect(pushButton, SIGNAL(clicked()),
            this, SLOT(pushButtonClicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::setLedState()
{
    // read LED state first before writing.
    bool state = getLedState();

    // return false if /sys/devices/platform/leds/leds/usr-led/brightness does not exist.
    if (!file.exists())
        return;

    if(!file.open(QIODevice::ReadWrite))
        qDebug()<<file.errorString();

    QByteArray buf[2] = {"0", "1"};

    // change brighetness by writing "0" or "1" to file.
    if (state)
        file.write(buf[0]);
    else
        file.write(buf[1]);

    // close file
    file.close();

    getLedState();
}

bool MainWindow::getLedState()
{
    // return false if /sys/devices/platform/leds/leds/usr-led/brightness does not exist.
    if (!file.exists())
        return false;

    if(!file.open(QIODevice::ReadWrite))
        qDebug()<<file.errorString();

    QTextStream in(&file);

    // read current brightness from sysfs file.
    QString currBrightness = in.readLine();

    // print to terminal console while the program is running.
    qDebug()<< "Current brightness in /sys/devices/platform/leds/leds/usr-led/brightness is: " << currBrightness <<endl;
    file.close();
    if (currBrightness == "1") {
        pushButton->setText("LED ON");
        return true;
    } else {
        pushButton->setText("LED OFF");
        return false;
    }
}

void MainWindow::pushButtonClicked()
{
    setLedState();
}


