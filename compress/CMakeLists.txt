cmake_minimum_required(VERSION 3.23)

set(COMPRESS_PROJECT_NAME CoCompress)

add_executable(${COMPRESS_PROJECT_NAME}
        main.c
)

target_link_libraries(${COMPRESS_PROJECT_NAME} CoCore)
