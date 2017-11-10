#ifndef ADDPRINTERZEBRA_H
#define ADDPRINTERZEBRA_H

#include <QDialog>

namespace Ui {
class addprinterzebra;
}

class addprinterzebra : public QDialog
{
	Q_OBJECT

public:
	explicit addprinterzebra(QWidget *parent = 0);
	~addprinterzebra();

private:
	Ui::addprinterzebra *ui;
};

#endif // ADDPRINTERZEBRA_H
