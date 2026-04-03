# Create an INTERFACE library for the video module
add_library(usermod_video INTERFACE)

# Add source file
target_sources(usermod_video INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/video_module.cpp
)

# Include current directory
target_include_directories(usermod_video INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Link to usermod
target_link_libraries(usermod INTERFACE usermod_video)
