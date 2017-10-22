#pragma once

#include <QWidget>
#include <QPaintEvent>

class LineIndexer : public QWidget
{
    Q_OBJECT

public:
    explicit LineIndexer(QWidget *parent = nullptr);
    QSize sizeHint() const { return {maximumWidth(), 800}; }

    void setLinesCount(const size_t count);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    size_t m_linesCount;

signals:

public slots:
};
