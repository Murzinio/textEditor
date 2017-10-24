#include <QTextBlock>

#include "editor.hpp"

Editor::Editor(QWidget* parent)
    :
        QPlainTextEdit(parent),
        m_lineIndexer(std::make_unique<LineIndexer>(this->document()->firstBlock(), this))
{

    setViewportMargins({ 28, 0, 0, 0 });
    connect(this, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
}

void Editor::resizeEvent(QResizeEvent *e)
{
}

void Editor::onTextChanged()
{
    std::vector<size_t> positions;
    auto block = firstVisibleBlock();

    //positions.emplace_back(contentOffset().y() + this->contentsMargins().top());

    auto offset = contentsMargins().top() + contentOffset().y();
    while (block.isValid())
    {
        positions.emplace_back(offset + (fontMetrics().height() * (positions.size())));
        block = block.next();
    }

    m_lineIndexer->setBlocksPositions(positions);
}
