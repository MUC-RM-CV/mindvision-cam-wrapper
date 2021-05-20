cmake_minimum_required(VERSION 3.1)

project(mindvision-camera-test)

message(STATUS "Your operation system is ${CMAKE_SYSTEM_NAME} - ${CMAKE_SYSTEM}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(./src)
include_directories(./3rdparty)

add_executable(camera_test 
    src/camera_test.cpp 
    src/image/MVCameraInput.cpp
)

if(WIN32)
    target_link_libraries(camera_test 
        ${OpenCV_LIBS} 
        ${PROJECT_SOURCE_DIR}/3rdparty/MVSDK/lib/MVCAMSDK_X64.lib
    )
elseif(UNIX)
    target_link_libraries(camera_test 
        ${OpenCV_LIBS} 
        MVSDK
    )
endif()
