#include "addnotebook.h"
#include "ui_addnotebook.h"

addnotebook::addnotebook(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addnotebook)
{
	ui->setupUi(this);
}

addnotebook::~addnotebook()
{
	delete ui;
}
