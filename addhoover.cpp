#include "addhoover.h"
#include "ui_addhoover.h"

addhoover::addhoover(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addhoover)
{
	ui->setupUi(this);
}

addhoover::~addhoover()
{
	delete ui;
}
