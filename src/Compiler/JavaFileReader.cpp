#include "include/Compiler/JavaFileReader.h"

JavaFileReader::JavaFileReader(QFile &file): m_in(&file),m_last(-1) {
	m_line = m_in.readLine();
	m_last = m_line.at(0);
	m_index = 1;
	m_quote = 0;
}

/**
* lit le fichier .java caractère par caractère en ignorant tous les commentaires et les suites d'espaces.
* ignore les bloc lorsque la variable m_bloc est à true.
*/
QChar JavaFileReader::readChar(){
	bool end = false;
	QChar res = 0;
	do{
		if(m_index >= m_line.size()){	
			if(m_in.atEnd()){
				res = m_last;
				m_last = -1;
				return res;
			}
			m_index = 0;
			m_line = m_in.readLine();
		}
		for(;m_index < m_line.size() && !end;m_index++){
			if(!m_comment){
				if(m_index == 1 && m_back == false){
					m_back = true;
					return '\n';
				}else if(m_quote != 0){
					if(m_line.at(m_index) == m_quote && m_last != '\\'){
						m_quote = 0;
					}
					m_back = false;
					end = true;
				}else if(m_last == '/' && m_line.at(m_index) == '/'){
					m_index = std::numeric_limits<int>::max();
					m_last = 0;
					break;
				}else if(m_last == '/' && m_line.at(m_index) == '*'){
					m_comment = true;
				}else if(m_last != '\\' && (m_line.at(m_index) == '"' || m_line.at(m_index) == '\'')){
					m_quote = m_line.at(m_index);
					m_back = false;
					end = true;
				}else if(m_last == 0 || (m_last.isSpace() && m_line.at(m_index).isSpace())){
					
				}else{
					if(m_last.isSpace()){
						m_last = ' ';
					}
					m_back = false;
					end = true;
				}
			}else if(m_last == '*' && m_line.at(m_index) == '/'){
				m_comment = false;
				m_last = 0;
				continue;
			}
			res = m_last;
			m_last = m_line.at(m_index);
		}
	}while(!end);
	
	return res;
}

void JavaFileReader::ignoreCurrentBloc(){
	m_bloc = true;
}

