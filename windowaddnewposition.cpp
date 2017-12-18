#include "windowaddnewposition.h"
#include "ui_windowaddnewposition.h"

WindowAddNewPosition::WindowAddNewPosition(brokerdb* pBroker, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::WindowAddNewPosition)
{
	ui->setupUi(this);
	pointerBroker = pBroker;

	ComparativeList = new QVector<Comparative>;

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

	leftSymbolsType = new QLabel;
	leftSymbolsName = new QLabel;
	leftSymbolsStatus = new QLabel;

	NoteForNewTypeLabel = new QLabel;
	NoteForNewNameLabel = new QLabel;
	NoteForNewStatusLabel = new QLabel;

	QString lengthLine;
	QString tempStringLine = "Осталось " + lengthLine.setNum(pointerBroker->getLenghtTypeDevice()) + " символов";
	leftSymbolsType->setText(tempStringLine);
	leftSymbolsType->setStyleSheet("color: rgb(80, 80, 80)");
	tempStringLine = "Осталось " + lengthLine.setNum(pointerBroker->getLengthNameDevice()) + " символов";
	leftSymbolsName->setText(tempStringLine);
	leftSymbolsName->setStyleSheet("color: rgb(80, 80, 80)");
//	ui->leftSymbolsSerial->setAlignment(Qt::AlignRight);
	tempStringLine = "Осталось " + lengthLine.setNum(pointerBroker->getLenghtStatus()) + " символов";
	leftSymbolsStatus->setText(tempStringLine);
	leftSymbolsStatus->setStyleSheet("color: rgb(80, 80, 80)");

//	NoteString = new QString;

	TitleOfTypesDevices->setText("Выберите тип устройства");
	TitleOfNamesDevices->setText("Выберите название устройства");
	TitleOfStatusDevices->setText("Выберите статус устройства");

	NoteForNewTypeLabel->setText("или введите название нового типа(можно цифры, буквы и дефис)");
	NoteForNewNameLabel->setText("или введите новое название(можно цифры, буквы и дефис)");
	NoteForNewStatusLabel->setText("или введите название нового статуса(можно цифры, буквы и дефис)");

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
	vertBoxLayout->addWidget(NoteForNewTypeLabel);
	horBoxLayoutAddType->addWidget(NewTypeDeviceLine);
	horBoxLayoutAddType->addWidget(NextAddTypeDeviceButton);
	vertBoxLayout->addItem(horBoxLayoutAddType);
	vertBoxLayout->addWidget(leftSymbolsType);

	vertBoxLayout->addStretch(1);
	vertBoxLayout->addWidget(TitleOfNamesDevices);
	vertBoxLayout->addWidget(BoxOfNamesDevices);
	vertBoxLayout->addWidget(NoteForNewNameLabel);
	horBoxLayoutAddName->addWidget(NewNameDeviceLine);
	horBoxLayoutAddName->addWidget(NextAddNameDeviceButton);
	vertBoxLayout->addItem(horBoxLayoutAddName);
	vertBoxLayout->addWidget(leftSymbolsName);

	vertBoxLayout->addStretch(1);
	vertBoxLayout->addWidget(TitleOfStatusDevices);
	vertBoxLayout->addWidget(BoxOfStatusDevices);
	vertBoxLayout->addWidget(NoteForNewStatusLabel);
	horBoxLayoutAddStatus->addWidget(NewStatusOfDeviceLine);
	horBoxLayoutAddStatus->addWidget(AddStatusButton);
	vertBoxLayout->addItem(horBoxLayoutAddStatus);
	vertBoxLayout->addWidget(leftSymbolsStatus);

	vertBoxLayout->addStretch(2);
	vertBoxLayout->addLayout(horBoxLayoutBottomButtons);

	this->setLayout(vertBoxLayout);

	NextAddTypeDeviceButton->setDisabled(true);
	this->show();

	connect(WindowAddNewPosition::NextAddTypeDeviceButton, SIGNAL(released()), this, SLOT(AddFeaturesToNewTypeInNewWindow()));
	connect(WindowAddNewPosition::NextAddNameDeviceButton, SIGNAL(released()), this, SLOT(AddNewNameInNewWindow()));
	connect(WindowAddNewPosition::AddStatusButton, SIGNAL(released()), this, SLOT(AddNewStatusSlot()));
	connect(WindowAddNewPosition::SetFeaturesOfDevicesButton, SIGNAL(released()), this, SLOT(SetFeaturesForExistNameSlot()));
	connect(WindowAddNewPosition::OkButton, SIGNAL(released()), this, SLOT(OkSlot()));
	connect(WindowAddNewPosition::CancelButton, SIGNAL(released()), this, SLOT(CancelSlot()));

	QObject::connect(this, SIGNAL(getType()), pointerBroker, SLOT(getTypeFromDBSlot()));
	QObject::connect(pointerBroker, SIGNAL(pushQueryTypeDevice(QSqlQuery)), this, SLOT(getQueryTypeDeviceSlot(QSqlQuery)));

	QObject::connect(this, SIGNAL(getName()), pointerBroker, SLOT(getNameFromDBSlot()));
	QObject::connect(pointerBroker, SIGNAL(pushQueryNameDevice(QSqlQuery)), this, SLOT(getQueryNameDeviceSlot(QSqlQuery)));

	QObject::connect(this, SIGNAL(getStatus()), pointerBroker, SLOT(getStatusFromDBSlot()));
	QObject::connect(pointerBroker, SIGNAL(pushQueryStatusDevice(QSqlQuery)), this, SLOT(getQueryStatus(QSqlQuery)));

	QObject::connect(NewTypeDeviceLine, SIGNAL(textChanged(QString)), this, SLOT(ControlTypeNameInLineSlot(QString)));
	QObject::connect(NewNameDeviceLine, SIGNAL(textChanged(QString)), this, SLOT(ControlNameDeviceInLineSlot(QString)));
	QObject::connect(NewStatusOfDeviceLine, SIGNAL(textChanged(QString)), this, SLOT(ControlStatusInLineSlot(QString)));

	emit getType();
	emit getName();
	emit getStatus();
}

WindowAddNewPosition::~WindowAddNewPosition()
{
	delete ui;
}

//SLOTS
void WindowAddNewPosition::AddFeaturesToNewTypeInNewWindow()
{
	FeaturesTableForNewType = new WindowSetFeaturesForNewTypeDevice(pointerBroker, NewTypeDeviceLine->text());
}

void WindowAddNewPosition::AddNewNameInNewWindow()
{
	qDebug() << "AddNewNameInNewWindow";
	QString text = NewNameDeviceLine->text();
	emit insertNewNameDeviceToDB(text);
	//SelectValuesOfFeatures = new windowSelectFeatureValues;
}

void WindowAddNewPosition::AddNewStatusSlot()
{
	qDebug() << "AddNewStatusSlot";
}

void WindowAddNewPosition::SetFeaturesForExistNameSlot()
{
	SelectValuesOfFeatures = new windowSelectFeatureValues;
}

void WindowAddNewPosition::OkSlot()
{
	qDebug() << "OkSlot";
	emit reject();
}

void WindowAddNewPosition::CancelSlot()
{
	emit reject();
}

void WindowAddNewPosition::getQueryTypeDeviceSlot(QSqlQuery queryTypeDevice)
{
	QStringList strList;
//	QString str;
	QSqlRecord rec;
	int indexTemp = 0;
	ComparativeList->clear();

	rec = queryTypeDevice.record();
	ComparativeList->resize(rec.count());
	QVector<Comparative>::Iterator iter = ComparativeList->begin();

	while(queryTypeDevice.next())
	{
		iter->nameItem = queryTypeDevice.value(rec.indexOf("typedevice")).toString();
		iter->DBIndex = queryTypeDevice.value(rec.indexOf("id")).toInt();
		iter->ComboBoxIndex = indexTemp+1;
		strList << iter->nameItem;
		indexTemp++;
		iter++;
		//---------------------------------
		if(iter == ComparativeList->end())
			break;
	}
	BoxOfTypesDevices->clear();
	BoxOfTypesDevices->addItems(strList);
}

void WindowAddNewPosition::getQueryNameDeviceSlot(QSqlQuery queryNameDevice)
{
	QStringList strList;
	QSqlRecord rec;
	int indexTemp = 0;
	ComparativeList->clear();

	rec = queryNameDevice.record();
	ComparativeList->resize(rec.count());
	QVector<Comparative>::Iterator iter = ComparativeList->begin();

	while(queryNameDevice.next())
	{
		iter->nameItem = queryNameDevice.value(rec.indexOf("namedevice")).toString();
		iter->DBIndex = queryNameDevice.value(rec.indexOf("id")).toInt();
		iter->ComboBoxIndex = indexTemp+1;
		strList << iter->nameItem;
		indexTemp++;
		iter++;
		//---------------------------------
		if(iter == ComparativeList->end())
			break;
	}
	BoxOfNamesDevices->clear();
	BoxOfNamesDevices->addItems(strList);
}

void WindowAddNewPosition::getQueryStatus(QSqlQuery queryStatus)
{
	QStringList strList;
	QSqlRecord rec;
	int indexTemp = 0;
	ComparativeList->clear();

	rec = queryStatus.record();
	ComparativeList->resize(rec.count());
	QVector<Comparative>::Iterator iter = ComparativeList->begin();

	while(queryStatus.next())
	{
		iter->nameItem = queryStatus.value(rec.indexOf("status")).toString();
		iter->DBIndex = queryStatus.value(rec.indexOf("id")).toInt();
		iter->ComboBoxIndex = indexTemp+1;
		strList << iter->nameItem;
		indexTemp++;
		iter++;
		//---------------------------------
		if(iter == ComparativeList->end())
			break;
	}
	BoxOfStatusDevices->clear();
	BoxOfStatusDevices->addItems(strList);
}

void WindowAddNewPosition::ControlTypeNameInLineSlot(QString textString)
{
	int countDown = pointerBroker->getLenghtTypeDevice();
	QString warningString = "Название не должно превышать " + QString::number(countDown) + " символов!";


	NewTypeDeviceLine->setText(textString.remove(QRegExp("[^0-9а-яА-Я/- ]")));

	if(textString.length() > countDown && textString.length() > prevNoteString.length())
	{
		OkButton->setDisabled(true);
		NextAddTypeDeviceButton->setDisabled(true);
		leftSymbolsType->setText("Осталось " + QString::number(countDown - (textString.length())) + " символов");
		QMessageBox::critical(0, "Внимание!", warningString, QMessageBox::Ok);
	}
	else if(textString.length() > countDown && textString.length() < prevNoteString.length())
	{
//		ui->pushButtonSave->setDisabled(true);
		NextAddTypeDeviceButton->setDisabled(true);
		leftSymbolsType->setText("Осталось " + QString::number(countDown - (textString.length())) + " символов");
	}
	else if(textString.length() <= countDown && textString.length() != 0)
	{
//		ui->pushButtonSave->setDisabled(false);
		NextAddTypeDeviceButton->setDisabled(false);
		leftSymbolsType->setText("Осталось " + QString::number(countDown - (textString.length())) + " символов");
	}
	else if(textString.length() <= countDown && textString.length() == 0)
	{
		leftSymbolsType->setText("Осталось " + QString::number(countDown) + " символов");
		NextAddTypeDeviceButton->setDisabled(true);
	}
	prevNoteString = textString;
}

void WindowAddNewPosition::ControlNameDeviceInLineSlot(QString textString)
{
	int countDown = pointerBroker->getLengthNameDevice();
	QString warningString = "Название не должно превышать " + QString::number(countDown) + " символов!";

	NewNameDeviceLine->setText(textString.remove(QRegExp("[^0-9a-zA-ZаяА-Я/-]")));

	if(textString.length() > countDown && textString.length() > prevNoteString.length())
	{
		OkButton->setDisabled(true);
//		ui->pushAddAndContinue->setDisabled(true);
		leftSymbolsName->setText("Осталось " + QString::number(countDown - (textString.length())) + " символов");
		QMessageBox::critical(0, "Внимание!", warningString, QMessageBox::Ok);
	}
	else if(textString.length() > countDown && textString.length() < prevNoteString.length())
	{
//		ui->pushButtonSave->setDisabled(true);
//		ui->pushAddAndContinue->setDisabled(true);
		leftSymbolsName->setText("Осталось " + QString::number(countDown - (textString.length())) + " символов");
	}
	else if(textString.length() <= countDown)
	{
//		ui->pushButtonSave->setDisabled(false);
//		ui->pushAddAndContinue->setDisabled(false);
		leftSymbolsName->setText("Осталось " + QString::number(countDown - (textString.length())) + " символов");
	}
	prevNoteString = textString;
}

void WindowAddNewPosition::ControlStatusInLineSlot(QString textString)
{
	int countDown = pointerBroker->getLenghtStatus();
	QString warningString = "Название не должно превышать " + QString::number(countDown) + " символов!";

	NewStatusOfDeviceLine->setText(textString.remove(QRegExp("[^а-яА-Я/-]")));

	if(textString.length() > countDown && textString.length() > prevNoteString.length())
	{
		OkButton->setDisabled(true);
//		ui->pushAddAndContinue->setDisabled(true);
		leftSymbolsStatus->setText("Осталось " + QString::number(countDown - (textString.length())) + " символов");
		QMessageBox::critical(0, "Внимание!", warningString, QMessageBox::Ok);
	}
	else if(textString.length() > countDown && textString.length() < prevNoteString.length())
	{
//		ui->pushButtonSave->setDisabled(true);
//		ui->pushAddAndContinue->setDisabled(true);
		leftSymbolsStatus->setText("Осталось " + QString::number(countDown - (textString.length())) + " символов");
	}
	else if(textString.length() <= countDown)
	{
//		ui->pushButtonSave->setDisabled(false);
//		ui->pushAddAndContinue->setDisabled(false);
		leftSymbolsStatus->setText("Осталось " + QString::number(countDown - (textString.length())) + " символов");
	}
	prevNoteString = textString;
}
