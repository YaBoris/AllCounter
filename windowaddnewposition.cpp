#include "windowaddnewposition.h"
#include "ui_windowaddnewposition.h"

WindowAddNewPosition::WindowAddNewPosition(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::WindowAddNewPosition)
{
	ui->setupUi(this);
	ListOfTypesDevices = new QLabel;
	ListOfNamesDevices = new QLabel;
	ListOfFeatureDevices = new QLabel;
	BoxOfTypesDevices = new QComboBox;
	BoxOfNamesDevices = new QComboBox;
	BoxOfFeatureDevices = new QComboBox;

	NewTypeDeviceLine = new QLineEdit;
	NewNameDeviceLine = new QLineEdit;
	NewFeatureOfDeviceLine = new QLineEdit;

	OkButton = new QPushButton;
	CancelButton = new QPushButton;

	ListOfTypesDevices->setText("Выберите тип устройства");
	ListOfNamesDevices->setText("Выберите название устройства");
	ListOfFeatureDevices->setText("Выберите набор характеристик для этого типа устройств");

	vertBoxLayout = new QVBoxLayout;
	horBoxLayout = new QHBoxLayout;

	OkButton->setText("Oк");
	CancelButton->setText("Отмена");
	OkButton->baseSize();
	CancelButton->baseSize();

	horBoxLayout->addWidget(OkButton);
	horBoxLayout->addWidget(CancelButton);
	horBoxLayout->setSpacing(25);
	horBoxLayout->setAlignment(Qt::AlignRight);
	horBoxLayout->setContentsMargins(20, 40, 10, 10);

	vertBoxLayout->setMargin(20);
	vertBoxLayout->addWidget(ListOfTypesDevices);
	vertBoxLayout->addWidget(BoxOfTypesDevices);
	vertBoxLayout->addWidget(NewTypeDeviceLine);
	vertBoxLayout->addStretch(2);
	vertBoxLayout->addWidget(ListOfNamesDevices);
	vertBoxLayout->addWidget(BoxOfNamesDevices);
	vertBoxLayout->addWidget(NewNameDeviceLine);
	vertBoxLayout->addStretch(6);
	vertBoxLayout->addLayout(horBoxLayout);
//	vertBoxLayout->setSpacing(15);

	this->setLayout(vertBoxLayout);
	this->show();
}

WindowAddNewPosition::~WindowAddNewPosition()
{
	delete ui;
}

