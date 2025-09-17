cmake_minimum_required(VERSION 3.16)

project(TimerApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_library(TimerCore STATIC
    Timer.cpp
    Timer.h
    Timer.ui
)

target_link_libraries(TimerCore PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(AppLauncher
        MANUAL_FINALIZATION
        Main.cpp
    )
else()
    if(ANDROID)
        add_library(AppLauncher SHARED
            Main.cpp
        )
    else()
        add_executable(AppLauncher
            Main.cpp
        )
    endif()
endif()

target_link_libraries(AppLauncher PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    TimerCore
)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TimerApp)
endif()
set_target_properties(AppLauncher PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS AppLauncher
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AppLauncher)
endif()

option(ENABLE_TESTS "Build unit tests" OFF)

if(ENABLE_TESTS)
    message(STATUS "Unit tests enabled")

    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)

    set(UNIT_TESTING_SOURCES
        UnitTesting.cpp
        UnitTesting.h
    )

    add_executable(UnitTesting ${UNIT_TESTING_SOURCES})

    target_link_libraries(UnitTesting PRIVATE
        Qt${QT_VERSION_MAJOR}::Test
        Qt${QT_VERSION_MAJOR}::Widgets
        TimerCore
    )

    target_include_directories(UnitTesting PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

    set_target_properties(UnitTesting PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
        OUTPUT_NAME "UnitTesting"
    )

    enable_testing()
    add_test(NAME UnitTest COMMAND UnitTesting)

    message(STATUS "Unit testing executable: ${CMAKE_BINARY_DIR}/UnitTesting")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Tests enabled: ${ENABLE_TESTS}")
