import os

from ament_index_python_pacakges import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node


def generate_launch_description():
    camera_node_ = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            get_package_share_directory('rann'), 'launch'),
            '/camera_launch.py']),
        )

    return LaunchDescription([
        camera_node_,
        Node(
            package='rann',
            executable='camera_node',
            name='rann_camera_node',
        ),
    ])l
