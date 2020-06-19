#include "videocatcher.h"
#include "ui_videocatcher.h"

VideoCatcher::VideoCatcher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VideoCatcher)
{
    ui->setupUi(this);
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras) {
        qDebug() << cameraInfo.description();
    }
}

VideoCatcher::~VideoCatcher()
{
    delete ui;
}
