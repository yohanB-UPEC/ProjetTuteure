#ifndef QUESTIONDIALOG_H
#define QUESTIONDIALOG_H

#include <QtWidgets>

class QuestionDialog : public QDialog{
	Q_OBJECT
	public:
		QuestionDialog(QString title, QString message, QString checkMsg, QWidget *parent=nullptr);
		QHBoxLayout* getButtonLayout(){return btns;}
		bool isChecked(){return box->isChecked();}

	private:
		QHBoxLayout* btns;
		QCheckBox* box;
};
#endif