#ifndef WINDOWSELECTFEATUREVALUES_H
#define WINDOWSELECTFEATUREVALUES_H

#include <QDialog>
#include <QtWidgets>
#include <QVector>



namespace Ui {
class windowSelectFeatureValues;
}

class windowSelectFeatureValues : public QDialog
{
	Q_OBJECT

public:
	explicit windowSelectFeatureValues(QWidget *parent = 0);
	~windowSelectFeatureValues();

private:
	Ui::windowSelectFeatureValues *ui;

//	QVector* Features<featureSet>;

	QPushButton* OkButton;
	QPushButton* CancelButton;

	QVBoxLayout* vertBoxLayout;
	QHBoxLayout* horBottomButtonsBoxLayout;

	QHBoxLayout* horBox1;
	QHBoxLayout* horBox2;
	QHBoxLayout* horBox3;
	QHBoxLayout* horBox4;
	QHBoxLayout* horBox5;
	QHBoxLayout* horBox6;
	QHBoxLayout* horBox7;
	QHBoxLayout* horBox8;
	QHBoxLayout* horBox9;
	QHBoxLayout* horBox10;
	QHBoxLayout* horBox11;
	QHBoxLayout* horBox12;
	QHBoxLayout* horBox13;
	QHBoxLayout* horBox14;
	QHBoxLayout* horBox15;
	QHBoxLayout* horBox16;
	QHBoxLayout* horBox17;
	QHBoxLayout* horBox18;
	QHBoxLayout* horBox19;
	QHBoxLayout* horBox20;

	QLabel* tempNameFeatureLabel;
	QComboBox* tempFeatureValueComboBox;
};

#endif // WINDOWSELECTFEATUREVALUES_H
