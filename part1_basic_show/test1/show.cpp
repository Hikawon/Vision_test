#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
        if (access("/home/nirvana/Desktop/test1/image.jpeg", R_OK) == 0) {
            printf("文件可读\n");
        } else {
            perror("权限检查失败");
        }

    cv::Mat img = cv::imread("/home/nirvana/Desktop/test1/image.jpeg");
    if(img.empty()) {
        std::cerr << "加载失败，请检查路径和文件权限" << std::endl;
        return -1;
    }
    cv::imshow("img",img);
    cv::waitKey(0);
    return 0;
}