#include "include/View/Widget/JavaHighLighter.h"

JavaHighLighter::JavaHighLighter(QTextDocument *parent) : QSyntaxHighlighter(parent){
	keyWordsFormat.setForeground(Qt::red);
	keyWords.setPattern("\\b(abstract|boolean|break|byte|case|catch|char|class|continue|default|do|double|else|extends|final"
						"|finally|float|for|if|implements|import|instanceof|int|interface|long|native|new|null|package|private" 
						"|protected|public|return|short|static|super|switch|synchronized|this|throw|throws|transient|try|void|volatile|while)\\b");
	stringsFormat.setForeground(Qt::darkGray);
	commentFormat.setForeground(Qt::darkGreen);
}

void JavaHighLighter::highlightBlock(const QString &text){
	setCurrentBlockState(0);
	int start = 0;
	if(previousBlockState() == 1){
		start = text.indexOf("*/");
		if(start == -1){
			setCurrentBlockState(1);
			setFormat(0, text.length(), commentFormat);
			return;
		}else{
			start += 2;
			setCurrentBlockState(0);
			setFormat(0, start, commentFormat);
		}
	}
	
	QRegularExpressionMatchIterator matchIterator = keyWords.globalMatch(text,start);
	while (matchIterator.hasNext()) {
		QRegularExpressionMatch match = matchIterator.next();
		setFormat(match.capturedStart(), match.capturedLength(), keyWordsFormat);
	}
	
	int quote = -1;
	int commentSlash = -2;
	for(int i = start; i < text.length();i++){
		if(text.at(i) == '"'){
			if(quote == -1){
				quote = i;
			}else{
				setFormat(quote, i+1-quote, stringsFormat);
				quote = -1;
			}
		}else if(text.at(i) == '/' && quote == -1){
			if(commentSlash == i-1){
				setFormat(commentSlash, text.length()-commentSlash, commentFormat);
				break;
			}
			commentSlash = i;
		}else if(quote == -1 && text.at(i) == '*' && commentSlash == i-1){
			int end = text.indexOf("*/",i);
			if(end != -1){
				setFormat(commentSlash, end+3-i, commentFormat);
				setCurrentBlockState(0);
				i = end+1;
			}else{
				setFormat(commentSlash, text.length(), commentFormat);
				setCurrentBlockState(1);
				break;
			}
		}
	}
	
}
 