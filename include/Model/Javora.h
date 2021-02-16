#ifndef JAVORA_H
#define JAVORA_H

#include <QObject>

class Javora : public QObject{
    Q_OBJECT

    public:
        enum ModelType {
            Project=0x1,
            Folder=0x10,
            SourceFolder=0x100,
            Package=0x1000,
            JavaFile=0x10000,
            TreeItem=0x100000
        };
        Q_DECLARE_FLAGS(ModelTypes, ModelType)

        enum ClassType {
            Class=0x1,
            Interface=0x10,
            Enum=0x100
        };
        Q_DECLARE_FLAGS(ClassTypes, ClassType)
};
Q_DECLARE_OPERATORS_FOR_FLAGS(Javora::ModelTypes)
Q_DECLARE_OPERATORS_FOR_FLAGS(Javora::ClassTypes)
#endif // JAVORA_H
