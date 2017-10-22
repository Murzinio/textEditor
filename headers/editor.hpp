#pragma once

#include <memory>

#include <QPlainTextEdit>

#include "lineindexer.hpp"

class Editor : public QPlainTextEdit
{
    Q_OBJECT

public:
    Editor(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* e) override;

private:
    std::unique_ptr<LineIndexer> m_lineIndexer;

public slots:
    void onTextChanged();
};
