#ifndef JAVAFILEREADER
#define JAVAFILEREADER

#ifndef COUT
#define COUT QTextStream(stdout)
#endif

#include <QFile>
#include <QTextStream>
#include <iostream>

class JavaFileReader {
	public:
		JavaFileReader(QFile &file);
		QChar readChar();
		void ignoreCurrentBloc();
		
	private:
		QTextStream m_in;
		bool m_comment;
		bool m_back;
		bool m_bloc;
		QChar m_last;
		QChar m_quote;
		QString m_line;
		int m_index;
};

#endif