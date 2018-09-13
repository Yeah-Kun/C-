#pragma once
#include <opencv2/opencv.hpp>
#include <qimage.h>
#include "Common.h"

/*
create by Ian in 2018-7-9 16:13:38
摄像头控制类
功能：
1. 检测摄像头是否连接成功
2. 返回实时图像数据
*/


using namespace cv;

class ControlCamera
{
private:
	ControlCamera();
	~ControlCamera();

public:
	static bool openCamera(int number); // 打开相机
	static bool closeCamera(int number); // 关闭相机
	static cv::Mat toFrame(); // 传输图像，opencv版本
	static QImage toImage(); // 传输图像，Qt版本

private:
	static VideoCapture capture;

};

// 静态变量初始化
VideoCapture ControlCamera::capture = VideoCapture();
