# Install script for directory: C:/SYN/diligent/DiligentFX

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentFX/Debug" TYPE STATIC_LIBRARY FILES "C:/SYN/diligent/DiligentFX/Debug/DiligentFX.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentFX/Release" TYPE STATIC_LIBRARY FILES "C:/SYN/diligent/DiligentFX/Release/DiligentFX.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentFX/MinSizeRel" TYPE STATIC_LIBRARY FILES "C:/SYN/diligent/DiligentFX/MinSizeRel/DiligentFX.lib")
  elseif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/DiligentFX/RelWithDebInfo" TYPE STATIC_LIBRARY FILES "C:/SYN/diligent/DiligentFX/RelWithDebInfo/DiligentFX.lib")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentFX/PostProcess/EpipolarLightScattering" TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentFX/PostProcess/EpipolarLightScattering/interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentFX/PostProcess/TemporalAntiAliasing" TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentFX/PostProcess/TemporalAntiAliasing/interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentFX/PostProcess/ScreenSpaceReflection" TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentFX/PostProcess/ScreenSpaceReflection/interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentFX/PostProcess/ScreenSpaceAmbientOcclusion" TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentFX/PostProcess/ScreenSpaceAmbientOcclusion/interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentFX/PostProcess/Bloom" TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentFX/PostProcess/Bloom/interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentFX/Components" TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentFX/Components/interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/DiligentFX/PBR" TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentFX/PBR/interface")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE DIRECTORY FILES "C:/SYN/diligent/DiligentFX/Shaders" FILES_MATCHING REGEX "/public\\/[^/]*\\.[^/]*$" REGEX "/private$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/SYN/diligent/DiligentFX/Utilities/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentFX/Components/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentFX/PostProcess/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentFX/PBR/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentFX/Tests/cmake_install.cmake")

endif()

