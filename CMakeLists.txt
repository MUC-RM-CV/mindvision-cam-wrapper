cmake_minimum_required(VERSION 3.13)

project(mindvision-camera-test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(./include)

add_executable(camera_test 
    src/camera_test.cpp 
    src/image/CameraInput.cpp
)

target_link_libraries(camera_test 
    ${OpenCV_LIBS} 
    ${PROJECT_SOURCE_DIR}/lib/MVCAMSDK_X64.lib
)
