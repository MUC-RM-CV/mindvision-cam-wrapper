#ifndef VIDEO_INPUT_H
#define VIDEO_INPUT_H

#include "ImageInput.h"

#include <iostream>
#include <string>

class VideoInput : public ImageInput {
private:
    cv::Mat tmp;
    cv::VideoCapture origin;
    int cam_no = 0;

    bool initUSBCamera();

public:
    VideoInput(int idx = 0);
    VideoInput(const std::string & fileName);
    ~VideoInput();
    bool    init() final;
    cv::Mat read() final;
};

#endif
