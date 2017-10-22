#include "lineindexer.hpp"
#include <QPainter>

LineIndexer::LineIndexer(QWidget *parent)
    :
        QWidget(parent),
        m_linesCount(1)
{
    //this->setMinimumHeight(200);
    this->setMinimumWidth(fontMetrics().width("12345"));
    this->setMaximumWidth(fontMetrics().width("12345"));

    //this->show();
    //QSizePolicy policy;
    //policy.setHorizontalStretch(0.1);
}

void LineIndexer::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QRect rect{ 0, 0, maximumWidth(), 800 };

    QColor color;

    color.setRgb(100, 200, 0);
    painter.fillRect(rect, color);

    for (int i = 0; i < m_linesCount; ++i)
    {
        painter.drawText(0, (fontMetrics().height() * i),
                         width(), fontMetrics().height(),
                         Qt::AlignRight, QString::number(i + 1));
    }
}

void LineIndexer::setLinesCount(const size_t count)
{
    m_linesCount = count;
    update();
}
