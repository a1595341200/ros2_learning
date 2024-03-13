/*
 * @Author: yao.xie 1595341200@qq.com
 * @Date: 2023-07-13 16:43:29
 * @LastEditors: yao.xie 1595341200@qq.com
 * @LastEditTime: 2024-03-13 09:23:37
 * @FilePath: /ros2_learning/rviz2/src/xy_demo/include/xy_demo/MyTest.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef MYTEST_H
#define MYTEST_H

#include "xy_demo/SelectTest.h"
#include <OgreSceneNode.h>
#include <boost/circular_buffer.hpp>
#include <memory>
#include <rviz_common/display.hpp>
#include <rviz_common/message_filter_display.hpp>
#include <rviz_common/properties/color_property.hpp>
#include <rviz_common/properties/float_property.hpp>
#include <rviz_rendering/objects/arrow.hpp>
#include <rviz_rendering/objects/movable_text.hpp>
#include <rviz_rendering/objects/shape.hpp>
#include <visualization_msgs/msg/interactive_marker.hpp>
#include <visualization_msgs/msg/marker.hpp>

namespace demo {
class MyTest : public rviz_common::MessageFilterDisplay<
                   visualization_msgs::msg::Marker> {
  Q_OBJECT
public:
  MyTest();
  ~MyTest();

protected:
  void onInitialize() override;
  void
  processMessage(visualization_msgs::msg::Marker::ConstSharedPtr msg) override;

private:
  std::shared_ptr<rviz_rendering::Arrow> acceleration_arrow_;
  Ogre::SceneNode *frame_node_;
  Ogre::SceneNode *text_node;

  std::shared_ptr<rviz_rendering::Arrow> test;
  std::shared_ptr<rviz_rendering::Shape> shap;
  std::shared_ptr<rviz_rendering::MovableText> text;
  // The SceneManager, kept here only so the destructor can ask it to
  // destroy the ``frame_node_``.
  Ogre::SceneManager *scene_manager_;
  std::shared_ptr<SelectTest> mSelectTest;
};
} // namespace demo

#endif /* MYTEST_H */
