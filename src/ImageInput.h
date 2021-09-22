#ifndef IMAGE_INPUT_H
#define IMAGE_INPUT_H

#include <opencv2/opencv.hpp>

class ImageInput
{
protected:
    cv::Size imgResolution;
    bool opened;
public:
    ImageInput(cv::Size res = cv::Size(640,480)) : imgResolution(res) {}
    
    virtual ~ImageInput() = default;

    virtual bool        init() = 0;
    virtual cv::Mat     read() = 0;

    ImageInput&         operator>>(cv::Mat& image)  { image = this->read(); return *this; }
    bool                isOpened() const            { return opened; }
    operator            bool()                      { return opened; }

    void setResolution(const cv::Size & _res) { imgResolution = _res; }
    auto getResolution() { return imgResolution; }
};

#endif 
