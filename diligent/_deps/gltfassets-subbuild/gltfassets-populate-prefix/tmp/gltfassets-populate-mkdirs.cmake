# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/SYN/diligent/DiligentSamples/Samples/GLTFViewer/assets/models"
  "C:/SYN/diligent/_deps/gltfassets-build"
  "C:/SYN/diligent/_deps/gltfassets-subbuild/gltfassets-populate-prefix"
  "C:/SYN/diligent/_deps/gltfassets-subbuild/gltfassets-populate-prefix/tmp"
  "C:/SYN/diligent/_deps/gltfassets-subbuild/gltfassets-populate-prefix/src/gltfassets-populate-stamp"
  "C:/SYN/diligent/_deps/gltfassets-subbuild/gltfassets-populate-prefix/src"
  "C:/SYN/diligent/_deps/gltfassets-subbuild/gltfassets-populate-prefix/src/gltfassets-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/SYN/diligent/_deps/gltfassets-subbuild/gltfassets-populate-prefix/src/gltfassets-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/SYN/diligent/_deps/gltfassets-subbuild/gltfassets-populate-prefix/src/gltfassets-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
