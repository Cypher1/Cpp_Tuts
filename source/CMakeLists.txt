add_subdirectory(demo)

add_library(demo STATIC $<TARGET_OBJECTS:demo.employee>)