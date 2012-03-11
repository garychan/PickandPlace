#include <QtGui/QApplication>
#include <Qdir>
#include <QtOpenGL>

#include "mainwindow.h"
#include "opencv2/opencv.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}

