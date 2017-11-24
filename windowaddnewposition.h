#ifndef WINDOWADDNEWPOSITION_H
#define WINDOWADDNEWPOSITION_H

#include <QDialog>
#include <QtWidgets>
#include <QDebug>


#include "windowsetfeaturesfornewtypedevice.h"
#include "windowselectfeaturevalues.h"

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
	QHBoxLayout* horBoxLayoutBottomButtons;
	QHBoxLayout* horBoxLayoutAddType;
	QHBoxLayout* horBoxLayoutAddName;
	QHBoxLayout* horBoxLayoutAddStatus;

	QLabel* TitleOfTypesDevices;
	QLabel* TitleOfNamesDevices;
	QLabel* TitleOfStatusDevices;

	QComboBox* BoxOfTypesDevices;
	QComboBox* BoxOfNamesDevices;
	QComboBox* BoxOfStatusDevices;

	QPushButton* OkButton;
	QPushButton* CancelButton;
	QPushButton* SetFeaturesOfDevicesButton;
	QPushButton* NextAddTypeDeviceButton;
	QPushButton* NextAddNameDeviceButton;
	QPushButton* AddStatusButton;

	QLineEdit* NewTypeDeviceLine;
	QLineEdit* NewNameDeviceLine;
	QLineEdit* NewStatusOfDeviceLine;

	WindowSetFeaturesForNewTypeDevice* FeaturesTableForNewType;
	windowSelectFeatureValues* SelectValuesOfFeatures;

private slots:
	void AddFeaturesToNewTypeInNewWindow();
	void AddNewNameInNewWindow();
	void AddNewStatusSlot();
	void SetFeaturesForExistNameSlot();
	void OkSlot();
	void CancelSlot();

};

#endif // WINDOWADDNEWPOSITION_H
