#ifndef ADDCHARGER_H
#define ADDCHARGER_H

#include <QDialog>

namespace Ui {
class addcharger;
}

class addcharger : public QDialog
{
	Q_OBJECT

public:
	explicit addcharger(QWidget *parent = 0);
	~addcharger();

private:
	Ui::addcharger *ui;
};

#endif // ADDCHARGER_H
