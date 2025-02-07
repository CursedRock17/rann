#include "rclcpp/rclcpp.hpp"

#include "rann/nodes/information_analysis.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

namespace rann 
{

InformationAnalysisNode::InformationAnalysisNode() : Node("rann_information_analysis")
{

}

InformationAnalysisNode::InformationAnalysisNode(const std::string & node_name, 
                       const rclcpp::NodeOptions & opts)
  : Node(node_name, "rann", opts)
{
    information_sub= this->create_subscription<std_msgs::msg::String>(
      "rann_information_analysis_acquisition", rclcpp::SensorDataQoS(), 
      std::bind(&InformationAnalysisNode::acquire_info, this, _1));
}

InformationAnalysisNode::~InformationAnalysisNode()
{
}

void InformationAnalysisNode::acquire_info(
    const std_msgs::msg::String & info_string)
{
    // Do something with this speech/text
}

} // namespace rann
