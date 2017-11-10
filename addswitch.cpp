#include "addswitch.h"
#include "ui_addswitch.h"

addswitch::addswitch(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addswitch)
{
	ui->setupUi(this);
}

addswitch::~addswitch()
{
	delete ui;
}
