//
// Created by nirvana on 2025/9/15.
//

#include <fmt/format.h>

#include <opencv2/opencv.hpp>

#include "include/armor.hpp"
#include "include/img_tools.hpp"
#include "tasks/detector.hpp"
#include "tasks/plotter.h"

using namespace auto_aim;

int main()
{
  Detector detector;
  Plotter plotter;

  std::list<Armor> armors;
  cv::VideoCapture video("imgs/8radps.avi");

  // 检查视频文件是否成功打开
  if (!video.isOpened()) {
    std::cerr << "Error: Cannot open video file imgs/8radps.avi" << std::endl;
    return -1;
  }

  while (true) {
    cv::Mat bgr_img;
    bool success = video.read(bgr_img); //从视频读取一帧

    armors = detector.detect(bgr_img);

    // 检查是否有装甲板被检测到
    if (!armors.empty()) {
      nlohmann::json data;
      data["armors_x"] = armors.front().center.x;
      data["armors_y"] = armors.front().center.y;
      plotter.plot(data);
    }

    //显示装甲板，调试用
    cv::Mat draw_armor = bgr_img.clone();

    for (const auto & armor : armors) {
      //熟悉的绘图函数
      tools::draw_points(draw_armor, armor.points);
      tools::draw_text(
        draw_armor,
        fmt::format("{}, {}, {:.2f}",COLORS[armor.color], ARMOR_NAMES[armor.name], armor.confidence),
        armor.left.top);
    }
    cv::imshow("draw_armor", draw_armor);
    auto key = cv::waitKey(25);  //阻塞25ms
    if (key == 'q') {
      break;  //按下q键退出循环
    }
  }
  return 0;
}
