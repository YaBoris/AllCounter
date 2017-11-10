#include "addwifi.h"
#include "ui_addwifi.h"

addwifi::addwifi(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addwifi)
{
	ui->setupUi(this);
}

addwifi::~addwifi()
{
	delete ui;
}
