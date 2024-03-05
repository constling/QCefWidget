#pragma once
#include <QWidget>

#include <QMainWindow>

class CefWidget : public QWidget {
    Q_OBJECT

public:
    CefWidget(QWidget* parent = nullptr);
    ~CefWidget();
};

