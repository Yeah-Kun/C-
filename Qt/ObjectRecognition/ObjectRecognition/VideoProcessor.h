#pragma once
#include <opencv2/core.hpp>
#include <opencv2/tracking.hpp>
#include <opencv.hpp>
#include <sstream>
#include <string>
#include <vector>

class FrameProcessor {
public:
	virtual void process(cv::Mat &input, cv::Mat& output) = 0;
};

class VideoProcessor
{
public:
	VideoProcessor();
	~VideoProcessor();

private:
	cv::VideoCapture capture;
	void(*process) (cv::Mat&, cv::Mat&); // 回调函数
	VideoProcessor(*processAlgorithm) (cv::Mat&, cv::Mat&); // 回调函数
	bool callIt; // 处理标志符，表示回调函数是否会被调用
	std::string windowNameInput;
	std::string windowNameOutput;
	int delay; // 帧延时
	long fnumber; // 已经处理的帧数
	long frameToStop; // 处理完此帧的前一帧结束
	bool stop; // 结束处理
	std::vector<std::string> images;
	std::vector<std::string>::const_iterator itImg;
	FrameProcessor *frameProcessor;
	// 写入视频对象
	cv::VideoWriter writer;
	std::string outputFile; // 输出文件名
	int currentIndex;
	int digits; // 
	std::string extension; // 输出文件扩展名
	cv::Rect2d ROI;
	bool isInit;  // 识别器的init标志
	cv::Ptr<cv::TrackerKCF> tracker;

public:
	void setFrameProcessor(FrameProcessor *frameProcessorPtr);
	void setFrameProcessor(void(*frameProcessingCallback)(cv::Mat&, cv::Mat&));
	void setFrameProcessor(VideoProcessor(*frameProcessingCallback)(cv::Mat&, cv::Mat&));
	bool setInput(std::string filename);
	bool setInput(const std::vector<std::string>& imgs);
	bool setRect2d(cv::Rect2d select_roi);
	void displayInput(std::string wn);
	void displayOutput(std::string wn);
	void stopIt();
	bool isStopped();
	bool isOpened();
	void setDelay(int d); // 帧延时函数，0代表每一帧都延时，负数代表不延时
	bool readNextFrame(cv::Mat& frame);
	void callProcess();
	void dontCallProcess();
	void stopAtFrameNo(long frame);
	long getFrameNumber();
	long getTotalFrameCount();
	cv::Size getFrameSize();
	void run();
	double getFrameRate(); // 获得帧率

	// 输出视频文件
	bool setOutput(const std::string& filename, int codec = 0, double framerate = 0.0, bool isColor = true); // 设置输出文件格式
	bool setOutput(const std::string &filename, const std::string &ext, int numberOfDigits = 3, int startIndex = 0); 
	void writeNextFrame(cv::Mat& frame);
	int getCodec(char codec[4]);  // 获得输入视频的解码器

	// 算法
	void KCF(cv::Mat& img, cv::Mat& out);
	
};



void canny(cv::Mat& img, cv::Mat& out); 
