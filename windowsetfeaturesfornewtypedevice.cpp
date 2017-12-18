#include "windowSetFeaturesForNewTypeDevice.h"
#include "ui_windowSetFeaturesForNewTypeDevice.h"

WindowSetFeaturesForNewTypeDevice::WindowSetFeaturesForNewTypeDevice(brokerdb *pBroker,  QString newTypeName, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::WindowSetFeaturesForNewTypeDevice)
{
	ui->setupUi(this);

	pointerBroker = pBroker;

	ComparativeList = new QVector<Comparative>;

	titleTypeName = new QLabel;

	tableOfFeatures = new QTableWidget;
	createNewFeatureButton = new QPushButton;
	addFeatureSetToTypeButton = new QPushButton;
	CancelButton = new QPushButton;
	titleOfFeatureTable = new QLabel;

	titleTypeName->setText(newTypeName);
	titleTypeName->setAlignment(Qt::AlignCenter);
	titleTypeName->setStyleSheet(QString("font-size: %1px").arg(30));

	titleOfFeatureTable->setText("Список характеристик");
	addFeatureSetToTypeButton->setText("Добавить");
	createNewFeatureButton->setText("Создать новую хар-ку >>");
	CancelButton->setText("Отмена");

	vertBoxLayout = new QVBoxLayout;
	horBoxLayout = new QHBoxLayout;

	vertBoxLayout->addWidget(titleTypeName);
	horBoxLayout->addWidget(createNewFeatureButton);
	horBoxLayout->addStretch(1);
	horBoxLayout->addWidget(addFeatureSetToTypeButton);
	horBoxLayout->addWidget(CancelButton);

	vertBoxLayout->addWidget(titleOfFeatureTable);
	vertBoxLayout->addWidget(tableOfFeatures);
	vertBoxLayout->addStretch(1);
	vertBoxLayout->addItem(horBoxLayout);
	this->setLayout(vertBoxLayout);

	connect (createNewFeatureButton, SIGNAL(released()), this, SLOT(createWindowAddNewFeatureToFeatureList()));
	connect (CancelButton, SIGNAL(released()), this, SLOT(CancelButtonSlot()));
	connect (addFeatureSetToTypeButton, SIGNAL(released()), this, SLOT(CancelButtonSlot()));
	connect (this, SIGNAL(getFeatureList()), pointerBroker, SLOT(getFeatureListSlot()));
	connect (pointerBroker, SIGNAL(pushQueryFeatureList(QSqlQuery)), this, SLOT(getFeaturesListSlot(QSqlQuery)));

	emit getFeatureList();
}

WindowSetFeaturesForNewTypeDevice::~WindowSetFeaturesForNewTypeDevice()
{
	delete ui;
}

//SLOTS

void WindowSetFeaturesForNewTypeDevice::createWindowAddNewFeatureToFeatureList()
{
	newFeatureToFeatureList = new AddNewFeatureToFeatureList;
}

void WindowSetFeaturesForNewTypeDevice::getFeaturesListSlot(QSqlQuery queryFeatureList)
{
	QStringList strList;
	QSqlRecord rec;
	rec = queryFeatureList.record();
	tableOfFeatures->setColumnCount(rec.count());
	tableOfFeatures->setShowGrid(true);
	tableOfFeatures->horizontalHeader()->setStretchLastSection(true);

	int indexTemp = 0;
	ComparativeList->clear();

	ComparativeList->resize(rec.count());
	QVector<Comparative>::Iterator iter = ComparativeList->begin();

	while(queryFeatureList.next())
	{
		rec = queryFeatureList.record();
		QTableWidgetItem *checkBoxitem = new QTableWidgetItem();
//		checkBoxitem->data(Qt::CheckStateRole);
		checkBoxitem->setFlags(Qt::ItemIsUserCheckable);
		checkBoxitem->setCheckState(Qt::Checked);
//		checkBoxitem->
		iter->nameItem = queryFeatureList.value(rec.indexOf("table_feature_name_rus")).toString();
		iter->DBIndex = queryFeatureList.value(rec.indexOf("id")).toInt();
		iter->ComboBoxIndex = indexTemp+1;

		tableOfFeatures->insertRow(indexTemp);
		QTableWidgetItem* item = new QTableWidgetItem(iter->nameItem);

		strList << "" << "#" << "Название характеристики";
		tableOfFeatures->setHorizontalHeaderLabels(strList);
		tableOfFeatures->setItem((iter->ComboBoxIndex)-1, 1, checkBoxitem);
		tableOfFeatures->setItem((iter->ComboBoxIndex)-1, 2, item);
		tableOfFeatures->hideColumn(0);

		indexTemp++;
		iter++;
	}
	tableOfFeatures->resizeColumnsToContents();
	this->show();
//	this->update();
}

void WindowSetFeaturesForNewTypeDevice::CancelButtonSlot()
{
	delete this;

//	emit reject();
}

void WindowSetFeaturesForNewTypeDevice::OkButtonSlot()
{
	delete this;
//	emit  reject();
}


