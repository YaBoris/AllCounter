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
	QHBoxLayout* horBoxLayout;
	QHBoxLayout* horBottomButtonsBoxLayout;
};

#endif // WINDOWSELECTFEATUREVALUES_H
