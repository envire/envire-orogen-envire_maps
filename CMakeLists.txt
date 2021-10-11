PROJECT(envire_maps)
cmake_minimum_required(VERSION 2.6)

SET (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/.orogen/config")

# Default to C++14 (PCL requirement)
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

INCLUDE(envire_mapsBase)

# FIND_PACKAGE(KDL)
# FIND_PACKAGE(OCL)

