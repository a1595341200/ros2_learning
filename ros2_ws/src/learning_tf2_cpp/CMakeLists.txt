cmake_minimum_required(VERSION 3.8)
project(learning_tf2_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(turtlesim REQUIRED)
add_executable(static_turtle_tf2_broadcaster src/static_turtle_tf2_broadcaster.cpp)
ament_target_dependencies(
   static_turtle_tf2_broadcaster
   geometry_msgs
   rclcpp
   tf2
   tf2_ros
)

add_executable(turtle_tf2_broadcaster src/turtle_tf2_broadcaster.cpp)
ament_target_dependencies(
    turtle_tf2_broadcaster
    geometry_msgs
    rclcpp
    tf2
    tf2_ros
    turtlesim
)

add_executable(turtle_tf2_listener src/turtle_tf2_listener.cpp)
ament_target_dependencies(
    turtle_tf2_listener
    geometry_msgs
    rclcpp
    tf2
    tf2_ros
    turtlesim
)

add_executable(turtle_tf2_listener_debug src/turtle_tf2_listener_debug.cpp)
ament_target_dependencies(
    turtle_tf2_listener_debug
    geometry_msgs
    rclcpp
    tf2
    tf2_ros
    turtlesim
)

install(TARGETS
    turtle_tf2_listener_debug
    DESTINATION lib/${PROJECT_NAME})

add_executable(fixed_frame_tf2_broadcaster src/fixed_frame_tf2_broadcaster.cpp)
ament_target_dependencies(
    fixed_frame_tf2_broadcaster
    geometry_msgs
    rclcpp
    tf2_ros
)

add_executable(dynamic_frame_tf2_broadcaster src/dynamic_frame_tf2_broadcaster.cpp)
ament_target_dependencies(
    dynamic_frame_tf2_broadcaster
    geometry_msgs
    rclcpp
    tf2_ros
)

install(TARGETS
    dynamic_frame_tf2_broadcaster
    DESTINATION lib/${PROJECT_NAME})

install(TARGETS
    fixed_frame_tf2_broadcaster
    DESTINATION lib/${PROJECT_NAME})

install(TARGETS
    turtle_tf2_listener
    DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

install(TARGETS
    turtle_tf2_broadcaster
    DESTINATION lib/${PROJECT_NAME})

install(TARGETS
   static_turtle_tf2_broadcaster
   DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
   find_package(ament_cmake_gtest REQUIRED)
   ament_add_gtest(${PROJECT_NAME}_tutorial_test test/tutorial_test.cpp)
   target_include_directories(${PROJECT_NAME}_tutorial_test PUBLIC
     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
     $<INSTALL_INTERFACE:include>
   )
   ament_target_dependencies(${PROJECT_NAME}_tutorial_test
     std_msgs
   )
#    target_link_libraries(${PROJECT_NAME}_tutorial_test name_of_local_library)
endif()

ament_package()
