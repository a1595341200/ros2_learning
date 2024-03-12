/*
 * @Author: yao.xie 1595341200@qq.com
 * @Date: 2024-03-12 05:59:15
 * @LastEditors: yao.xie 1595341200@qq.com
 * @LastEditTime: 2024-03-12 05:59:20
 * @FilePath: /ros2_learning/ros2_ws/src/learning_tf2_cpp/test/tutorial_test.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include <gtest/gtest.h>

TEST(package_name, a_first_test)
{
  ASSERT_EQ(4, 2 + 2);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
