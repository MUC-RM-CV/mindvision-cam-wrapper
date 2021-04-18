#ifndef IMAGE_INPUT_H
#define IMAGE_INPUT_H

#include <opencv2/opencv.hpp>

class ImageInput
{
protected:
    cv::Size imgRes = cv::Size(640,480);
public:
    ImageInput() {}
    virtual ~ImageInput() = default;

    virtual bool        init()          = 0;
    virtual cv::Mat     read()          = 0;
    virtual bool        is_opened()     = 0;
    virtual             operator bool() = 0;

    void set_res(int cols, int rows)    { imgRes = cv::Size(cols, rows); }
    void set_res(const cv::Size & _res) { imgRes = _res; }
};

#endif 
