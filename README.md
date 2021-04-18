
Mindvision 迈德威视 工业摄像头 SDK 读取图像 API 封装

迈德威视 SDK 请在官网自行下载安装。官网：[mindvision.com.cn](https://mindvision.com.cn)

官方提供的 Windows 环境的 SDK 似乎依赖 MFC，
即迈德威视 Windows SDK 似乎是和 Visual Studio 集成度很高。

若打算采用 OpenCV 的话，可以在安装 Windows SDK 中的 dll 库文件后，
再下载 Linux 的 SDK，使用 Linux SDK 的标头文件，放在该项目的[include/image/MVSDK](include/image/MVSDK)下，
就常用的接口来说，头文件似乎是通用的；

不过 Windows SDK 上的文档似乎更全面，而且两个里面 OpenCV 的 Demo 程序也不完全相同，
可以互相结合起来参考。

Windows + MSYS2 MinGW64 + OpenCV 4.5.1 + CMake 测试通过

