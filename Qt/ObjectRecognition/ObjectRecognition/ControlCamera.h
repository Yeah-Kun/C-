#pragma once
#include <opencv2/opencv.hpp>
#include <qimage.h>
#include "Common.h"

/*
create by Ian in 2018-7-9 16:13:38
����ͷ������
���ܣ�
1. �������ͷ�Ƿ����ӳɹ�
2. ����ʵʱͼ������
*/


using namespace cv;

class ControlCamera
{
private:
	ControlCamera();
	~ControlCamera();

public:
	static bool openCamera(int number); // �����
	static bool closeCamera(int number); // �ر����
	static cv::Mat toFrame(); // ����ͼ��opencv�汾
	static QImage toImage(); // ����ͼ��Qt�汾

private:
	static VideoCapture capture;

};

// ��̬������ʼ��
VideoCapture ControlCamera::capture = VideoCapture();
