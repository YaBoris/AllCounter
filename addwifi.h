#ifndef ADDWIFI_H
#define ADDWIFI_H

#include <QDialog>

namespace Ui {
class addwifi;
}

class addwifi : public QDialog
{
	Q_OBJECT

public:
	explicit addwifi(QWidget *parent = 0);
	~addwifi();

private:
	Ui::addwifi *ui;
};

#endif // ADDWIFI_H
