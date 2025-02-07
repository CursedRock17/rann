#include <utility>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "rann/nodes/camera.hpp"
#include "rclcpp/experimental/executors/events_executor/events_executor.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto node_opts = rclcpp::NodeOptions();
  auto camera_node = std::make_shared<rann::CameraNode>("rann_camera", 
    node_opts);

  // Use the EventsExecutor to create an events queue
  auto executor = std::make_shared<
    rclcpp::experimental::executors::EventsExecutor>();
  
  executor->add_node(camera_node);
  executor->spin();
  executor->remove_node(camera_node);

  rclcpp::shutdown();
  return 0;
}
