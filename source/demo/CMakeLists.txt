add_executable(demo.hello hello.cpp)
add_test(test.demo.hello demo.hello)

add_library(demo.employee OBJECT employee.cpp)
