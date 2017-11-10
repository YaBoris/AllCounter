#ifndef ADDKEYBOARD_H
#define ADDKEYBOARD_H

#include <QDialog>

namespace Ui {
class addkeyboard;
}

class addkeyboard : public QDialog
{
	Q_OBJECT

public:
	explicit addkeyboard(QWidget *parent = 0);
	~addkeyboard();

private:
	Ui::addkeyboard *ui;
};

#endif // ADDKEYBOARD_H
