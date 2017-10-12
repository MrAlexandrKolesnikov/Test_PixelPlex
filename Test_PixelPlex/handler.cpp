/**
 * @file   worker.h
 * @Author Kolesnikov Alexandr(mr.alexandr.kolesnikov@gmail.com)
 * @date   October, 2017
 * @brief  header file for worker function
 **/

/* Required Project Header Files. -----------------------------------*/
#include "handler.h"

/**
 * @brief  The function delete all comments from line
 * @param  line - line of file in byte array
 * @retval QString line without comments
 */
static QByteArray deleteComments(QByteArray line)
{
    static bool isMultiLineComment = false;
    QString lineQString = line;
    if(lineQString.indexOf("//") != -1)
    {
        lineQString.remove(lineQString.indexOf("//"),lineQString.length());
    }
    return lineQString.toLocal8Bit();
}

/**
 * @brief  The function of executing the basic logic of working with files
 * @param  filePath - path to input file
 * @param  mode - Overwriting an input file or creating a new
 * @retval none
 */
void handler(QString filePath, bool mode)
{
    QFile InputFile(filePath);
    QFile OutFile(QFileInfo(InputFile).canonicalPath() + "/NO_COMMENTS_" + QFileInfo(InputFile).fileName());
    if( mode )
    {
        if(!InputFile.open(QIODevice::ReadOnly)) throw OPEN_FILE_ERROR;
        if(!OutFile.open(QIODevice::WriteOnly)) throw CREATE_FILE_ERROR;
    }
    else
    {
        if(!InputFile.open(QIODevice::ReadWrite)) throw OPEN_FILE_ERROR;
    }
    while (!InputFile.atEnd())
    {
           QByteArray line = InputFile.readLine();
           if(mode) OutFile.write(deleteComments(line));
    }
    InputFile.close();
    OutFile.close();
}
