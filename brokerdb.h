#ifndef BROKERDB_H
#define BROKERDB_H

#include "QString"
//#include <Qvector>
//#include "addcharger.h"
//#include "addcompcase.h"
//#include "addhoover.h"
//#include "addkeyboard.h"
//#include "addmonitor.h"
//#include "addmouse.h"
//#include "addnotebook.h"
//#include "addphone.h"
//#include "addphoto.h"
//#include "addprintera4.h"
//#include "addprinterzebra.h"
//#include "addswitch.h"
//#include "addtsd.h"
//#include "addwifi.h"
#include "addwirelescan.h"
#include "addwiredscanner.h"

class brokerdb : public QObject
{
	Q_OBJECT

//	addcharger* charger;
//	addcompcase* compcase;
//	addhoover* hoover;
//	addkeyboard* keyboard;
//	addmonitor* monitor;
//	addmouse* mouse;
//	addnotebook* notebook;
//	addphone* phone;
//	addphoto* photo;
//	addprintera4* printera4;
//	addprinterzebra* printerzebra;
//	addswitch* switch_;
//	addtsd* tsd;
//	addwifi* wifi;
	addwirelescan* wirelescan;
	addwiredscanner* wiredscanner;
	int td;
	QSqlDatabase db;

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
