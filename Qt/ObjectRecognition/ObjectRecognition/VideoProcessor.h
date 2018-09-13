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
	void(*process) (cv::Mat&, cv::Mat&); // �ص�����
	VideoProcessor(*processAlgorithm) (cv::Mat&, cv::Mat&); // �ص�����
	bool callIt; // �����־������ʾ�ص������Ƿ�ᱻ����
	std::string windowNameInput;
	std::string windowNameOutput;
	int delay; // ֡��ʱ
	long fnumber; // �Ѿ������֡��
	long frameToStop; // �������֡��ǰһ֡����
	bool stop; // ��������
	std::vector<std::string> images;
	std::vector<std::string>::const_iterator itImg;
	FrameProcessor *frameProcessor;
	// д����Ƶ����
	cv::VideoWriter writer;
	std::string outputFile; // ����ļ���
	int currentIndex;
	int digits; // 
	std::string extension; // ����ļ���չ��
	cv::Rect2d ROI;
	bool isInit;  // ʶ������init��־
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
	void setDelay(int d); // ֡��ʱ������0����ÿһ֡����ʱ������������ʱ
	bool readNextFrame(cv::Mat& frame);
	void callProcess();
	void dontCallProcess();
	void stopAtFrameNo(long frame);
	long getFrameNumber();
	long getTotalFrameCount();
	cv::Size getFrameSize();
	void run();
	double getFrameRate(); // ���֡��

	// �����Ƶ�ļ�
	bool setOutput(const std::string& filename, int codec = 0, double framerate = 0.0, bool isColor = true); // ��������ļ���ʽ
	bool setOutput(const std::string &filename, const std::string &ext, int numberOfDigits = 3, int startIndex = 0); 
	void writeNextFrame(cv::Mat& frame);
	int getCodec(char codec[4]);  // ���������Ƶ�Ľ�����

	// �㷨
	void KCF(cv::Mat& img, cv::Mat& out);
	
};



void canny(cv::Mat& img, cv::Mat& out); 
