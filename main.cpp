/*! @file                              main.cpp
    @version                           1.00
    @brief                             This program can generate a header file in c++

    @date                              2020-11-15
    @author                            Marc-Antoine Ricard
 */
//** **************************************************************************
#include <QApplication>
#include <QWidget>

#include "mainWindow.h"

int main(int argc,char *argv[]){

    QApplication app(argc,argv);

    MainWindow fenetre;
    fenetre.show();

    return app.exec();

}
