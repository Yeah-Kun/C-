/*
	update by Ian in 2018-8-24 14:43:10
	目标检测模块
	算法：
		1. HSV颜色检测

*/

#include "ObjectCatcher.h"

ObjectCatcher::ObjectCatcher(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	connect(ui.maxHueSlider, SIGNAL(sliderReleased()), this, SLOT(getSliderParm()));
	connect(ui.minHueSlider, SIGNAL(sliderReleased()), this, SLOT(getSliderParm()));
	connect(ui.maxSatSlider, SIGNAL(sliderReleased()), this, SLOT(getSliderParm()));
	connect(ui.minSatSlider, SIGNAL(sliderReleased()), this, SLOT(getSliderParm()));
	connect(ui.maxValSlider, SIGNAL(sliderReleased()), this, SLOT(getSliderParm()));
	connect(ui.maxValSlider, SIGNAL(sliderReleased()), this, SLOT(getSliderParm()));
	connect(timer, SIGNAL(timeout()), this, SLOT(readFrame()));
	startRecognition(0);
}

ObjectCatcher::~ObjectCatcher()
{
}

void ObjectCatcher::toOrigFrame(Mat& frame)
{
	QImage image;
	image = Common::cvMat2QImage(frame);
	ui.OrigFrame->setPixmap(QPixmap::fromImage(image));
}

void ObjectCatcher::toRecogFrame(Mat& frame)
{
	QImage image;
	image = Common::cvMat2QImage(frame);
	ui.RecoFrame->setPixmap(QPixmap::fromImage(image));
}

void ObjectCatcher::startRecognition(int camera)
{
	
	capture.open(camera);
	if (capture.isOpened()) {
		timer->start(30);
	}
}

void ObjectCatcher::readFrame()
{
	Mat frame, mask, detectFrame, origFrame;
	ColorRecognition* colorer = new ColorRecognition();
	capture >> frame;
	colorer->detectHSV(frame, minHue, maxHue, minSat, maxSat, minVal, maxVal, mask);
	origFrame = colorer->showColor(frame, mask);
	detectFrame = colorer->showDetect(frame, origFrame, mask);
	toOrigFrame(origFrame);
	toRecogFrame(detectFrame);
}


void ObjectCatcher::getSliderParm()
{
	maxHue = ui.maxHueSlider->value();
	minHue = ui.minHueSlider->value();
	maxSat = ui.maxSatSlider->value();
	minSat = ui.minSatSlider->value();
	maxVal = ui.maxValSlider->value();
	minVal = ui.minValSlider->value();
}