#include <iostream>
#include <string>
#include <vector>

using namespace std;


class ImageFormat
{
public:
    ImageFormat() = default;

    virtual void LoadImage(const string& filename) = 0;

private:
    char* data = nullptr;
};


class ImageFormatGif: private ImageFormat
{


};

class ImageFormatTiff: private ImageFormat
{


};

class ImageFormatJpeg: private ImageFormat
{


};

class ImageFormatBmp: private ImageFormat
{


};