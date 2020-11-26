/*!  @file                              showcodewindow.h
     @version                           1.00
     @brief                             Display the code window to allow the user to view it

     @date                              2020-11-15
     @author                            Marc-Antoine

 */
//** **************************************************************************
#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QtWidgets>

class ShowCodeWindow : public QDialog
{
public:
    ShowCodeWindow(QString &code,QWidget *parent = NULL);

private:

    QTextEdit *editCode;
    QPushButton *closeDisplay;

};

#endif // DISPLAYWINDOW_H
