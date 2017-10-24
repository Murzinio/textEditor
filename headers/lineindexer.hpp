#pragma once

#include <vector>

#include <QWidget>
#include <QPaintEvent>
#include <QTextBlock>

class LineIndexer : public QWidget
{
    Q_OBJECT

public:
    explicit LineIndexer(QTextBlock firstBLock, QWidget *parent = nullptr);
    QSize sizeHint() const { return {maximumWidth(), 800}; }

    void setBlocksPositions(const std::vector<size_t>& positions);
    void setRect(const QRect& rect) { m_rect = rect; }
protected:
    void paintEvent(QPaintEvent* e) override;

private:
    std::vector<size_t> m_blockPositions;
    QRect m_rect;

signals:

public slots:
};
