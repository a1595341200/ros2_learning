'''
Author: yao.xie 1595341200@qq.com
Date: 2024-03-12 03:44:45
LastEditors: yao.xie 1595341200@qq.com
LastEditTime: 2024-03-12 03:44:50
FilePath: /ros2_learning/ros2_ws/src/learning_tf2_cpp/launch/start_tf2_debug_demo_launch.py
Description: 

Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
'''
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

from launch_ros.actions import Node

def generate_launch_description():
   return LaunchDescription([
      DeclareLaunchArgument(
         'target_frame', default_value='turtle1',
         description='Target frame name.'
      ),
      Node(
         package='turtlesim',
         executable='turtlesim_node',
         name='sim',
         output='screen'
      ),
      Node(
         package='learning_tf2_cpp',
         executable='turtle_tf2_broadcaster',
         name='broadcaster1',
         parameters=[
               {'turtlename': 'turtle1'}
         ]
      ),
      Node(
         package='learning_tf2_cpp',
         executable='turtle_tf2_broadcaster',
         name='broadcaster2',
         parameters=[
               {'turtlename': 'turtle2'}
         ]
      ),
      Node(
         package='learning_tf2_cpp',
         executable='turtle_tf2_listener_debug',
         name='listener_debug',
         parameters=[
               {'target_frame': LaunchConfiguration('target_frame')}
         ]
      ),
   ])
