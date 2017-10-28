#include <QFileDialog>

#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_tabManager(m_ui.data())
{
    m_ui->setupUi(this);
    setCentralWidget(m_tabManager.getWidget());

    connect(m_ui->actionNew, SIGNAL(triggered()), this, SLOT(onActionNew()));
    connect(m_ui->actionOpen, SIGNAL(triggered()), this, SLOT(onActionOpen()));
    connect(m_ui->actionSave, SIGNAL(triggered()), this, SLOT(onActionSave()));
    connect(m_ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(onActionSaveAs()));
}

void MainWindow::onActionNew()
{
    m_tabManager.createTab();
}

void MainWindow::onActionOpen()
{
    m_tabManager.createTabFromExistingFile(QFileDialog::getOpenFileName(this, tr("Open File")));
}

void MainWindow::onActionSave()
{
    if (m_tabManager.currentTabHasPath())
    {
        m_tabManager.saveTabToFile();
    }
    else
    {
        m_tabManager.saveTabToFile(QFileDialog::getSaveFileName(this, tr("Save File")));
    }
}

void MainWindow::onActionSaveAs()
{
    m_tabManager.saveTabToFile(QFileDialog::getSaveFileName(this, tr("Save File")));
}
