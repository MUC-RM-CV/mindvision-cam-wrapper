cmake_minimum_required(VERSION 3.1)

project(mindvision-camera-test)

message(STATUS "Your operation system is ${CMAKE_SYSTEM_NAME} - ${CMAKE_SYSTEM}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

include_directories(./src)
include_directories(./3rdparty/MVSDK/include)

add_executable(camera_test 
    src/demo/camera_test.cpp 
    src/MVCameraInput.cpp
)

add_executable(camera_calib 
    src/demo/camera_calib.cpp 
    src/MVCameraInput.cpp
)

if(WIN32)
    target_link_libraries(camera_test 
        ${OpenCV_LIBS} 
        ${PROJECT_SOURCE_DIR}/3rdparty/MVSDK/lib/MVCAMSDK_X64.lib
    )
    target_link_libraries(camera_calib 
        ${OpenCV_LIBS} 
        ${PROJECT_SOURCE_DIR}/3rdparty/MVSDK/lib/MVCAMSDK_X64.lib
    )
elseif(UNIX)
    target_link_libraries(camera_test 
        ${OpenCV_LIBS} 
        MVSDK
    )
    target_link_libraries(camera_calib 
        ${OpenCV_LIBS} 
        MVSDK
    )
endif()
