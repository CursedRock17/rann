#ifndef RANN__NODES__CAMERA_HPP_
#define RANN__NODES__CAMERA_HPP_

#include <functional>
#include <string>
#include <utility>
#include <vector>

#include "rclcpp/node_options.hpp"
#include "rclcpp/publisher.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp/qos.hpp"

#include "sensor_msgs/msg/image.hpp"

/*
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
*/

namespace rann {

class CameraNode : public rclcpp::Node
{
public:
CameraNode();
CameraNode(const std::string & node_name, const rclcpp::NodeOptions & opts);
~CameraNode();

private:
rclcpp::Subscription<sensor_msgs::msg:::Image>::SharedPtr image_scan_original;
rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_detection_new;

void image_detection(const sensor_msgs::msg::Image::SharedPtr & img);


};

} // namespace rann

// RANN__NODES__CAMERA_HPP_
