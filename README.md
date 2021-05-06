
对 Mindvision 迈德威视 工业摄像头 SDK 图像读取 API 的 OpenCV C++ 封装

迈德威视 SDK 请在官网自行下载安装。官网：[mindvision.com.cn](https://mindvision.com.cn)

**注意**：使用 迈德威视 的摄像头前，一定在官网上下载对应操作系统的SDK进行安装（并重启），不然会无法识别到连接的摄像头

- 最新的 Linux SDK 的`install.sh`中已经做了判断，但是Linux 平台安装时还是要注意复制的动态库`.so`文件是否为对应平台的架构；
- Linux 平台的`install.sh`会将标头文件复制到`/usr/include`目录（同时也会将动态链接库复制到系统库目录），因此在**SDK安装完成后**，如果需要调用 Mindvision 的 SDK，可以直接引用`CameraApi.h`等文件
- 然而 Windows 平台暂时不清楚是否会将标头文件复制到系统包含路径下，并且考虑到 Windows 上工具链的的复杂性，建议还是将标头文件拷贝一份放在工程目录下

- 官方提供的 Windows 环境的 SDK 似乎依赖 MFC，即迈德威视 Windows SDK 似乎是和 Visual Studio 集成度很高。
- 就常用的接口来说，Windows 和 Linux SDK 的头文件似乎是通用的；出于兼容性考虑，建议使用 Linux SDK 的标头文件；
- Windows SDK 中的文档似乎更全面，而且两个里面 OpenCV 的 Demo 程序也不完全相同，可以互相结合起来参考
- 对于该项目，将 Mindvision SDK 的标头文件放在该项目的[3rdparty/MVSDK/include](3rdparty/MVSDK/include)下

- Windows SDK 安装后，Mindvision 的工业摄像头似乎可以直接作为 USB Camera 使用（未验证），也就是说，使用`cv::VideoCapture`即可调用工业摄像头；但是Linux下貌似不能成功

- 在 x86_64 Windows 上，似乎需要调用 MVSDK 中的 `CameraFlipFrameBuffer` 来对获取的图像进行镜像反转，但是在 Nvidia TX2 （MVSDK for Linux）上则似乎不需要进行翻转操作；
- 如果没有使用`CameraSetIspOutFormat`，则可能会遇到色彩错乱的问题

x86_64: Windows + MSYS2 MinGW64 + OpenCV 4.5.1 + CMake 测试通过

aarch64: Linux for Tegra (L4T) + gcc-7 + NVIDIA-OpenCV + CMake 测试通过
