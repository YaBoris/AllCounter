#include "windowaddnewposition.h"
#include "ui_windowaddnewposition.h"

WindowAddNewPosition::WindowAddNewPosition(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::WindowAddNewPosition)
{
	ui->setupUi(this);
	TitleOfTypesDevices = new QLabel;
	TitleOfNamesDevices = new QLabel;
	TitleOfStatusDevices = new QLabel;

	BoxOfTypesDevices = new QComboBox;
	BoxOfNamesDevices = new QComboBox;
	BoxOfStatusDevices = new QComboBox;

	NewTypeDeviceLine = new QLineEdit;
	NewNameDeviceLine = new QLineEdit;
	NewStatusOfDeviceLine = new QLineEdit;

	OkButton = new QPushButton;
	CancelButton = new QPushButton;
	SetFeaturesOfDevicesButton = new QPushButton;
	NextAddNameDeviceButton = new QPushButton;
	NextAddTypeDeviceButton = new QPushButton;
	AddStatusButton = new QPushButton;

//	NextAddNameDeviceButton->resize(50, 1);
//	NextAddTypeDeviceButton->resize(2, 1);
//	AddStatusButton->resize(2, 1);

	TitleOfTypesDevices->setText("Выберите тип устройства");
	TitleOfNamesDevices->setText("Выберите название устройства");
	TitleOfStatusDevices->setText("Выберите статус устройства");

	vertBoxLayout = new QVBoxLayout;
	horBoxLayoutBottomButtons = new QHBoxLayout;
	horBoxLayoutAddName = new QHBoxLayout;
	horBoxLayoutAddType = new QHBoxLayout;
	horBoxLayoutAddStatus = new QHBoxLayout;

	OkButton->setText("Oк");
	CancelButton->setText("Отмена");
	NextAddNameDeviceButton->setText("Создать устройство >>");
	NextAddTypeDeviceButton->setText("Создать тип >>");
	AddStatusButton->setText("Создать новый статус >>");
	SetFeaturesOfDevicesButton->setText("Назначить характеристики...");
	OkButton->baseSize();
	CancelButton->baseSize();
	SetFeaturesOfDevicesButton->baseSize();

	NextAddNameDeviceButton->setFixedWidth(150);
	AddStatusButton->setFixedWidth(150);
	NextAddTypeDeviceButton->setFixedWidth(150);

	horBoxLayoutBottomButtons->addWidget(SetFeaturesOfDevicesButton);
	horBoxLayoutBottomButtons->addWidget(OkButton);
	horBoxLayoutBottomButtons->addWidget(CancelButton);
	horBoxLayoutBottomButtons->setAlignment(Qt::AlignRight);
	horBoxLayoutBottomButtons->setContentsMargins(20, 40, 10, 10);

	vertBoxLayout->setContentsMargins(30, 20, 30, 20);
	vertBoxLayout->addWidget(TitleOfTypesDevices);
	vertBoxLayout->addWidget(BoxOfTypesDevices);
	horBoxLayoutAddType->addWidget(NewTypeDeviceLine);
	horBoxLayoutAddType->addWidget(NextAddTypeDeviceButton);
	vertBoxLayout->addItem(horBoxLayoutAddType);

	vertBoxLayout->addStretch(1);
	vertBoxLayout->addWidget(TitleOfNamesDevices);
	vertBoxLayout->addWidget(BoxOfNamesDevices);
	horBoxLayoutAddName->addWidget(NewNameDeviceLine);
	horBoxLayoutAddName->addWidget(NextAddNameDeviceButton);
	vertBoxLayout->addItem(horBoxLayoutAddName);

	vertBoxLayout->addStretch(1);
	vertBoxLayout->addWidget(TitleOfStatusDevices);
	vertBoxLayout->addWidget(BoxOfStatusDevices);
	horBoxLayoutAddStatus->addWidget(NewStatusOfDeviceLine);
	horBoxLayoutAddStatus->addWidget(AddStatusButton);
	vertBoxLayout->addItem(horBoxLayoutAddStatus);

	vertBoxLayout->addStretch(2);
	vertBoxLayout->addLayout(horBoxLayoutBottomButtons);

	this->setLayout(vertBoxLayout);
	this->show();

	connect(WindowAddNewPosition::NextAddTypeDeviceButton, SIGNAL(released()), this, SLOT(AddFeaturesToNewTypeInNewWindow()));
	connect(WindowAddNewPosition::NextAddNameDeviceButton, SIGNAL(released()), this, SLOT(AddNewNameInNewWindow()));
	connect(WindowAddNewPosition::AddStatusButton, SIGNAL(released()), this, SLOT(AddNewStatusSlot()));
	connect(WindowAddNewPosition::SetFeaturesOfDevicesButton, SIGNAL(released()), this, SLOT(SetFeaturesForExistNameSlot()));
	connect(WindowAddNewPosition::OkButton, SIGNAL(released()), this, SLOT(OkSlot()));
	connect(WindowAddNewPosition::CancelButton, SIGNAL(released()), this, SLOT(CancelSlot()));
}

WindowAddNewPosition::~WindowAddNewPosition()
{
	delete ui;
}


void WindowAddNewPosition::AddFeaturesToNewTypeInNewWindow()
{
	FeaturesTableForNewType = new WindowSetFeaturesForNewTypeDevice;
}

void WindowAddNewPosition::AddNewNameInNewWindow()
{
	qDebug() << "TEST2";
}

void WindowAddNewPosition::AddNewStatusSlot()
{
	qDebug() << "TEST3";
}

void WindowAddNewPosition::SetFeaturesForExistNameSlot()
{
	qDebug() << "TEST4";
}

void WindowAddNewPosition::OkSlot()
{
	qDebug() << "TEST5";
}

void WindowAddNewPosition::CancelSlot()
{
	qDebug() << "TEST6";
}
