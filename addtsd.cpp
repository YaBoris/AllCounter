#include "addtsd.h"
#include "ui_addtsd.h"

addtsd::addtsd(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addtsd)
{
	ui->setupUi(this);
}

addtsd::~addtsd()
{
	delete ui;
}
