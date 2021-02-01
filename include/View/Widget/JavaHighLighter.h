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
};

#endif