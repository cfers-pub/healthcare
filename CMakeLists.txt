cmake_minimum_required(VERSION 3.20.1)

#env config
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(Qt5_ROOT "C:/Qt/Qt5.9.7/5.9.7/msvc2015_64/"  CACHE PATH Qt5_ROOT)
set(Qt5_DIR "${Qt5_ROOT}/lib/cmake/Qt5/")

# get root dir name
get_filename_component(root_dir_name_ ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE CACHE)

#define solution
project(${root_dir_name_} VERSION 0.1.2)

# add projects
add_subdirectory(source)