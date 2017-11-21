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

	vertBoxLayout = new QVBoxLayout;
	horBoxRButtonsLayout = new QHBoxLayout;
	horBoxNewValueLineLayout = new QHBoxLayout;
	horBoxBottomButtonLayout = new QHBoxLayout;

	vertBoxLayout->addWidget(titleNameFeature);
	vertBoxLayout->addWidget(featureBox);
	vertBoxLayout->addWidget(titleTypeFeatureDigitOrText);
	horBoxRButtonsLayout->addWidget(DigitalRButton);
	horBoxRButtonsLayout->addWidget(TextRButton);
	vertBoxLayout->addItem(horBoxRButtonsLayout);
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
	delete ui;
}
