#include "tab.hpp"

Tab::Tab(const QString& name, QTabWidget* tabWidget) :
    m_name(name),
    m_file(m_name),
    m_widget(std::make_unique<QWidget>(tabWidget)),
    m_editor(std::make_unique<Editor>(m_widget.get())),
    m_layout(std::make_unique<QHBoxLayout>(m_widget.get()))

{
    m_layout->addWidget(m_editor.get());
}
