# CMake 3.18 due to https://gitlab.kitware.com/cmake/cmake/-/issues/20764
cmake_minimum_required(VERSION 3.18)

if(DEFINED DEPENDENCIES_DIR)
	include(${DEPENDENCIES_DIR}/modorganizer_super/cmake_common/mo2.cmake)
else()
	include(${CMAKE_CURRENT_LIST_DIR}/../cmake_common/mo2.cmake)
endif()

# set globally as Nuget gets confused about ZERO_CHECK, ALL_BUILD and INSTALL otherwise
set(CMAKE_DOTNET_TARGET_FRAMEWORK_VERSION "v4.8")

project(installer_omod LANGUAGES CXX CSharp)

add_subdirectory(src)
