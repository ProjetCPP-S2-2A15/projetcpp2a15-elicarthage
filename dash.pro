#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       +=  sql
QT += charts
QT += printsupport
QT += network
QT += serialport
QT += texttospeech





greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mon_executable
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += console




SOURCES += \
        emailnotifier.cpp \
        historique.cpp \
        main.cpp \
        mainwindow.cpp \
        connection.cpp \
        ressource.cpp \
        SmtpClient.cpp \
        MimeMessage.cpp \
        MimeText.cpp \
        MimePart.cpp \
        mimeqpencoder.cpp\
        MimeMultiPart.cpp \
        mimebase64formatter.cpp\
        mimebase64encoder.cpp\
        MimeContentFormatter.cpp \
        mimecontentencoder.cpp \
        EmailAddress.cpp \
        mimeqpformatter.cpp \
        QuotedPrintable.cpp

HEADERS += \
    emailnotifier.h \
    historique.h \
    mainwindow.h \
    connection.h \
    ressource.h \
    SmtpClient.h \
    MimeMessage.h \
    mimeqpencoder.h\
    MimeText.h \
    MimePart.h \
    EmailAddress.h \
    smtpmime_global.h \
    MimeMultiPart.h \
    mimebase64formatter.h \
    MimeContentFormatter.h \
    mimecontentencoder.h \
    mimeqpformatter.h \
    quotedprintable.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
