#include "tab.hpp"

Tab::Tab(const QString& name, QTabWidget* tabWidget) :
    m_name(name),
    m_widget(new QWidget(tabWidget)),
    m_editor(new Editor(m_widget)),
    m_layout(new QHBoxLayout(m_widget))

{
    m_layout->addWidget(m_editor);
}

Tab::Tab(QTabWidget* tabWidget, const QString& path) :
    m_widget(new QWidget(tabWidget)),
    m_editor(new Editor(m_widget)),
    m_layout(new QHBoxLayout(m_widget)),
    m_path(path)

{
    m_name = path.split("/").last();
    m_editor->setPlainText(m_file.openFile(path));

    m_layout->addWidget(m_editor);
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
        m_name = path.split("/").last();
    }
}
