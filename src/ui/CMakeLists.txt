

add_library(UI STATIC
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_include_directories(UI 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(UI
    PUBLIC
        Qt::Core
        Qt::Widgets
)


