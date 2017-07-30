add_executable(q1 q1.cpp)
add_executable(q2 q2.cpp)
add_library(q3_lib STATIC q3.h)
# because we don't have a cpp file in the line above, this line tells it that the library is c++
set_target_properties(q3_lib PROPERTIES LINKER_LANGUAGE CXX)
add_executable(q3 q3.cpp)
target_link_libraries(q3 q3_lib)
