#ifndef NAIVEANALYZER
#define NAIVEANALYZER

#define COUT QTextStream(stdout)

#include <QFile>
#include <QTextStream>
#include <iostream>

class NaiveAnalyzer {
	
	public:
		NaiveAnalyzer(QFile& file);
		//static void fileAnalyze(QFile& file);
	
	private:
		void lineAnalyze(QChar c);

	private:
		QString m_line;
		int m_paranthese;
		int m_accolade;
		
};
#endif