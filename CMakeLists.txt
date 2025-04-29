cmake_minimum_required(VERSION 3.16)

project(SmartArchitect VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql TextToSpeech)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)

# Ajoutez aux sources
set(PROJECT_SOURCES
    # ... vos fichiers existants ...
    chatserver.cpp
    chatserver.h
    chatclient.cpp
    chatclient.h
)









set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SmartArchitect
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        mainwindow.ui
        connection.cpp
        connection.h
        connection.h connection.cpp
        connection.h
        connection.h
        projet.h projet.cpp
        speechnotifier.h
        speechnotifier.cpp
        chatserver.h
        chatserver.cpp
        chatclient.h
        chatclient.cpp

    )
target_link_libraries(SmartArchitect PRIVATE Qt6::Sql)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SmartArchitect APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
target_link_libraries(SmartArchitect PRIVATE Qt${QT_VERSION_MAJOR}::TextToSpeech)
# Ajoutez aux liens
target_link_libraries(SmartArchitect PRIVATE Qt${QT_VERSION_MAJOR}::Network)
else()
    if(ANDROID)
        add_library(SmartArchitect SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SmartArchitect
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SmartArchitect PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SmartArchitect)
endif()
set_target_properties(SmartArchitect PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SmartArchitect
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SmartArchitect)
endif()
