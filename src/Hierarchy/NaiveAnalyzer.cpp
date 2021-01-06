#include "include/Hierarchy/NaiveAnalyzer.h"

NaiveAnalyzer::NaiveAnalyzer(QFile& file): m_paranthese(0), m_accolade(0){
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	COUT << "we're in the analyzer\n";
	
	bool comment = false;
	bool white = true;
	bool egual = false;
	QChar last = 0;
	
	QTextStream in(&file);
	QString str;
	str = in.readLine();
	while(!in.atEnd()){
		for(int i = 0; i < str.size();i++){

			if(str.at(i) == '/' && last == '/'){
				last = 0;
				break;
			}else if(str.at(i) == '*' && last == '/'){
				comment = true;
			}else if(str.at(i) == '/' && last == '*'){
				comment = false;
			}else if(!comment && !(m_accolade > 0 )){ // enfin les caracteres qui comptes !!!
			
				if(!comment){
					if(str.at(i) == '('){
						m_paranthese++;
					}else if(str.at(i) == ')'){
						m_paranthese--;
					}else if(str.at(i) == '{'){
						m_accolade++;
					}else if(str.at(i) == '}'){
						m_accolade--;
					}
				}
				
				if(str.at(i).isSpace()){
					if(white == false){
						this->lineAnalyze(' ');
						white = true;
					}
				}else {
					this->lineAnalyze(str.at(i));
					white = false;
				}
				
			}
			last = str.at(i);
		}
		str = in.readLine().trimmed();
	}
	COUT << in.readLine().trimmed() << '\n';
}


void NaiveAnalyzer::lineAnalyze(QChar c){
	COUT << c;
	

}
/*
void NaiveAnalyzer::fileAnalyze(QFile& file){
	//DJavaFile jf = new DJavaFile(file.fileName());
	
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	
	printf("we're in the analyzer\n");
	bool comment = false;
	bool white = true;
	bool egual = false;
	int paranthese = 0, accolade = 0;
	QChar last = 0;
	QString line;
	
	QTextStream in(&file);
	QString str;
	str = in.readLine();
	while(!in.atEnd()){
		for(int i = 0; i < str.size();i++){
			if(str.at(i) == '/' && last == '/'){
				last = 0;
				break;
			}else if(str.at(i) == '*' && last == '/'){
				comment = true;
			}else if(str.at(i) == '/' && last == '*'){
				comment = false;
			}else if(!comment){ // enfin les caracteres qui comptes !!!
				if((str.at(i) == ';'&& paranthese == 0 && accolade == 0) || (str.at(i) == '{' && paranthese == 0 && accolade == 0) ){
					if(white == false)
						line += QString(" ");
					line +=	str.at(i);
					printf("%s<fin>\n",line.toStdString().c_str());
					line = "";
				}else if(str.at(i) == ',' && egual == true && paranthese == 0 && accolade == 0){
					egual = false;
					if(white == false)
						line += QString(" ");
					line +=	str.at(i);
					line +=	" ";
					white = true;
				}else if(str.at(i).isSpace()){
					if(white == false){
						line += " ";
						white = true;
					}
				}else if(egual == true){
					// on fait rien
				}else if(str.at(i) == '='){
					egual = true;
				}else{
					white = false;
					line += str.at(i);
				}
				
				if(str.at(i) == '('){
					paranthese++;
				}else if (str.at(i) == ')'){
					paranthese--;
				}else if (str.at(i) == '{'){
					accolade++;
				}else if (str.at(i) == '}'){
					accolade--;
				}
			}
			last = str.at(i);
		}
		str = in.readLine().trimmed();
	}
	
}*/