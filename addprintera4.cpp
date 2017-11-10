#include "addprintera4.h"
#include "ui_addprintera4.h"

addprintera4::addprintera4(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addprintera4)
{
	ui->setupUi(this);
}

addprintera4::~addprintera4()
{
	delete ui;
}
