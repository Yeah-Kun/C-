#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <iostream>
/*
	create by Ian in 2018-7-3 16:54:53
	颜色识别器类
	功能：
	1. 输入图像，返回识别出的信息
*/

using namespace cv;

class ColorRecognition
{
public:
	ColorRecognition();
	~ColorRecognition();
	void test();
	Mat detectHSV(const Mat& image, double minHue, double maxHue,
		double minSat, double maxSat, double minVal, double maxVal, Mat& mask); // 颜色识别器
	Point detectPoint(const Mat& image, Mat& mask, int vote); // 关键点检测器
	Mat showDetect(const Mat& image, const Mat& colorImage,Mat& mask); // 展现识别内容
	Mat showColor(const Mat& image, Mat& mask);
	
// 公有变量
public:
	//Point keyPoint;


// 私有变量
private:
	Mat frame;
	VideoCapture capture;
};

