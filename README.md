# Mindvision Industrial Camera OpenCV Wrapper

对 Mindvision 迈德威视 工业摄像头 SDK 图像读取 API 的 OpenCV C++ 封装

## 💿 安装 SDK 

**注意**：使用 迈德威视 的摄像头前，一定在官网上下载对应操作系统的 SDK 进行安装（并重启），不然会无法识别到连接的摄像头

迈德威视 SDK 请在官网自行下载安装。官网：[mindvision.com.cn](http://mindvision.com.cn)

### 安装时注意事项：

- 最新的 Linux SDK 的 `install.sh` 中已经做了判断，但是 Linux 平台安装时还是要注意复制的动态库 `.so` 文件是否为对应平台的架构；

### 原理

计算机要访问摄像头这一硬件，就需要一定的协议，从摄像头读取数据，并将数据进行一定的处理。迈德威视将这些功能以动态链接库的形式提供。这样，应用程序就得以使用这些代码。

而我们要的调用这些功能——即读取摄像头图像数据——进行自己软件的开发，则需要在编写自己的程序调用该库。这样，就不止需要库文件，也需要对应的头文件（headers），加起来就属于 SDK 了。整个过程具体来说就是：

- 包含迈德威视 SDK 中提供的头文件，使得自行开发应用程序能够通过编译；
- 链接自己的程序到迈德威视提供的库（动态链接）。

如上操作后，由于是动态链接，我们的程序就会在运行时去寻找并加载指定的动态链接库文件，查找的位置一般来说是系统存放库文件的路径。安装程序的目的，就是将迈德威视提供的这些库文件复制到系统的库文件目录下。对于 Windows 来说，就是 `X:/Windows/System32/`。

比如，链接后我们的程序中有一个要加载 `some_dylib.dll` 的指令，那么程序就会去寻找 `some_dylib.dll` 这个文件。如果没有找到，就会提示缺失库文件的错误，程序也就不能执行。

## 🔧 使用 SDK

### 注意事项

再次提醒：首先要确保安装了 Mindvision 的 SDK

- Linux 平台的 `install.sh` 会将标头文件复制到 `/usr/include` 目录（同时也会将动态链接库复制到系统库目录），因此在**SDK 安装完成后**，如果需要调用 Mindvision 的 SDK，可以直接引用 `CameraApi.h` 等文件
- 然而 Windows 平台暂时不清楚是否会将标头文件复制到系统包含路径下，建议还是将标头文件拷贝一份放在工程目录下；就常用的接口来说，使用 Linux SDK 的头文件也能访问 Windows SDK 中的功能；出于兼容性考虑，建议使用 Linux SDK 的标头文件
- 对于该项目，将 Mindvision SDK 的标头文件放在 [`${PROJECT_ROOT}/3rdparty/MVSDK/include/`](3rdparty/MVSDK/include) 目录下。
- 另外，虽然库文件已经放置在了系统目录（`X:/Windows/System32/`）中，但是 MSVC 在链接时需要链接动态链接库文件对应的 `.lib` 文件，因此需要将 `.lib` 文件放入 [`${PROJECT_ROOT}/3rdparty/MVSDK/lib/`](3rdparty/MVSDK/lib) 下，详见 [`CMakeLists.txt`](./CMakeLists.txt)。
- 目前机器通常为 `x86_64`（`amd64`）架构，推荐使用 64 位的链接库，即链接到 `MVCAMSDK_X64.lib`（复制到 `System32` 的也是对应的 `MVCAMSDK_X64.dll`；此外，迈德威视提供的 32 位的库文件似乎有问题）。

### 不同平台 SDK 差别

- 官方提供的 Windows 环境的 SDK 似乎依赖 MFC，也就是说，迈德威视 Windows SDK 似乎是和 Visual Studio 集成度很高。
- Windows SDK 中的文档似乎更全面，而且两个里面 OpenCV 的 Demo 程序也不完全相同，可以互相结合起来参考

### 其他问题

- Windows SDK 安装后，Mindvision 的工业摄像头似乎可以直接作为 USB Camera 使用（未验证），也就是说，使用 `cv::VideoCapture` 即可调用工业摄像头；但是 Linux 下貌似不能成功
- 在 Windows (x86_64) 上，似乎需要调用 MVSDK 中的 `CameraFlipFrameBuffer` 来对获取的图像进行垂直反转操作，但是在 Linux for Tegra (L4T) (aarch64) 上则似乎不需要进行翻转操作；
- 如果没有调用 `CameraSetIspOutFormat`，则可能会遇到色彩错乱的问题

## 🔨 Build Test

| Passed | Platform                         | Toolchain                                       |
| :----: | -------------------------------- | ----------------------------------------------- |
|   ✔️    | Windows (x86_64)                 | MSYS2 MinGW-w64 gcc-10.2.0 + OpenCV 4.5.1 + CMake |
|   ✔️    | Windows (x86_64)                 | MSVC 19.30.30528.0 (amd64) + OpenCV 4.5.3 + CMake |
|   ✔️    | Linux for Tegra (L4T)  (aarch64) | gcc-7 + NVIDIA-OpenCV + CMake                   |

