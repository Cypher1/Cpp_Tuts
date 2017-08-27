set_source_files_properties(mon/constexpr.cpp PROPERTIES COMPILE_FLAGS "-Wno-unused-variable -Wno-unused-parameter")
add_executable(constexpr mon/constexpr.cpp)

add_executable(explicit mon/explicit/min.cpp mon/explicit/min.h mon/explicit/user.cpp)
add_executable(findmin mon/findmin.cpp)
add_executable(ass1 mon/ass1.cpp)
