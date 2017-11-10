#ifndef ADDMONITOR_H
#define ADDMONITOR_H

#include <QDialog>

namespace Ui {
class addmonitor;
}

class addmonitor : public QDialog
{
	Q_OBJECT

public:
	explicit addmonitor(QWidget *parent = 0);
	~addmonitor();

private:
	Ui::addmonitor *ui;
};

#endif // ADDMONITOR_H
