#include "windowaddnewfeaturetofeaturelist.h"
#include "ui_windowaddnewfeaturetofeaturelist.h"

AddNewFeatureToFeatureList::AddNewFeatureToFeatureList(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::AddNewFeatureToFeatureList)
{
	ui->setupUi(this);

	titleNameFeature = new QLabel;
	titleTypeFeatureDigitOrText = new QLabel;
	titleNameOfNewFeature = new QLabel;
	titleNameFeature->setText("Существующие характеристики");
	titleTypeFeatureDigitOrText->setText("Обязательно отметьте тип характеристики");
	titleNameOfNewFeature->setText("Введите название новой характеристики");

	featureBox = new QComboBox;

	newFeatureLine = new QLineEdit;

	DigitalRButton = new QRadioButton;
	TextRButton = new QRadioButton;
	DigitalRButton->setText("Цифровая");
	TextRButton->setText("Текстовая");
	newValueLine = new QLineEdit;

	OkButton = new QPushButton;
	CancelButton = new QPushButton;
	addNewFeatureButton = new QPushButton;
	OkButton->setText("Ок");
	CancelButton->setText("Отмена");
	addNewFeatureButton->setText("Добавить");

	vertBoxLayout = new QVBoxLayout;
	vertBoxLayout->setContentsMargins(20, 15, 20, 15);

	horBoxRButtonsLayout = new QHBoxLayout;
	horBoxNewValueLineLayout = new QHBoxLayout;
	horBoxBottomButtonLayout = new QHBoxLayout;
	horBoxRButtonsLayout->setAlignment(Qt::AlignCenter);
	horBoxRButtonsLayout->setContentsMargins(15, 0, 15, 0);

	horBoxBottomButtonLayout->setAlignment(Qt::AlignRight);
	horBoxBottomButtonLayout->setSpacing(10);
	horBoxBottomButtonLayout->setContentsMargins(0, 0, 20, 0);

	vertBoxLayout->addWidget(titleNameFeature);
	vertBoxLayout->addWidget(featureBox);
	vertBoxLayout->addStretch(1);
	vertBoxLayout->addWidget(titleTypeFeatureDigitOrText);
	horBoxRButtonsLayout->addWidget(DigitalRButton);
	horBoxRButtonsLayout->addWidget(TextRButton);
	vertBoxLayout->addItem(horBoxRButtonsLayout);
	vertBoxLayout->addStretch(1);
	vertBoxLayout->addWidget(titleNameOfNewFeature);
	horBoxNewValueLineLayout->addWidget(newFeatureLine);
	horBoxNewValueLineLayout->addWidget(addNewFeatureButton);
	vertBoxLayout->addItem(horBoxNewValueLineLayout);
	vertBoxLayout->addStretch(1);
	horBoxBottomButtonLayout->addWidget(OkButton);
	horBoxBottomButtonLayout->addWidget(CancelButton);
	vertBoxLayout->addItem(horBoxBottomButtonLayout);

	this->setLayout(vertBoxLayout);
	this->show();
}

AddNewFeatureToFeatureList::~AddNewFeatureToFeatureList()
{
	delete titleNameFeature;
	delete titleTypeFeatureDigitOrText;
	delete titleNameOfNewFeature;
	delete featureBox;
	delete newFeatureLine;
	delete DigitalRButton;
	delete TextRButton;
	delete newValueLine;
	delete OkButton;
	delete CancelButton;
	delete addNewFeatureButton;
	delete vertBoxLayout;
	delete horBoxRButtonsLayout;
	delete horBoxNewValueLineLayout;
	delete horBoxBottomButtonLayout;

	delete ui;
}
