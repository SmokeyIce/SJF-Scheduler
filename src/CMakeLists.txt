add_library(scheduler_lib
    process.h
    sjf/sjf_scheduler.cpp
    sjf/sjf_scheduler.h
)

add_executable(os_scheduler 
    main.cpp
)

target_link_libraries(os_scheduler
    PRIVATE scheduler_lib
) 