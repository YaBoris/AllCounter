#ifndef WINDOWSELECTFEATUREVALUES_H
#define WINDOWSELECTFEATUREVALUES_H

#include <QDialog>

#include <QtWidgets>
#include <QVector>
#include <QDebug>
#include <QtSql>
#include <clocale>

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

	QWidget* baseWidget;

	QVBoxLayout* vertBoxLayout;
	QVBoxLayout* vertBoxFull;

	QLabel* label1;
	QLabel* label2;
	QLabel* label3;
	QLabel* label4;
	QLabel* label5;
	QLabel* label6;
	QLabel* label7;
	QLabel* label8;
	QLabel* label9;
	QLabel* label10;
	QLabel* label11;
	QLabel* label12;
	QLabel* label13;
	QLabel* label14;
	QLabel* label15;
	QLabel* label16;
	QLabel* label17;
	QLabel* label18;
	QLabel* label19;
	QLabel* label20;


	QComboBox* box1;
	QComboBox* box2;
	QComboBox* box3;
	QComboBox* box4;
	QComboBox* box5;
	QComboBox* box6;
	QComboBox* box7;
	QComboBox* box8;
	QComboBox* box9;
	QComboBox* box10;
	QComboBox* box11;
	QComboBox* box12;
	QComboBox* box13;
	QComboBox* box14;
	QComboBox* box15;
	QComboBox* box16;
	QComboBox* box17;
	QComboBox* box18;
	QComboBox* box19;
	QComboBox* box20;
};

#endif // WINDOWSELECTFEATUREVALUES_H
