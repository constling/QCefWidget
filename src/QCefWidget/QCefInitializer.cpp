#include "Include/QCefInitializer.h"
#include "QCefManager.h"

void InitializeQCef() {
  QCefManager::getInstance().initializeCef();
}

void UnInitializeQCef() {
  QCefManager::getInstance().uninitializeCef();
}

void SetAppHandler(QCefWeb::QCefWebAppInterface* app)
{
  QCefManager::getInstance().setAppInterface(app);
}