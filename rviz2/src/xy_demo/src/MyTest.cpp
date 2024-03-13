/*
 * @Author: yao.xie 1595341200@qq.com
 * @Date: 2024-03-13 01:58:42
 * @LastEditors: yao.xie 1595341200@qq.com
 * @LastEditTime: 2024-03-13 10:20:56
 * @FilePath: /ros2_learning/rviz2/src/xy_demo/src/MyTest.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved.
 */
#include "xy_demo/MyTest.h"
#include <OGRE/OgreSceneManager.h>
#include <OgreEntity.h>
namespace demo {
MyTest::MyTest() { std::cout << "start" << std::endl; }
MyTest::~MyTest() {
  context_->getSceneManager()->destroySceneNode(frame_node_);
}

void MyTest::onInitialize() {
  MFDClass::onInitialize();
  scene_manager_ = context_->getSceneManager();
  frame_node_ = scene_node_->createChildSceneNode();
  mSelectTest = rviz_common::interaction::createSelectionHandler<SelectTest>(
      context_, frame_node_);
  auto selection_manager = context_->getSelectionManager();
  acceleration_arrow_ =
      std::make_shared<rviz_rendering::Arrow>(scene_manager_, frame_node_);

  acceleration_arrow_->setColor(Ogre::ColourValue::Red);
  Ogre::Vector3 p;
  p.x = 0;
  p.y = 0;
  p.z = 0;
  acceleration_arrow_->setPosition(p);
  Ogre::Quaternion q{0, 0, 0, 1};
  acceleration_arrow_->setOrientation(q);
  Ogre::Vector3 scale{1, 1, 1};
  acceleration_arrow_->setScale(scale);
  Ogre::Vector3 acc{1, 0, 0};
  acceleration_arrow_->setDirection(acc);

  acc.x = -1;
  test = std::make_shared<rviz_rendering::Arrow>(scene_manager_, frame_node_);
  test->setPosition(p);
  test->setOrientation(q);
  test->setScale(scale);
  test->setDirection(acc);

  shap = std::make_shared<rviz_rendering::Shape>(rviz_rendering::Shape::Cube,
                                                 scene_manager_, frame_node_);
  shap->setColor(Ogre::ColourValue::Green);

  p.x = 5;
  shap->setPosition(p);
  shap->setOrientation(q);
  shap->setScale(scale);
  acc.x = 0;
  // mSelectTest->addTrackedObjects(frame_node_);
  mSelectTest->addTrackedObject(shap->getEntity());
  // mSelectTest->setPosition(p);

  text = std::make_shared<rviz_rendering::MovableText>("test");
  text_node = frame_node_->createChildSceneNode();
  text->setColor(Ogre::ColourValue::Blue);
  text->setTextAlignment(rviz_rendering::MovableText::H_CENTER,
                         rviz_rendering::MovableText::V_CENTER);
  text->setCaption("test1");
  text_node->setPosition(Ogre::Vector3(-5, 0, 0));
  text->setCharacterHeight(3);
  text_node->attachObject(text.get());
  text_node->setVisible(true);
  std::cout << "init done" << std::endl;
}

void MyTest::processMessage(
    visualization_msgs::msg::Marker::ConstSharedPtr msg) {}
} // namespace demo
#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(demo::MyTest, rviz_common::Display)
