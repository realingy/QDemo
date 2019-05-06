cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

project(helloworld)

# Qt库查询
set(Qt5_DIR $ENV{QT590}/lib/cmake/Qt5)
message(${Qt5_DIR})
set(ACTIVE_QT_DIR $ENV{QTDIRMSVC})

# Qt查询路径
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${ACTIVE_QT_DIR}")
set(INSTALL_PREFIX_INITIALIZED ${CMAKE_CURRENT_SOURCE_DIR}/build/install CACHE STRINGS "change prefix")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTORCC ON)
# set(RESOURCE_DIR resources/resources.qrc)
find_package(Qt5 REQUIRED Widgets Core)
# qt5_wrap_cpp( MOC widget.h)
# qt5_wrap_ui( UIC widget.ui)
# qt5_add_resources(RCC resources.qrc)

# 查找源文件
aux_source_directory(. DIR_SRCS)

set(EXE_NAME 03_Slider)
add_executable(${EXE_NAME} ${DIR_SRCS})
target_link_libraries(${EXE_NAME} Qt5::Widgets)
