#include "windowselectfeaturevalues.h"
#include "ui_windowselectfeaturevalues.h"

windowSelectFeatureValues::windowSelectFeatureValues(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::windowSelectFeatureValues)
{
	ui->setupUi(this);

	vertBoxLayout = new QVBoxLayout;
	horBottomButtonsBoxLayout = new QHBoxLayout;
	horBox1 = new QHBoxLayout;
	horBox2 = new QHBoxLayout;
	horBox3 = new QHBoxLayout;
	horBox4 = new QHBoxLayout;
	horBox5 = new QHBoxLayout;
	horBox6 = new QHBoxLayout;
	horBox7 = new QHBoxLayout;
	horBox8 = new QHBoxLayout;
	horBox9 = new QHBoxLayout;
	horBox10 = new QHBoxLayout;
	horBox11 = new QHBoxLayout;
	horBox12 = new QHBoxLayout;
	horBox13 = new QHBoxLayout;
	horBox14 = new QHBoxLayout;
	horBox15 = new QHBoxLayout;
	horBox16 = new QHBoxLayout;
	horBox17 = new QHBoxLayout;
	horBox18 = new QHBoxLayout;
	horBox19 = new QHBoxLayout;
	horBox20 = new QHBoxLayout;

	OkButton = new QPushButton;
	CancelButton = new QPushButton;

	tempNameFeatureLabel = new QLabel;
	tempFeatureValueComboBox = new QComboBox;

	struct FeaturesStruct
	{
		int index;
		QString featureNameLabel;
		QString featureValueBox;
	} featureLine;



	//тестовая версия структуры. В рабочем виде в цикле будет заполняться из результата запроса в БД
	featureLine.index = 1;
	featureLine.featureNameLabel.setText("TESTLabel1");
	featureLine.featureValueBox.setText("TESTTooltip1");


	QVector<FeaturesStruct> FeaturesVector;
	FeaturesVector.push_back(featureLine);

	featureLine.index = 2;
	featureLine.featureNameLabel.setText("TESTLabel2");
	featureLine.featureValueBox.setText("TESTTooltip2");

	FeaturesVector.push_back(featureLine);

	//конец тестовой версии

	QVector<FeaturesStruct>::Iterator it;

	for(it = FeaturesVector.begin(); it != FeaturesVector.end(); it++)
	{
		switch (featureLine.index) {
			case 1:
				tempNameFeatureLabel->setText(&(it->featureLine.featureNameLabel));
				horBox1->addWidget(tempNameFeatureLabel);
				tempFeatureValueComboBox->setToolTip(&(it->featureLine.featureValueBox));
				horBox1->addWidget(tempFeatureValueComboBox);
				vertBoxLayout->addItem(horBox1);
				break;
			case 2:
				tempNameFeatureLabel->setText(&(it->featureLine.featureNameLabel));
				horBox2->addWidget(tempNameFeatureLabel);
				tempFeatureValueComboBox->setToolTip(&(it->featureLine.featureValueBox));
				horBox2->addWidget(tempFeatureValueComboBox);
				vertBoxLayout->addItem(horBox2);
				break;
//			case 3:
//				horBox3->addWidget(it->featureLine.featureNameLabel);
//				horBox3->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox3;
//				break;
//			case 4:
//				horBox4->addWidget(it->featureLine.featureNameLabel);
//				horBox4->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox4);
//				break;
//			case 5:
//				horBox5->addWidget(it->featureLine.featureNameLabel);
//				horBox5->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox5);
//				break;
//			case 6:
//				horBox6->addWidget(it->featureLine.featureNameLabel);
//				horBox6->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox6);
//				break;
//			case 7:
//				horBox7->addWidget(it->featureLine.featureNameLabel);
//				horBox7->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox7);
//				break;
//			case 8:
//				horBox8->addWidget(it->featureLine.featureNameLabel);
//				horBox8->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox8);
//				break;
//			case 9:
//				horBox9->addWidget(it->featureLine.featureNameLabel);
//				horBox9->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox9);
//				break;
//			case 10:
//				horBox10->addWidget(it->featureLine.featureNameLabel);
//				horBox10->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox10);
//				break;
//			case 11:
//				horBox11->addWidget(it->featureLine.featureNameLabel);
//				horBox11->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox11);
//				break;
//			case 12:
//				horBox12->addWidget(it->featureLine.featureNameLabel);
//				horBox12->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox12);
//				break;
//			case 13:
//				horBox13->addWidget(it->featureLine.featureNameLabel);
//				horBox13->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox13);
//				break;
//			case 14:
//				horBox14->addWidget(it->featureLine.featureNameLabel);
//				horBox14->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox14);
//				break;
//			case 15:
//				horBox15->addWidget(it->featureLine.featureNameLabel);
//				horBox15->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox15);
//				break;
//			case 16:
//				horBox16->addWidget(it->featureLine.featureNameLabel);
//				horBox16->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox16);
//				break;
//			case 17:
//				horBox17->addWidget(it->featureLine.featureNameLabel);
//				horBox17->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox17);
//				break;
//			case 18:
//				horBox18->addWidget(it->featureLine.featureNameLabel);
//				horBox18->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox18);
//				break;
//			case 19:
//				horBox19->addWidget(it->featureLine.featureNameLabel);
//				horBox19->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox19);
//				break;
//			case 20:
//				horBox20->addWidget(it->featureLine.featureNameLabel);
//				horBox20->addWidget(featureLine.featureValueBox);
//				vertBoxLayout->addItem(horBox20);
//				break;
			default:
				break;
		}

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
	delete tempNameFeatureLabel;
	delete tempFeatureValueComboBox;

	delete OkButton;
	delete CancelButton;
	delete horBottomButtonsBoxLayout;
	delete horBox1;
	delete horBox2;
	delete horBox3;
	delete horBox4;
	delete horBox5;
	delete horBox6;
	delete horBox7;
	delete horBox8;
	delete horBox9;
	delete horBox10;
	delete horBox11;
	delete horBox12;
	delete horBox13;
	delete horBox14;
	delete horBox15;
	delete horBox16;
	delete horBox17;
	delete horBox18;
	delete horBox19;
	delete horBox20;
	delete vertBoxLayout;

	delete ui;
}
