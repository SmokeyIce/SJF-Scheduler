cmake_minimum_required(VERSION 3.10)
project(SJF_Scheduler VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# First create a library with the scheduler implementation
add_library(scheduler_lib
    src/process.h
    src/sjf/sjf_scheduler.cpp
    src/sjf/sjf_scheduler.h
)

# Then create the executable and link it with the library
add_executable(SJF_Scheduler 
    main.cpp
)

target_link_libraries(SJF_Scheduler
    PRIVATE scheduler_lib
)

target_include_directories(SJF_Scheduler PRIVATE src)

configure_file(${CMAKE_SOURCE_DIR}/process_data.txt
               ${CMAKE_BINARY_DIR}/process_data.txt COPYONLY)
