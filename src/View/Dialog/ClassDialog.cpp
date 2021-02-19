#include "include/View/Dialog/ClassDialog.h"

ClassDialog::ClassDialog(QWidget *parent, Model *model, QFlags<Javora::ClassType> type): QDialog(parent),m_model(model), m_type(type), clc(model, this),locDia(this) {

	/* Paramètrage de la boîte de dialogue */

	this->setMinimumWidth(500);
    if(type.testFlag(Javora::Class)){
        this->resize(600,350);
        this->setWindowTitle("Nouvelle classe");
    }else if(type.testFlag(Javora::Interface)){
        this->resize(600,200);
        this->setWindowTitle("Nouvelle interface");
    }else if(type.testFlag(Javora::Enum)){
        this->resize(600,200);
        this->setWindowTitle("Nouvelle enumération");
    }else{
        qDebug() << " la class ClassDialog ne gère que les boites de dialogue de création de class,interface et Enum";
        return;
    }

    QGridLayout *layout = new QGridLayout();
    layout->setColumnStretch(1,2);

    // future emplacement de la classe
    QLabel *lab = new QLabel("Emplacement: ");
    loc = new QLineEdit();
    loc->setEnabled(false);
    QPushButton *browse1 = new QPushButton("Parcourir");
    layout->addWidget(lab,0,0,Qt::AlignLeft);
    layout->addWidget(loc,0,1);
    layout->addWidget(browse1,0,2,Qt::AlignHCenter);

    // Séparateur
    QFrame *s1 = new QFrame();
    s1->setFrameShape(QFrame::HLine);
    layout->addWidget(s1,1,0,1,3);


    // Nom de la classe
    lab = new QLabel("Nom: ");
    name = new QLineEdit();
    layout->addWidget(lab,2,0);
    layout->addWidget(name,2,1);

    // Modifieurs de la classe
    lab = new QLabel("Modifieurs: ");
    radioMod = new QButtonGroup();
    QHBoxLayout *h = new QHBoxLayout();
    QRadioButton *rb1 = new QRadioButton("public");
    QRadioButton *rb2 = new QRadioButton("package");
    QRadioButton *rb3 = new QRadioButton("private");
    QRadioButton *rb4 = new QRadioButton("protected");
    rb3->setEnabled(false);
    rb4->setEnabled(false);
    radioMod->addButton(rb1,0);
    radioMod->addButton(rb2,1);
    radioMod->addButton(rb3,2);
    radioMod->addButton(rb4,3);
    h->addWidget(rb1);
    h->addWidget(rb2);
    h->addWidget(rb3);
    h->addWidget(rb4);
    layout->addWidget(lab,3,0);
    layout->addLayout(h,3,1);


    if(type.testFlag(Javora::Class)){

        h = new QHBoxLayout();
        abstract = new QCheckBox("abstract");
        final = new QCheckBox("final");
        h->addWidget(abstract);
        h->addWidget(final);
        layout->addLayout(h,4,1);

        // super classe
        lab = new QLabel("Super class: ");
        superClass = new QLineEdit();
        layout->addWidget(lab,5,0);
        layout->addWidget(superClass,5,1);
    }

    // implemented interfaces
    lab = new QLabel("interfaces");
    interfaces = new QLineEdit();
    layout->addWidget(lab,6,0);
    layout->addWidget(interfaces,6,1);

    // question
    if(type.testFlag(Javora::Class)){
        lab = new QLabel("Quelle méthod voullez-vous créer");
        main = new QCheckBox("public static void main(String[] args)");
        constructor = new QCheckBox("les constructeurs depuis la superclass");
        layout->addWidget(lab,7,0,1,3,Qt::AlignLeft);
        layout->addWidget(main,8,1);
        layout->addWidget(constructor,9,1);
    }

    QSpacerItem *si = new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    layout->addItem(si,10,0,1,3);

    // Séparateur
    s1 = new QFrame();
    s1->setFrameShape(QFrame::HLine);
    layout->addWidget(s1,11,0,1,3);

    valider = new QPushButton("Valider");
    valider->setEnabled(false);
    QPushButton *annuler = new QPushButton("Annuler");
    h = new QHBoxLayout();
    h->addWidget(annuler);
    h->addWidget(valider);
    layout->addLayout(h,12,0,1,3,Qt::AlignRight);


    this->setLayout(layout);


    createLocDia();
    locationInit();
    connect(browse1,SIGNAL(clicked()),&locDia,SLOT(exec()));
    connect(name,SIGNAL(textChanged(const QString&)), &clc,SLOT(validateName(const QString&)));
    connect(annuler,SIGNAL(clicked()),this,SLOT(reject()));
    connect(valider,SIGNAL(clicked()),&clc,SLOT(createClass()));
}

void ClassDialog::createLocDia(){
    QVBoxLayout *layout = new QVBoxLayout();

    QTreeView *tree = new QTreeView;
    fm = new FilteredModel(Javora::Project | Javora::SourceFolder | Javora::Package);
    fm->setSourceModel(m_model);
    tree->setHeaderHidden(true);
    tree->setModel(fm);
    layout->addWidget(tree);

    QHBoxLayout *h = new QHBoxLayout();
    diaV = new QPushButton("Valider");
    diaV->setEnabled(false);
    QPushButton* a = new QPushButton("Annuler");
    h->addWidget(a);
    h->addWidget(diaV);
    h->setAlignment(Qt::AlignRight);
    layout->addLayout(h);

    locDia.setLayout(layout);

    connect(a,SIGNAL(clicked()),&locDia,SLOT(reject()));
    connect(tree->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)),&clc,SLOT(selectLocation(const QItemSelection&, const QItemSelection&)));
    connect(diaV,SIGNAL(clicked()),&clc,SLOT(validateLocation()));
}

void ClassDialog::locationInit(){
    if(typeid(*parentWidget()) != typeid(Fenetre)){
        return;
    }
    Fenetre *fen = (Fenetre*)parentWidget();
    QModelIndex index = fen->getExplorer()->selectionModel()->currentIndex();
    if(!index.isValid())
        return;
    TreeItem *item = (TreeItem*)index.internalPointer();
    if(typeid(*item) == typeid(DJavaFile)){
        loc->setText(m_model->getRelativePath(item->parent()));
    }else if(typeid(*item) == typeid(DSourceFolder)){
        int size = item->childCount();
        for(int i = 0; i < size;i++){
            TreeItem* child = item->child(i);
            if(typeid(*child) == typeid(DPackage)){
                loc->setText(m_model->getRelativePath(child));
                break;
            }
        }
    }else if(typeid(*item) == typeid(DPackage)){
        loc->setText(m_model->getRelativePath(item));
    }
}
