#ifndef BROKERDB_H
#define BROKERDB_H

#include "QString"
//#include <Qvector>
#include "workwithdevice.h"
#include <QObject>

class brokerdb : public QObject
{
	Q_OBJECT

//	workwithdevice* WorkingDevice;
	int td;
	QSqlDatabase db;

//	void GetContentToWindowOfDevice(int typedevice);

	//список принимаемых из окон добавления устройств всех параметров устройств
	int sumIndexTypeDevice;
	int sumIndexNameDevice;
	bool sumOnGuarantee;
	bool sumLicense;
	int sumOSVersion;
	QString sumSerialNumber;
	int sumPhoto;
	int sumStatus;
	int sumResponsible;
	int sumTypeInterface;
	int sumCountEthernet;
	int sumTypeCartridge;
	bool sumNewOrNot;
	int sumTypeContacts;
	int sumDiagonal;
	int sumVideoInterface;
	int sumCountUSB;
	int sumTypePhone;
	int sumTypeWiFi;
	int sumCountAccum;
	int sumTypeAccum;
	int sumSubdivision;
	int sumCoworker;
	QString strF;
	QString str;

	//длина табличных полей, которые будут заполняться, нужно для контроля ввода
	int lengthNameDevice;
	int lenghtTypeDevice;
	int lenghtStatus;
	int lenghtAllNameCoworker;
	int lenghtEmail;
	int lenghtSubdivision;
	int lenghtSerialNumber;


//	QSqlQuery query2;

public:
	brokerdb();
	~brokerdb();
	bool createConnection();
	int getLengthNameDevice();
	int getLenghtTypeDevice();
	int getLenghtStatus();
	int getLenghtAllNameCoworker();
	int getLenghtEmail();
	int getLenghtSubdivision();
	int getLenghtSerialNumber();

public slots:
	int getTypeFromDB();
	int getNameFromDB();
	int getStatusFromDB();

//	bool insertNewTypeToDB();
//	bool insertNewNameToDB();
//	bool insertNewFeatureToDB();

private slots:
//	void  slotAddDataAboutNewDevice(int typedevice);


signals:
	void pushQueryTypeDevice(QSqlQuery);
	void pushQueryNameDevice(QSqlQuery);
	void pushQueryStatusDevice(QSqlQuery);

//	OLD
//	refreshTable();
//	ClearAllItems();

};

#endif // BROKERDB_H
