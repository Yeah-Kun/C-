

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
		Mat mask; // 掩膜
		namedWindow("ColorRecognition", CV_WINDOW_AUTOSIZE);
		while (1) {
			capture >> frame;
			Mat detected(frame.size(), CV_8UC3, Scalar(0, 0, 0)); // 经过过滤的图像，这个值放在while外面有问题
	
			createTrackbar("最小色调：", "ColorRecognition", &minHue, max_value);
			createTrackbar("最大色调：", "ColorRecognition", &maxHue, max_value);
			createTrackbar("最小饱和度：", "ColorRecognition", &minSat, max_value);
			createTrackbar("最大饱和度：", "ColorRecognition", &maxSat, max_value);
			createTrackbar("最小亮度：", "ColorRecognition", &minVal, max_value);
			createTrackbar("最大亮度：", "ColorRecognition", &maxVal, max_value);

			detectHSV(frame, minHue, maxHue, minSat, maxSat, minVal, maxVal,  mask);
			//detectHSV(frame, 160, 10, 25, 166, mask);	 //皮肤颜色检测器
			frame.copyTo(detected, mask);
			Mat outFrame;
			Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3)); // 自定义核
			dilate(detected, outFrame, element); // 膨胀操作

			std::vector<Vec3f> circles;//保存矢量
			Mat edges;
			cvtColor(detected, edges, CV_BGR2GRAY);
			// 高斯滤波
			GaussianBlur(edges, edges, Size(7, 7), 2, 2);
			HoughCircles(edges, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 30, 5, 0); // 霍夫圆变换
			for (auto i = 0; i < circles.size(); i++) {
				Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
				int radius = cvRound(circles[i][2]);
				circle(frame, center, 3, Scalar(0, 255, 0), -1, 8, 0); // 画圆心
				circle(frame, center, radius, Scalar(155, 50, 255), 3, 8, 0);// 画圆
			}
			imshow("ColorRecognition", frame);
			imshow("经过变换", edges);
			imshow("未经过变换", outFrame);
			//imshow("ColorRecognition", outFrame);
			if (waitKey(30) == 27) break; // 遇到Esc键返回
		}
	}
	else{
		std::cerr << "摄像头打开失败";
	}
}

Mat ColorRecognition::detectHSV(const Mat & image, double minHue, double maxHue, double minSat, double maxSat, double minVal, double maxVal, Mat & mask)
// 颜色检测器
/*
	输入：
		minHue：最小色调
		maxHue：最大色调
		minSat：最小饱和度
		maxSat：最大饱和度
		minVal：最小亮度
		maxValt：最大亮度

	输出：
		mask：掩膜
*/
{
	Mat HSVframe;
	cvtColor(image, HSVframe, CV_BGR2HSV);
	std::vector<Mat> channels;
	split(HSVframe, channels); // 将图像分隔到3个通道：色调，饱和度，亮度

	Mat mask1;
	threshold(channels[0], mask1, maxHue, 255, cv::THRESH_BINARY_INV);// 大于阈值就为0，将不是选定颜色的区间变为0

	
	Mat mask2;
	threshold(channels[0], mask2, minHue, 255, cv::THRESH_BINARY); // 小于阈值就为0，跟上面一样

	// 色调掩膜
	Mat hueMask;
	if (minHue < maxHue)
		hueMask = mask1 & mask2;
	else // 如果区间穿越了0度中轴线
		hueMask = mask1 | mask2;

	// 饱和度掩膜
	Mat satMask;
	inRange(channels[1], minSat, maxSat, satMask); // 彩色分割，直将某种饱和度的显示出来

	// 亮度掩膜
	Mat valMask;
	inRange(channels[2], minVal, maxVal, valMask); // 彩色分割，直将某种饱和度的显示出来

	// 组合掩膜
	mask = hueMask & satMask & valMask;
	return mask;
}

Point ColorRecognition::detectPoint(const Mat & image, Mat & mask, int vote=30)
{
	Mat detected(image.size(), CV_8UC3, Scalar(0, 0, 0)); // 经过过滤的图像
	image.copyTo(detected, mask); // 加掩膜后的图像detected
	Mat outFrame;
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3)); // 自定义核
	dilate(detected, outFrame, element); // 膨胀操作

	std::vector<Vec3f> circles;//保存矢量
	Mat edges;
	cvtColor(outFrame, edges, CV_BGR2GRAY);
	// 高斯滤波
	GaussianBlur(edges, edges, Size(7, 7), 2, 2);
	HoughCircles(edges, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, vote, 5, 0); // 霍夫圆变换

	Point center(cvRound(circles[0][0]), cvRound(circles[0][1])); // 获得关键点

	return center;
}

Mat ColorRecognition::showDetect(const Mat & frame, const Mat& edges, Mat & mask)
{
	Mat detectFrame = frame;
	std::vector<Vec3f> circles;//保存矢量
	HoughCircles(edges, circles, CV_HOUGH_GRADIENT, 1.5, 10, 200, 30, 5, 0); // 霍夫圆变换
	for (auto i = 0; i < circles.size(); i++) {
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		circle(detectFrame, center, 3, Scalar(0, 255, 0), -1, 8, 0); // 画圆心
		circle(detectFrame, center, radius, Scalar(155, 50, 255), 3, 8, 0);// 画圆
		if (i > 3) break;
	}
	return detectFrame;
}

Mat ColorRecognition::showColor(const Mat & frame, Mat& mask)
{
	Mat origFrame;
	Mat detectFrame = frame;
	frame.copyTo(origFrame, mask);
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3)); // 自定义核
	dilate(origFrame, origFrame, element); // 膨胀操作

	std::vector<Vec3f> circles;//保存矢量
	Mat edges;
	cvtColor(origFrame, edges, CV_BGR2GRAY);
	// 高斯滤波
	GaussianBlur(edges, edges, Size(7, 7), 2, 2);

	return edges;
}




