QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appointment.cpp \
    main.cpp \
    mainwindow.cpp \
    myAppointments.cpp \
    personalaccount.cpp \
    registration.cpp \
    creationAppointment.cpp \
    user.cpp \
    usersdata.cpp \



HEADERS += \
    appointment.h \
    mainwindow.h \
    myAppointments.h \
    personalaccount.h \
    registration.h \
    creationAppointment.h \
    user.h \
    usersdata.h \


FORMS += \
    mainwindow.ui \
    myAppointments.ui \
    personalaccount.ui \
    registration.ui \
    creationAppointment.ui \



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recources.qrc \
    users.json
