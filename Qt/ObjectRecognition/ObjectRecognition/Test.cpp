#include "Test.h"



Test::Test()
{
}


Test::~Test()
{
}

bool Test::test_VideoProcessor()
{
	VideoProcessor processor;
	std::string filepath = "D:\\Users\\Yeah_Kun\\Desktop\\clip\\11_clip.mp4";
	processor.setInput(filepath);
	processor.displayInput("Input Video");
	processor.displayOutput("Output Video");
	processor.setDelay(1000. / processor.getFrameRate());
	processor.setFrameProcessor(canny);
	processor.run();
	cv::waitKey();
	return true;
}

bool Test::test_temp_module()
{
	{
		Mat frame;
		Rect2d roi;
		std::string video = "D:\\Users\\Yeah_Kun\\Desktop\\ay_clip.mpg";
		VideoCapture cap(video);
		cap >> frame;
		roi = selectROI("ROI selector", frame);
		//! [selectroi]

		//quit if ROI was not selected
		if (roi.width == 0 || roi.height == 0)
			return false;
		// initialize the tracker
		Ptr<TrackerKCF> tracker = TrackerKCF::create();
		//! [init]
		tracker->init(frame, roi);
		//! [init]

		// perform the tracking process
		printf("Start the tracking process\n");
		for (;; ) {
			// get frame from the video
			cap >> frame;

			// stop the program if no more images
			if (frame.rows == 0 || frame.cols == 0)
				break;

			// update the tracking result
			//! [update]
			tracker->update(frame, roi);
			//! [update]

			//! [visualization]
			// draw the tracked object
			rectangle(frame, roi, Scalar(255, 0, 0), 2, 1);

			// show image with the tracked object
			imshow("tracker", frame);
			//! [visualization]
			//quit on ESC button
			if (waitKey(800) == 27)
				break;
		}
		return true;
	}
	return true;

	//int smin = 15;
	//int vmin = 40;
	//int vmax = 256;
	//int bins = 16;
	//VideoCapture capture;
	//capture.open("D:\\Users\\Yeah_Kun\\Desktop\\clip\\11_clip.mp4");
	//if (!capture.isOpened()) {
	//	printf("could not find video data file...\n");
	//	return -1;
	//}
	//namedWindow("CAMShift Tracking", CV_WINDOW_AUTOSIZE);
	//namedWindow("ROI Histogram", CV_WINDOW_AUTOSIZE);

	//bool firstRead = true;
	//float hrange[] = { 0, 180 };
	//const float* hranges = hrange;
	//Rect selection;
	//Mat frame, hsv, hue, mask, hist, backprojection;
	//Mat drawImg = Mat::zeros(300, 300, CV_8UC3);
	//while (capture.read(frame)) {
	//	if (firstRead) {
	//		Rect2d first = selectROI("CAMShift Tracking", frame);
	//		selection.x = first.x;
	//		selection.y = first.y;
	//		selection.width = first.width;
	//		selection.height = first.height;
	//		printf("ROI.x= %d, ROI.y= %d, width = %d, height= %d", selection.x, selection.y, selection.width, selection.height);
	//	}
	//	// convert to HSV
	//	cvtColor(frame, hsv, COLOR_BGR2HSV);
	//	inRange(hsv, Scalar(0, smin, vmin), Scalar(180, vmax, vmax), mask);
	//	hue = Mat(hsv.size(), hsv.depth());
	//	int channels[] = { 0, 0 };
	//	mixChannels(&hsv, 1, &hue, 1, channels, 1);

	//	if (firstRead) {
	//		// ROI 直方图计算
	//		Mat roi(hue, selection);
	//		Mat maskroi(mask, selection);
	//		calcHist(&roi, 1, 0, maskroi, hist, 1, &bins, &hranges);
	//		normalize(hist, hist, 0, 255, NORM_MINMAX);

	//		// show histogram
	//		int binw = drawImg.cols / bins;
	//		Mat colorIndex = Mat(1, bins, CV_8UC3);
	//		for (int i = 0; i < bins; i++) {
	//			colorIndex.at<Vec3b>(0, i) = Vec3b(saturate_cast<uchar>(i * 180 / bins), 255, 255);
	//		}
	//		cvtColor(colorIndex, colorIndex, COLOR_HSV2BGR);
	//		for (int i = 0; i < bins; i++) {
	//			int  val = saturate_cast<int>(hist.at<float>(i)*drawImg.rows / 255);
	//			rectangle(drawImg, Point(i*binw, drawImg.rows), Point((i + 1)*binw, drawImg.rows - val), Scalar(colorIndex.at<Vec3b>(0, i)), -1, 8, 0);
	//		}
	//	}

	//	// back projection
	//	calcBackProject(&hue, 1, 0, hist, backprojection, &hranges);
	//	// CAMShift tracking
	//	backprojection &= mask;
	//	RotatedRect trackBox = CamShift(backprojection, selection, TermCriteria((TermCriteria::COUNT | TermCriteria::EPS), 10, 1));

	//	// draw location on frame;
	//	ellipse(frame, trackBox, Scalar(255, 0, 0), 2, 1);

	//	if (firstRead) {
	//		firstRead = false;
	//	}
	//	imshow("CAMShift Tracking", frame);
	//	imshow("ROI Histogram", drawImg);
	//	char c = waitKey(800);// ESC
	//	if (c == 27) {
	//		break;
	//	}
	//}

	//capture.release();
	//waitKey(0);

}

