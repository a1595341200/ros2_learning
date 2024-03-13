#ifndef SELECTTEST_H
#define SELECTTEST_H
#include <rviz_common/display_context.hpp>
#include <rviz_common/interaction/selection_manager.hpp>
#include <rviz_common/interactive_object.hpp>
#include <rviz_common/properties/int_property.hpp>
#include <rviz_rendering/objects/movable_text.hpp>
#include <visualization_msgs/msg/marker.hpp>

class SelectTest;
class MourseListener : public rviz_common::InteractiveObject {
public:
  MourseListener(rviz_common::DisplayContext *context) : mContext(context) {}
  bool isInteractive() override;
  void enableInteraction(bool enable) override;
  void handleMouseEvent(rviz_common::ViewportMouseEvent &event) override;
  const QCursor &getCursor() const override;
  SelectTest *select;

private:
  QCursor q{Qt::CursorShape::OpenHandCursor};
  std::shared_ptr<rviz_rendering::MovableText> text;
  rviz_common::DisplayContext *mContext;
  Ogre::SceneNode *text_node;
  rclcpp::Logger mLogger{rclcpp::get_logger("MourseListener")};
};

class SelectTest : public rviz_common::interaction::SelectionHandler {
public:
  SelectTest(rviz_common::DisplayContext *context, Ogre::SceneNode *frame_node);
  void
  createProperties(const rviz_common::interaction::Picked &obj,
                   rviz_common::properties::Property *parent_property) override;
  void updateProperties() override;
  void setPosition(const Ogre::Vector3 &position);
  Ogre::SceneNode *frame_node_;
  Ogre::Vector3 mPosition;

  void onSelect(const rviz_common::interaction::Picked &obj) override;

private:
  std::shared_ptr<MourseListener> interactive;
  rclcpp::Logger mLogger{rclcpp::get_logger("SelectTest")};
};

#endif /* SELECTTEST_H */
