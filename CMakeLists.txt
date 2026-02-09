cmake_minimum_required(VERSION 3.19)
project(test4 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets SerialPort SerialBus Multimedia)

qt_standard_project_setup()

qt_add_executable(test4
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_link_libraries(test4
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::SerialPort
        Qt::SerialBus
        Qt::Multimedia
)

include(GNUInstallDirs)

install(TARGETS test4
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET test4
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
