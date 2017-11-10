#include "addmonitor.h"
#include "ui_addmonitor.h"

addmonitor::addmonitor(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addmonitor)
{
	ui->setupUi(this);
}

addmonitor::~addmonitor()
{
	delete ui;
}
