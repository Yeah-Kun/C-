

#include "ColorRecognition.h"

const int max_value = 255;
int minHue = 0;
int maxHue = 5;
int minSat = 88;
int maxSat = 242;
int minVal = 177;
int maxVal = 255;


ColorRecognition::ColorRecognition()
{
}


ColorRecognition::~ColorRecognition()
{
}

void ColorRecognition::test()
{
	if (capture.open(0)) {
		Mat mask; // ��Ĥ
		namedWindow("ColorRecognition", CV_WINDOW_AUTOSIZE);
		while (1) {
			capture >> frame;
			Mat detected(frame.size(), CV_8UC3, Scalar(0, 0, 0)); // �������˵�ͼ�����ֵ����while����������
	
			createTrackbar("��Сɫ����", "ColorRecognition", &minHue, max_value);
			createTrackbar("���ɫ����", "ColorRecognition", &maxHue, max_value);
			createTrackbar("��С���Ͷȣ�", "ColorRecognition", &minSat, max_value);
			createTrackbar("��󱥺Ͷȣ�", "ColorRecognition", &maxSat, max_value);
			createTrackbar("��С���ȣ�", "ColorRecognition", &minVal, max_value);
			createTrackbar("������ȣ�", "ColorRecognition", &maxVal, max_value);

			detectHSV(frame, minHue, maxHue, minSat, maxSat, minVal, maxVal,  mask);
			//detectHSV(frame, 160, 10, 25, 166, mask);	 //Ƥ����ɫ�����
			frame.copyTo(detected, mask);
			Mat outFrame;
			Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3)); // �Զ����
			dilate(detected, outFrame, element); // ���Ͳ���

			std::vector<Vec3f> circles;//����ʸ��
			Mat edges;
			cvtColor(detected, edges, CV_BGR2GRAY);
			// ��˹�˲�
			GaussianBlur(edges, edges, Size(7, 7), 2, 2);
			HoughCircles(edges, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 30, 5, 0); // ����Բ�任
			for (auto i = 0; i < circles.size(); i++) {
				Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
				int radius = cvRound(circles[i][2]);
				circle(frame, center, 3, Scalar(0, 255, 0), -1, 8, 0); // ��Բ��
				circle(frame, center, radius, Scalar(155, 50, 255), 3, 8, 0);// ��Բ
			}
			imshow("ColorRecognition", frame);
			imshow("�����任", edges);
			imshow("δ�����任", outFrame);
			//imshow("ColorRecognition", outFrame);
			if (waitKey(30) == 27) break; // ����Esc������
		}
	}
	else{
		std::cerr << "����ͷ��ʧ��";
	}
}

Mat ColorRecognition::detectHSV(const Mat & image, double minHue, double maxHue, double minSat, double maxSat, double minVal, double maxVal, Mat & mask)
// ��ɫ�����
/*
	���룺
		minHue����Сɫ��
		maxHue�����ɫ��
		minSat����С���Ͷ�
		maxSat����󱥺Ͷ�
		minVal����С����
		maxValt���������

	�����
		mask����Ĥ
*/
{
	Mat HSVframe;
	cvtColor(image, HSVframe, CV_BGR2HSV);
	std::vector<Mat> channels;
	split(HSVframe, channels); // ��ͼ��ָ���3��ͨ����ɫ�������Ͷȣ�����

	Mat mask1;
	threshold(channels[0], mask1, maxHue, 255, cv::THRESH_BINARY_INV);// ������ֵ��Ϊ0��������ѡ����ɫ�������Ϊ0

	
	Mat mask2;
	threshold(channels[0], mask2, minHue, 255, cv::THRESH_BINARY); // С����ֵ��Ϊ0��������һ��

	// ɫ����Ĥ
	Mat hueMask;
	if (minHue < maxHue)
		hueMask = mask1 & mask2;
	else // ������䴩Խ��0��������
		hueMask = mask1 | mask2;

	// ���Ͷ���Ĥ
	Mat satMask;
	inRange(channels[1], minSat, maxSat, satMask); // ��ɫ�ָֱ��ĳ�ֱ��Ͷȵ���ʾ����

	// ������Ĥ
	Mat valMask;
	inRange(channels[2], minVal, maxVal, valMask); // ��ɫ�ָֱ��ĳ�ֱ��Ͷȵ���ʾ����

	// �����Ĥ
	mask = hueMask & satMask & valMask;
	return mask;
}

Point ColorRecognition::detectPoint(const Mat & image, Mat & mask, int vote=30)
{
	Mat detected(image.size(), CV_8UC3, Scalar(0, 0, 0)); // �������˵�ͼ��
	image.copyTo(detected, mask); // ����Ĥ���ͼ��detected
	Mat outFrame;
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3)); // �Զ����
	dilate(detected, outFrame, element); // ���Ͳ���

	std::vector<Vec3f> circles;//����ʸ��
	Mat edges;
	cvtColor(outFrame, edges, CV_BGR2GRAY);
	// ��˹�˲�
	GaussianBlur(edges, edges, Size(7, 7), 2, 2);
	HoughCircles(edges, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, vote, 5, 0); // ����Բ�任

	Point center(cvRound(circles[0][0]), cvRound(circles[0][1])); // ��ùؼ���

	return center;
}

Mat ColorRecognition::showDetect(const Mat & frame, const Mat& edges, Mat & mask)
{
	Mat detectFrame = frame;
	std::vector<Vec3f> circles;//����ʸ��
	HoughCircles(edges, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 30, 5, 0); // ����Բ�任
	for (auto i = 0; i < circles.size(); i++) {
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(detectFrame, center, 3, Scalar(0, 255, 0), -1, 8, 0); // ��Բ��
		circle(detectFrame, center, radius, Scalar(155, 50, 255), 3, 8, 0);// ��Բ
		if (i > 3) break;
	}
	return detectFrame;
}

Mat ColorRecognition::showColor(const Mat & frame, Mat& mask)
{
	Mat origFrame;
	Mat detectFrame = frame;
	frame.copyTo(origFrame, mask);
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3)); // �Զ����
	dilate(origFrame, origFrame, element); // ���Ͳ���

	std::vector<Vec3f> circles;//����ʸ��
	Mat edges;
	cvtColor(origFrame, edges, CV_BGR2GRAY);
	// ��˹�˲�
	GaussianBlur(edges, edges, Size(7, 7), 2, 2);

	return edges;
}




