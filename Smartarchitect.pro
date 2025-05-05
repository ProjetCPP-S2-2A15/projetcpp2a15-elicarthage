QT += core gui sql network texttospeech charts printsupport serialport

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
    chatclient.cpp \
    emailnotifier.cpp \
    historique.cpp \
    ressource.cpp \
    SmtpClient.cpp \
    MimeMessage.cpp \
    MimeText.cpp \
    MimePart.cpp \
    mimeqpencoder.cpp \
    MimeMultiPart.cpp \
    mimebase64formatter.cpp \
    mimebase64encoder.cpp \
    MimeContentFormatter.cpp \
    mimecontentencoder.cpp \
    EmailAddress.cpp \
    mimeqpformatter.cpp \
    QuotedPrintable.cpp \
    architecte.cpp \
    arduino.cpp \
    login.cpp \
    tache.cpp


HEADERS += \
    mainwindow.h \
    connection.h \
    projet.h \
    speechnotifier.h \
    chatserver.h \
    chatclient.h \
    emailnotifier.h \
    historique.h \
    ressource.h \
    SmtpClient.h \
    MimeMessage.h \
    mimeqpencoder.h \
    MimeText.h \
    MimePart.h \
    EmailAddress.h \
    smtpmime_global.h \
    MimeMultiPart.h \
    mimebase64formatter.h \
    MimeContentFormatter.h \
    mimecontentencoder.h \
    mimeqpformatter.h \
    quotedprintable.h \
    arduino.h \
    login.h \
    architecte.h \
    tache.h


FORMS +=mainwindow.ui \
login.ui

CONFIG += c++11
QT += pdf
QT += charts


