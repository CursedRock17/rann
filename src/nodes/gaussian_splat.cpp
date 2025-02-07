#include "rclcpp/rclcpp.hpp"

#include "rann/nodes/gaussian_splat.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

namespace rann 
{

GaussianSplatNode::GaussianSplatNode() : Node("rann_gaussian_splat")
{

}

GaussianSplatNode::GaussianSplatNode(const std::string & node_name, 
                       const rclcpp::NodeOptions & opts)
  : Node(node_name, "rann", opts)
{
    image_scan_original = this->create_subscription<
      sensor_msgs::msg::PointCloud2>(
      "rann_gaussian_splat_scan", rclcpp::SensorDataQoS(), 
      std::bind(&GaussianSplatNode::scan_environment, this, _1));
}

GaussianSplatNode::~GaussianSplatNode()
{
}

void GaussianSplatNode::scan_environment(
  const sensor_msgs::msg::PointCloud2 & point_cloud)
{
}

} // namespace rann
