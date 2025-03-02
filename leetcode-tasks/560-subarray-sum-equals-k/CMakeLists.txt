cmake_minimum_required(VERSION 3.20.0)
project(560-subarray-sum-equals-k)

# Enable testing
if (WIN32)
    add_compile_definitions("GTEST_HAS_PTHREAD=0")
elseif(NOT WIN32)
    find_package(Threads REQUIRED)
endif()
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../extern/googletest googletest_build)
enable_testing()

# Added executables & linking g-tests
add_executable(${PROJECT_NAME} "${PROJECT_NAME}.cpp")
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        gtest 
        gtest_main 
        gmock
)
if (NOT WIN32)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
            pthread
    )
endif()
    
# Added tests
add_test(
    NAME
        ${PROJECT_NAME}
    COMMAND
        ${PROJECT_NAME}
    WORKING_DIRECTORY 
        ${CMAKE_CURRENT_BINARY_DIR}
)
