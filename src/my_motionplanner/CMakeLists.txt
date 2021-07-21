cmake_minimum_required(VERSION 3.0.2)
project(my_motionplanner)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs

  geometry_msgs
  nav_core
  nav_msgs
  tf
)

# find_package(Boost REQUIRED COMPONENTS system)



catkin_package(
    INCLUDE_DIRS include
#   LIBRARIES my_motionplanner
    CATKIN_DEPENDS roscpp rospy std_msgs geometry_msgs nav_core
    nav_msgs tf
#   DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

set(LINK_LIBRARIES
    ${catkin_LIBRARIES}
)

# # Declare a C++ library
# add_library(${PROJECT_NAME}
#     src/my_motionplanner.cpp
# )
## Declare a C++ executable
add_executable(${PROJECT_NAME}_node 
    src/my_motionplanner_node.cpp
)
# Add cmake target dependencies of the executable
add_dependencies(${PROJECT_NAME}_node
    ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
)

# Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}_node    ${LINK_LIBRARIES})

#############
## Install ##
#############

# install(TARGETS ${PROJECT_NAME}

#     ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#     LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#     RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}

# )

install(DIRECTORY launch

    DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  
)
