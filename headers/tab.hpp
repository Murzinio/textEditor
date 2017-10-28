#pragma once

#include <QString>
#include <QWidget>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QPointer>

#include "lineindexer.hpp"
#include "file.hpp"
#include "editor.hpp"

class Tab
{
public:
    Tab(const QString& name, QTabWidget* tabWidget); // new tab
    Tab(QTabWidget* tabWidget, const QString& path); // tab from file

    QPointer<QWidget>& getWidget() { return m_widget; }
    QString& getName() { return m_name; }
    void saveFile(const QString& path = "");
    bool hasPath() { return m_path != ""; }

private:
    QString m_name;
    QString m_path{ "" };
    File m_file;

    QPointer<QWidget> m_widget;
    QPointer<QHBoxLayout> m_layout;
    QPointer<Editor> m_editor;
};
