cmake_minimum_required(VERSION 3.0.2)
project(aliengo_control)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# release
SET(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_FLAGS "-O3 -fPIC")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  realtime_tools
  tf2_ros
  cheetah_msgs
)
find_package(Eigen3 REQUIRED)

catkin_package(
        INCLUDE_DIRS include
        LIBRARIES aliengo_control
        CATKIN_DEPENDS roscpp 
        DEPENDS
)

###########
## Build ##
###########

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR}
)
link_directories(lib)
set(EXTRA_LIBS -pthread libunitree_legged_sdk_x86.so lcm)

add_library(aliengo_control
        src/aliengo_control.cpp
        )
target_link_libraries(aliengo_control
        ${catkin_LIBRARIES}
        ${EXTRA_LIBS}
        )

add_library(aliengo_low_level
        src/aliengo_low_level.cpp
)
target_link_libraries(aliengo_low_level
        ${catkin_LIBRARIES}
        ${EXTRA_LIBS}
        )

###########
##  EXE  ##
###########

add_executable(aliengo_control_node
        src/aliengo_control_node.cpp
)
target_link_libraries(aliengo_control_node
        aliengo_control
)

add_executable(aliengo_low_level_node
        src/aliengo_low_level_node.cpp
)
target_link_libraries(aliengo_low_level_node
        aliengo_low_level
)





