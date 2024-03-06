#ifndef QSYNCCEF_CLIENT_H_
#define QSYNCCEF_CLIENT_H_
#include <include/cef_v8.h>
#include <list>
#include <map>

#include "QCefProtocol.h"
#include "../../../QCefWidget/Include/QCefVersion.h"

class QSyncCefClient : public CefBaseRefCounted {
public:
  class SyncV8Handler : public CefV8Handler {
  public:
    SyncV8Handler(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame);

    virtual bool Execute(const CefString& function,
                       CefRefPtr<CefV8Value> object,
                       const CefV8ValueList& arguments,
                       CefRefPtr<CefV8Value>& retval,
                       CefString& exception) override;
    private:
      CefRefPtr<CefBrowser> browser_;
      CefRefPtr<CefFrame> frame_;
    private:
      IMPLEMENT_REFCOUNTING(SyncV8Handler);
    };

public:
    QSyncCefClient(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame);

    CefRefPtr<CefV8Value> GetObject();

private:
  CefRefPtr<CefV8Value> object_;

  CefRefPtr<CefBrowser> browser_;

  CefRefPtr<CefFrame> frame_;

private:
  IMPLEMENT_REFCOUNTING(QSyncCefClient);
};

#endif  // !QCEF_CLIENT_H_
