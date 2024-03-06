#ifndef QCEF_RESOURCE_UTIL_H_
#define QCEF_RESOURCE_UTIL_H_

#include <string>
#include "include/cef_image.h"
#include "include/cef_stream.h"
#include "include/wrapper/cef_resource_manager.h"
#include <QByteArray>


class QCefResourceProvider;
class CustomResourceProvider : public CefResourceManager::Provider {
public:
  CustomResourceProvider(QCefResourceProvider* provider)
    : provider_(provider) {}

  bool OnRequest(scoped_refptr<CefResourceManager::Request> request) override;

private:
  QCefResourceProvider* provider_;

  DISALLOW_COPY_AND_ASSIGN(CustomResourceProvider);
};

class ResourceOwner : public CefBaseRefCounted {
public:
  QByteArray buffer;

private:
  IMPLEMENT_REFCOUNTING(ResourceOwner);
};

#endif // !QCEF_RESOURCE_UTIL_H_