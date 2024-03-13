/*
 * @Author: yao.xie 1595341200@qq.com
 * @Date: 2023-07-13 16:22:56
 * @LastEditors: yao.xie 1595341200@qq.com
 * @LastEditTime: 2024-03-13 09:32:04
 * @FilePath: /ros2_learning/rviz2/src/xy_demo/src/SelectTest.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "xy_demo/SelectTest.h"
#include <OgreSceneNode.h>
#include <rclcpp/rclcpp.hpp>

bool MourseListener::isInteractive() { return true; }

void MourseListener::enableInteraction(bool enable) {}

void MourseListener::handleMouseEvent(rviz_common::ViewportMouseEvent &event) {
  std::cout << "handleMouseEvent" << std::endl;
  if (!text) {
    text = std::make_shared<rviz_rendering::MovableText>("test");
    text_node = select->frame_node_->createChildSceneNode();
    text->setColor(Ogre::ColourValue::Blue);
    text->setTextAlignment(rviz_rendering::MovableText::H_CENTER,
                           rviz_rendering::MovableText::V_CENTER);
    text->setCaption("test1");
    text_node->setPosition(select->mPosition);
    text->setCharacterHeight(3);
    text_node->attachObject(text.get());
    text_node->setVisible(true);
  }
  if (event.type == QEvent::FocusIn) {
    std::cout << "x : " << event.x << std::endl;
    std::cout << "y : " << event.y << std::endl;
    text_node->setVisible(true);
  }

  if (event.type == QEvent::FocusOut) {
    std::cout << "Leave" << event.x << std::endl;
    text_node->setVisible(false);
  }
}

const QCursor &MourseListener::getCursor() const { return q; }

SelectTest::SelectTest(rviz_common::DisplayContext *context,
                       Ogre::SceneNode *frame_node)
    : rviz_common::interaction::SelectionHandler(context) {
  interactive = std::make_shared<MourseListener>(context);
  interactive->enableInteraction(true);
  rviz_common::interaction::SelectionHandler::setInteractiveObject(interactive);
  interactive->select = this;
  frame_node_ = frame_node;
  setBoxVisibility(true);
}

void SelectTest::createProperties(
    const rviz_common::interaction::Picked &obj,
    rviz_common::properties::Property *parent_property) {
  rviz_common::interaction::SelectionHandler::createProperties(obj,
                                                               parent_property);
  std::cout << "Creating\n";
}

void SelectTest::updateProperties() {
  rviz_common::interaction::SelectionHandler::updateProperties();
  std::cout << "updateProperties\n";
}

void SelectTest::setPosition(const Ogre::Vector3 &position) {
  mPosition = position;
}

void SelectTest::onSelect(const rviz_common::interaction::Picked &obj) {
  rviz_common::interaction::SelectionHandler::onSelect(obj);
  std::cout << "obj" << std::endl;
}
