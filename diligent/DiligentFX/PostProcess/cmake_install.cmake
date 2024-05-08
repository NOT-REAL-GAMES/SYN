# Install script for directory: C:/SYN/diligent/DiligentFX/PostProcess

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/SYN/diligent/install")
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
  include("C:/SYN/diligent/DiligentFX/PostProcess/Common/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentFX/PostProcess/EpipolarLightScattering/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentFX/PostProcess/TemporalAntiAliasing/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentFX/PostProcess/ScreenSpaceReflection/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentFX/PostProcess/ScreenSpaceAmbientOcclusion/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentFX/PostProcess/Bloom/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentFX/PostProcess/DepthOfField/cmake_install.cmake")

endif()

