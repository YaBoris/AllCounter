#ifndef WINDOWADDNEWPOSITION_H
#define WINDOWADDNEWPOSITION_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class WindowAddNewPosition;
}

class WindowAddNewPosition : public QDialog
{
	Q_OBJECT

public:
	explicit WindowAddNewPosition(QWidget *parent = 0);
	~WindowAddNewPosition();

private:
	Ui::WindowAddNewPosition *ui;
	QVBoxLayout* vertBoxLayout;
	QHBoxLayout* horBoxLayout;
	QLabel* ListOfTypesDevices;
	QLabel* ListOfNamesDevices;
	QLabel* ListOfFeatureDevices;
	QComboBox* BoxOfTypesDevices;
	QComboBox* BoxOfNamesDevices;
	QComboBox* BoxOfFeatureDevices;
	QPushButton* OkButton;
	QPushButton* CancelButton;
	QButtonGroup* ButtonGroup;
	QLineEdit* NewTypeDeviceLine;
	QLineEdit* NewNameDeviceLine;
	QLineEdit* NewFeatureOfDeviceLine;
};

#endif // WINDOWADDNEWPOSITION_H
