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
	QPixmap color;  // ��ɫ��־��
	double rate; //FPS
	cv::VideoWriter writer;
	std::string out_file; // ���avi�ļ�
	bool is_stop; // �Ƿ�¼��
	bool close_flag; // �Ƿ��Ѿ�����ر�����ͷ
	QTimer    *timer;

};
QImage  Mat2QImage(cv::Mat*);
