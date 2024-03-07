/*
 * @Author: error: error: git config user.name & please set dead value or
 * install git && error: git config user.email & please set dead value or
 * install git & please set dead value or install git
 * @Date: 2024-03-07 08:42:29
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * install git && error: git config user.email & please set dead value or
 * install git & please set dead value or install git
 * @LastEditTime: 2024-03-07 08:47:13
 * @FilePath: /ros2_learning/ros2_ws/src/more_interfaces/src/publish_address_book.cpp
 * /ros2_learning/ros2_ws/src/more_interfaces/src/publish_address_book.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved.
 */
#include <chrono>
#include <memory>

#include "more_interfaces/msg/address_book.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class AddressBookPublisher : public rclcpp::Node {
public:
  AddressBookPublisher() : Node("address_book_publisher") {
    address_book_publisher_ =
        this->create_publisher<more_interfaces::msg::AddressBook>(
            "address_book", 10);

    auto publish_msg = [this]() -> void {
      auto message = more_interfaces::msg::AddressBook();

      message.first_name = "John";
      message.last_name = "Doe";
      message.phone_number = "1234567890";
      message.phone_type = message.PHONE_TYPE_MOBILE;

      std::cout << "Publishing Contact\nFirst:" << message.first_name
                << "  Last:" << message.last_name << std::endl;

      this->address_book_publisher_->publish(message);
    };
    timer_ = this->create_wall_timer(1s, publish_msg);
  }

private:
  rclcpp::Publisher<more_interfaces::msg::AddressBook>::SharedPtr
      address_book_publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AddressBookPublisher>());
  rclcpp::shutdown();

  return 0;
}
