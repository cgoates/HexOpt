cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wall -Wextra -Wpedantic)

project(HexOpt)

add_library( HexOpt SHARED
  geometry.cpp
  meshQuality.cpp
  HexOpt.cpp
)

target_include_directories( HexOpt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  target_link_libraries(HexOpt PUBLIC OpenMP::OpenMP_CXX)
  target_compile_definitions(HexOpt PRIVATE USE_OPENMP)
endif()

install(TARGETS HexOpt DESTINATION lib)
install(FILES HexOpt.h DESTINATION include)