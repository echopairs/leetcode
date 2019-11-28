cmake_minimum_required(VERSION 3.2)
project(bfss)

file(GLOB ALL_SOURCES "*.cpp")

foreach(SOURCE ${ALL_SOURCES})
    get_filename_component(FIL_WE ${SOURCE} NAME_WE)
    list(APPEND bfss ${FIL_WE})
endforeach()

link_libraries(pthread)

foreach(bfs ${bfss})
    add_executable(${bfs} ${bfs}.cpp)
    set_target_properties(${bfs}
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${leetcode_SOURCE_DIR}/bin"
            )
endforeach()
