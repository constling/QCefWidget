#pragma once
#include "QCefDefine.h"

class CefAppHandler : public QCefWeb::QCefWebAppInterface {
 public:
  virtual void onCefInitialized() override;
};