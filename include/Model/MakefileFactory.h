#ifndef MAKEFILEFACTORY_H
#define MAKEFILEFACTORY_H

#include <QtWidgets>
#include "DProject.h"
#include "DPackage.h"
#include "DJavaFile.h"
#include "DSourceFolder.h"

class DProject;

class MakefileFactory {

    public:
        MakefileFactory(DProject *project);
        void writeMakefile();
    private:
        DProject *m_project;
        QStringList m_res;
        QStringList m_pvisited;
        QString m_jarcmd;
        TreeItem *m_makefile;
        int m_def;
        void generate();
        void packageGeneration(QString src, TreeItem *item);
};

#endif // MAKEFILEFACTORY_H
