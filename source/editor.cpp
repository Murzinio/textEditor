#include <QTextBlock>

#include "editor.hpp"

Editor::Editor(QWidget* parent)
    :
        QPlainTextEdit(parent),
        m_lineIndexer(std::make_unique<LineIndexer>(this))
{

    setViewportMargins({ 28, 0, 0, 0 });
    connect(this, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
}

void Editor::resizeEvent(QResizeEvent *e)
{

}

void Editor::onTextChanged()
{
    m_lineIndexer->setLinesCount(blockCount());
}
