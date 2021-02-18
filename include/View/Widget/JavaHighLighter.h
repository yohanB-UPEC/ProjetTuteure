#ifndef JAVAHIGHLIGHTER
#define JAVAHIGHLIGHTER

#include <QtWidgets>

class JavaHighLighter : public QSyntaxHighlighter {
    Q_OBJECT
    public:
        JavaHighLighter(QTextDocument *parent);
    private:
        QRegularExpression keyWords;
        QTextCharFormat keyWordsFormat;

        QTextCharFormat stringsFormat;
        QTextCharFormat commentFormat;
    protected:
        void highlightBlock(const QString &text);

    private:
        struct HighlightingRule{
            QRegularExpression pattern;
            QTextCharFormat format;
        };
        QVector<HighlightingRule> highlightingRules;

        QRegularExpression commentStartExpression;
        QRegularExpression commentEndExpression;

        QTextCharFormat keywordFormat;
        QTextCharFormat classFormat;
        QTextCharFormat singleLineCommentFormat;
        QTextCharFormat multiLineCommentFormat;
        QTextCharFormat quotationFormat;
        QTextCharFormat functionFormat;

};

#endif
