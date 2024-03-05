#pragma once

namespace QCefWeb {
class QCefWebAppInterface {
 public:
  virtual void onCefInitialized() = 0;
};
}  // namespace QCefWeb
