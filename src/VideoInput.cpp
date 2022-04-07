#include "VideoInput.h"

VideoInput::VideoInput(int idx) : cam_no(idx)
{
    opened = init();
}

VideoInput::VideoInput(const std::string & fileName)
{
    origin.open(fileName);
    if (origin.isOpened()) {
        std::cout << "Input video '" << fileName << "' opened successfully." << std::endl;
        opened = true;
    }
    else {
        std::cout << "Failed to open '" << fileName << "' Fall back to USB Camera." << std::endl;
        opened = initUSBCamera();
    }
}

bool VideoInput::init() { 
    return initUSBCamera(); 
}

VideoInput::~VideoInput()
{
    origin.release();
    std::cout << "VideoInput Released!\n";
}

bool VideoInput::initUSBCamera()
{
    std::cout << "Try using USB camera. " << std::endl;
    origin.open(this->cam_no);
    if (origin.isOpened()) {
        std::cout << "USB Camera opened successfully. " << std::endl;
        return true;
    }
    else {
        std::cout << "Failed to open USB Camera!" << std::endl;
        return false;
    }
}

cv::Mat VideoInput::read()
{
    origin >> tmp;
    if (!tmp.empty()) cv::resize(tmp, tmp, imgResolution);
    return tmp;
}
