#include "QSyncCefClient.h"

#define INVOKE_METHOD "invoke"

QSyncCefClient::SyncV8Handler::SyncV8Handler(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame)
    : browser_(browser)
    , frame_(frame)
{

}

bool QSyncCefClient::SyncV8Handler::Execute(const CefString& function,
                                    CefRefPtr<CefV8Value> object,
                                    const CefV8ValueList& arguments,
                                    CefRefPtr<CefV8Value>& retval,
                                    CefString& exception) {
  if (function == INVOKE_METHOD) {
      retval = CefV8Value::CreateString("My String!");
      return true;
  }

  return false;
}

QSyncCefClient::QSyncCefClient(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame)
    : object_(CefV8Value::CreateObject(nullptr, nullptr))
    , browser_(browser)
    , frame_(frame)
{
    CefRefPtr<SyncV8Handler> handler = new SyncV8Handler(browser_, frame_);

    CefRefPtr<CefV8Value> funcInvokeMethod = CefV8Value::CreateFunction(INVOKE_METHOD, handler);

    object_->SetValue(INVOKE_METHOD, funcInvokeMethod, V8_PROPERTY_ATTRIBUTE_READONLY);
}

CefRefPtr<CefV8Value> QSyncCefClient::GetObject()
{
    return object_;
}