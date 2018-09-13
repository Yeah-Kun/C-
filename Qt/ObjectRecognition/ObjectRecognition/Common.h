#pragma once
#include <qimage.h>
#include <qdebug.h>
#include "opencv2\core\core.hpp"
#include "cv.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

/*
* ���ڴ��һЩͨ�õĹ��߷���
* ������Դ����,���õĸ�������ת����
* ע�����Ķ��ⷽ��Ҫ������Ǿ�̬��
* ԭ���ϱ�����Ӧ�þ���û�����Ժ��ֶ�
*/


class Common
{
private:
	Common();
	~Common();

public:
	static QImage cvMat2QImage(const cv::Mat& mat);
	static cv::Mat QImage2cvMat(QImage image);

};

