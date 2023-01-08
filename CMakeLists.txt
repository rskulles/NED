#Most of this was taken from the cmake tutorial and figuring out the cmake documentation ...OMFG
cmake_minimum_required(VERSION 3.21)

project(NED VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
file(TO_CMAKE_PATH "$ENV{SFML_INCLUDE_DIR}" SF_INC_DIR)
file(TO_CMAKE_PATH "$ENV{SFML_LIB_DIR}" SF_LIB_DIR)

set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src/")

set(HEADER_FILES "${INCLUDE_DIR}application.hpp"
 "${INCLUDE_DIR}theme.hpp" 
 "${INCLUDE_DIR}element.hpp" 
 "${INCLUDE_DIR}panel.hpp" 
 "${INCLUDE_DIR}scene_object.hpp" 
 "${INCLUDE_DIR}scene.hpp"
 )

set(SRC_FILES "${SRC_DIR}main.cpp" 
"${SRC_DIR}/application.cpp"
)

set(ALL_SRCS ${SRC_FILES} ${HEADER_FILES})

add_executable(NED ${ALL_SRCS})
target_include_directories(NED PUBLIC "${SF_INC_DIR}" "${PROJECT_SOURCE_DIR}/include/" "${PROJECT_SOUR_DIR}/src/")

if(WIN32)
    #I had to modify a solution to not include quotes and I didn't need different options for different build types
    set(SUBSYSTEM_LINKER_OPTIONS /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup)

    file(TO_CMAKE_PATH "$ENV{SFML_BIN_DIR}" SF_BIN_DIR)
    file(GLOB THE_DLLS "${SF_BIN_DIR}/*.dll")
    add_custom_command(TARGET NED POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${THE_DLLS} $<TARGET_FILE_DIR:NED>
        COMMAND_EXPAND_LISTS
    )
else()
    set(SUBSYSTEM_LINKER_OPTIONS "-mwindows")
endif(WIN32)

target_link_options(NED PRIVATE ${SUBSYSTEM_LINKER_OPTIONS})

#target_include_directories GOOD target_link_directories BAD!!!
find_library(SFML_GRAPHICS NAMES sfml-graphics PATHS "${SF_LIB_DIR}/")
find_library(SFML_AUDIO NAMES sfml-audio PATHS "${SF_LIB_DIR}/")
find_library(SFML_SYSTEM NAMES sfml-system PATHS "${SF_LIB_DIR}/")
find_library(SFML_NETWORK NAMES sfml-network PATHS "${SF_LIB_DIR}/")
find_library(SFML_WINDOW NAMES sfml-window PATHS "${SF_LIB_DIR}/")

#love how consistent cmake is...
target_link_libraries(NED ${SFML_GRAPHICS} ${SFML_AUDIO} ${SFML_SYSTEM} ${SFML_NETWORK} ${SFML_WINDOW})
file(COPY ${FILE_DIR}content DESTINATION  ${CMakeCurrentBuildDir}/)
