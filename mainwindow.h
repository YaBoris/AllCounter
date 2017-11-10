#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QDesktopWidget>
#include <QEvent>
#include <QtWidgets>
#include <clocale>

#include "brokerdb.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	brokerdb* broker;
	int widthWindow;
	int heightWindow;
	QSqlRelationalTableModel* model;
	QSqlDatabase db;


public:
	explicit MainWindow(QWidget *parent = 0);
//    bool eventFilter(QObject *obj, QEvent *ev);
	bool createConnection();
	void configViewTable();
	void setMainWindow(QWidget* mainWidget);

	int CountScreens;
	int widthFirstScreen;
	int heightFirstScreen;
	int widthSecondScreen;
	int heightSecondScreen;

	~MainWindow();

public slots:

	//void slotTechWork();
	void WiredScanner();
	void WirelessScanner();
	void slotRefreshTable();

private:
	QDesktopWidget* mainDesktopWidget;
	Ui::MainWindow *ui;
	QStringList headers;

signals:
	void workInDB(int);
};

#endif // MAINWINDOW_H
