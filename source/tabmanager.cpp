#include "tabmanager.hpp"

TabManager::TabManager(std::unique_ptr<Ui::MainWindow>& ui) :
    m_ui(ui),
    m_widget(std::make_unique<QTabWidget>())
{
    m_widget->setTabsClosable(true);
    m_widget->setMovable(true);
}

void TabManager::createTab(QString name)
{
    if (name == "")
    {
        name = "newFile_" + QString::number(m_tabs.size());
    }

    m_tabs.emplace_back(Tab(name, m_widget.get()));
    m_widget->addTab(m_tabs.back().getWidget().get(), m_tabs.back().getName());
}

void TabManager::createTabFromExistingFile(const QString &path)
{
    m_tabs.emplace_back(Tab(m_widget.get(), path));
    m_widget->addTab(m_tabs.back().getWidget().get(), m_tabs.back().getName());
}
