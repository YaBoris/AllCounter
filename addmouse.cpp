#include "addmouse.h"
#include "ui_addmouse.h"

addmouse::addmouse(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addmouse)
{
	ui->setupUi(this);
}

addmouse::~addmouse()
{
	delete ui;
}
