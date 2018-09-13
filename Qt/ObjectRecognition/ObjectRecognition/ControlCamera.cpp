#include "ControlCamera.h"



ControlCamera::ControlCamera()
{

}


ControlCamera::~ControlCamera()
{
}

bool ControlCamera::openCamera(int number)
{
	if (capture.open(number)) {
		//capture.release();
		return true;
	}
	else
		return false;
}

bool ControlCamera::closeCamera(int number)
{	
	capture.release();
	if (!capture.isOpened())
		return true;
	else
	    return false;
}

cv::Mat ControlCamera::toFrame()
{
	Mat frame;
	if (capture.isOpened()) {
		capture.read(frame);
		return frame;
	}
	else
		return frame;
}

QImage ControlCamera::toImage()
{
	QImage image;
	Mat frame;
	if (capture.isOpened()) {
		capture.read(frame);
		image = Common::cvMat2QImage(frame);
	}
	return image;
}
