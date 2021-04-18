#include <opencv2/opencv.hpp>
#include "image/CameraInput.h"
#include <iostream>

int main() {
    cv::Ptr<ImageInput> cam = new CameraInput();

    if (!(cam->is_opened())) return 0;

    cv::namedWindow("Minvision Camera", cv::WINDOW_NORMAL);

    cv::Size frame_size = cam->read().size();
    cv::Rect center(
        frame_size.width / 2 - frame_size.width * 0.1,
        frame_size.height / 2 - frame_size.height * 0.1, 
        frame_size.width * 0.2, 
        frame_size.height * 0.2
    );

    cv::Mat frame;

    while(true) {
        frame = cam->read();
        if (!frame.empty()) {
            cv::rectangle(frame, center, cv::Scalar(0,255,0));
            cv::imshow("cam", frame);
        } else {
            std::cerr << "no img!\n";
        }
        if (cv::waitKey(25) == 27) break;
    }
}
