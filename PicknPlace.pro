####-------------------------------------------------
#
# Project created by QtCreator 2012-02-14T15:35:48
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = PicknPlace
TEMPLATE = app

INCLUDEPATH +=  $$PWD/include


SOURCES +=  src/mainwindow.cpp \
            src/main.cpp \
            src/cnc.cpp \
            src/camarea.cpp

HEADERS +=  include/mainwindow.h \
            include/cncapi.h \
            include/cnc_types.h \
            include/cnc.h \
            include/opencv.hpp \
            include/camarea.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/cncapi/ -lcncapi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/cncapi/ -lcncapid

    LIBS += -L$$PWD/lib/ -lopencv_calib3d231 \
            -L$$PWD/lib/ -lopencv_contrib231 \
            -L$$PWD/lib/ -lopencv_core231 \
            -L$$PWD/lib/ -lopencv_features2d231 \
            -L$$PWD/lib/ -lopencv_flann231 \
            -L$$PWD/lib/ -lopencv_gpu231 \
            -L$$PWD/lib/ -lopencv_haartraining_engine \
            -L$$PWD/lib/ -lopencv_highgui231 \
            -L$$PWD/lib/ -lopencv_imgproc231 \
            -L$$PWD/lib/ -lopencv_legacy231 \
            -L$$PWD/lib/ -lopencv_ml231 \
            -L$$PWD/lib/ -lopencv_objdetect231 \
            -L$$PWD/lib/ -lopencv_ts231 \
            -L$$PWD/lib/ -lopencv_video231



DEPENDPATH += $$PWD/cncapi
