/**
 * @file   errorcodes.h
 * @Author Kolesnikov Alexandr(mr.alexandr.kolesnikov@gmail.com)
 * @date   October, 2017
 * @brief  Header file provides function error codes
 **/

#ifndef ERRORCODES_H
#define ERRORCODES_H

/** Enumeration of error codes                                                  */
typedef enum
{
    BAD_CMD_LINE_PARAM           =1,/**<Bad input parameters                    */
    OPEN_FILE_ERROR                 /**<Error open file                         */
}ERROR_CODE;

#endif // ERRORCODES_H
