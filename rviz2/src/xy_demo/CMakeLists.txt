cmake_minimum_required(VERSION 3.8)
project(xy_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_AUTOMOC ON)
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rviz_common REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(rviz_ogre_vendor REQUIRED)

# qt5_wrap_cpp(src_MOCS include/xy_demo/MyTest.h)
pluginlib_export_plugin_description_file(rviz_common plugins_description.xml)
include_directories(
  include
)
add_library(${PROJECT_NAME} SHARED src/MyTest.cpp src/SelectTest.cpp include/xy_demo/MyTest.h)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
# prevent pluginlib from using boost
# target_compile_definitions(${PROJECT_NAME} PUBLIC "PLUGINLIB__DISABLE_BOOST_FUNCTIONS")
target_compile_definitions(${PROJECT_NAME} PRIVATE "RVIZ_DEFAULT_PLUGINS_BUILDING_LIBRARY")
ament_target_dependencies(${PROJECT_NAME}   
  rclcpp   
  rviz_common 
  pluginlib
  visualization_msgs
  rviz_ogre_vendor
)
target_compile_definitions(${PROJECT_NAME} PRIVATE "POLYGON_PLUGINS_BUILDING_LIBRARY")
install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()
# # 在ament中导出项目的头文件、库、目标和依赖项
# ament_export_include_directories(include) # 将include目录中的头文件导出
ament_export_libraries(${PROJECT_NAME}) # 将项目名称指定的库导出
ament_export_targets(${PROJECT_NAME} ) # 将项目名称指定的目标导出
ament_export_dependencies(
      rclcpp   
      rviz_common 
      pluginlib
      visualization_msgs
      rviz_ogre_vendor
) # 将此包的依赖项导出
ament_package()
