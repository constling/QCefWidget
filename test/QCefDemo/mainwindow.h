#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qwidget.h>
#include <QEvent>
#include "QCefWidget.h"
#include "CefWndBase.h"

class MainWindow : public CefWndBase<QWidget> {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

  void test();

 public:
 protected:
  void showEvent(QShowEvent* event) override;
  void hideEvent(QHideEvent* event) override;
  void closeEvent(QCloseEvent* event) override;
  QSize sizeHint() const override;

 public slots:
  // cef
  virtual void onInvokeMethodNotify(int browserId,
                                    int frameId,
                                    const QString& method,
                                    const QVariantList& arguments);
  virtual void onCefQueryRequest(const QCefQuery& query);
  virtual void onPopupWindow(const QString& url);

 private:
  QCefWidget* m_cefWidget;
};
#endif  // MAINWINDOW_H
