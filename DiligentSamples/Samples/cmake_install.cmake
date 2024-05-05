# Install script for directory: C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentSamples/Samples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/SYN/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/SYN/DiligentSamples/Samples/Atmosphere/cmake_install.cmake")
  include("C:/SYN/DiligentSamples/Samples/GLTFViewer/cmake_install.cmake")
  include("C:/SYN/DiligentSamples/Samples/Shadows/cmake_install.cmake")
  include("C:/SYN/DiligentSamples/Samples/ImguiDemo/cmake_install.cmake")
  include("C:/SYN/DiligentSamples/Samples/NuklearDemo/cmake_install.cmake")
  include("C:/SYN/DiligentSamples/Samples/GLFWDemo/cmake_install.cmake")
  include("C:/SYN/DiligentSamples/Samples/Asteroids/cmake_install.cmake")

endif()
