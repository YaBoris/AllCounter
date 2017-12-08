#ifndef SetFeaturesForNewTypeDevice_H
#define SetFeaturesForNewTypeDevice_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>
#include <clocale>
#include "windowaddnewfeaturetofeaturelist.h"

namespace Ui {
class WindowSetFeaturesForNewTypeDevice;
}

class WindowSetFeaturesForNewTypeDevice : public QDialog
{
	Q_OBJECT

public:
	explicit WindowSetFeaturesForNewTypeDevice(QString newTypeName, QWidget *parent = 0);
	~WindowSetFeaturesForNewTypeDevice();

private:
	Ui::WindowSetFeaturesForNewTypeDevice *ui;

	QLabel* titleTypeName;

	QTableWidget* tableOfFeatures;

	QPushButton* createNewFeatureButton;
	QPushButton* addFeatureSetToTypeButton;
	QPushButton* CancelButton;

	QLabel* titleOfFeatureTable;
	QVBoxLayout* vertBoxLayout;
	QHBoxLayout* horBoxLayout;

	AddNewFeatureToFeatureList* newFeatureToFeatureList;

private slots:
	void createWindowAddNewFeatureToFeatureList();
};

#endif // SetFeaturesForNewTypeDevice_H
