#include "include/Model/MakefileFactory.h"

MakefileFactory::MakefileFactory(DProject *project): m_project(project){
}

void MakefileFactory::writeMakefile(){
    this->generate();
    if(m_makefile == nullptr){
        m_makefile = new TreeItem("Makefile");
        m_project->appendChild(m_makefile);
    }
    QFile file(m_makefile->getPath());
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "impossible d'écrire dans le fichier " << file.fileName() ;
        QMessageBox::critical(nullptr,"erreur d'ecriture","impossible d'écrire dans le fichier Makefile");
        return;
    }
    QTextStream out(&file);

    QList<QString>::iterator it = m_res.begin();
    while(it != m_res.end()){
        out << *it << "\n";
        ++it;
    }
    file.close();
}


void MakefileFactory::generate(){
    qDebug() << "MakefileFactory::generate() début";
    m_res.clear();
    m_res.append("JCC = javac");
    m_res.append("JFLAGS = -implicit:none -encoding UTF-8 -d bin -classpath bin");
    m_res.append("");
    m_res.append("default: ");
    m_res.append("");
    m_def = 3;
    int size = m_project->childCount();
    for(int i = 0; i < size; i++){
        TreeItem *item = m_project->child(i);
        if(typeid(*item) == typeid(DSourceFolder)){
            int sf = item->childCount();
            for(int j = 0; j < sf; j++){
                this->packageGeneration(item->label(),item->child(j));
            }
        }else if(typeid(*item) == typeid(DFolder)){
               m_jarcmd.append(" -C "+item->label());
        }else if(typeid(*item) == typeid(TreeItem)){
            if(item->label() == "Makefile"){
                m_makefile = item;
                continue;
            }
            m_jarcmd.append(" -C "+item->label());
        }else{
            qDebug() << "objet inconnnu dans le projet " << m_project->label();
        }
    }

    m_res.append("");
    m_res.append("jar:");
    m_res.append("\tjar cvfe "+m_project->label()+".jar <classMain> " + m_jarcmd);
    m_res.append("");
    qDebug() << "MakefileFactory::generate() fin";
}

void MakefileFactory::packageGeneration(QString src, TreeItem *item){
    qDebug() << "MakefileFactory::packageGeneration début " + item->label();
    if(typeid(*item) != typeid(DPackage)){
           qDebug() << item->label() + " n'est pas un package !!!";
           return;
    }
    QString package = item->label();
    QString first = package.split(".")[0];
    if(!m_pvisited.contains(first)){
        m_pvisited.append(first);
        m_jarcmd.append(" -C bin "+first);
    }
    package.replace('.','/');
    int size = item->childCount();
    for(int i = 0; i < size; i++){
        TreeItem *javaFile = item->child(i);
        QString classPath = "bin/"+package+"/"+javaFile->label().replace(".java",".class");
        QString srcPath = src+"/"+package+"/"+javaFile->label();
        m_res[m_def].append("\\");
        m_res.insert(++m_def, "\t\t"+classPath);

        m_res.append(classPath+": "+srcPath);
        m_res.append("\t $(JCC) $(JFLAGS) -sourcepath "+src+" "+srcPath );
    }
    qDebug() << "MakefileFactory::packageGeneration fin " + item->label();
}
