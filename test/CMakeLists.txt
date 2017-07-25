file(TO_NATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/australian_scientists.txt" in)
file(TO_NATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/output" out)

add_executable(test.employee employee.cpp)
target_link_libraries(test.employee demo)
add_test(NAME test.demo.employee
   COMMAND ${BASH} -c "$<TARGET_FILE:test.employee> < ${in} > ${out}")
