/**
 * @file   main.cpp
 * @Author Kolesnikov Alexandr(mr.alexandr.kolesnikov@gmail.com)
 * @date   October, 2017
 * @brief  main file for Test_PixelPlex function
 **/

#include "iostream"
#include <iomanip>
#include <QCoreApplication>
#include <QFile>
#include <QDebug>

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
    cout<< "[file]"<< " Path to file flag"          <<endl;
    cout<< "-r" << " Overwrite current file flag"   <<endl;
    cout<< "-n" << " Create new file flag"          <<endl;
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
        if(argc < 2) throw 1;
        if(!strcmp( argv[1] ,"-help")) printHelp();
    }
    catch(int exception)
    {
        switch(exception)
        {
            case 1: std::cout<<"Bad parameters. For help use '-help'"<<std::endl;
            break;
        }
    }
    return a.exec();
}
