set(TEST_SOURCE_FILES vec3.cpp img.cpp)
add_library(raytrace STATIC ${TEST_SOURCE_FILES})
target_include_directories(raytrace PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})