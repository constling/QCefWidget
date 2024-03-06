#ifndef QCEF_DEFAULT_RENDER_DELEGATE_H_
#define QCEF_DEFAULT_RENDER_DELEGATE_H_
#include <include/wrapper/cef_message_router.h>
#include <unordered_map>
#include "../QCefRenderApp.h"
#include "QCefClient.h"
#include "QSyncCefClient.h"

namespace QCefDefaultRenderDelegate {

void CreateBrowserDelegate(QCefRenderApp::RenderDelegateSet& delegates);

class RenderDelegate : public QCefRenderApp::RenderDelegate {
  typedef std::unordered_map<int64, CefRefPtr<QCefClient>>
      FrameID2QCefClientMap;

  typedef std::unordered_map<int64, CefRefPtr<QSyncCefClient>>
      SyncFrameID2QCefClientMap;

 public:
  RenderDelegate();

  virtual void OnWebKitInitialized(CefRefPtr<QCefRenderApp> app);

  virtual void OnContextCreated(CefRefPtr<QCefRenderApp> app,
                                CefRefPtr<CefBrowser> browser,
                                CefRefPtr<CefFrame> frame,
                                CefRefPtr<CefV8Context> context);

  virtual void OnContextReleased(CefRefPtr<QCefRenderApp> app,
                                 CefRefPtr<CefBrowser> browser,
                                 CefRefPtr<CefFrame> frame,
                                 CefRefPtr<CefV8Context> context);

  virtual bool OnProcessMessageReceived(CefRefPtr<QCefRenderApp> app,
                                        CefRefPtr<CefBrowser> browser,
                                        CefRefPtr<CefFrame> frame,
                                        CefProcessId source_process,
                                        CefRefPtr<CefProcessMessage> message);

 protected:
  bool OnTriggerEventNotifyMessage(CefRefPtr<CefBrowser> browser,
                                   CefRefPtr<CefFrame> frame,
                                   CefProcessId source_process,
                                   CefRefPtr<CefProcessMessage> message);

  void ExecuteEventListener(CefRefPtr<CefBrowser> browser,
                            CefRefPtr<CefFrame> frame,
                            const CefString& name,
                            CefRefPtr<CefDictionaryValue> dict);

 private:
  CefRefPtr<CefMessageRouterRendererSide> render_message_router_;

  FrameID2QCefClientMap frame_id_to_client_map_;
  SyncFrameID2QCefClientMap sync_frame_id_to_client_map_;

 private:
  IMPLEMENT_REFCOUNTING(RenderDelegate);
};

}  // namespace QCefDefaultRenderDelegate
#endif  // !QCEF_DEFAULT_RENDER_DELEGATE_H_
