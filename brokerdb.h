#ifndef BROKERDB_H
#define BROKERDB_H

#include "QString"
//#include <Qvector>
#include "workwithdevice.h"

class brokerdb : public QObject
{
	Q_OBJECT

	workwithdevice* WorkingDevice;
	int td;
	QSqlDatabase db;

	void GetContentToWindowOfDevice(int typedevice);

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


//	QSqlQuery query2;

public:
	brokerdb();
	~brokerdb();
	bool createConnection();



public slots:
	bool RecieverInDB(int typedevice);

private slots:
	void  slotAddDataAboutNewDevice(int typedevice);

signals:
	refreshTable();
	ClearAllItems();

};

#endif // BROKERDB_H
