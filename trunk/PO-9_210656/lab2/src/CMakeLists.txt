cmake_minimum_required(VERSION 3.0.0)
project(TextEditor VERSION 2023.10.04.0 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
add_executable(po9_210656_lab2
        main.cpp
        texteditor.cpp
        texteditor.ui
        texteditor.h
        icons.qrc
)
target_link_libraries(po9_210656_lab2 Qt${QT_VERSION_MAJOR}::Widgets)
