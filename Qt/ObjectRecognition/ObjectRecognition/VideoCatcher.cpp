#include "VideoCatcher.h"


VideoCatcher::VideoCatcher(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	connect(ui.openCamera, SIGNAL(clicked()), this, SLOT(openCameraClick()));
	connect(ui.startVideo, SIGNAL(clicked()), this, SLOT(startVideo()));
	connect(ui.stopVideo, SIGNAL(clicked()), this, SLOT(stopVideo()));
	connect(ui.closeCamera, SIGNAL(clicked()), this, SLOT(closeCameraClick()));
	connect(timer, SIGNAL(timeout()), this, SLOT(readFrame()));
	is_stop = true;
	close_flag = false;
	color = QPixmap(93, 93);
	color.fill(Qt::red);
	ui.startVideo->setIcon(color);
}


QImage  Mat2QImage(cv::Mat cvImg)
{
	QImage qImg;
	if (cvImg.channels() == 3)    //3 channels color image
	{

		cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}
	else if (cvImg.channels() == 1)                    //grayscale image
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_Indexed8);
	}
	else
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}
	return qImg;
}

void VideoCatcher::openCameraClick() {
	int i = ui.selectCamera->currentIndex();
	capture.open(i);    //0:打开默认摄像头，1：打开第二个摄像头
	capture.set(CV_CAP_PROP_FPS, 60);
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	timer->start(34);

}

void VideoCatcher::closeCameraClick()
{
	is_stop = true;
	capture.release();
	writer.release();
	cv::destroyWindow("双目录制"); // 删除窗口
	image.fill((0, 0, 0));
	ui.label->setPixmap(QPixmap::fromImage(image));
	close_flag = true;
	timer->stop();
}

void VideoCatcher::startVideo()
{
	is_stop = false;
	int w = static_cast<int>(capture.get(CV_CAP_PROP_FRAME_WIDTH));
	int h = static_cast<int>(capture.get(CV_CAP_PROP_FRAME_HEIGHT));
	size = cv::Size(w, h);
	out_file = "./detect.avi";
	writer.open(out_file, CV_FOURCC('M', 'J', 'P', 'G'), 30, size);
	color.fill(Qt::green);
	ui.startVideo->setIcon(color);
	while (!is_stop)
	{
		if (!capture.read(frame)) {
			QMessageBox::critical(NULL, "Error", QString::fromLocal8Bit("摄像头出现错误，停止工作！"),
				QMessageBox::Yes, QMessageBox::Yes);
			timer->stop();
			return;
		}
		writer.write(frame);
		toFrame(frame);
		imshow("双目录制", frame);
		cv::waitKey(10); // 为了保证给imshow函数处理显示的时间
	}
}

void VideoCatcher::stopVideo()
{
	is_stop = true;
	qDebug() << "stop";
	color.fill(Qt::red);
	ui.startVideo->setIcon(color);
}

void VideoCatcher::toFrame(cv::Mat f)
{
	image = Mat2QImage(f);
	ui.label->setPixmap(QPixmap::fromImage(image));
}

void VideoCatcher::readFrame()
{
	if (capture.isOpened())
	{
		if (!capture.read(frame)) {
			if (!close_flag) {
				QMessageBox::critical(NULL, "Error", QString::fromLocal8Bit("摄像头出现错误，停止工作！"),
					QMessageBox::Yes, QMessageBox::Yes);
				timer->stop();
				return;
			}
			timer->stop();
			return;
		}
		toFrame(frame);
	}
	else
	{
		QMessageBox::critical(NULL, "Error", QString::fromLocal8Bit("识别不出摄像头，请重新插拔USB，再试一遍！"),
			QMessageBox::Yes, QMessageBox::Yes);
		timer->stop();
		return;
	}
}

