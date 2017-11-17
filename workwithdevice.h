#ifndef workwithdevice_H
#define workwithdevice_H

#include <QDialog>
#include <QtSql>
#include <clocale>
#include <QDebug>
#include <QColor>
#include "control_rec.h"
#include <QtWidgets>

namespace Ui {
class workwithdevice;
}

class workwithdevice: public QDialog
{
	Q_OBJECT

public:
	struct DeviceData
	{
		int typeDevice;
		int nameDevice;
		QString serialNumber;
		int status;
		int license;
		int coworker;
		int subDivision;
		int fromSubDivision;
		int newOrNot;
		int guarantee;
		int type_interface;
		int ethernet_count;
		int type_cartridge;
		int type_contact;
		int diagonal;
		int video_in;
		int usb_count;
		int type_phone;
		int type_wifi;
		int accum_count;
		int accum_type;
		int os_version;

		QString note;
	}DataAboutDevice;

	//массивы для временного хранения сопоставлений для выпадающих списков ID + порядок в выпадающем меню
//	struct MenuModel
//	{
//		int id;
//		Qstring value;
//		int programm_index;
//	};

//	QVector <MenuModel> vecNamedevice;
//	QVector <MenuModel> vecCoworker;
//	QVector <MenuModel> vecSubdivision;
//	QVector <MenuModel> vecStatus;

	explicit workwithdevice(QWidget *parent = 0);
	~workwithdevice();
	void SelectItemsFromDB();
	void addStringToStringList(QString stringItem);
	void clearStringList();
	void showWindow();
	void SetListIntoItem(int NumberItem);

private:
	Ui::workwithdevice *ui;
	QStringList lst;
	//промежуточные переменные для сохранения значений выпадающих списков
	QStringList lstCoworker;
	QStringList lstStatus;
	QStringList lstSubdivision;
	QStringList lstNameDevice;
	control_rec control;
	bool controlEnteredData();
	void setWindowView();
	int checkResult;
	QString NoteString;
	QString prevNoteString;
	QString SerialString;
	QString prevSerialString;

	//Резерв элементов визуализации для макета универсального окна
	QLabel lbl1;
	QLabel lbl2;
	QLabel lbl3;
	QLabel lbl4;
	QLabel lbl5;
	QLabel lbl6;
	QLabel lbl7;
	QLabel lbl8;
	QLabel lbl9;
	QLabel lbl10;
	QLabel lbl11;
	QLabel lbl12;
	QLabel lbl13;
	QLabel lbl14;
	QLabel lbl15;
	QLabel lbl16;
	QLabel lbl17;

	QComboBox lEdit1;
	QComboBox lEdit2;
	QComboBox lEdit3;
	QComboBox lEdit4;
	QComboBox lEdit5;
	QComboBox lEdit6;
	QComboBox lEdit7;
	QComboBox lEdit8;
	QComboBox lEdit9;
	QComboBox lEdit10;
	QComboBox lEdit11;
	QComboBox lEdit12;
	QComboBox lEdit13;
	QComboBox lEdit14;
	QComboBox lEdit15;
	QComboBox lEdit16;
	QComboBox lEdit17;



//	void setWindowView();

signals:
	signalNoSerial(QString);
	signalAddDeviceData(int);

private slots:
	void on_addNoSerial_clicked(bool);
	void cleanAllItems();

	void on_pushAddAndContinue_clicked();
	void on_pushButtonSave_clicked();
	void on_pushButtonCancel_clicked();

	void on_addNoteDevice_textChanged();
	void on_addSerial_textEdited(const QString &arg1);

};

#endif // workwithdevice_H
