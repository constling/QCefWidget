#ifndef QCEF_INITIALIZER_H_
#define QCEF_INITIALIZER_H_

#include "QCefExport.h"
#include "QCefDefine.h"

QCEFWIDGET_EXPORT void SetAppHandler(QCefWeb::QCefWebAppInterface* app);
QCEFWIDGET_EXPORT void InitializeQCef();
QCEFWIDGET_EXPORT void UnInitializeQCef();


#endif // !QCEF_INITIALIZER_H_
