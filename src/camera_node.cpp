#include "rclcpp/rclcpp.hpp"
#include "rann/nodes/camera.hpp"
#include "rclcpp/executors/events_executor/events_executor.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto executor = std::make_shared<
    rclcpp::experimental::executors::EventsExecutor>();
  
  auto camera_node = std::make_shared<CameraNode>();

  executor.add_node(camera_node);
  executor.spin();

  rclcpp::shutdown();
  return 0;
}
