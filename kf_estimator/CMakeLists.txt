cmake_minimum_required(VERSION 3.0.2)
project(kf_estimator)

## Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_BUILD_TYPE "Release")

find_package(catkin REQUIRED
        COMPONENTS
        roscpp
        realtime_tools
        cheetah_msgs
        tf2_ros
        )

find_package(PkgConfig REQUIRED)
pkg_check_modules(pinocchio REQUIRED pinocchio)

catkin_package(
        INCLUDE_DIRS
        include
        LIBRARIES
        ${PROJECT_NAME}
        CATKIN_DEPENDS
        roscpp
)

###########
## Build ##
###########

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${pinocchio_INCLUDE_DIRS}
)

link_directories(
        ${pinocchio_LIBRARY_DIRS}
)

add_library(${PROJECT_NAME}
        src/kf_estimator.cpp
        src/state_estimate.cpp
        )

target_link_libraries(${PROJECT_NAME}
        ${catkin_LIBRARIES}
        ${pinocchio_LIBRARIES}
        )

###########
##  EXE  ##
###########
add_executable(kf_estimator_node
        src/kf_estimator_node.cpp
        )
target_link_libraries(kf_estimator_node
        ${PROJECT_NAME}
        )

###########
##  TEST ##
###########
add_executable(debug_test
        src/debug_test.cpp
        )
target_link_libraries(debug_test
        ${PROJECT_NAME}
        )
