#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <Windows.h>
#include <windef.h>
#include <setupapi.h>
#include <QCoreApplication>
#include <QMainWindow>
#include <QScreen>
#include <QPixmap>
#include <QTimer>
#include <qDebug>
#include <QWindow>
#include <QList>
#include <QCameraInfo>
#include <QCamera>
#include <QCameraImageCapture>
#include <QPainter>
#include <QDateTime>
#include "showlabel.h"


namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();
    void textSender(const QString& text);


signals:
    void textSend(const QString& text);



private slots:
    void showScreen(int, QImage);
    void selectCamrea(QAction*); // 选择摄像头
    void getFrame(); // 获得帧
    void openInsurance();
    void openLock();
    void openLaunch();
    void openScram();
    void textReceiver(const QString& text);


private:
    Ui::MainPage *ui;
    QTimer* timer;
    QScreen *screen;
    QCamera *camera;//摄像头
    QCameraImageCapture * imageCapture;//截图部件
    QList<QCameraInfo> cameras;
    bool insuranceStatus;
    bool lockStatus;
    bool launchStatus;
    bool scramStatus;

};

#endif // MAINPAGE_H
