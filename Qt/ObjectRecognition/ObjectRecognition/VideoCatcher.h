#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_VideoCatcher.h"
#include <opencv2/opencv.hpp>
#include <Windows.h>
#include <QTimer>
#include <qpainter.h>
#include <iostream>
#include <qdebug.h>
#include <qmessagebox.h>
#include <qpixmap.h>
#include <qtimer.h>
class VideoCatcher : public QMainWindow
{
	Q_OBJECT

public:
	VideoCatcher(QWidget *parent = Q_NULLPTR);

private slots:
	void openCameraClick();
	void closeCameraClick();
	void startVideo();
	void stopVideo();
	void toFrame(cv::Mat frame);
	void readFrame();


private:
	Ui::VideoCatcher ui;
	cv::Mat frame;
	cv::Size size;
	cv::VideoCapture capture;
	QImage  image;
	QPainter p;
	QPixmap color;  // 颜色标志灯
	double rate; //FPS
	cv::VideoWriter writer;
	std::string out_file; // 输出avi文件
	bool is_stop; // 是否录制
	bool close_flag; // 是否已经点击关闭摄像头
	QTimer    *timer;

};
QImage  Mat2QImage(cv::Mat*);
