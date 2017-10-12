#pragma once

#include <memory>
#include <QMainWindow>
#include "tabmanager.hpp"
#include "ui_mainwindow.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    std::unique_ptr<Ui::MainWindow> m_ui;
    TabManager m_tabManager;
};
