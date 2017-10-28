#pragma once

#include <QScopedPointer>
#include <QPointer>
#include <QMainWindow>

#include "tabmanager.hpp"
#include "ui_mainwindow.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    QSize minimumSizeHint() const override { return QSize(800, 600); }

private:
    QScopedPointer<Ui::MainWindow> m_ui;
    TabManager m_tabManager;

    QString getCurrentTabName();

private slots:
    void onActionNew();
    void onActionOpen();
    void onActionSave();
    void onActionSaveAs();
};
