#pragma once
#include <QString>

namespace QCefWeb {

	// ȫ�ֻص�
class QCefWebAppInterface {
 public:
  virtual void onCefInitialized() = 0;
};

struct tagCookieItem {
	QString url;
	QString name;
	QString value;
	QString domain;
	QString path;
};

struct tagCefGlobalSetting {
};

}  // namespace QCefWeb
