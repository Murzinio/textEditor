#pragma once

#include <QPlainTextEdit>
#include <QPointer>

#include "lineindexer.hpp"

class Editor : public QPlainTextEdit
{
    Q_OBJECT

public:
    Editor(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* e) override;

private:
    QPointer<LineIndexer> m_lineIndexer;

    void updateIndexer();

private slots:
    void onTextChanged();
    void onScrollValueChanged();
};
