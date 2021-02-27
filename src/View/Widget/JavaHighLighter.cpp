#include "include/View/Widget/JavaHighLighter.h"

JavaHighLighter::JavaHighLighter(QTextDocument *parent) : QSyntaxHighlighter(parent) {
    HighlightingRule rule;

    //if(menu == nullptr){
    //    qDebug() << "null";
    //}
    //if(menu->getClear()->isChecked())
    /*quotationFormat.setForeground(QColor("#E6DB74"));
    rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
    rule.format = quotationFormat;
    highlightingRules.append(rule);*/
        keywordFormat.setForeground(QColor("#66D9EF"));
    //else keywordFormat.setForeground(Qt::blue);
    keywordFormat.setFontItalic(true);
    const QString keywordPatterns[] = {
        QStringLiteral("\\bchar\\b"), QStringLiteral("\\bclass\\b"), QStringLiteral("\\bconst\\b"),
        QStringLiteral("\\bdouble\\b"), QStringLiteral("\\benum\\b"), QStringLiteral("\\bexplicit\\b"),
        QStringLiteral("\\bString\\b"), QStringLiteral("\\bint\\b"),
        QStringLiteral("\\blong\\b"), QStringLiteral("\\bnamespace\\b"), QStringLiteral("\\boperator\\b"),
        QStringLiteral("\\bshort\\b"), QStringLiteral("\\bsignals\\b"), QStringLiteral("\\bsigned\\b"),
        QStringLiteral("\\bvoid\\b"), QStringLiteral("\\bvolatile\\b"), QStringLiteral("\\bboolean\\b")
    };

    for (const QString &pattern : keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }


    //if(menu->getClear()->isChecked())
        keywordFormat.setForeground(QColor("#66D9EF"));
    //else keywordFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Z][a-z]*\\b"));
    rule.format = keywordFormat;
    highlightingRules.append(rule);

    keywordFormat.setFontItalic(false);
    keywordFormat.setForeground(QColor("#AE81FF"));
    const QString userDefinedPatterns[] = {
        QStringLiteral("\\bnull\\b"), QStringLiteral("\\btrue\\b"), QStringLiteral("\\bfalse\\b")
    };
    for (const QString &pattern : userDefinedPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor("#AE81FF"));
    rule.pattern = QRegularExpression(QStringLiteral("[0-9]"));
    rule.format = keywordFormat;
    highlightingRules.append(rule);

    functionFormat.setForeground(QColor("#66D9EF"));
    rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
    rule.format = functionFormat;
    highlightingRules.append(rule);

    keywordFormat.setForeground(QColor("#F92672"));
    const QString keyPatterns[] = {
        QStringLiteral("\\breturn\\b"), QStringLiteral("\\bpublic\\b"), QStringLiteral("\\bprivate\\b"), QStringLiteral("\\bprotected\\b"), QStringLiteral("\\bstatic\\b"), QStringLiteral("\\bnew\\b"),
        QStringLiteral("\\bif\\b"), QStringLiteral("\\belse\\b"), QStringLiteral("\\bwhile\\b"), QStringLiteral("!"), QStringLiteral("<"), QStringLiteral(">"), QStringLiteral("="),
        QStringLiteral("\\|"), QStringLiteral("&"), QStringLiteral("instanceof"), QStringLiteral("\\+"), QStringLiteral("\\-"), QStringLiteral("\\/"), QStringLiteral("\\*"), QStringLiteral("\\%"),
        QStringLiteral("try"), QStringLiteral("catch"), QStringLiteral("\\["), QStringLiteral("\\]"), QStringLiteral("\\bpackage\\b"), QStringLiteral("\\bimport\\b")
    };
    for (const QString &pattern : keyPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(QColor("#FD971F"));
    const QString thisPatterns[] = {
        QStringLiteral("this")
    };
    for (const QString &pattern : thisPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    singleLineCommentFormat.setForeground(QColor("#75715E"));
    rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(QColor("#75715E"));

    //functionFormat.setFontItalic(true);

    functionFormat.setForeground(QColor("#A6E22E"));
    rule.pattern = QRegularExpression(QStringLiteral("\\b +[A-Za-z0-9_]+(?=\\()"));
    rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
    commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));

    stringsFormat.setForeground(QColor("#E6DB74"));
}

void JavaHighLighter::highlightBlock(const QString &text) {
    for (const HighlightingRule &rule : qAsConst(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }

    int quote = -1;
    for(int i = 0; i < text.length();i++){
        if(text.at(i) == '"'){
            if(quote == -1){
                quote = i;
            }else{
                setFormat(quote, i+1-quote, stringsFormat);
                quote = -1;
            }
        }
    }
}
