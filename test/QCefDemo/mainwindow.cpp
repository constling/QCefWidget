#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    CefWndBase<QWidget>(false, false, parent) {
  this->setGeometry(100, 100, 600, 600);
  this->setResizeable(true);
}

MainWindow::~MainWindow() {
}

void MainWindow::test() {
  m_cefWidget = new QCefWidget("https://test/login.html", this);
  m_cefWidget->setObjectName("cefwidget");
  m_cefWidget->setOsrEnabled(false);
  m_cefWidget->setContextMenuEnabled(false);
  m_cefWidget->setAutoShowDevToolsContextMenu(false);
  m_cefWidget->setBrowserBackgroundColor(QColor(0, 0, 0));
  m_cefWidget->setAllowExecuteUnknownProtocolViaOS(false);
  m_cefWidget->setAutoDestoryCefWhenCloseEvent(false);
  m_cefWidget->setGeometry(0, 0, 600, 600);
  

  connect(m_cefWidget,
          &QCefWidget::invokeMethodNotify,
          this,
          &MainWindow::onInvokeMethodNotify);
  connect(m_cefWidget,
          &QCefWidget::cefQueryRequest,
          this,
          &MainWindow::onCefQueryRequest);
  connect(m_cefWidget,
          &QCefWidget::popupWindow,
          this,
          &MainWindow::onPopupWindow);

  this->resize(sizeHint());
}

void MainWindow::onInvokeMethodNotify(int browserId,
    int frameId,
    const QString& method,
    const QVariantList& arguments)
{
    // 接口调用
  int a = 3;
}

void MainWindow::onCefQueryRequest(const QCefQuery& query) {
  int a = 3;
}

void MainWindow::onPopupWindow(const QString& url) {
  int a = 3;
}

void MainWindow::showEvent(QShowEvent* event) {
  QWidget::showEvent(event);
}

void MainWindow::hideEvent(QHideEvent* event) {
  QWidget::hideEvent(event);
}

void MainWindow::closeEvent(QCloseEvent* event) {
  //if (!usingHideInsteadClose_ || forceClose_) {
    event->accept();
  //}
}   

QSize MainWindow::sizeHint() const {
  return QSize(600, 600);
}