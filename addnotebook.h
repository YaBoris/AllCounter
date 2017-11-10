#ifndef ADDNOTEBOOK_H
#define ADDNOTEBOOK_H

#include <QDialog>

namespace Ui {
class addnotebook;
}

class addnotebook : public QDialog
{
	Q_OBJECT

public:
	explicit addnotebook(QWidget *parent = 0);
	~addnotebook();

private:
	Ui::addnotebook *ui;
};

#endif // ADDNOTEBOOK_H
