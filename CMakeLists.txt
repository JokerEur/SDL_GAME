cmake_minimum_required(VERSION 3.8)
project(SDL2_App)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)
# includes cmake/FindSDL2.cmake
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} include usr/include include/ECS)

set(SOURCE_FILES src/main.cpp src/Window.cpp include/Window.hpp src/TextureManager.cpp include/TextureManager.hpp src/GameObject.cpp include/GameObject.hpp)

add_executable(SDL2_App ${SOURCE_FILES})
target_link_libraries(SDL2_App ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
