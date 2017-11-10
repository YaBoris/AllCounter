#include "addphone.h"
#include "ui_addphone.h"

addphone::addphone(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addphone)
{
	ui->setupUi(this);
}

addphone::~addphone()
{
	delete ui;
}
