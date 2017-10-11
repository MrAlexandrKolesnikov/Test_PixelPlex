/**
 * @file   worker.h
 * @Author Kolesnikov Alexandr(mr.alexandr.kolesnikov@gmail.com)
 * @date   October, 2017
 * @brief  header file for worker function
 **/

#ifndef WORKER_H
#define WORKER_H

/* Required headers for QT libraries. -------------------------------*/
#include <QFile>
#include <QString>
#include <QDebug>
#include <QFileInfo>

/* Required header files of standard libraries. ---------------------*/

/* Required Project Header Files. -----------------------------------*/
#include "errorcodes.h"

/**
 * @brief  The function of executing the basic logic of working with files
 * @param  filePath - path to file input file
 * @param  mode - Overwriting an input file or creating a new
 * @retval none
 */
void handler(QString filePath, bool mode);

#endif // WORKER_H
