#include "windowSetFeaturesForNewTypeDevice.h"
#include "ui_windowSetFeaturesForNewTypeDevice.h"

WindowSetFeaturesForNewTypeDevice::WindowSetFeaturesForNewTypeDevice(QString newTypeName, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::WindowSetFeaturesForNewTypeDevice)
{
	ui->setupUi(this);


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
	this->show();

	connect (WindowSetFeaturesForNewTypeDevice::createNewFeatureButton, SIGNAL(released()), this, SLOT(createWindowAddNewFeatureToFeatureList()));
}

WindowSetFeaturesForNewTypeDevice::~WindowSetFeaturesForNewTypeDevice()
{
	delete ui;
}

void WindowSetFeaturesForNewTypeDevice::createWindowAddNewFeatureToFeatureList()
{
	newFeatureToFeatureList = new AddNewFeatureToFeatureList;
}

