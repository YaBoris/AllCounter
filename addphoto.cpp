#include "addphoto.h"
#include "ui_addphoto.h"

addphoto::addphoto(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addphoto)
{
	ui->setupUi(this);
}

addphoto::~addphoto()
{
	delete ui;
}
