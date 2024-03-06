#include "QCefResourceUtil.h"
#include "include/base/cef_logging.h"
#include "include/cef_stream.h"
#include "include/wrapper/cef_byte_read_handler.h"
#include "include/wrapper/cef_stream_resource_handler.h"
#include "QCefGlobalSetting.h"
#include <QDebug>
#include "Include/QCefResourceProvider.h"



bool CustomResourceProvider::OnRequest(
  scoped_refptr<CefResourceManager::Request> request) {
  CEF_REQUIRE_IO_THREAD();
  if (!provider_)
    return false;

  QString url = QString::fromStdString(request->url());
  CefRefPtr<ResourceOwner> owner = new ResourceOwner();
  if (!provider_->onRequest(url, owner->buffer))
    return false;

  CefRefPtr<CefResourceHandler> handler;

  CefRefPtr<CefStreamReader> stream = CefStreamReader::CreateForHandler(
    new CefByteReadHandler((const unsigned char*)owner->buffer.constData(),
                           (size_t)owner->buffer.size(),
                           owner));
  if (stream.get()) {
    handler = new CefStreamResourceHandler(
      request->mime_type_resolver().Run(request->url()), stream);
  }

  request->Continue(handler);
  return true;
}
