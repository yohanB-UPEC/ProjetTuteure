#include "include/Model/DMethod.h"

DMethod::~DMethod(){
    printf("destruction de la méthode\n");
    while(!this->mParametres.empty()){
        delete this->mParametres.back();
        this->mParametres.pop_back();
    }
}

QString DMethod::toString(){
    QString res = ClassSubElement::toString();
    res.append("( ");

    for(int i = 0; i < this->mParametres.size();i++){
        if(i != 0){
            res.append(", ");
        }
        res.append(mParametres[i]->type()+" "+mParametres[i]->label());
    }

    res.append(" ){\n\n\t} ");
    return res;
}
