#pragma once

#include <QString>
#include <QFile>
#include <QTextStream>

class File
{
public:
    QString openFile(const QString& path);
    void saveFile(const QString& path, const QString& content);
};
