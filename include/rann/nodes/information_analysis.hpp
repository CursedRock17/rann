#ifndef RANN__NODES__INFORMATION_ANALYSIS_HPP_
#define RANN__NODES__INFORMATION_ANALYSIS_HPP_

#include <functional>
#include <string>
#include <utility>
#include <vector>

#include "rclcpp/node_options.hpp"
#include "rclcpp/publisher.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp/qos.hpp"

#include "rann/visibility_control.h"

#include "std_msgs/msg/string.hpp"

namespace rann {

// This node will be the brains of the operation
// I.E. the user tells the robot what they want it to do from which
// We can process this information to make decisions
class InformationAnalysisNode : public rclcpp::Node
{
public:
InformationAnalysisNode();
InformationAnalysisNode(const std::string & node_name, const rclcpp::NodeOptions & opts);
~InformationAnalysisNode();

private:
rclcpp::Subscription<std_msgs::msg::String>::SharedPtr information_sub;

void acquire_info(const std_msgs::msg::String & info_string);

};

} // namespace rann

#endif // RANN__NODES__INFORMATION_ANALYSIS_HPP_
