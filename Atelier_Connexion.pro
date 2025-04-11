# Nom du projet
TARGET =Atelier_Connexion
TEMPLATE = app
RESOURCES += ressources.qrc
# Fichiers sources du projet
SOURCES += main.cpp \
           tache.cpp \
           connection.cpp \
           mainwindow.cpp

# Fichiers d'en-têtes
HEADERS += mainwindow.h \
    tache.h \
    connection.h

# Fichier de formulaire Qt Designer
FORMS += mainwindow.ui

# Ressources (si vous en avez)
# RESOURCES += ressources.qrc

# Configuration de compilation
CONFIG += c++1

# Ajouter les modules nécessaires de Qt
QT += widgets sql

QT += charts
