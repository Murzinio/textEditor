#pragma once

#include <QString>
#include <QFile>
#include <QTextStream>

class File
{
public:
    File();

    void openFile(const QString& path);
    void saveFile(const QString& path);

    QString& getContent() { return m_content; }

private:
    QString m_content{ "" };
};
