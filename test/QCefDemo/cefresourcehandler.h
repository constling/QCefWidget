#pragma once
#include "QCefResourceProvider.h"


class CefResourceHandler : public QCefResourceProvider {
 public:
	 virtual bool onRequest(const QString& resourceUrl, QByteArray& buffer) override;
};