add_executable(q1 q1.cpp)
add_executable(q2 q2.cpp)

add_library(order3 STATIC order3.h order3.cpp)
add_executable(q3 q3.cpp)
target_link_libraries(q3 order3)

add_executable(q3_together q3.cpp order3.h order3.cpp)
