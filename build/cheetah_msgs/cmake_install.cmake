# Install script for directory: /home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cheetah_msgs/msg" TYPE FILE FILES
    "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg"
    "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg"
    "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg"
    "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg"
    "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg"
    "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg"
    "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg"
    "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cheetah_msgs/cmake" TYPE FILE FILES "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/build/cheetah_msgs/catkin_generated/installspace/cheetah_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/devel/include/cheetah_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/devel/share/roseus/ros/cheetah_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/devel/share/common-lisp/ros/cheetah_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/devel/share/gennodejs/ros/cheetah_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/devel/lib/python3/dist-packages/cheetah_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/devel/lib/python3/dist-packages/cheetah_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/build/cheetah_msgs/catkin_generated/installspace/cheetah_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cheetah_msgs/cmake" TYPE FILE FILES "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/build/cheetah_msgs/catkin_generated/installspace/cheetah_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cheetah_msgs/cmake" TYPE FILE FILES
    "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/build/cheetah_msgs/catkin_generated/installspace/cheetah_msgsConfig.cmake"
    "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/build/cheetah_msgs/catkin_generated/installspace/cheetah_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cheetah_msgs" TYPE FILE FILES "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/package.xml")
endif()

