cmake_minimum_required(VERSION 3.20.0)

set(TARGET_NAME poweroftwo)

# Enable testing
enable_testing()

add_executable(${TARGET_NAME} "${TARGET_NAME}.cpp")

# After adding directories paths, we should only added libs names
target_link_libraries(
    ${TARGET_NAME}
        PRIVATE
            gtest 
            gmock 
            pthread
)
    
# Added tests
add_test(
        NAME              ${TARGET_NAME}
        COMMAND           ${TARGET_NAME}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
