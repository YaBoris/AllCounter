#ifndef ADDMOUSE_H
#define ADDMOUSE_H

#include <QDialog>

namespace Ui {
class addmouse;
}

class addmouse : public QDialog
{
	Q_OBJECT

public:
	explicit addmouse(QWidget *parent = 0);
	~addmouse();

private:
	Ui::addmouse *ui;
};

#endif // ADDMOUSE_H
