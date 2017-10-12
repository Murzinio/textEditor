#pragma once

#include <memory>

#include <QString>
#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>

#include "file.hpp"
#include "editor.hpp"

class Tab
{
public:
    Tab(const QString& name, QTabWidget* tabWidget); // new tab
    Tab(QTabWidget* tabWidget, const QString& path); // tab from file

    std::unique_ptr<QWidget>& getWidget() { return m_widget; }
    QString& getName() { return m_name; }

private:
    QString m_name;
    File m_file;

    std::unique_ptr<QWidget> m_widget;
    std::unique_ptr<QHBoxLayout> m_layout;
    std::unique_ptr<Editor> m_editor;
};
