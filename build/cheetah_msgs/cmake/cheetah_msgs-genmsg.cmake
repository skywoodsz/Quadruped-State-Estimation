# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "cheetah_msgs: 8 messages, 0 services")

set(MSG_I_FLAGS "-Icheetah_msgs:/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(cheetah_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg" NAME_WE)
add_custom_target(_cheetah_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cheetah_msgs" "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg" ""
)

get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg" NAME_WE)
add_custom_target(_cheetah_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cheetah_msgs" "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg" "cheetah_msgs/LegPrefix:geometry_msgs/Point:geometry_msgs/Vector3:std_msgs/Header"
)

get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg" NAME_WE)
add_custom_target(_cheetah_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cheetah_msgs" "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg" "geometry_msgs/Vector3:geometry_msgs/Point:std_msgs/Header"
)

get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg" NAME_WE)
add_custom_target(_cheetah_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cheetah_msgs" "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg" "cheetah_msgs/LegPrefix:geometry_msgs/Point:geometry_msgs/Vector3:std_msgs/Header"
)

get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg" NAME_WE)
add_custom_target(_cheetah_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cheetah_msgs" "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg" NAME_WE)
add_custom_target(_cheetah_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cheetah_msgs" "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg" "geometry_msgs/Vector3:geometry_msgs/Point:std_msgs/Header:geometry_msgs/Quaternion"
)

get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg" NAME_WE)
add_custom_target(_cheetah_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cheetah_msgs" "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg" NAME_WE)
add_custom_target(_cheetah_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "cheetah_msgs" "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_cpp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_cpp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_cpp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_cpp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_cpp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_cpp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_cpp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(cheetah_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(cheetah_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(cheetah_msgs_generate_messages cheetah_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_cpp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_cpp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_cpp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_cpp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_cpp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_cpp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_cpp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_cpp _cheetah_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cheetah_msgs_gencpp)
add_dependencies(cheetah_msgs_gencpp cheetah_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cheetah_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_eus(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_eus(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_eus(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_eus(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_eus(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_eus(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_eus(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(cheetah_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(cheetah_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(cheetah_msgs_generate_messages cheetah_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_eus _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_eus _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_eus _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_eus _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_eus _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_eus _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_eus _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_eus _cheetah_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cheetah_msgs_geneus)
add_dependencies(cheetah_msgs_geneus cheetah_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cheetah_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_lisp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_lisp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_lisp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_lisp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_lisp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_lisp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_lisp(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(cheetah_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(cheetah_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(cheetah_msgs_generate_messages cheetah_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_lisp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_lisp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_lisp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_lisp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_lisp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_lisp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_lisp _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_lisp _cheetah_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cheetah_msgs_genlisp)
add_dependencies(cheetah_msgs_genlisp cheetah_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cheetah_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_nodejs(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_nodejs(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_nodejs(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_nodejs(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_nodejs(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_nodejs(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_nodejs(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(cheetah_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(cheetah_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(cheetah_msgs_generate_messages cheetah_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_nodejs _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_nodejs _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_nodejs _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_nodejs _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_nodejs _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_nodejs _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_nodejs _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_nodejs _cheetah_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cheetah_msgs_gennodejs)
add_dependencies(cheetah_msgs_gennodejs cheetah_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cheetah_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_py(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_py(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_py(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_py(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_py(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_py(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs
)
_generate_msg_py(cheetah_msgs
  "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(cheetah_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(cheetah_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(cheetah_msgs_generate_messages cheetah_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegPrefix.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_py _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_py _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegsState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_py _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/FeetCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_py _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/JoyCmd.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_py _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/ArmState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_py _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/MotorState.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_py _cheetah_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/skywoodsz/Quadrupted/alienGo_ws/LegSlam_ws/src/cheetah_msgs/msg/LegContact.msg" NAME_WE)
add_dependencies(cheetah_msgs_generate_messages_py _cheetah_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(cheetah_msgs_genpy)
add_dependencies(cheetah_msgs_genpy cheetah_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS cheetah_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/cheetah_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(cheetah_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(cheetah_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/cheetah_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(cheetah_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(cheetah_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/cheetah_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(cheetah_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(cheetah_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/cheetah_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(cheetah_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(cheetah_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/cheetah_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(cheetah_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(cheetah_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
