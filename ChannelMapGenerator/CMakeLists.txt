cmake_minimum_required(VERSION 3.5)

project(ChannelMap LANGUAGES CXX)

file(GLOB HEADERS_HPP ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_executable(ChannelMapGenerator
  main.cpp
  ${HEADERS}
)

target_include_directories(ChannelMapGenerator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

