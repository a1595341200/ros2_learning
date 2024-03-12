<!--
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-07 05:50:56
 * @LastEditors: yao.xie 1595341200@qq.com
 * @LastEditTime: 2024-03-12 06:31:16
 * @FilePath: /ros2_learning/README.md
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
-->

- [1. ros2\_learning](#1-ros2_learning)
  - [1.1. 构建](#11-构建)
  - [1.2. 包由哪些组成](#12-包由哪些组成)
    - [1.2.1. cmake](#121-cmake)
    - [1.2.2. python](#122-python)
  - [1.3. 创建一个包](#13-创建一个包)
  - [1.4. 单独构建包](#14-单独构建包)
  - [1.5. 生成自定义消息](#15-生成自定义消息)
  - [1.6. 参数](#16-参数)
  - [1.7. ros2doctor](#17-ros2doctor)
  - [1.8. 创建和使用插件](#18-创建和使用插件)
  - [1.9. 安装依赖](#19-安装依赖)
  - [1.10. action](#110-action)
  - [1.11. 查看广播图](#111-查看广播图)
  - [1.12. launch带参数](#112-launch带参数)
  - [1.13. 测试构建](#113-测试构建)
  - [1.14. URDF](#114-urdf)

# 1. ros2_learning

## 1.1. 构建
```
colcon build
source install/setup.bash
colcon_cd

tips:
如果您不想构建特定的包，请在目录中放置一个名为 COLCON_IGNORE 的空文件，它将不会被索引。
如果您想避免在 CMake 包中配置和构建测试，可以传递：--cmake-args -DBUILD_TESTING=0。
```

如果您想从包中运行单个特定测试

```
colcon test --packages-select YOUR_PKG_NAME --ctest-args -R YOUR_TEST_IN_PKG
```

检查依赖

```
rosdep install -i --from-path src --rosdistro iron -y
```

colcon 构建的其他有用参数：

```
--packages-up-to 构建您想要的包及其所有依赖项，但不是整个工作区（节省时间）
--symlink-install 使您不必每次调整 python 脚本时都重新构建
--event-handlers console_direct+ 在构建时显示控制台输出（否则可以在日志目录中找到）
```

## 1.2. 包由哪些组成

### 1.2.1. cmake

+ CMakeLists.txt 文件，描述如何在包中构建代码include/<package_name> 包含包的公共标头的目录
+ package.xml 文件包含有关包的元信息
+ src 目录包含包的源代码

```
my_package/
     CMakeLists.txt
     include/my_package/
     package.xml
     src/
```

### 1.2.2. python

+ package.xml 文件包含有关包的元信息包
+ resource/<package_name> 标记文件当软件包有可执行文件时需要 
+ setup.cfg，因此 ros2 run 可以找到它们
+ setup.py 包含如何安装包的说明
+ <package_name> 与您的包同名的目录，ROS 2 工具使用它来查找您的包，包含 __init__.py

```
my_package/
      package.xml
      resource/my_package
      setup.cfg
      setup.py
      my_package/
```
## 1.3. 创建一个包

```
ros2 pkg create --build-type ament_cmake --license Apache-2.0 --node-name my_node my_package
ros2 pkg create --build-type ament_python --license Apache-2.0 --node-name my_node my_package
ros2 pkg create --build-type ament_cmake --license Apache-2.0 cpp_srvcli --dependencies rclcpp example_interfaces
```
## 1.4. 单独构建包

```
colcon build --packages-select my_package
```

## 1.5. 生成自定义消息

```
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Num.msg"
  "msg/Sphere.msg"
  "srv/AddThreeInts.srv"
  DEPENDENCIES geometry_msgs # Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
)
```

## 1.6. 参数

通过命令行修改
```
ros2 param set /minimal_param_node my_parameter earth
```

通过launch文件修改
```
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="cpp_parameters",
            executable="minimal_param_node",
            name="custom_minimal_param_node",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"my_parameter": "earth"}
            ]
        )
    ])
```

## 1.7. ros2doctor

```
ros2 doctor --report
```

## 1.8. 创建和使用插件

```
ros2 pkg create --build-type ament_cmake --license Apache-2.0 --dependencies pluginlib --node-name area_node polygon_base

ros2 pkg create --build-type ament_cmake --license Apache-2.0 --dependencies polygon_base pluginlib --library-name polygon_plugins polygon_plugins
colcon build --packages-select polygon_base polygon_plugins
```
## 1.9. 安装依赖

```
rosdep install --from-paths src -y --ignore-src
```
## 1.10. action

```
ros2 pkg create --dependencies custom_action_interfaces rclcpp rclcpp_action rclcpp_components --license Apache-2.0 -- custom_action_cpp
```

## 1.11. 查看广播图

```
ros2 run tf2_tools view_frames
ros2 run tf2_ros tf2_echo world turtle1
ros2 run tf2_ros tf2_monitor turtle2 turtle1
```
## 1.12. launch带参数

```
ros2 launch learning_tf2_cpp turtle_tf2_fixed_frame_demo_launch.py target_frame:=carrot1
或者在launch文件加入
launch_arguments={'target_frame': 'carrot1'}.items(),
```

## 1.13. 测试构建

```
colcon test --ctest-args tests  --packages-select learning_tf2_cpp
colcon test-result --all
colcon test-result --all --verbose
colcon build --cmake-clean-cache --mixin debug
gdb -ex run ./build/rcl/test/test_logging
gdb ./build/rcl/test/test_logging
catch throw
run
```
## 1.14. URDF

```
apt install ros-iron-urdf-launch
apt install  joint_state_publisher-gui
ros2 launch urdf_tutorial display.launch.py model:=urdf/05-visual.urdf
```
