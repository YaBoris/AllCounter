#include "addcharger.h"
#include "ui_addcharger.h"

addcharger::addcharger(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addcharger)
{
	ui->setupUi(this);
}

addcharger::~addcharger()
{
	delete ui;
}
