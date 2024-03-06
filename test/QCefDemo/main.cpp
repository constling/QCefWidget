#include <QtWidgets/QApplication>
#include "QCefInitializer.h"
#include "mainwindow.h"
#include "CefWnd.h"
#include "cefapphandler.h"
#include "QCefSetting.h"

#pragma execution_character_set("utf-8")

int main(int argc, char* argv[]) {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
  QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#endif
#endif
  QApplication a(argc, argv);

  SetAppHandler(new CefAppHandler());
  
  InitializeQCef();

  MainWindow w;
  w.test();
  w.show();
  //todo È¥µô
    //QCefSetting::setResourceMap({{"login.html", {123, "PAGE"}}});


  /*CefWnd wnd(false, false);
  wnd.setGeometry(100, 100, 600, 600);

  wnd.setUsingGLWidget(false);
  wnd.setOsrEnabled(false);
  wnd.setContextMenuEnabled(true);
  wnd.setUsingHideInsteadClose(false);
  wnd.setAutoAddDevToolsContextMenu(false);
  wnd.setInitSize(QSize(600, 600));
  wnd.setInitUrl("http://qcefwidget/login.html");
  wnd.setupUi();
  wnd.show();*/
  

  int iret = a.exec();

  UnInitializeQCef();
  return iret;
}
