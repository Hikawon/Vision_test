//
// Created by nirvana on 2025/9/14.
//

// tools.h
#pragma once
#include <opencv2/opencv.hpp>

namespace tools {
    template<typename T>
    void draw_points(cv::Mat& img, const std::vector<T>& points, cv::Scalar color = cv::Scalar(255, 0, 255), int radius = 3) {
        for (const auto& point : points) {
            cv::circle(img, point, radius, color, -1);
        }
    }
}
