#include "tabmanager.hpp"

TabManager::TabManager(std::unique_ptr<Ui::MainWindow>& ui) :
    m_ui(ui),
    m_widget(std::make_unique<QTabWidget>())
{

}

void TabManager::createTab(const QString& name)
{
    m_tabs.emplace_back(Tab(name, m_widget.get()));
    m_widget->addTab(m_tabs.back().getWidget().get(), m_tabs.back().getName());
}
