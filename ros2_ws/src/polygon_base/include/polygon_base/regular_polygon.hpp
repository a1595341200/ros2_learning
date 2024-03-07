/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-07 09:13:42
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-07 09:13:47
 * @FilePath: /ros2_learning/ros2_ws/src/polygon_base/include/polygon_base/regular_polygon.hpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef POLYGON_BASE_REGULAR_POLYGON_HPP
#define POLYGON_BASE_REGULAR_POLYGON_HPP

namespace polygon_base {
class RegularPolygon {
public:
  virtual void initialize(double side_length) = 0;
  virtual double area() = 0;
  virtual ~RegularPolygon() {}

protected:
  RegularPolygon() {}
};
} // namespace polygon_base

#endif // POLYGON_BASE_REGULAR_POLYGON_HPP
