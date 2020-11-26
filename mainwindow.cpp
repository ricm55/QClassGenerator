/*! @file                              mainwindow.cpp
    @version                           1.00
    @brief                             This file contain the configuration of all widgets and
                                       layouts for the main window.

    @date                              2020-11-15
    @author                            Marc-Antoine Ricard
 */
//** **************************************************************************
#include "mainwindow.h"

MainWindow::MainWindow(): QWidget()
{
    code = new QString;

    //Create the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    //Section: Class information
    groupClassDef = new QGroupBox("Class information");

    editClassName = new QLineEdit;
    editInherits = new QLineEdit;

    form_ClassName = new QFormLayout;
    form_ClassName->addRow("name: ",editClassName);
    form_ClassName->addRow("inherits: ",editInherits);

    groupClassDef->setLayout(form_ClassName);

    //Section: Options
    groupOption = new QGroupBox("Options");
    optionLayout = new QVBoxLayout;
    checkProtectHeader = new QCheckBox("Add header guard");
    checkDefaultConstruct = new QCheckBox("Generate a default constructor");
    checkDestruct = new QCheckBox("Generate a destructor");

    optionLayout->addWidget(checkProtectHeader);
    optionLayout->addWidget(checkDefaultConstruct);
    optionLayout->addWidget(checkDestruct);

    groupOption->setLayout(optionLayout);

    //Section: Add Comments
    groupAddComments = new QGroupBox("Add comments");
    AddCommentsLayout = new QVBoxLayout;
    form_AddComments = new QFormLayout;

    checkAddComments = new QCheckBox("Add a header to your code");
    editCommentAutor = new QLineEdit;
    editCommentDate = new QDateEdit;
    editCommentClassRole = new QTextEdit;

    form_AddComments->addRow("Autor: ",editCommentAutor);
    form_AddComments->addRow("Creation date: ",editCommentDate);
    form_AddComments->addRow("Class role: ",editCommentClassRole);

    AddCommentsLayout->addWidget(checkAddComments);
    AddCommentsLayout->addLayout(form_AddComments);

    groupAddComments->setLayout(AddCommentsLayout);

    //Section: window buttons
    buttonLayout = new QHBoxLayout;

    buttonVisualize = new QPushButton("Visualize !");
    buttonQuit = new QPushButton("Quit");

    buttonLayout->addWidget(buttonVisualize);
    buttonLayout->addWidget(buttonQuit);

    //Setup layout
    mainLayout->addWidget(groupClassDef);
    mainLayout->addWidget(groupOption);
    mainLayout->addWidget(groupAddComments);
    mainLayout->addLayout(buttonLayout);

    //*** Interraction ***
    QObject::connect(buttonQuit,SIGNAL(clicked()),qApp,SLOT(quit()));
    QObject::connect(buttonVisualize,SIGNAL(clicked()),this,SLOT(displayCode()));

}

//** **************************************************************************
/*!  @brief                             If the code can be generate, this methode runs
                                        another window to display the code

     @date                              2020-11-15
     @author                            Marc-Antoine Ricard
 */
void MainWindow::displayCode(){

    if(generate()){
        ShowCodeWindow *display = new ShowCodeWindow(*code,this);
        display->exec();
    }
}

//** **************************************************************************
/*!  @brief                             Generate the code for the user

     @date                              2020-11-15
     @author                            Marc-Antoine Ricard

 */
bool MainWindow::generate(){

    //The class must have a name
    if(!editClassName->text().isEmpty()){
        code->clear();

        //User comment
        if(checkAddComments->isChecked()){
            code->append( "/*\n");
            code->append( "autor: " + editCommentAutor->text() + "\n");
            code->append( "date: " + editCommentDate->text() + "\n\n");
            code->append( editCommentClassRole->toPlainText() + "\n");
            code->append( "*/\n");
        }

        //Add header guard
        if(checkProtectHeader->isChecked()){
            code->append( "#ifndef " + editClassName->text().toUpper() + "_H\n");
            code->append( "#define " + editClassName->text().toUpper() + "_H\n");
        }



        code->append( "class " + editClassName->text() + " ");

        //Inherits class
        if(!(editInherits->text().isEmpty())){
            code->append( ": public " + editInherits->text() + " ");
        }

        code->append( " {\n");

        code->append( "public: \n");

        //Generate default constructor
        if(checkDefaultConstruct->isChecked()){
            code->append( TAB + editClassName->text() + "();\n");
        }

        //Generate destructor
        if(checkDestruct->isChecked()){
            code->append( TAB + ("~" +editClassName->text() + "();\n"));
        }

        code->append( "protected: \n");
        code->append( "private: \n");

        code->append( "\n};\n");

        //End header guarg
        if(checkProtectHeader->isChecked()){
            code->append( "#endif //" + editClassName->text().toUpper() + "_H\n");
        }

        return true;

    }else{

        QMessageBox::critical(this,"Class name missing","You must have a name for your class.");
        return false;
    }
}


