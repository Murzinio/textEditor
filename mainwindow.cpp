#include <QFileDialog>

#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    m_ui(std::make_unique<Ui::MainWindow>()),
    m_tabManager(m_ui)
{
    m_ui->setupUi(this);
    setCentralWidget(m_tabManager.getWidget().get());

    connect(m_ui->actionNew, SIGNAL(triggered()), this, SLOT(onActionNew()));
    connect(m_ui->actionOpen, SIGNAL(triggered()), this, SLOT(onActionOpen()));
    connect(m_ui->actionSave, SIGNAL(triggered()), this, SLOT(onActionSave()));
}

void MainWindow::onActionNew()
{
    m_tabManager.createTab("");
}

void MainWindow::onActionOpen()
{
    m_tabManager.createTabFromExistingFile(QFileDialog::getOpenFileName(this, tr("Open File")));
}

void MainWindow::onActionSave()
{
    m_tabManager.createTab("");
}
