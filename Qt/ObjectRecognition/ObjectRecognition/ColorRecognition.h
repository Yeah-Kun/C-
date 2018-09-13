#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <iostream>
/*
	create by Ian in 2018-7-3 16:54:53
	��ɫʶ������
	���ܣ�
	1. ����ͼ�񣬷���ʶ�������Ϣ
*/

using namespace cv;

class ColorRecognition
{
public:
	ColorRecognition();
	~ColorRecognition();
	void test();
	Mat detectHSV(const Mat& image, double minHue, double maxHue,
		double minSat, double maxSat, double minVal, double maxVal, Mat& mask); // ��ɫʶ����
	Point detectPoint(const Mat& image, Mat& mask, int vote); // �ؼ�������
	Mat showDetect(const Mat& image, const Mat& colorImage,Mat& mask); // չ��ʶ������
	Mat showColor(const Mat& image, Mat& mask);
	
// ���б���
public:
	//Point keyPoint;


// ˽�б���
private:
	Mat frame;
	VideoCapture capture;
};

