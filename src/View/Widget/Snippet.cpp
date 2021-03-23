#include "include/View/Widget/Snippet.h"
#include "include/View/Fenetre.h"

Snippet::Snippet(Fenetre *fen, SnippetModel *model): m_fen(fen){
    m_model = new QSortFilterProxyModel;
    m_model->setSourceModel(model);
    m_model->setFilterCaseSensitivity(Qt::CaseInsensitive);
    sc = new SnippetController(this);

    listView.setModel(m_model);

    listView.setMouseTracking(true);
    this->setContentsMargins(0,0,0,0);
    SnippetDelegate *sd = new SnippetDelegate(&listView);
    listView.setItemDelegate(sd);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    QHBoxLayout *hb = new QHBoxLayout();
    QLineEdit *search = new QLineEdit;
    search->setPlaceholderText("rechercher");
    QPushButton *add = new QPushButton(DIcons::add, "");
    hb->addWidget(search);
    hb->setContentsMargins(0,5,0,0);
    hb->addWidget(add);

    layout->addLayout(hb);
    layout->addWidget(&listView);
    this->setLayout(layout);


    connect(search,SIGNAL(textChanged(const QString&)),sc,SLOT(filtre(const QString&)));
    connect(add,SIGNAL(clicked()), sc, SLOT(addSnippet()));
    connect(&listView,SIGNAL(doubleClicked(const QModelIndex&)),sc,SLOT(modifyFile(const QModelIndex&)));
    connect(sd,SIGNAL(remove(const QModelIndex&)),sc,SLOT(removeSnippet(const QModelIndex&)));
    connect(sd,SIGNAL(copy(const QModelIndex&)),sc,SLOT(copySnippet(const QModelIndex&)));
}
