# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/C++/LoginAppProject/build/_deps/zlib-src"
  "C:/C++/LoginAppProject/build/_deps/zlib-build"
  "C:/C++/LoginAppProject/build/_deps/zlib-subbuild/zlib-populate-prefix"
  "C:/C++/LoginAppProject/build/_deps/zlib-subbuild/zlib-populate-prefix/tmp"
  "C:/C++/LoginAppProject/build/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp"
  "C:/C++/LoginAppProject/build/_deps/zlib-subbuild/zlib-populate-prefix/src"
  "C:/C++/LoginAppProject/build/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/C++/LoginAppProject/build/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/C++/LoginAppProject/build/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
