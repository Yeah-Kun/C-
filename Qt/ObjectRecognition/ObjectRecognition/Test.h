#pragma once
#include <catch.hpp>
#include <opencv/cv.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include "VideoProcessor.h"

using namespace cv;
using namespace std;

class Test
{
public:
	Test();
	~Test();

	bool test_VideoProcessor();
	bool test_temp_module();
};

