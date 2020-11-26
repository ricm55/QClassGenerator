/*!  @file                              mainwindow.h
     @version                           1.00
     @brief                             MainWindow is the main window for this application.
                                        The user choose whish options he wants to keep in his code.

     @date                              2020-11-15
     @author                            Marc-Antoine
 */
//** **************************************************************************
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include "showcodewindow.h"

#define TAB "    "


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void displayCode();

private:

    bool generate();

    //!code generate
    QString *code;

    //!Section: Class definition
    QGroupBox *groupClassDef;
    QFormLayout *form_ClassName;
    QLineEdit *editClassName;
    QLineEdit *editInherits;


    //!Section: Options
    QGroupBox *groupOption;
    QVBoxLayout *optionLayout;
    QFormLayout *form_Options;

    QCheckBox *checkProtectHeader;
    QCheckBox *checkDefaultConstruct;
    QCheckBox *checkDestruct;

    //!Section: Add Comments
    QGroupBox *groupAddComments;
    QVBoxLayout *AddCommentsLayout;
    QCheckBox *checkAddComments;
    QDateEdit *editCreationDate;
    QFormLayout *form_AddComments;

    QLineEdit *editCommentAutor;
    QDateEdit *editCommentDate;
    QTextEdit *editCommentClassRole;

    //!Section: Window button
    QHBoxLayout *buttonLayout;
    QPushButton *buttonVisualize;
    QPushButton *buttonQuit;



};

#endif // MAINWINDOW_H
