#include "file.hpp"

File::File()
{

}

void File::openFile(const QString &path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream input(&file);

    while (!input.atEnd())
    {
        m_content += input.readLine() + "\n";
    }
}
