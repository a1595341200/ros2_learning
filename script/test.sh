$ export FASTRTPS_DEFAULT_PROFILES_FILE="no_intraprocess_configuration.xml"
###
 # @Author: yao.xie 1595341200@qq.com
 # @Date: 2024-03-12 08:03:54
 # @LastEditors: yao.xie 1595341200@qq.com
 # @LastEditTime: 2024-03-12 08:03:58
 # @FilePath: /ros2_learning/script/test.sh
 # @Description: 
 # 
 # Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
### 
$ sudo bash generate_discovery_packages.bash ~/ros2/install/local_setup.bash
$ sudo bash generate_discovery_packages.bash ~/ros2/install/local_setup.bash SERVER
$ python3 discovery_packets.py
