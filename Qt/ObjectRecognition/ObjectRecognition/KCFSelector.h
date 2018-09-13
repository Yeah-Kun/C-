/*
	create by Ian in 2018-8-24 17:20:59
	KCF识别器
*/

#pragma once

#include <QWidget>
#include <QTimer>
#include <qfiledialog.h>
#include <opencv2/tracking.hpp>
#include <iostream>
#include <cstring>
#include "Common.h"
#include "VideoProcessor.h"
#include "ui_KCFSelector.h"

using namespace std;
using namespace cv;

class KCFSelector : public QWidget
{
	Q_OBJECT

public:
	KCFSelector(QWidget *parent = Q_NULLPTR);
	~KCFSelector();

private slots:
	Rect2d selectROI();
	void showFrame();
	void processFrame();
	std::string loadVideoName();
	std::string outputVideoNmae();
	bool changeStreamMode();
	


private:
	Ui::KCFSelector ui;
	Mat frame;
	Rect2d ROI_rect;
	QTimer* timer;
	VideoCapture capture;
	bool select_frame_flag;
	Ptr<TrackerKCF> tracker;
	int stream_mode; // 视频流，默认为摄像头：0
	std::string inputVideoName;
	std::string outputVideoName;
};
