# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-src"
  "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-build"
  "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-subbuild/jsoncpp-populate-prefix"
  "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-subbuild/jsoncpp-populate-prefix/tmp"
  "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-subbuild/jsoncpp-populate-prefix/src/jsoncpp-populate-stamp"
  "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-subbuild/jsoncpp-populate-prefix/src"
  "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-subbuild/jsoncpp-populate-prefix/src/jsoncpp-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-subbuild/jsoncpp-populate-prefix/src/jsoncpp-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/Programming/c++/H2-shock/cmake-build-debug/_deps/jsoncpp-subbuild/jsoncpp-populate-prefix/src/jsoncpp-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
