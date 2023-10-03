cmake_minimum_required(VERSION 3.10)

# set the project name
project(HELLO VERSION 1.0)


set(CMAKE_MODULE_PATH "${HELLO_SOURCE_DIR}/Modules")
message(${CMAKE_MODULE_PATH})

# find PETSc
find_package(PETSc REQUIRED)
message(STATUS "Found PETSc version ${PETSC_VERSION}")
include_directories(${PETSC_INCLUDES})

# use HDF5 macro
include(MyFindHDF5)
# define include directories
include_directories(${HDF5_INCLUDE_DIRS})

# add the executable
add_executable(hello_project src/hello_project.cpp)

# enable GSl library linkage
target_link_libraries(hello_project ${HDF5_LIBRARIES} ${PETSC_LIBRARIES})


