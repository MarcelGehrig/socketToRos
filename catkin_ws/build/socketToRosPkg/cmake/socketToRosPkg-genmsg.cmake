# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "socketToRosPkg: 1 messages, 0 services")

set(MSG_I_FLAGS "-IsocketToRosPkg:/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(socketToRosPkg_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg" NAME_WE)
add_custom_target(_socketToRosPkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "socketToRosPkg" "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(socketToRosPkg
  "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/socketToRosPkg
)

### Generating Services

### Generating Module File
_generate_module_cpp(socketToRosPkg
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/socketToRosPkg
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(socketToRosPkg_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(socketToRosPkg_generate_messages socketToRosPkg_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg" NAME_WE)
add_dependencies(socketToRosPkg_generate_messages_cpp _socketToRosPkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(socketToRosPkg_gencpp)
add_dependencies(socketToRosPkg_gencpp socketToRosPkg_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS socketToRosPkg_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(socketToRosPkg
  "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/socketToRosPkg
)

### Generating Services

### Generating Module File
_generate_module_eus(socketToRosPkg
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/socketToRosPkg
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(socketToRosPkg_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(socketToRosPkg_generate_messages socketToRosPkg_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg" NAME_WE)
add_dependencies(socketToRosPkg_generate_messages_eus _socketToRosPkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(socketToRosPkg_geneus)
add_dependencies(socketToRosPkg_geneus socketToRosPkg_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS socketToRosPkg_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(socketToRosPkg
  "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/socketToRosPkg
)

### Generating Services

### Generating Module File
_generate_module_lisp(socketToRosPkg
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/socketToRosPkg
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(socketToRosPkg_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(socketToRosPkg_generate_messages socketToRosPkg_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg" NAME_WE)
add_dependencies(socketToRosPkg_generate_messages_lisp _socketToRosPkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(socketToRosPkg_genlisp)
add_dependencies(socketToRosPkg_genlisp socketToRosPkg_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS socketToRosPkg_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(socketToRosPkg
  "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/socketToRosPkg
)

### Generating Services

### Generating Module File
_generate_module_nodejs(socketToRosPkg
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/socketToRosPkg
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(socketToRosPkg_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(socketToRosPkg_generate_messages socketToRosPkg_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg" NAME_WE)
add_dependencies(socketToRosPkg_generate_messages_nodejs _socketToRosPkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(socketToRosPkg_gennodejs)
add_dependencies(socketToRosPkg_gennodejs socketToRosPkg_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS socketToRosPkg_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(socketToRosPkg
  "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/socketToRosPkg
)

### Generating Services

### Generating Module File
_generate_module_py(socketToRosPkg
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/socketToRosPkg
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(socketToRosPkg_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(socketToRosPkg_generate_messages socketToRosPkg_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mgehrig2/git_repos/socketToRos/catkin_ws/src/socketToRosPkg/msg/float64_header.msg" NAME_WE)
add_dependencies(socketToRosPkg_generate_messages_py _socketToRosPkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(socketToRosPkg_genpy)
add_dependencies(socketToRosPkg_genpy socketToRosPkg_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS socketToRosPkg_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/socketToRosPkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/socketToRosPkg
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(socketToRosPkg_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/socketToRosPkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/socketToRosPkg
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(socketToRosPkg_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/socketToRosPkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/socketToRosPkg
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(socketToRosPkg_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/socketToRosPkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/socketToRosPkg
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(socketToRosPkg_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/socketToRosPkg)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/socketToRosPkg\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/socketToRosPkg
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(socketToRosPkg_generate_messages_py std_msgs_generate_messages_py)
endif()
