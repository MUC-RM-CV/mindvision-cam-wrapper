#ifndef CAMERA_INPUT_H
#define CAMERA_INPUT_H

#include "ImageInput.h"

#include "MVSDK/include/CameraApi.h"

#include <iostream>
#include <string>

class CameraInput : public ImageInput {
private:
    unsigned char*          g_pRgbBuffer = nullptr; // 处理后图像输出的数据缓存区地址
    CameraHandle            hCamera;                // 相机句柄
    bool                    opened;
public:
    CameraInput();
    bool        init()      final;
    cv::Mat     read()      final;
    bool        is_opened() final { return opened; }
    operator    bool()      final { return opened; }
    ~CameraInput();
};

#endif 
