#ifndef ADDPRINTERA4_H
#define ADDPRINTERA4_H

#include <QDialog>

namespace Ui {
class addprintera4;
}

class addprintera4 : public QDialog
{
	Q_OBJECT

public:
	explicit addprintera4(QWidget *parent = 0);
	~addprintera4();

private:
	Ui::addprintera4 *ui;
};

#endif // ADDPRINTERA4_H
