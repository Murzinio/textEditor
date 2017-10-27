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
    void setHeight(const size_t height);
    void setFirstBlockNumber(const size_t number) { m_firstBlockNumber = number; }
protected:
    void paintEvent(QPaintEvent* e) override;

private:
    std::vector<size_t> m_blockPositions;
    size_t m_firstBlockNumber;
};
