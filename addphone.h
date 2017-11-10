#ifndef ADDPHONE_H
#define ADDPHONE_H

#include <QDialog>

namespace Ui {
class addphone;
}

class addphone : public QDialog
{
	Q_OBJECT

public:
	explicit addphone(QWidget *parent = 0);
	~addphone();

private:
	Ui::addphone *ui;
};

#endif // ADDPHONE_H
