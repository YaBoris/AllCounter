#ifndef ADDHOOVER_H
#define ADDHOOVER_H

#include <QDialog>

namespace Ui {
class addhoover;
}

class addhoover : public QDialog
{
	Q_OBJECT

public:
	explicit addhoover(QWidget *parent = 0);
	~addhoover();

private:
	Ui::addhoover *ui;
};

#endif // ADDHOOVER_H
