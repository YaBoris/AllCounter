#ifndef ADDSWITCH_H
#define ADDSWITCH_H

#include <QDialog>

namespace Ui {
class addswitch;
}

class addswitch : public QDialog
{
	Q_OBJECT

public:
	explicit addswitch(QWidget *parent = 0);
	~addswitch();

private:
	Ui::addswitch *ui;
};

#endif // ADDSWITCH_H
