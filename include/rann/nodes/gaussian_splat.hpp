#ifndef RANN__NODES__GAUSSIAN_SPLAT_HPP_
#define RANN__NODES__GAUSSIAN_SPLAT_HPP_

#include <functional>
#include <string>
#include <utility>
#include <vector>

#include "rclcpp/node_options.hpp"
#include "rclcpp/publisher.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp/qos.hpp"

#include "rann/visibility_control.h"

#include "sensor_msgs/msg/point_cloud2.hpp"

namespace rann {

class GaussianSplatNode : public rclcpp::Node
{
public:
GaussianSplatNode();
GaussianSplatNode(const std::string & node_name, const rclcpp::NodeOptions & opts);
~GaussianSplatNode();

private:
rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr image_scan_original;

void scan_environment(const sensor_msgs::msg::PointCloud2 & point_cloud);

};

} // namespace rann

#endif // RANN__NODES__GAUSSIAN_SPLAT_HPP_
