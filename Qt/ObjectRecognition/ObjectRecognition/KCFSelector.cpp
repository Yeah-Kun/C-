#include "KCFSelector.h"
KCFSelector::KCFSelector(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	select_frame_flag = false;
	tracker = TrackerKCF::create();  // 检测器
	timer = new QTimer(this);
	stream_mode = 0;

	timer->start(15);
	if (capture.open(0)) {
		connect(timer, SIGNAL(timeout()), this, SLOT(showFrame()));
		connect(ui.select_btn, SIGNAL(clicked()), this, SLOT(selectROI()));
	}
	connect(ui.camera_radbtn, SIGNAL(clicked()), this, SLOT(changeStreamMode()));
	connect(ui.file_radbtn, SIGNAL(clicked()), this, SLOT(changeStreamMode()));
	connect(ui.load_video_btn, SIGNAL(clicked()), this, SLOT(loadVideo()));
}


KCFSelector::~KCFSelector()
{
}


Rect2d KCFSelector::selectROI()
{
	timer->stop();
	Mat temp;
	temp = frame;
	ROI_rect = cv::selectROI(temp);
	qDebug() << "ROI_rect: " << ROI_rect.height << ROI_rect.width;
	timer->start(10);
	select_frame_flag = true;
	tracker->init(frame, ROI_rect);
	destroyWindow("ROI selector");
	return ROI_rect;
}


void KCFSelector::showFrame()
{
	QImage image;
	capture >> frame;
	if (select_frame_flag) {
		tracker->update(frame, ROI_rect);
		rectangle(frame, ROI_rect, Scalar(255, 0, 0), 2, 1);
	}
	image = Common::cvMat2QImage(frame);
	ui.show_label->setPixmap(QPixmap::fromImage(image));
}

void KCFSelector::processFrame()
{
	VideoProcessor processor;
	if (inputVideoName.length() != 0) {
		processor.setInput(inputVideoName);
		processor.displayInput(inputVideoName);
	}
	if (outputVideoName.length() != 0)
		processor.setOutput(outputVideoName);
	processor.setDelay(1000. / processor.getFrameRate());
}

std::string KCFSelector::loadVideoName()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("选择源视频"),
		"./",
		"MP4 (*.mp4);;"
		"MKV (*.mkv);;"
		"Images (*.png *.xpm *.jpg);;"
		);
	inputVideoName = filename.toStdString();
	return inputVideoName;
}

std::string KCFSelector::outputVideoNmae()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("选择源视频"),
		"./",
		"MP4 (*.mp4);;"
		"MKV (*.mkv);;"
		"Images (*.png *.xpm *.jpg);;"
	);
	qDebug() << "输出视频：" << filename;
	outputVideoName = filename.toStdString();
	return outputVideoName;
}

bool KCFSelector::changeStreamMode()
{
	if (ui.file_radbtn->isChecked()) {
		stream_mode = 1;
		timer->stop();
		qDebug() << "filestream";
		disconnect(timer, SIGNAL(timeout()), this, SLOT(showFrame()));
		return true;
	}
	else if (ui.camera_radbtn->isChecked()) {
		stream_mode = 0;
		timer->start(10);
		qDebug() << "camerastream";
		connect(timer, SIGNAL(timeout()), this, SLOT(showFrame()));
		return true;
	}
	else
		return false;
}



//namedWindow("input", WINDOW_AUTOSIZE);
//namedWindow("output", WINDOW_AUTOSIZE);
//capture.read(frame);
//if (frame.empty())
//	return -1;
//Rect2d first = selectROI("output", frame);
//Rect selectionROI;
//selectionROI.width = first.width;
//selectionROI.height = first.height;
//selectionROI.x = first.x;
//selectionROI.y = first.y;
//printf("x= %d, y=%d, width=%d, height=%d", selectionROI.x, selectionROI.y, selectionROI.width, selectionROI.height);

//Mat mask, hist, backproject;
//int bins = 120;
//Mat drawImg = Mat::zeros(300, 300, CV_8UC3);

//while (capture.read(frame))
//{
//	Mat hsvimage;
//	cvtColor(frame, hsvimage, CV_BGR2HSV);
//	inRange(hsvimage, Scalar(25, 43, 46), Scalar(35, 256, 256), mask);
//	Mat hue = Mat(hsvimage.size(), hsvimage.depth());
//	int channels[] = { 0, 0 };
//	mixChannels(&hsvimage, 1, &hue, 1, channels, 1);

//	//ROI直方图计算
//	Mat roi(hue, first);
//	Mat maskroi(mask, first);
//	float hrange[] = { 0, 180 };
//	const float* hranges = hrange;
//	//直方图
//	calcHist(&roi, 1, 0, maskroi, hist, 1, &bins, &hranges);
//	normalize(hist, hist, 0, 255, NORM_MINMAX);

//	int binw = drawImg.cols / bins;
//	Mat colorIndex = Mat(1, bins, CV_8UC3);
//	for (int i = 0; i < bins; i++)
//	{
//		colorIndex.at<Vec3b>(0, i) = Vec3b(saturate_cast<uchar>(i * 180 / bins), 255, 255);
//	}
//	cvtColor(colorIndex, colorIndex, COLOR_HSV2BGR);
//	for (int i = 0; i < bins; i++)
//	{
//		int val = saturate_cast<int>(hist.at<float>(i)*drawImg.rows / 255);
//		rectangle(drawImg, Point(i*binw, drawImg.rows), Point((i + 1)*binw, drawImg.rows * val), Scalar(colorIndex.at<Vec3b>(0, i)), -1, 8, 0);
//	}

//	//计算直方图的反投影
//	calcBackProject(&hue, 1, 0, hist, backproject, &hranges);
//	backproject &= mask;
//	RotatedRect trackBox = CamShift(backproject, selectionROI, TermCriteria((TermCriteria::COUNT | TermCriteria::EPS), 10, 1));
//	Rect rect;
//	rect.x = trackBox.center.x - trackBox.size.width / 2.0;
//	rect.y = trackBox.center.y - trackBox.size.height / 2.0;
//	rect.width = trackBox.size.width;
//	rect.height = trackBox.size.height;

//	rectangle(frame, rect, Scalar(255, 255, 0), 3);

//	pt.push_back(Point(rect.x + rect.width / 2, rect.y + rect.height / 2));
//	for (int i = 0; i < pt.size() - 1; i++)
//	{
//		line(frame, pt[i], pt[i + 1], Scalar(0, 255, 0), 2.5);
//	}
//	imshow("input", frame);
//	imshow("output", drawImg);
//	waitKey(10);
//}

//capture.release();
//return 0;