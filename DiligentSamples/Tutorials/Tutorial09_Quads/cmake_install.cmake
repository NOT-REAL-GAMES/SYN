# Install script for directory: C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentSamples/Tutorials/Tutorial09_Quads

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Debug" TYPE EXECUTABLE FILES "C:/SYN/DiligentSamples/Tutorials/Tutorial09_Quads/Debug/Tutorial09_Quads.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Release" TYPE EXECUTABLE FILES "C:/SYN/DiligentSamples/Tutorials/Tutorial09_Quads/Release/Tutorial09_Quads.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel" TYPE EXECUTABLE FILES "C:/SYN/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel/Tutorial09_Quads.exe")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo" TYPE EXECUTABLE FILES "C:/SYN/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo/Tutorial09_Quads.exe")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    include("C:/SYN/DiligentSamples/Tutorials/Tutorial09_Quads/CMakeFiles/Tutorial09_Quads.dir/install-cxx-module-bmi-Debug.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    include("C:/SYN/DiligentSamples/Tutorials/Tutorial09_Quads/CMakeFiles/Tutorial09_Quads.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    include("C:/SYN/DiligentSamples/Tutorials/Tutorial09_Quads/CMakeFiles/Tutorial09_Quads.dir/install-cxx-module-bmi-MinSizeRel.cmake" OPTIONAL)
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    include("C:/SYN/DiligentSamples/Tutorials/Tutorial09_Quads/CMakeFiles/Tutorial09_Quads.dir/install-cxx-module-bmi-RelWithDebInfo.cmake" OPTIONAL)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Debug" TYPE DIRECTORY FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentSamples/Tutorials/Tutorial09_Quads/assets/")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Release" TYPE DIRECTORY FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentSamples/Tutorials/Tutorial09_Quads/assets/")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel" TYPE DIRECTORY FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentSamples/Tutorials/Tutorial09_Quads/assets/")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo" TYPE DIRECTORY FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentSamples/Tutorials/Tutorial09_Quads/assets/")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Debug" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D11/Debug/GraphicsEngineD3D11_64d.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Release" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D11/Release/GraphicsEngineD3D11_64r.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D11/MinSizeRel/GraphicsEngineD3D11_64r.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D11/RelWithDebInfo/GraphicsEngineD3D11_64r.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Debug" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D11/Debug/GraphicsEngineD3D11_64d.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Release" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D11/Release/GraphicsEngineD3D11_64r.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D11/MinSizeRel/GraphicsEngineD3D11_64r.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D11/RelWithDebInfo/GraphicsEngineD3D11_64r.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Debug" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D12/Debug/GraphicsEngineD3D12_64d.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Release" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D12/Release/GraphicsEngineD3D12_64r.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D12/MinSizeRel/GraphicsEngineD3D12_64r.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D12/RelWithDebInfo/GraphicsEngineD3D12_64r.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Debug" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D12/Debug/GraphicsEngineD3D12_64d.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Release" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D12/Release/GraphicsEngineD3D12_64r.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D12/MinSizeRel/GraphicsEngineD3D12_64r.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineD3D12/RelWithDebInfo/GraphicsEngineD3D12_64r.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Debug" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineOpenGL/Debug/GraphicsEngineOpenGL_64d.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Release" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineOpenGL/Release/GraphicsEngineOpenGL_64r.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineOpenGL/MinSizeRel/GraphicsEngineOpenGL_64r.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineOpenGL/RelWithDebInfo/GraphicsEngineOpenGL_64r.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Debug" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineOpenGL/Debug/GraphicsEngineOpenGL_64d.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Release" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineOpenGL/Release/GraphicsEngineOpenGL_64r.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineOpenGL/MinSizeRel/GraphicsEngineOpenGL_64r.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineOpenGL/RelWithDebInfo/GraphicsEngineOpenGL_64r.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Debug" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineVulkan/Debug/GraphicsEngineVk_64d.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Release" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineVulkan/Release/GraphicsEngineVk_64r.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineVulkan/MinSizeRel/GraphicsEngineVk_64r.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineVulkan/RelWithDebInfo/GraphicsEngineVk_64r.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Debug" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineVulkan/Debug/GraphicsEngineVk_64d.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/Release" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineVulkan/Release/GraphicsEngineVk_64r.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/MinSizeRel" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineVulkan/MinSizeRel/GraphicsEngineVk_64r.dll")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/DiligentSamples/Tutorials/Tutorial09_Quads/RelWithDebInfo" TYPE SHARED_LIBRARY FILES "C:/SYN/DiligentCore/Graphics/GraphicsEngineVulkan/RelWithDebInfo/GraphicsEngineVk_64r.dll")
  endif()
endif()

