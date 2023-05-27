cmake_minimum_required(VERSION 3.5)
project(NeoPos VERSION 1.0.0)

set( NEOPOS_VERSION_MAJOR 1)
set( NEOPOS_VERSION_MINOR 0)

set( CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_STANDARD_REQUIRED ON)
set( CMAKE_CXX_EXTENSIONS OFF)

#################################################################
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

# Incluir los directorios de cabecera y las opciones de compilación
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

# Agregar las librerías de gtkmm3 a la lista de librerías a enlazar
list(APPEND LIBRARIES ${GTKMM_LIBRARIES})

include_directories(
        ${Boost_INCLUDE_DIR}
        ${LIBPQXX_INCLUDE_DIR}
)
enable_testing()
add_subdirectory(test)


set(SOURCES                 
        "${PROJECT_SOURCE_DIR}/src/main.cpp"
        
)

# "${PROJECT_SOURCE_DIR}/include/mensaje.pb.cc"

add_executable(NeoPos ${SOURCES})

target_link_libraries (
        NeoPos
        stdc++fs
        rt
        pthread
)
