#add_definitions(-std=c++0x)
#find_package(Boost 1.62.0 COMPONENTS filesystem system REQUIRED)
#include_directories(${Boost_INCLUDE_DIRS})

FIND_PACKAGE(Boost) 
LINK_DIRECTORIES(${LINK_DIRECTORIES} ${Boost_LIBRARY_DIRS})
INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS})

add_subdirectory(helloboost)