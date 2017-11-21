#include "windowSetFeaturesForNewTypeDevice.h"
#include "ui_windowSetFeaturesForNewTypeDevice.h"

WindowSetFeaturesForNewTypeDevice::WindowSetFeaturesForNewTypeDevice(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::WindowSetFeaturesForNewTypeDevice)
{
	ui->setupUi(this);

	tableOfFeatures = new QTableWidget;
	createNewFeatureButton = new QPushButton;
	addFeatureSetToTypeButton = new QPushButton;
	CancelButton = new QPushButton;
	titleOfFeatureTable = new QLabel;
	titleOfFeatureTable->setText("Список характеристик");
	addFeatureSetToTypeButton->setText("Ok");
	createNewFeatureButton->setText("Создать новую хар-ку >>");
	CancelButton->setText("Отмена");

	vertBoxLayout = new QVBoxLayout;
	horBoxLayout = new QHBoxLayout;

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
