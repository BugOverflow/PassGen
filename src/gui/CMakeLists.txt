# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets)

set(PASSGEN_GUI_HEADERS mainwindow.h)
set(PASSGEN_GUI_SOURCES main.cpp
						mainwindow.cpp)

add_executable(Q${PROJECT_NAME} ${PASSGEN_GUI_HEADERS} ${PASSGEN_GUI_SOURCES})

# Use the Widgets module from Qt 5.
target_link_libraries(Q${PROJECT_NAME} Qt5::Widgets)
