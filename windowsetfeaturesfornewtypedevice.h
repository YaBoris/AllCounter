#ifndef SetFeaturesForNewTypeDevice_H
#define SetFeaturesForNewTypeDevice_H

#include <QDialog>
#include <QtWidgets>
#include <QtSql>
#include <clocale>

#include "windowaddnewfeaturetofeaturelist.h"
#include "brokerdb.h"

namespace Ui {
class WindowSetFeaturesForNewTypeDevice;
}

class WindowSetFeaturesForNewTypeDevice : public QDialog
{
	Q_OBJECT

public:
	explicit WindowSetFeaturesForNewTypeDevice(brokerdb *pBroker, QString newTypeName, QWidget *parent = 0);
	~WindowSetFeaturesForNewTypeDevice();

private:
	Ui::WindowSetFeaturesForNewTypeDevice *ui;

	brokerdb* pointerBroker;

	QLabel* titleTypeName;

	struct Comparative
	{
		QString nameItem;
		int DBIndex;
		int ComboBoxIndex;
	};
	QVector<Comparative>* ComparativeList;

	QTableWidget* tableOfFeatures;

	QPushButton* createNewFeatureButton;
	QPushButton* addFeatureSetToTypeButton;
	QPushButton* CancelButton;

	QLabel* titleOfFeatureTable;
	QVBoxLayout* vertBoxLayout;
	QHBoxLayout* horBoxLayout;

	AddNewFeatureToFeatureList* newFeatureToFeatureList;

signals:
	void getFeatureList();

private slots:
	void createWindowAddNewFeatureToFeatureList();
	void CancelButtonSlot();
	void OkButtonSlot();

public slots:
	void getFeaturesListSlot(QSqlQuery queryFeatureList);
};

#endif // SetFeaturesForNewTypeDevice_H
