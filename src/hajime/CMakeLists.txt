set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_library(hajime SHARED
    hajime.cpp
)
target_include_directories(hajime PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/include
    $<INSTALL_INTERFACE:include>
)
target_include_directories(hajime PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/src
)
target_link_libraries(hajime PRIVATE
    opencv_core
    opencv_imgproc
    opencv_imgcodecs
    spdlog::spdlog
)

add_library(hajime::hajime ALIAS hajime)
