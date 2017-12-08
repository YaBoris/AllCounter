#ifndef WINDOWADDNEWPOSITION_H
#define WINDOWADDNEWPOSITION_H

#include <QDialog>
#include <QtWidgets>
#include <QDebug>
#include <QtSql>
#include <clocale>

#include "windowsetfeaturesfornewtypedevice.h"
#include "windowselectfeaturevalues.h"
#include "brokerdb.h"

namespace Ui {
class WindowAddNewPosition;
}

class WindowAddNewPosition : public QDialog
{
	Q_OBJECT

public:
	explicit WindowAddNewPosition(brokerdb *pBroker, QWidget *parent = 0);
	~WindowAddNewPosition();

private:
	Ui::WindowAddNewPosition *ui;

	brokerdb* pointerBroker;

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

	QLabel* leftSymbolsType;
	QLabel* leftSymbolsName;
	QLabel* leftSymbolsStatus;

	QLabel* NoteForNewTypeLabel;
	QLabel* NoteForNewNameLabel;
	QLabel* NoteForNewStatusLabel;

	struct Comparative
	{
		QString nameItem;
		int DBIndex;
		int ComboBoxIndex;
	};

	QString prevNoteString;
	QVector<Comparative>* ComparativeList;

	WindowSetFeaturesForNewTypeDevice* FeaturesTableForNewType;
	windowSelectFeatureValues* SelectValuesOfFeatures;

private slots:
	void AddFeaturesToNewTypeInNewWindow();
	void AddNewNameInNewWindow();
	void AddNewStatusSlot();
	void SetFeaturesForExistNameSlot();
	void OkSlot();
	void CancelSlot();
	void ControlTypeNameInLineSlot(QString textString);
	void ControlNameDeviceInLineSlot(QString textString);
	void ControlStatusInLineSlot(QString textString);

public slots:
	//слоты для приема запросов из брокера
	void getQueryNameDeviceSlot(QSqlQuery queryNameDevice);
	void getQueryTypeDeviceSlot(QSqlQuery queryTypeDevice);
	void getQueryStatus(QSqlQuery queryStatus);

signals:
	void getType();
	void getName();
	void getStatus();
	void insertNewNameDeviceToDB(QString tempString);
//	void on_NewNameDeviceLine_textChanged();
//	void on_NewStatusOfDeviceLine_textChanged();
};

#endif // WINDOWADDNEWPOSITION_H
