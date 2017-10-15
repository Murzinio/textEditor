#include "tab.hpp"

Tab::Tab(const QString& name, QTabWidget* tabWidget) :
    m_name(name),
    m_widget(std::make_unique<QWidget>(tabWidget)),
    m_editor(std::make_unique<Editor>(m_widget.get())),
    m_layout(std::make_unique<QHBoxLayout>(m_widget.get()))

{
    m_layout->addWidget(m_editor.get());
}

Tab::Tab(QTabWidget* tabWidget, const QString& path) :
    m_widget(std::make_unique<QWidget>(tabWidget)),
    m_editor(std::make_unique<Editor>(m_widget.get())),
    m_layout(std::make_unique<QHBoxLayout>(m_widget.get())),
    m_path(path)

{
    m_name = path.split("/").last();
    m_editor->setPlainText(m_file.openFile(path));
    m_layout->addWidget(m_editor.get());
}


void Tab::saveFile(const QString& path)
{
    if (path == "")
    {
        m_file.saveFile(m_editor->toPlainText(), m_path);
    }
    else
    {
        m_file.saveFile(m_editor->toPlainText(), path);
    }
}
