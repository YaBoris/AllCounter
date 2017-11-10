#ifndef ADDCOMPCASE_H
#define ADDCOMPCASE_H

#include <QDialog>

namespace Ui {
class addcompcase;
}

class addcompcase : public QDialog
{
	Q_OBJECT

public:
	explicit addcompcase(QWidget *parent = 0);
	~addcompcase();

private:
	Ui::addcompcase *ui;
};

#endif // ADDCOMPCASE_H
