cmake_minimum_required( VERSION 3.0 )

set( CMAKE_BUILD_TYPE "Debug" CACHE STRING "Project build type" )
set( CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "Install prefix" )
set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH} )
set( EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin" )
set( LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib" )
set( CMAKE_MACOSX_RPATH 1 )
set( CMAKE_VERBOSE_MAKEFILE 1 )

project( cfetch C CXX )

option( CF_BUILD_CF_LIB "Build cfetchlib library"  ON )
option( CF_BUILD_CF_TOOL "Build cfetch tool"  ON )
set( Poco_DIR "" CACHE PATH "Directory containing includes and libraries of Poco" )

#
# OS definitions
#
message( "-- ${CMAKE_PROJECT_NAME} -- System name: ${CMAKE_SYSTEM_NAME}" )
message( "-- ${CMAKE_PROJECT_NAME} -- System version: ${CMAKE_SYSTEM_VERSION}" )

if( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
    set( CF_OS_LINUX TRUE )
elseif( ${CMAKE_SYSTEM_NAME} MATCHES "Darwin" )
    set( CF_OS_OSX TRUE )
elseif( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )
    set( CF_OS_WINDOWS TRUE )
else()
    message( FATAL_ERROR "UNSUPPORTED OS!" )
endif()

#
# Compiler options
#
message( "-- ${CMAKE_PROJECT_NAME} -- Compiler name: ${CMAKE_CXX_COMPILER_ID}" )
message( "-- ${CMAKE_PROJECT_NAME} -- Compiler version: ${CMAKE_CXX_COMPILER_VERSION}" )

if( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" )
    set( CMAKE_CXX_FLAGS "-std=c++11" )
elseif( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" )
    set( CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++" )
else()
    #TODO: investigate what to do on windows
endif()

#
# Enable project folders
#
set_property( GLOBAL PROPERTY USE_FOLDERS ON )
set_property( GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake" )


add_subdirectory( src )
