/*! @file                              showcodewindow.cpp
    @version                           1.00
    @brief                             This file contain the code display window

    @date                              2020-11-15
    @author                            Marc-Antoine Ricard

 */
//** **************************************************************************
#include "showcodewindow.h"

ShowCodeWindow::ShowCodeWindow(QString &code,QWidget *parent): QDialog(parent)
{
    QVBoxLayout *displayLayout = new QVBoxLayout(this);

    //Setup the code
    editCode = new QTextEdit;
    editCode->setPlainText(code);
    editCode->setText(code);
    editCode->setReadOnly(true);
    editCode->setFont(QFont("Courier"));

    closeDisplay = new QPushButton("Close");

    //Setup layout
    displayLayout->addWidget(editCode);
    displayLayout->addWidget(closeDisplay);

    resize(350,450);
    setLayout(displayLayout);

    //*** Interraction ***
    QObject::connect(closeDisplay,SIGNAL(clicked()),this,SLOT(accept()));

}

