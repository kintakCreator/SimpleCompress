cmake_minimum_required(VERSION 3.23)

set(CORE_PROJECT_NAME CoCore)

set(CORE_PUBLIC_INCLUDES
        data/stack.h
        io/getline.h
)

set(CORE_PRIVATE_SOURCES
        data/stack.c
        io/getline.c
)

set(CORE_ALL_SOURCES
        ${CORE_PUBLIC_INCLUDES}
        ${CORE_PRIVATE_SOURCES}
)

add_library(${CORE_PROJECT_NAME} STATIC
        ${CORE_ALL_SOURCES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
        ${CORE_ALL_SOURCES}
)

target_include_directories(${CORE_PROJECT_NAME} PUBLIC .)