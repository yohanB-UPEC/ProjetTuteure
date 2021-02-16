#include "include/Model/ClassSubElement.h"

QString ClassSubElement::toString(){
    QString res;
    res.append("\t"+this->scope()+" ");
    if(this->isStatic()){
        res.append("static ");
    }
    if(this->isFinal()){
        res.append("final ");
    }
    if(this->isAbstract()){
        res.append("abstract ");
    }
    if(this->isTransient()){
        res.append("transient ");
    }
    if(this->isSynchronized()){
        res.append("synchronized ");
    }
    if(this->isVolatile()){
        res.append("volatile ");
    }
    res.append(this->type()+" "+this->label());
    return res;
}
