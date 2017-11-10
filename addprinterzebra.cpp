#include "addprinterzebra.h"
#include "ui_addprinterzebra.h"

addprinterzebra::addprinterzebra(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addprinterzebra)
{
	ui->setupUi(this);
}

addprinterzebra::~addprinterzebra()
{
	delete ui;
}
