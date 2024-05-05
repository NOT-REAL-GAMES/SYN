# Install script for directory: C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Licenses/ThirdParty/DiligentTools" TYPE FILE RENAME "libjpeg-readme.txt" FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/libjpeg-9e/README")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Licenses/ThirdParty/DiligentTools" TYPE FILE RENAME "libtiff-copyright.txt" FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/libtiff/COPYRIGHT")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Licenses/ThirdParty/DiligentTools" TYPE FILE RENAME "zlib-readme.txt" FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/zlib/README")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Licenses/ThirdParty/DiligentTools" TYPE FILE RENAME "lpng-license.txt" FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/libpng/LICENSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Licenses/ThirdParty/DiligentTools" TYPE FILE RENAME "args-license.txt" FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/args/LICENSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Licenses/ThirdParty/DiligentTools" TYPE FILE RENAME "tinygltf-license.txt" FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/tinygltf/LICENSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Licenses/ThirdParty/DiligentTools" TYPE FILE RENAME "imGuIZMO.quat-license.txt" FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/imGuIZMO.quat/license.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Licenses/ThirdParty/DiligentTools" TYPE FILE RENAME "stb-license.txt" FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/stb/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Licenses/ThirdParty/DiligentTools" TYPE FILE RENAME "json-license.txt" FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/json/LICENSE.MIT")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/Licenses/ThirdParty/DiligentTools" TYPE FILE RENAME "imgui-license.txt" FILES "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/imgui/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/Debug" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libjpeg-9e/Debug/LibJpeg.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/Release" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libjpeg-9e/Release/LibJpeg.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/MinSizeRel" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libjpeg-9e/MinSizeRel/LibJpeg.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/RelWithDebInfo" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libjpeg-9e/RelWithDebInfo/LibJpeg.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/Debug" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libtiff/Debug/LibTiff.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/Release" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libtiff/Release/LibTiff.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/MinSizeRel" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libtiff/MinSizeRel/LibTiff.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/RelWithDebInfo" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libtiff/RelWithDebInfo/LibTiff.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/Debug" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/Debug/ZLib.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/Release" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/Release/ZLib.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/MinSizeRel" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/MinSizeRel/ZLib.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/RelWithDebInfo" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/RelWithDebInfo/ZLib.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/Debug" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libpng/Debug/libpng16_staticd.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/Release" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libpng/Release/libpng16_static.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/MinSizeRel" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libpng/MinSizeRel/libpng16_static.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentTools/RelWithDebInfo" TYPE STATIC_LIBRARY FILES "C:/SYN/DiligentTools/ThirdParty/libpng/RelWithDebInfo/libpng16_static.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentTools/ThirdParty/imgui" TYPE FILE FILES
    "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/imgui/imconfig.h"
    "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/imgui/imgui.h"
    "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/imgui/imgui_internal.h"
    "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/imgui/imstb_rectpack.h"
    "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/imgui/imstb_textedit.h"
    "C:/Users/rbwld/Downloads/DiligentEngine_v2.5.4/DiligentEngine_v2.5.4/DiligentTools/ThirdParty/imgui/imstb_truetype.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/SYN/DiligentTools/ThirdParty/libjpeg-9e/cmake_install.cmake")
  include("C:/SYN/DiligentTools/ThirdParty/libtiff/cmake_install.cmake")
  include("C:/SYN/DiligentTools/ThirdParty/libpng/cmake_install.cmake")

endif()

