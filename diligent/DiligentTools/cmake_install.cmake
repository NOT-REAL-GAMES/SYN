# Install script for directory: C:/SYN/diligent/DiligentTools

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/Debug" TYPE FILE FILES "C:/SYN/diligent/DiligentTools/Debug/DiligentTools.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/Release" TYPE FILE FILES "C:/SYN/diligent/DiligentTools/Release/DiligentTools.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/MinSizeRel" TYPE FILE FILES "C:/SYN/diligent/DiligentTools/MinSizeRel/DiligentTools.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/RelWithDebInfo" TYPE FILE FILES "C:/SYN/diligent/DiligentTools/RelWithDebInfo/DiligentTools.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/SYN/diligent/DiligentTools/ThirdParty/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentTools/TextureLoader/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentTools/AssetLoader/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentTools/Imgui/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentTools/NativeApp/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentTools/HLSL2GLSLConverter/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentTools/RenderStateNotation/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentTools/RenderStatePackager/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentTools/Tests/cmake_install.cmake")

endif()

