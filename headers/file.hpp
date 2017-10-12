#pragma once

#include <QString>
#include <QFile>
#include <QDir>

class File
{
public:
    File(const QString& m_name);
private:
    const QString& m_name; //reference to name in the tab that holds the file
    QString m_content;

    void openFile(const QString& path);
    void saveFile(const QString& path);
};
