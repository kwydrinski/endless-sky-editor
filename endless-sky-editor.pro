#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T20:16:36
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = endless-sky-editor
TEMPLATE = app
CONFIG += c++11

#---
# Nov 9, 2020 KDW - added to avoid clang issue with missing stddef.h
#INCLUDEPATH += /usr/lib/gcc/x86_64-linux-gnu/9/include/
INCLUDEPATH += /usr/lib/llvm-10/lib/clang/10.0.0/include/
#---

target.path = /usr/games/
INSTALLS += target

desktop.path = /usr/share/applications/
desktop.files = endless-sky-editor.desktop
INSTALLS += desktop

manual.path = /usr/share/man/man6/
manual.files = endless-sky-editor.6
INSTALLS += manual

icon.path = /usr/share/icons/hicolor/48x48/apps/
icon.files = endless-sky-editor.png
INSTALLS += icon

macx {
    ICON = endless-sky-editor.icns
    QMAKE_INFO_PLIST = Info.plist
}

SOURCES += main.cpp\
    DataFile.cpp\
    DataNode.cpp\
    DataWriter.cpp\
    Harvesting.cpp \
    HarvestingView.cpp \
    MainWindow.cpp\
    Minable.cpp \
    Planet.cpp\
    StellarObject.cpp\
    System.cpp \
    SystemView.cpp \
    Map.cpp \
    SpriteSet.cpp \
    GalaxyView.cpp \
    Galaxy.cpp \
    DetailView.cpp \
    AsteroidField.cpp \
    PlanetView.cpp \
    LandscapeView.cpp \
    LandscapeLoader.cpp

HEADERS  += DataFile.h\
    DataNode.h\
    DataWriter.h\
    Harvesting.h \
    HarvestingView.h \
    MainWindow.h\
    Minable.h \
    Planet.h\
    StellarObject.h\
    System.h \
    SystemView.h \
    Map.h \
    SpriteSet.h \
    GalaxyView.h \
    Galaxy.h \
    DetailView.h \
    AsteroidField.h \
    PlanetView.h \
    LandscapeView.h \
    LandscapeLoader.h \
    pi.h
