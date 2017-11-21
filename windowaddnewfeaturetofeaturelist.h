#ifndef ADDNEWFEATURETOFEATURELIST_H
#define ADDNEWFEATURETOFEATURELIST_H

#include <QDialog>

#include <QtWidgets>

namespace Ui {
class AddNewFeatureToFeatureList;
}

class AddNewFeatureToFeatureList : public QDialog
{
	Q_OBJECT

public:
	explicit AddNewFeatureToFeatureList(QWidget *parent = 0);
	~AddNewFeatureToFeatureList();

private:
	Ui::AddNewFeatureToFeatureList *ui;

	QLabel* titleNameFeature;
	QLabel* titleTypeFeatureDigitOrText;
	QLabel* titleNameOfNewFeature;

	QComboBox* featureBox;

	QLineEdit* newFeatureLine;

	QRadioButton* DigitalRButton;
	QRadioButton* TextRButton;

	QLineEdit* newValueLine;

	QPushButton* OkButton;
	QPushButton* CancelButton;
	QPushButton* addNewFeatureButton;

	QVBoxLayout* vertBoxLayout;
	QHBoxLayout* horBoxRButtonsLayout;
	QHBoxLayout* horBoxNewValueLineLayout;
	QHBoxLayout* horBoxBottomButtonLayout;
};

#endif // ADDNEWFEATURETOFEATURELIST_H
