# Install script for directory: C:/SYN/diligent/DiligentSamples/Tutorials

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
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial00_HelloWin32/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial01_HelloTriangle/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial02_Cube/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial03_Texturing/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial03_Texturing-C/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial03_Texturing-DotNet/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial04_Instancing/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial05_TextureArray/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial06_Multithreading/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial07_GeometryShader/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial08_Tessellation/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial09_Quads/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial10_DataStreaming/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial11_ResourceUpdates/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial12_RenderTarget/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial13_ShadowMap/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial14_ComputeShader/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial15_MultipleWindows/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial16_BindlessResources/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial17_MSAA/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial18_Queries/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial19_RenderPasses/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial20_MeshShader/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial21_RayTracing/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial22_HybridRendering/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial23_CommandQueues/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial24_VRS/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial25_StatePackager/cmake_install.cmake")
  include("C:/SYN/diligent/DiligentSamples/Tutorials/Tutorial26_StateCache/cmake_install.cmake")

endif()

