#include "VideoProcessor.h"



VideoProcessor::VideoProcessor()
{
}


VideoProcessor::~VideoProcessor()
{
}

void VideoProcessor::setFrameProcessor(void(*frameProcessingCallback)(cv::Mat &, cv::Mat &))
{
	process = frameProcessingCallback;
}

void VideoProcessor::setFrameProcessor(VideoProcessor(*frameProcessingCallback)(cv::Mat &, cv::Mat &))
{
	processAlgorithm = frameProcessingCallback;
}

bool VideoProcessor::setInput(std::string filename)
{
	fnumber = 0;
	capture.release();
	return capture.open(filename);
}

bool VideoProcessor::setInput(const std::vector<std::string>& imgs)
{
	fnumber = 0;
	capture.release();
	images = imgs;
	itImg = images.begin();
	return true;
}

bool VideoProcessor::setRect2d(cv::Rect2d select_roi)
{
	if (select_roi.width == 0 || select_roi.height == 0)
		return false;
	else {
		isInit = false; // 初始化识别器的init标志，等待init完就设为true
		ROI = select_roi;
		return true;
	}
	
}

void VideoProcessor::displayInput(std::string wn)
{
	windowNameInput = wn;
	cv::namedWindow(windowNameInput);
}

void VideoProcessor::displayOutput(std::string wn)
{
	windowNameOutput = wn;
	cv::namedWindow(windowNameOutput);
}

void VideoProcessor::stopIt()
{
	stop = true;
}

bool VideoProcessor::isStopped()
{
	return stop;
}

bool VideoProcessor::isOpened()
{
	return capture.isOpened() || images.empty();
}

void VideoProcessor::setDelay(int d)
{
	delay = d;
}

bool VideoProcessor::readNextFrame(cv::Mat & frame)
{
	if(images.size() == 0)
		return capture.read(frame);
	else {
		if (itImg != images.end()) {
			frame = cv::imread(*itImg);
			itImg++;
			return frame.data != 0;
		}
		else {
			return false;
		}
	}
}

void VideoProcessor::callProcess()
{
	callIt = true;
}

void VideoProcessor::dontCallProcess()
{
	callIt = false;
}

void VideoProcessor::stopAtFrameNo(long frame)
{
	frameToStop = frame;
}

long VideoProcessor::getFrameNumber()
{
	long fnumber = static_cast<long>(capture.get(CV_CAP_PROP_POS_FRAMES));
	return fnumber;
}

long VideoProcessor::getTotalFrameCount()
{
	if (images.size() != 0) return images.size();

	long t = capture.get(cv::CAP_PROP_FRAME_COUNT);
	return t;
}

cv::Size VideoProcessor::getFrameSize()
{
	if (images.size() == 0) {
		int w = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_WIDTH));
		int h = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_HEIGHT));
		return cv::Size(w,h);
	}
	else {
		cv::Mat tmp = cv::imread(images[0]);
		if (!tmp.data)
			return cv::Size(0, 0);  // 没有获得图片大小，返回0
		else
			return tmp.size();
	}
}

void VideoProcessor::run()
{
	cv::Mat frame;
	cv::Mat output;

	if (!isOpened())
		return;
	stop = false;
	while (!isStopped()) {
		if (!readNextFrame(frame))  // 有下一帧就读取，没有就退出
			break;
		if (windowNameInput.length() != 0)
			cv::imshow(windowNameInput, frame); // 显示输入帧
		if (callIt) {
			if (process)
				process(frame, output);
			else if (frameProcessor)
				frameProcessor->process(frame, output);
			fnumber++;
		}
		else {
			output = frame;
		}
		if (windowNameOutput.length() != 0) {
			cv::imshow(windowNameOutput, output);
			if (delay >= 0 && cv::waitKey(delay) >= 0) // 产生延时
				stopIt();
			if (frameToStop >= 0 && getFrameNumber() == frameToStop)
				stopIt();
		}
		
		// 写入到输出的序列
		if (outputFile.length() != 0)
			writeNextFrame(output);
		if (windowNameOutput.length() != 0)
			cv::imshow(windowNameOutput, output);
		if (delay >= 0 && cv::waitKey(delay) >= 0)
			stopIt();
		if (frameToStop >= 0 && getFrameNumber() == frameToStop)
			stopIt();
	}
}

void VideoProcessor::setFrameProcessor(FrameProcessor * frameProcessorPtr)
{
	process = 0;
	frameProcessor = frameProcessorPtr;
	callProcess();
}

double VideoProcessor::getFrameRate()
{
	if (images.size() != 0) return 0;

	double r = capture.get(cv::CAP_PROP_FPS);
	return r;
}

bool VideoProcessor::setOutput(const std::string & filename, int codec, double framerate, bool isColor)
{
	outputFile = filename;
	extension.clear();
	if (framerate = 0.0)
		framerate = getFrameRate();
	char c[4];
	if (codec == 0) {
		codec = getCodec(c);
	}

	return writer.open(outputFile,
					   codec,
					   framerate,
					   getFrameSize(),
					   isColor);
}

bool VideoProcessor::setOutput(const std::string & filename, const std::string & ext, int numberOfDigits, int startIndex)
{
	if (numberOfDigits <0)
		return false;
	outputFile = filename;
	extension = ext;
	digits = numberOfDigits;
	currentIndex = startIndex;
	return true;
}

void VideoProcessor::writeNextFrame(cv::Mat & frame)
{
	if (extension.length()) {
		std::stringstream ss; // 文件名
		ss << outputFile << std::setfill('0')
			<< std::setw(digits)
			<< currentIndex++ << extension;
		cv::imwrite(ss.str(), frame);
	}
	else {
		writer.write(frame);
	}
}

int VideoProcessor::getCodec(char codec[4])
{
	if (images.size() != 0)
		return -1;
	union
	{
		int value;
		char code[4];
	}returned;
	returned.value = static_cast<int>(capture.get(cv::CAP_PROP_FOURCC)); // 获得视频文件代码
	// 获得四个字符
	codec[0] = returned.code[0];
	codec[1] = returned.code[1];
	codec[2] = returned.code[2];
	codec[3] = returned.code[3];
	return returned.value;
}

void canny(cv::Mat& img, cv::Mat& out)
{
	// 先要把每帧图像转化为灰度图
	cv::cvtColor(img, out, CV_BGR2GRAY);
	// 调用Canny函数
	cv::Canny(out, out, 100, 200);
	// 对像素进行翻转
	cv::threshold(out, out, 128, 255, cv::THRESH_BINARY_INV);
}

void VideoProcessor::KCF(cv::Mat & img, cv::Mat & out)
{
	if (ROI.height == 0 || ROI.width == 0)
		//return false;
		return;
	else
		if (tracker == NULL)
			tracker = cv::TrackerKCF::create();  // 创建检测器
	if(!isInit)
		tracker->init(img, ROI);
	else {
		img.copyTo(out);
		tracker->update(out, ROI);
		rectangle(out, ROI, cv::Scalar(255, 0, 0), 2, 1);
	}
	//return true;
}

