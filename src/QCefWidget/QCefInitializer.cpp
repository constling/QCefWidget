#include "Include/QCefInitializer.h"
#include "QCefManager.h"
#include "Include/cef_cookie.h"

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

bool SetGlobalCookie(const QCefWeb::tagCookieItem &item) {
	CefRefPtr<CefCookieManager> manager = CefCookieManager::GetGlobalManager(nullptr);
    if (nullptr == manager) {
        return false;
    }
    CefCookie cookie;
    CefString(&cookie.name).FromString(item.name.toStdString());
    CefString(&cookie.value).FromString(item.value.toStdString());
    CefString(&cookie.domain).FromString(item.domain.toStdString());
    CefString(&cookie.path).FromString(item.path.toStdString());
    cookie.has_expires = false;
    
    return manager->SetCookie(CefString(item.url.toStdString()), cookie, nullptr);
}