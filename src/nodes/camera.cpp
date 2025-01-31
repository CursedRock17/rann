#include "rclcpp/rclcpp.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

namespace rann 
{

CameraNode::CameraNode() : Node("/rann_camera")
{

}

CameraNode::CameraNode(const std::string & node_name, 
                       const rclcpp::NodeOptions & opts)
  : Node(node_name, "rann", opts)
{
    image_scan_original = this->create_subscription<sensor_msgs::msg::Image>(
      "/rann_camera_scan", rclcpp::QoS::SensorDataQoS(), 
      &CameraNode::image_detection);
}

CameraNode::~CameraNode()
{
}

void CameraNode::image_detection(
  const sensor_msgs::msg::Image::SharedPtr & img)
{
    // Setup the time stamp for the current time
    img->header.stamp = this->get_clock()->now();
    img->header.frame_id = "camera_scan";

    // We can now extract the image and use open-cv to process it
}


} // namespace rann
