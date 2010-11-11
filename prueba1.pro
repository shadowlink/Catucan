LIBS += -lcurl
TEMPLATE = app
QT = gui core network
CONFIG += qt release warn_on console
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui
HEADERS = src/mainwindowimpl.h src/downloader.h src/megaupload.h src/link.h \
    src/download_handler.h \
    src/downloadmanager.h \
    src/textprogressbar.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/downloader.cpp \
 src/megaupload.cpp \
 src/link.cpp \
    src/download_handler.cpp \
    src/downloadmanager.cpp \
    src/textprogressbar.cpp

RESOURCES += \
    resource.qrc
