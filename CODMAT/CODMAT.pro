
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



HEADERS += \
    matrix.h \
    cmplx.h \
    squarematrix.h \
    augmentedmatrix.h \
    rowvector.h \
    columnvector.h \
    identitymatrix.h \
    mainmenu.h \
    button.h \
    squarematrixinput.h \
    orderdialog.h \
    ouputopener.h \
    orderdialog2.h \
    equationinput.h \
    rectmatrixinput.h

SOURCES += \
    matrix.cpp \
    cmplx.cpp \
    squarematrix.cpp \
    augmentedmatrix.cpp \
    rowvector.cpp \
    main.cpp \
    columnvector.cpp \
    identitymatrix.cpp \
    mainmenu.cpp \
    button.cpp \
    squarematrixinput.cpp \
    orderdialog.cpp \
    ouputopener.cpp \
    orderdialog2.cpp \
    equationinput.cpp \
    rectmatrixinput.cpp

DISTFILES += \
    splash.png

