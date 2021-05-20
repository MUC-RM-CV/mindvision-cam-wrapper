#include <opencv2/opencv.hpp>
#include "MVCameraInput.h"
#include <iostream>

int main() {
    //cv::Ptr<ImageInput> cam = new MVCameraInput();

    MVCameraInput cam;

    if (!(cam.isOpened())) return 0;

    cv::Mat frame;

    cam >> frame;

    cv::Size frame_size = frame.size();
    cv::Rect center(
        frame_size.width / 2 - frame_size.width * 0.1,
        frame_size.height / 2 - frame_size.height * 0.1, 
        frame_size.width * 0.2, 
        frame_size.height * 0.2
    );

    cv::String windowTitle = "Mindvision Camera";
    cv::namedWindow(windowTitle);

    std::cout << frame.size();

    const int process_width = 640;
    cam.setResolution(cv::Size(process_width, (double)process_width / frame.cols * frame.rows));

    while(true) {
        cam >> frame;
        if (!frame.empty()) {
            cv::rectangle(frame, center, cv::Scalar(0,255,0));
            cv::imshow(windowTitle, frame);
        } else {
            std::cerr << "no img!\n";
        }
        if (cv::waitKey(25) == 27) break;
    }
}
