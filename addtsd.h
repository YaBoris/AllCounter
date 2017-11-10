#ifndef ADDTSD_H
#define ADDTSD_H

#include <QDialog>

namespace Ui {
class addtsd;
}

class addtsd : public QDialog
{
	Q_OBJECT

public:
	explicit addtsd(QWidget *parent = 0);
	~addtsd();

private:
	Ui::addtsd *ui;
};

#endif // ADDTSD_H
