#include "rclcpp/rclcpp.hpp"

#include "rann/nodes/camera.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

namespace rann 
{

CameraNode::CameraNode() : Node("rann_camera")
{

}

CameraNode::CameraNode(const std::string & node_name, 
                       const rclcpp::NodeOptions & opts)
  : Node(node_name, "rann", opts)
{
    image_scan_original = this->create_subscription<sensor_msgs::msg::Image>(
      "rann_camera_scan", rclcpp::SensorDataQoS(), 
      std::bind(&CameraNode::image_detection, this, _1));
}

CameraNode::~CameraNode()
{
}

void CameraNode::image_detection(
  const sensor_msgs::msg::Image & img)
{
    // We can now extract the image and use open-cv to process it
    process_network("some_network.onnx", img);
}


void CameraNode::process_network(const std::string & model_path,
  const sensor_msgs::msg::Image & img)
{
    // Create a Network from the generated nn
    cv::dnn::Net net = cv::dnn::readNet(model_path);
    
    // Read the incoming image and extract the data (pre-process)
    cv::Size_<uint32_t> size(img.width, img.height);
    cv::Scalar scale;
    cv::Scalar mean;

}


} // namespace rann
