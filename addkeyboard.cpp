#include "addkeyboard.h"
#include "ui_addkeyboard.h"

addkeyboard::addkeyboard(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addkeyboard)
{
	ui->setupUi(this);
}

addkeyboard::~addkeyboard()
{
	delete ui;
}
