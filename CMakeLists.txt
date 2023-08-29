cmake_minimum_required(VERSION 3.15)

project(NeoPos CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-4.0)
find_package(SQLite3 REQUIRED) 

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(NeoPos 
    src/builder.cpp
    src/main.cpp
    src/point.cpp
    src/producto.cpp
    src/proveedor.cpp
    src/venta.cpp
    src/sqlite.cpp
)

target_link_libraries(NeoPos ${GTKMM_LIBRARIES} SQLite::SQLite3)
target_include_directories(NeoPos PRIVATE ${GTKMM_INCLUDE_DIRS})
