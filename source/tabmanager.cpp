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

void TabManager::saveTabToFile(QString path)
{
    auto name = m_widget->tabText(m_widget->currentIndex());

    auto tab = std::find_if(m_tabs.begin(), m_tabs.end(),
    [&] (Tab& tab)
    {
        if(tab.getName() == name) return true; return false;
    });

    if(tab == m_tabs.end())
    {
        return;
    }

    if (path == "")
    {
        tab->saveFile();
    }
    else
    {
        tab->saveFile(path);
        m_widget->setTabText(m_widget->currentIndex(), tab->getName());
    }
}

bool TabManager::currentTabHasPath()
{
    auto name = m_widget->tabText(m_widget->currentIndex());

    auto tab = std::find_if(m_tabs.begin(), m_tabs.end(),
    [&] (Tab& tab)
    {
        if(tab.getName() == name) return true; return false;
    });

    return tab->hasPath();
}
