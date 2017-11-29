#include "windowselectfeaturevalues.h"
#include "ui_windowselectfeaturevalues.h"

windowSelectFeatureValues::windowSelectFeatureValues(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::windowSelectFeatureValues)
{
	ui->setupUi(this);

	baseWidget = new QWidget(this);

	scrolling = new QScrollArea(baseWidget);
	scrolling->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrolling->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	baseWidget->resize(this->width(), this->height());
	scrolling->resize(this->width(), this->height());

	vertBoxLayout = new QVBoxLayout;
	vertBoxFull = new QVBoxLayout;

	OkButton = new QPushButton;
	CancelButton = new QPushButton;

	horBottomButtonsBoxLayout = new QHBoxLayout(this);

	label1 = new QLabel;
	label2 = new QLabel;
	label3 = new QLabel;
	label4 = new QLabel;
	label5 = new QLabel;
	label6 = new QLabel;
	label7 = new QLabel;
	label8 = new QLabel;
	label9 = new QLabel;
	label10 = new QLabel;
	label11 = new QLabel;
	label12 = new QLabel;
	label13 = new QLabel;
	label14 = new QLabel;
	label15 = new QLabel;
	label16 = new QLabel;
	label17 = new QLabel;
	label18 = new QLabel;
	label19 = new QLabel;
	label20 = new QLabel;

	box1 = new QComboBox;
	box2 = new QComboBox;
	box3 = new QComboBox;
	box4 = new QComboBox;
	box5 = new QComboBox;
	box6 = new QComboBox;
	box7 = new QComboBox;
	box8 = new QComboBox;
	box9 = new QComboBox;
	box10 = new QComboBox;
	box11 = new QComboBox;
	box12 = new QComboBox;
	box13 = new QComboBox;
	box14 = new QComboBox;
	box15 = new QComboBox;
	box16 = new QComboBox;
	box17 = new QComboBox;
	box18 = new QComboBox;
	box19 = new QComboBox;
	box20 = new QComboBox;

	const int SIZE = 20;

	struct strFeaturesSet
	{
		int index;
		QString FeatureNameString;
		QStringList FeatureValuesList;
	}FeaturesVector[SIZE];

	OkButton->setText("Ok");
	CancelButton->setText("Отмена");

	//TEST
	for(unsigned int tempIndex = 0; tempIndex < SIZE; tempIndex++)
	{
		FeaturesVector[tempIndex].FeatureNameString = "NameTest1";
		FeaturesVector[tempIndex].FeatureValuesList << "ValueTest1" << "ValueTest2" << "ValueTest3";
	}
	//END TEST

	for(unsigned int tempIndex2 = 0; tempIndex2 < SIZE; tempIndex2++)
	{
		switch (tempIndex2)
		{
			case 0:
				label1->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box1->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label1);
				scrolling->setWidget(box1);
				break;
			case 1:
				label2->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box2->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label2);
				scrolling->setWidget(box2);
				break;
			case 2:
				label3->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box3->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label3);
				scrolling->setWidget(box3);
				break;
			case 3:
				label4->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box4->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label4);
				scrolling->setWidget(box4);
				break;
			case 4:
				label5->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box5->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label5);
				scrolling->setWidget(box5);
				break;
			case 5:
				label6->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box6->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label6);
				scrolling->setWidget(box6);
				break;
			case 6:
				label7->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box7->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label7);
				scrolling->setWidget(box7);
				break;
			case 7:
				label8->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box8->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label8);
				scrolling->setWidget(box8);
				break;
			case 8:
				label9->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box9->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label9);
				scrolling->setWidget(box9);
				break;
			case 9:
				label10->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box10->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label10);
				scrolling->setWidget(box10);
				break;
			case 10:
				label11->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box11->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label11);
				scrolling->setWidget(box11);
				break;
			case 11:
				label12->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box12->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label12);
				scrolling->setWidget(box12);
				break;
			case 12:
				label13->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box13->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label13);
				scrolling->setWidget(box13);
				break;
			case 13:
				label14->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box14->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label14);
				scrolling->setWidget(box14);
				break;
			case 14:
				label15->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box15->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label15);
				scrolling->setWidget(box15);
				break;
			case 15:
				label16->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box16->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label16);
				scrolling->setWidget(box16);
				break;
			case 16:
				label17->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box17->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label17);
				scrolling->setWidget(box17);
				break;
			case 17:
				label18->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box18->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label18);
				scrolling->setWidget(box18);
				break;
			case 18:
				label19->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box19->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label19);
				scrolling->setWidget(box19);
				break;
			case 19:
				label20->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box20->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				scrolling->setWidget(label20);
				scrolling->setWidget(box20);
				break;
			default:
				break;
		}
//		vertBoxLayout->addStretch(1);
	}

	horBottomButtonsBoxLayout->addWidget(OkButton);
	horBottomButtonsBoxLayout->addWidget(CancelButton);
	horBottomButtonsBoxLayout->setAlignment(Qt::AlignRight);
	horBottomButtonsBoxLayout->setContentsMargins(0, 30, 20, 20);
	horBottomButtonsBoxLayout->setSpacing(10);

	scrolling->setLayout(vertBoxLayout);
	vertBoxFull->addWidget(baseWidget);
	vertBoxFull->addStretch(1);
	vertBoxFull->addItem(horBottomButtonsBoxLayout);

	this->setLayout(vertBoxFull);
	this->show();
}

windowSelectFeatureValues::~windowSelectFeatureValues()
{
	delete label1;
	delete label2;
	delete label3;
	delete label4;
	delete label5;
	delete label6;
	delete label7;
	delete label8;
	delete label9;
	delete label10;
	delete label11;
	delete label12;
	delete label13;
	delete label14;
	delete label15;
	delete label16;
	delete label17;
	delete label18;
	delete label19;
	delete label20;
	delete box1;
	delete box2;
	delete box3;
	delete box4;
	delete box5;
	delete box6;
	delete box7;
	delete box8;
	delete box9;
	delete box10;
	delete box11;
	delete box12;
	delete box13;
	delete box14;
	delete box15;
	delete box16;
	delete box17;
	delete box18;
	delete box19;
	delete box20;

	delete OkButton;
	delete CancelButton;
	delete horBottomButtonsBoxLayout;
	delete vertBoxLayout;

	delete ui;
}
