find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIRS})

add_library(strategies
            png_strategy.cpp
            dummy_strategy.cpp
            ppm_strategy.cpp)
# TODO: link strategies against needed libraries.
target_link_libraries(strategies ${PNG_LIBRARIES})