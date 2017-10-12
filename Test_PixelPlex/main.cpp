/**
 * @file   main.cpp
 * @Author Kolesnikov Alexandr(mr.alexandr.kolesnikov@gmail.com)
 * @date   October, 2017
 * @brief  main file for Test_PixelPlex function
 **/

/* Required headers for QT libraries. -------------------------------*/
#include <QCoreApplication>

/* Required header files of standard libraries. ---------------------*/
#include "iostream"
#include <iomanip>

/* Required Project Header Files. -----------------------------------*/
#include "errorcodes.h"
#include "handler.h"

using namespace std;

/**
 * @brief  Help information output function
 * @param  none
 * @retval none
 */
static void printHelp()
{
    cout<< "Test_PixelPlex version 1.0"             <<endl;
    cout<< "Command line parameters:"               <<endl;
    cout<< "[file] Path to file"                    <<endl;
    cout<< "Create by Alexander Kolesnikov"         <<endl;
    cout<< "Email: mr.alexandr.kolesnikov@gmail.com"<<endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("Test_PixelPlex");
    QCoreApplication::setApplicationVersion("1.0");
    try
    {
        if(argc < 1 || argc > 2) throw BAD_CMD_LINE_PARAM;
        else if(!strcmp(argv[1], "-help")) printHelp();
        else
        {
            handler(QString(argv[1]));
            cout<<"Done!"<<endl;
        }
    }
    catch(ERROR_CODE exception)
    {
        switch(exception)
        {
            case BAD_CMD_LINE_PARAM: cout<<"Bad parameters. For help use '-help'"<<endl;
            break;
            case OPEN_FILE_ERROR:    cout<<"Error open input file"               <<endl;
            break;
            case CREATE_FILE_ERROR:  cout<<"Error creating output file"          <<endl;
            break;
            case COMMENT_FILE_ERROR: cout<<"Error comments in input file"        <<endl;
            break;
        }
    }
    return a.exec();
}
