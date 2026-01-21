//
// Created by nirvana on 2025/9/13.
//
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat bgr_img;
	bgr_img = cv::imread("RM.jpg");

	//分离三个通道并显示，调试用
	std::vector<cv::Mat> channels;
	cv::split(bgr_img,channels);
	cv::Mat blue = channels.at(0);
	cv::Mat green = channels.at(1);
	cv::Mat red = channels.at(2);

	cv::resize(blue,blue,{},0.1,0.1);
	cv::resize(green,green,{},0.2,0.2);
	cv::resize(red,red,{},0.3,0.3);

	cv::imshow("blue",blue);
	cv::imshow("green",green);
	cv::imshow("red",red);

	cv::waitKey(0);
	return 0;
}