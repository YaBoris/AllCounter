#include "windowselectfeaturevalues.h"
#include "ui_windowselectfeaturevalues.h"

windowSelectFeatureValues::windowSelectFeatureValues(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::windowSelectFeatureValues)
{
	ui->setupUi(this);

	const int SIZE = 20;
	unsigned int tempIndex2 = 0;

	baseWidget = new QWidget(ui->scrollAreaWidgetContents);
	ui->scrolling->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->scrolling->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

	baseWidget->adjustSize();
	baseWidget->setMaximumWidth(ui->scrolling->width());
	baseWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

	vertBoxLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);

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

//	ui->scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	struct strFeaturesSet
	{
		int index;
		QString FeatureNameString;
		QStringList FeatureValuesList;
	}FeaturesVector[SIZE];

	QString tempString;
	QString tempString2 = "NameTest";

	//TEST
	for(unsigned int tempIndex = 0; tempIndex < SIZE; tempIndex++)
	{
		tempString.setNum(tempIndex+1);
		tempString2.clear();
		tempString2 = "NameTest";
		tempString2 += tempString;
		FeaturesVector[tempIndex].FeatureNameString = tempString2;
		FeaturesVector[tempIndex].FeatureValuesList << "ValueTest1" << "ValueTest2" << "ValueTest3";
	}
	//END TEST

	for(tempIndex2 = 0; tempIndex2 < SIZE; tempIndex2++)
	{
		switch (tempIndex2)
		{
			case 0:
				label1->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box1->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
//				box1->setFixedWidth(ui->scrolling->width()-30);
				label1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				box1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label1);
				vertBoxLayout->addWidget(box1);
				break;
			case 1:
				label2->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box2->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label2);
				vertBoxLayout->addWidget(box2);
				break;
			case 2:
				label3->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box3->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label3);
				vertBoxLayout->addWidget(box3);
				break;
			case 3:
				label4->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box4->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label4);
				vertBoxLayout->addWidget(box4);
				break;
			case 4:
				label5->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box5->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label5);
				vertBoxLayout->addWidget(box5);
				break;
			case 5:
				label6->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box6->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label6);
				vertBoxLayout->addWidget(box6);
				break;
			case 6:
				label7->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box7->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label7);
				vertBoxLayout->addWidget(box7);
				break;
			case 7:
				label8->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box8->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label8);
				vertBoxLayout->addWidget(box8);
				break;
			case 8:
				label9->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box9->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label9);
				vertBoxLayout->addWidget(box9);
				break;
			case 9:
				label10->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box10->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box10->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label10->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label10);
				vertBoxLayout->addWidget(box10);
				break;
			case 10:
				label11->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box11->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box11->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label11->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label11);
				vertBoxLayout->addWidget(box11);
				break;
			case 11:
				label12->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box12->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box12->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label12->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label12);
				vertBoxLayout->addWidget(box12);
				break;
			case 12:
				label13->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box13->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box13->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label13->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label13);
				vertBoxLayout->addWidget(box13);
				break;
			case 13:
				label14->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box14->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box14->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label14->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label14);
				vertBoxLayout->addWidget(box14);
				break;
			case 14:
				label15->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box15->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box15->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label15->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label15);
				vertBoxLayout->addWidget(box15);
				break;
			case 15:
				label16->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box16->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box16->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label16->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label16);
				vertBoxLayout->addWidget(box16);
				break;
			case 16:
				label17->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box17->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box17->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label17->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label17);
				vertBoxLayout->addWidget(box17);
				break;
			case 17:
				label18->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box18->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box18->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label18->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label18);
				vertBoxLayout->addWidget(box18);
				break;
			case 18:
				label19->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box19->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box19->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label19->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label19);
				vertBoxLayout->addWidget(box19);
				break;
			case 19:
				label20->setText(FeaturesVector[tempIndex2].FeatureNameString);
				box20->addItems(FeaturesVector[tempIndex2].FeatureValuesList);
				box20->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				label20->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
				vertBoxLayout->addWidget(label20);
				vertBoxLayout->addWidget(box20);
				break;
			default:
				break;
		}
	}

	ui->scrollAreaWidgetContents->setFixedHeight(label1->geometry().height()+box1->geometry().height());
	ui->scrolling->resize(this->width()-40, this->height()-100);

	this->show();
}

windowSelectFeatureValues::~windowSelectFeatureValues()
{
	delete ui;
}
