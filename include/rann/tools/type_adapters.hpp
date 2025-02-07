#ifndef RANN__TOOLS__TYPE_ADAPTERS_HPP_
#define RANN__TOOLS__TYPE_ADAPTERS_HPP_

#include <vector>
#include <utility>
#include <string>

#include "opencv2/core.hpp"

#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/header.hpp"

#include "rclcpp/type_adapter.hpp"
/*

template<>
struct rclcpp::TypeAdapter<
  cv::Mat,
  sensor_msgs::msg::Image 
>
{
  // Since OpenCV has no "Image" class, we must rely on cv::Mat
  using custom_type = cv::Mat;
  using ros_message_type = sensor_msgs::msg::Image;

  static
  void 
  convert_to_ros_message(
    const custom_type & source,
    ros_message_type & destination)
  {
    destination.height = source.rows;
    destination.width = source.cols;
    destination.encoding = source.type();
    destination.is_bigendian = 0;  // Data is not big endian 
    destination.step = source.step();  // get the size of the step struct
    destination.data = source.data;  // May have to extract data
  }

  static 
  void 
  convert_to_custom(
    const ros_message_type & source,
    custom_type & destination)
  {
      destination.create(source.height, source.width, source.encoding);
      destination.step = source.step;
      destination.data = source.data;
  }
};

*/

#endif  // RANN__TOOLS__TYPE_ADAPTERS_HPP_
