#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    m_ui(std::make_unique<Ui::MainWindow>()),
    m_tabManager(m_ui)
{
    m_ui->setupUi(this);
    setCentralWidget(m_tabManager.getWidget().get());
    m_tabManager.createTab("test");
}
