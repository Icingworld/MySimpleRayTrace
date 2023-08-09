add_executable(main main.cpp)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/raytrace)
target_link_libraries(main PRIVATE raytrace)
