# Install script for directory: C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentCore/Debug" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/Debug/GraphicsEngineOpenGL_64d.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentCore/Release" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/Release/GraphicsEngineOpenGL_64r.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentCore/MinSizeRel" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/MinSizeRel/GraphicsEngineOpenGL_64r.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentCore/RelWithDebInfo" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/RelWithDebInfo/GraphicsEngineOpenGL_64r.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentCore/Debug" TYPE SHARED_LIBRARY FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/Debug/GraphicsEngineOpenGL_64d.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentCore/Release" TYPE SHARED_LIBRARY FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/Release/GraphicsEngineOpenGL_64r.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentCore/MinSizeRel" TYPE SHARED_LIBRARY FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/MinSizeRel/GraphicsEngineOpenGL_64r.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentCore/RelWithDebInfo" TYPE SHARED_LIBRARY FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/RelWithDebInfo/GraphicsEngineOpenGL_64r.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentCore/Graphics/GraphicsEngineOpenGL/" TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentCore/Graphics/GraphicsEngineOpenGL/" TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentCore/Graphics/GraphicsEngineOpenGL/" TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentCore/Graphics/GraphicsEngineOpenGL/interface")
endif()

