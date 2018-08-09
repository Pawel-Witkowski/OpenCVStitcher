QT += gui core

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += D:/opencv-build/install/include

LIBS += -LD:/opencv-build/install/x86/mingw/bin
LIBS += -lopencv_core341 -lopencv_highgui341 -lopencv_imgcodecs341 -llibopencv_imgproc341 -llibopencv_features2d341 -llibopencv_calib3d341 -llibopencv_stitching341
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp
