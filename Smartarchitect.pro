QT += core gui sql network texttospeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartArchitect
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    projet.cpp \
    speechnotifier.cpp \
    chatserver.cpp \
    chatclient.cpp

HEADERS += \
    mainwindow.h \
    connection.h \
    projet.h \
    speechnotifier.h \
    chatserver.h \
    chatclient.h

FORMS += \
    mainwindow.ui
