'''
Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
Date: 2024-03-11 14:52:37
LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
LastEditTime: 2024-03-11 14:55:16
FilePath: /ros2_learning/ros2_ws/src/cpp_launch_example/launch/my_script_launch.py
Description: 

Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
'''
import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='demo_nodes_cpp',
            executable='talker',
            name='talker'),
  ])
