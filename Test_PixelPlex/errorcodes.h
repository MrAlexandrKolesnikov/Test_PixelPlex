/**
 * @file   errorcodes.h
 * @Author Kolesnikov Alexandr(mr.alexandr.kolesnikov@gmail.com)
 * @date   October, 2017
 * @brief  Header file provides function command codes
 **/

#ifndef ERRORCODES_H
#define ERRORCODES_H

/** Перечисление кодов команд, передаваемых для обработки в УВК                */
typedef enum
{
    OK                          = 0,/**<No Errors                               */
    BAD_CMD_LINE_PARAM             ,/**<Bad input parameters                    */
    OPEN_FILE_ERROR                 /**<Error open file                         */
}ERROR_CODE;

#endif // ERRORCODES_H
