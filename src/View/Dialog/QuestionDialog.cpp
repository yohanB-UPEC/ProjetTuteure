#include "include/View/Dialog/QuestionDialog.h"

QuestionDialog::QuestionDialog(QString title, QString message, QString checkMsg, QWidget *parent): QDialog(parent){
	this->setWindowTitle(title);

	QHBoxLayout *layout = new QHBoxLayout();

	QLabel *img = new QLabel(); 
	img->setPixmap(this->style()->standardIcon(QStyle::SP_MessageBoxQuestion).pixmap(128,128));

	QVBoxLayout *droite = new QVBoxLayout(); 
	QLabel *lab1 = new QLabel(message); 
	box = new QCheckBox(checkMsg);
	droite->addWidget(lab1);
	droite->addWidget(box);
	droite->setAlignment(Qt::AlignCenter);

	layout->addWidget(img);
	layout->addLayout(droite);

	QVBoxLayout *main = new QVBoxLayout();
	btns = new QHBoxLayout();
	btns->setAlignment(Qt::AlignRight);

	main->addLayout(layout);
	main->addLayout(btns); 

	this->setLayout(main);
}