#pragma once
#include "include\cef_scheme.h"


class LocalSchemeHandlerFactory : public CefSchemeHandlerFactory
{
public:
  LocalSchemeHandlerFactory();

    virtual CefRefPtr<CefResourceHandler> Create(CefRefPtr<CefBrowser> browser,
                                                 CefRefPtr<CefFrame> frame,
                                                 const CefString& scheme_name,
                                                 CefRefPtr<CefRequest> request) override;



private:
    IMPLEMENT_REFCOUNTING(LocalSchemeHandlerFactory);
};

