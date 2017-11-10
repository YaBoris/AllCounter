#include "addcompcase.h"
#include "ui_addcompcase.h"

addcompcase::addcompcase(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addcompcase)
{
	ui->setupUi(this);
}

addcompcase::~addcompcase()
{
	delete ui;
}
