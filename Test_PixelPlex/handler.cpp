/**
 * @file   handler.h
 * @Author Kolesnikov Alexandr(mr.alexandr.kolesnikov@gmail.com)
 * @date   October, 2017
 * @brief  header file for handler function
 **/

/* Required Project Header Files. -----------------------------------*/
#include "handler.h"

/**
 * @brief  The function delete all comments from line
 * @param  line - line of file in byte array
 * @retval QByteArray line without comments in byte array
 */
static QByteArray deleteComments(QByteArray line)
{
    static bool isMultiLineComment = false;
    QString lineQString = line;
    int endMultiLineComment = lineQString.indexOf("*/");
    int startMultiLineComment = lineQString.indexOf("/*");
    int simpleComment = lineQString.indexOf("//");

    if(simpleComment            != -1                                          &&         //just '//' in any part of line
       (endMultiLineComment    == -1 || endMultiLineComment > simpleComment)   &&
       (startMultiLineComment  == -1 || startMultiLineComment > simpleComment))
    {
        lineQString.replace(simpleComment,
                            lineQString.length() - simpleComment - 1,                     // -1 because of '/n
                            " ");
    }
    else
    {
        do
        {
            if(simpleComment != -1                   &&                                   // '/* .. */ .. //'
               startMultiLineComment < simpleComment &&
               simpleComment > endMultiLineComment     )
            {

                lineQString.replace(simpleComment,
                                     lineQString.length() - simpleComment -1,
                                     " ");
            }
            if(startMultiLineComment != -1)
            {
                isMultiLineComment = true;
                if(endMultiLineComment != -1)                                              // '/*...*/' comments
                {
                    lineQString.replace(startMultiLineComment,
                                        endMultiLineComment - startMultiLineComment + 2,   // add 2 becose length of '*/'
                                        " ");
                    isMultiLineComment = false;
                }
                else                                                                       // '/*...' comments
                {
                    lineQString.replace(startMultiLineComment,
                                        lineQString.length(),
                                        " ");
                }
            }
            else if(isMultiLineComment && endMultiLineComment == -1)                       //comment line in a multi-line comment
            {
                lineQString.replace(0, lineQString.length(), " ");
            }
            else if(isMultiLineComment && endMultiLineComment != -1)                       // '...*/' end of multi line comments
            {
                lineQString.replace(0, endMultiLineComment + 2, " ");                      // add 2 becose length of '*/'
                isMultiLineComment = false;
            }
            else if(!isMultiLineComment && endMultiLineComment != -1)                      // '..*/' without beginning '/*'
            {
                throw COMMENT_FILE_ERROR;
            }
            startMultiLineComment = lineQString.indexOf("/*");
            endMultiLineComment = lineQString.indexOf("*/");
        }
        while (startMultiLineComment != -1 || endMultiLineComment != -1);                  //while for find all comments in line
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
