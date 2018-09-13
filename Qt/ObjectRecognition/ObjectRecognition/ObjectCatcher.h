#pragma once
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <qdebug.h>
#include <qtimer.h>
#include "ui_ObjectCatcher.h"
#include "ColorRecognition.h"
#ifndef _VIDEOCATCHER_H_
#define _VIDEOCATCHER_H_
#endif // !_VIDEOCATCHER_H_
#ifndef _COMMON_H_
#define _COMMON_H_
#include "Common.h"
#endif // !_COMMON_H_



class ObjectCatcher : public QWidget
{
	Q_OBJECT


public:
	ObjectCatcher(QWidget *parent = Q_NULLPTR);
	~ObjectCatcher();
	void toOrigFrame(Mat& frame);
	void toRecogFrame(Mat& frame);
	void startRecognition(int camera);

public:
	

private slots:
	void getSliderParm(); // 获得滑动条值
	void readFrame();


private:
	Ui::ObjectCatcher ui;
	int minHue;
	int maxHue;
	int minSat;
	int maxSat;
	int minVal;
	int maxVal;
	QTimer* timer;
	VideoCapture capture;
};
