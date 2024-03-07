/*
 * @Author: error: error: git config user.name & please set dead value or
 * install git && error: git config user.email & please set dead value or
 * install git & please set dead value or install git
 * @Date: 2024-03-07 09:16:18
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * install git && error: git config user.email & please set dead value or
 * install git & please set dead value or install git
 * @LastEditTime: 2024-03-07 09:19:59
 * @FilePath: /ros2_learning/ros2_ws/src/polygon_plugins/src/polygon_plugins.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved.
 */
#include <cmath>
#include <polygon_base/regular_polygon.hpp>

namespace polygon_plugins {
class Square : public polygon_base::RegularPolygon {
public:
  void initialize(double side_length) override { side_length_ = side_length; }

  double area() override { return side_length_ * side_length_; }

protected:
  double side_length_;
};

class Triangle : public polygon_base::RegularPolygon {
public:
  void initialize(double side_length) override { side_length_ = side_length; }

  double area() override { return 0.5 * side_length_ * getHeight(); }

  double getHeight() {
    return sqrt((side_length_ * side_length_) -
                ((side_length_ / 2) * (side_length_ / 2)));
  }

protected:
  double side_length_;
};
} // namespace polygon_plugins

#include <pluginlib/class_list_macros.hpp>

PLUGINLIB_EXPORT_CLASS(polygon_plugins::Square, polygon_base::RegularPolygon)
PLUGINLIB_EXPORT_CLASS(polygon_plugins::Triangle, polygon_base::RegularPolygon)
