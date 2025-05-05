cmake_minimum_required(VERSION 3.29)
project(PongGame)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the executable
add_executable(PongGame main.cpp
)

# Specify SFML include directory
include_directories(/opt/homebrew/Cellar/sfml@2/2.6.2_1/include)

# Specify SFML library directory
link_directories(/opt/homebrew/Cellar/sfml@2/2.6.2_1/lib)

# Explicitly link SFML libraries with full paths
target_link_libraries(PongGame PRIVATE
        /opt/homebrew/Cellar/sfml@2/2.6.2_1/lib/libsfml-system.dylib
        /opt/homebrew/Cellar/sfml@2/2.6.2_1/lib/libsfml-window.dylib
        /opt/homebrew/Cellar/sfml@2/2.6.2_1/lib/libsfml-graphics.dylib
)