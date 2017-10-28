#pragma once

#include <vector>
#include <memory>

#include <QTabWidget>
#include <QPointer>
#include <QScopedPointer>

#include "tab.hpp"

namespace Ui
{
    class MainWindow;
}

class TabManager
{
public:
    TabManager(Ui::MainWindow* ui);
    ~TabManager() {}
    QPointer<QTabWidget> getWidget() { return m_widget.data(); }
    void createTab(QString name = "");
    void createTabFromExistingFile(const QString& path);
    void saveTabToFile(QString path = "");
    bool currentTabHasPath();

private:
    Ui::MainWindow* m_ui;
    QScopedPointer<QTabWidget> m_widget;
    std::vector<Tab> m_tabs;
};
