cmake_minimum_required(VERSION 3.20)
project(globalplatform_consumer C)

find_package(globalplatform CONFIG REQUIRED)
find_package(gppcscconnectionplugin CONFIG REQUIRED)

add_executable(test_gp main.c)
target_link_libraries(test_gp PRIVATE globalplatform::globalplatform)
target_link_libraries(test_gp PRIVATE gppcscconnectionplugin::gppcscconnectionplugin)

get_target_property(_type globalplatform::globalplatform TYPE)
