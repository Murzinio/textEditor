#include "file.hpp"

QString File::openFile(const QString& path)
{
    QString content;
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return "";
    }

    QTextStream input(&file);

    while (!input.atEnd())
    {
        content += input.readLine() + "\n";
    }

    return content;
}

void File::saveFile(const QString& content, const QString& path)
{
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream output(&file);
    output << content;
}
