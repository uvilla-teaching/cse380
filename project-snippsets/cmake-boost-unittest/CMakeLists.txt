cmake_minimum_required(VERSION 3.10)
project(MyProject)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
add_subdirectory(tests)

