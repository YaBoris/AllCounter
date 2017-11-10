#ifndef ADDPHOTO_H
#define ADDPHOTO_H

#include <QDialog>

namespace Ui {
class addphoto;
}

class addphoto : public QDialog
{
	Q_OBJECT

public:
	explicit addphoto(QWidget *parent = 0);
	~addphoto();

private:
	Ui::addphoto *ui;
};

#endif // ADDPHOTO_H
