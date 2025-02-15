cmake_minimum_required(VERSION 3.8)
project(rann)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(geometry2 REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
#find_package(rmw_zenoh_cpp REQUIRED)

# Develop a backend library which hooks up the nodes to the frontend
# We can develop all of the source files, then combine with the headers
add_library(nodes src/nodes/camera.cpp src/nodes/gaussian_splat.cpp
  src/nodes/information_analysis.cpp) 
add_library(rann::nodes ALIAS nodes)
target_compile_features(nodes PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(nodes PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
ament_target_dependencies(
  nodes 
  "rclcpp"
  "OpenCV"
  "geometry2"
  "geometry_msgs"
  "sensor_msgs"
  #  "rmw_zenoh_cpp"
)

# Create a header only reference to the Type Adapters
add_library(type_adapters include/rann/tools/type_adapters.hpp)
set_target_properties(type_adapters PROPERTIES LINKER_LANGUAGE CXX)
target_compile_features(type_adapters PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(type_adapters PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
ament_target_dependencies(
  type_adapters
  "rclcpp"
  "OpenCV"
  "sensor_msgs"
)

add_library(backend src/backend.cpp)
add_library(rann::backend ALIAS backend)
target_compile_features(backend PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(backend PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
ament_target_dependencies(
  backend
  "rclcpp"
  "geometry2"
  #  "rmw_zenoh_cpp"
)

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(backend PRIVATE "rann_BUILDING_LIBRARY")
target_compile_definitions(nodes PRIVATE "rann_BUILDING_LIBRARY")
target_compile_definitions(type_adapters PRIVATE "rann_BUILDING_LIBRARY")

# Install each of the backend libraries
install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)
install(
  TARGETS backend
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
install(
  TARGETS nodes 
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
install(
  TARGETS type_adapters 
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# Create an additional install through our launch directory
#install(
#  DIRECTORY launch 
#  DESTINATION share/${PROJECT_NAME}
#)

# Create a single running executable for our main node 
# TOOD() replace with launch file system
add_executable(camera_node src/camera_node.cpp)
target_include_directories(camera_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_link_libraries(camera_node backend nodes type_adapters)

install(TARGETS camera_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(
  "include/${PROJECT_NAME}"
)
ament_export_libraries(
  backend
  nodes
  type_adapters
)
ament_export_targets(
  export_${PROJECT_NAME}
)

ament_package()
