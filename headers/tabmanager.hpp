#pragma once

#include <memory>
#include <vector>
#include <QTabWidget>
#include "tab.hpp"

namespace Ui
{
    class MainWindow;
}

class TabManager
{
public:
    TabManager(std::unique_ptr<Ui::MainWindow>& ui);
    std::unique_ptr<QTabWidget>& getWidget() { return m_widget; }
    void createTab(QString name);
    void createTabFromExistingFile(const QString& path);

private:
    std::unique_ptr<Ui::MainWindow>& m_ui;
    std::unique_ptr<QTabWidget> m_widget;
    std::vector<Tab> m_tabs;
};
