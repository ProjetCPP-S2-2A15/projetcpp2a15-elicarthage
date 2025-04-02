# Nom du projet
TARGET = dash
TEMPLATE = app

# Fichiers sources du projet
SOURCES += main.cpp \
           architecte.cpp \
           connexion.cpp \
           login.cpp \
           mainwindow.cpp


# Fichiers d'en-têtes
HEADERS += mainwindow.h \
    architecte.h \
    connexion.h \
    login.h


# Fichier de formulaire Qt Designer
FORMS += mainwindow.ui \
    login.ui



# Ressources (si vous en avez)
# RESOURCES += ressources.qrc

# Configuration de compilation
CONFIG += c++11

# Ajouter les modules nécessaires de Qt
QT += widgets sql
QT += charts
QT += pdf



