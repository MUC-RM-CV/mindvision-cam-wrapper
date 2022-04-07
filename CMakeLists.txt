cmake_minimum_required(VERSION 3.1)

project(image-input)

message(STATUS "Your operation system is ${CMAKE_SYSTEM_NAME} - ${CMAKE_SYSTEM}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

# Image-Input Library Target
add_library(img_input OBJECT src/MVCameraInput.cpp src/VideoInput.cpp)

# Image-Input Library Target Include
target_include_directories(img_input PUBLIC src ./3rdparty/MVSDK/include)

# Image-Input Library Target Link Libraries
if(WIN32)
    target_link_libraries(
        img_input
        ${OpenCV_LIBS}
        ${PROJECT_SOURCE_DIR}/3rdparty/MVSDK/lib/MVCAMSDK_X64.lib
    )
elseif(UNIX)
    target_link_libraries(img_input ${OpenCV_LIBS} MVSDK)
endif()

# MV Camera Test

add_executable(camera_test src/demo/camera_test.cpp)
target_link_libraries(camera_test img_input)

# Camera Calib Demo

add_executable(camera_calib src/demo/camera_calib.cpp)
target_link_libraries(camera_calib img_input)
