#include "lineindexer.hpp"
#include <QPainter>

LineIndexer::LineIndexer(QTextBlock firstBLock, QWidget *parent)
    :
        QWidget(parent)
{
    setMinimumWidth(fontMetrics().width("12345"));
    setMaximumWidth(fontMetrics().width("12345"));
}

void LineIndexer::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QRect rect{ 0, 0, maximumWidth(), maximumHeight() };

    QColor color;

    color.setRgb(100, 200, 0);
    painter.fillRect(rect, color);

    size_t counter{ 1 };

    for (auto & position : m_blockPositions)
    {
        painter.drawText(0, position,
                         width(), fontMetrics().height(),
                         Qt::AlignRight, QString::number(counter));
        ++counter;
    }
}

void LineIndexer::setBlocksPositions(const std::vector<size_t> &positions)
{
    m_blockPositions = positions;
    update();
}

void LineIndexer::setHeight(const size_t height)
{
    setMinimumHeight(height);
    setMaximumHeight(height);
}
