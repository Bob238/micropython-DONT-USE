# Set location of base MicroPython directory.
if(NOT MICROPY_DIR)
    get_filename_component(MICROPY_DIR ${CMAKE_CURRENT_LIST_DIR}/../../.. ABSOLUTE)
endif()

# Set location of the ESP32 port directory.
if(NOT MICROPY_PORT_DIR)
    get_filename_component(MICROPY_PORT_DIR ${MICROPY_DIR}/ports/esp32 ABSOLUTE)
endif()

include(${MICROPY_PORT_DIR}/esp32_common.cmake)

# Add custom C++ module folder
file(GLOB MY_CPP_SRCS ${CMAKE_CURRENT_LIST_DIR}/video/*.cpp)
list(APPEND MICROPY_SRCS ${MY_CPP_SRCS})

# Mark all files as C++ so CMake uses the C++ compiler
set_source_files_properties(${MY_CPP_SRCS} PROPERTIES LANGUAGE CXX)

# Make sure headers are found
include_directories(${CMAKE_CURRENT_LIST_DIR}/video)
# Set location of base MicroPython directory.
if(NOT MICROPY_DIR)
    get_filename_component(MICROPY_DIR ${CMAKE_CURRENT_LIST_DIR}/../../.. ABSOLUTE)
endif()

# Set location of the ESP32 port directory.
if(NOT MICROPY_PORT_DIR)
    get_filename_component(MICROPY_PORT_DIR ${MICROPY_DIR}/ports/esp32 ABSOLUTE)
endif()

include(${MICROPY_PORT_DIR}/esp32_common.cmake)
