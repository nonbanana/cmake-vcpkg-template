cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)

# manage vcpkg feature
set(HAJIME_DEBUG_WITH_GUI OFF CACHE BOOL "use gui(opencv imshow) for debug")

if(HAJIME_DEBUG_WITH_GUI)
    list(APPEND VCPKG_MANIFEST_FEATURES "opencv-highgui")
endif()

# set project
project(hajime LANGUAGES CXX VERSION 0.1.0)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
find_package(OpenCV REQUIRED)
find_package(spdlog REQUIRED)
find_package(CLI11 REQUIRED)

add_subdirectory(src)
add_subdirectory(app)
