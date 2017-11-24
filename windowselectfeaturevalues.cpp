#include "windowselectfeaturevalues.h"
#include "ui_windowselectfeaturevalues.h"

windowSelectFeatureValues::windowSelectFeatureValues(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::windowSelectFeatureValues)
{
	ui->setupUi(this);

	vertBoxLayout = new QVBoxLayout;
	horBoxLayout = new QHBoxLayout;
	horBottomButtonsBoxLayout = new QHBoxLayout;

	OkButton = new QPushButton;
	CancelButton = new QPushButton;

	struct featureSet
	{
		QLabel featureNameLabel;
		QComboBox featureValueBox;
	};

	featureSet.featureNameLabel.setText("test");

	QVector<featureSet> Features;
	QLabel tempLabel;
	QComboBox tempBox;

	for(auto it = Features.begin(); it != Features.end(); it++)
	{
		horBoxLayout->addWidget(it->featuresSet.featureNameLabel);
		horBoxLayout->addWidget(it->featuresSet.featureValueBox);
		vertBoxLayout->addItem(horBoxLayout);
		vertBoxLayout->addStretch(1);
	}
	horBottomButtonsBoxLayout->addWidget(OkButton);
	horBottomButtonsBoxLayout->addWidget(CancelButton);

	vertBoxLayout->addItem(horBottomButtonsBoxLayout);

	this->setLayout(vertBoxLayout);
	this->show();
}

windowSelectFeatureValues::~windowSelectFeatureValues()
{
	delete ui;
}
