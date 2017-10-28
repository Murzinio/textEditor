#include <QTextBlock>
#include <QScrollBar>

#include "editor.hpp"

Editor::Editor(QWidget* parent)
    :
        QPlainTextEdit(parent),
        m_lineIndexer(new LineIndexer(this->document()->firstBlock(), this))
{
    setViewportMargins({ 28, 0, 0, 0 });
    connect(this, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
    connect(this->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(onScrollValueChanged()));
}

void Editor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);
    m_lineIndexer->setHeight(e->size().height());
}

void Editor::onTextChanged()
{
    updateIndexer();
}

void Editor::onScrollValueChanged()
{
    updateIndexer();
}

void Editor::updateIndexer()
{
    std::vector<size_t> positions;

    auto block = firstVisibleBlock();
    auto offset = contentsMargins().top() + contentOffset().y();

    while (block.isValid())
    {
        positions.emplace_back(offset + (fontMetrics().height() * (positions.size())));
        block = block.next();
    }

    m_lineIndexer->setBlocksPositions(positions);
    m_lineIndexer->setFirstBlockNumber(firstVisibleBlock().blockNumber());
}
