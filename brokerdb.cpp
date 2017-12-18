#include "brokerdb.h"

brokerdb::brokerdb()
{
	lenghtEmail = 50;
	lenghtSerialNumber = lenghtStatus = lengthNameDevice = lenghtAllNameCoworker = 40;

	//к этим именам после транслита прибавляются ключевые слова, поэтому длина оригинального названия на 10 символов меньше фактической длины поля в таблице
	lenghtSubdivision = lenghtTypeDevice = 30;
//	WorkingDevice = new WorkingDevice;

//	QObject::connect(WorkingDevice, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(this, SIGNAL(ClearAllItems()), WorkingDevice, SLOT(cleanAllItems()));
}

brokerdb::~brokerdb()
{
	db.close();
}

bool brokerdb::createConnection()
{
	db = QSqlDatabase::addDatabase("QPSQL7");
	db.setDatabaseName("allcounter");
	db.setUserName("postgres");
	db.setHostName("10.0.0.86");
	db.setPassword("123456");
	if (!db.open())
	{
		qDebug() << "Cannot open database:" << db.lastError();
		return false;
	}
	else
	{
		qDebug() << "\nDB opened\n";
	}
	return true;
}

int brokerdb::getLengthNameDevice()
{
	return lengthNameDevice;
}

int brokerdb::getLenghtTypeDevice()
{
	return lenghtTypeDevice;
}

int brokerdb::getLenghtStatus()
{
	return lenghtStatus;
}

int brokerdb::getLenghtAllNameCoworker()
{
	return lenghtAllNameCoworker;
}

int brokerdb::getLenghtEmail()
{
	return lenghtEmail;
}

int brokerdb::getLenghtSubdivision()
{
	return lenghtSubdivision;
}

int brokerdb::getLenghtSerialNumber()
{
	return lenghtSerialNumber;
}



//SLOTS

int brokerdb::getTypeFromDBSlot()
{
	QSqlQuery queryTypeDeviceTable;

	if (!queryTypeDeviceTable.exec("SELECT * FROM base_type_device ORDER BY id;"))
	{
		qDebug() << "\n" << queryTypeDeviceTable.lastError().databaseText();
		return 1;
	}
	emit pushQueryTypeDevice(queryTypeDeviceTable);
	return 0;
}

int brokerdb::getNameFromDBSlot()
{
	QSqlQuery queryNameDeviceTable;

	if (!queryNameDeviceTable.exec("SELECT * FROM base_name_device ORDER BY id;"))
	{
		qDebug() << "\n" << queryNameDeviceTable.lastError().databaseText();
		return 1;
	}
	emit pushQueryNameDevice(queryNameDeviceTable);
	return 0;
}

int brokerdb::getStatusFromDBSlot()
{
	QSqlQuery queryStatusDeviceTable;

	if (!queryStatusDeviceTable.exec("SELECT * FROM required_status ORDER BY id;"))
	{
		qDebug() << "\n" << queryStatusDeviceTable.lastError().databaseText();
		return 1;
	}
	emit pushQueryStatusDevice(queryStatusDeviceTable);
	return 0;
}

int brokerdb::getFeatureListSlot()
{
	QSqlQuery queryFeatureListTable;

	if (!queryFeatureListTable.exec("SELECT * FROM FEAT_TABLE_LIST ORDER BY id;"))
	{
		qDebug() << "\n" << queryFeatureListTable.lastError().databaseText();
		return 1;
	}
	emit pushQueryFeatureList(queryFeatureListTable);
	return 0;
}



//bool brokerdb::insertNewTypeToDB()
//{
//	QSqlQuery query;

//	QString strF;
//	QString str;

//	strF.clear();
//	str.clear();

//	strF =	"INSERT INTO  summary (typedevice, namedevice, serialnumber, status, license, acceptor, subdivision, fromsubdivision, newornot,  guarantee, type_interface, ethernet_count, type_cartridge, type_contact, diagonal, video_in, usb_count, type_phone, type_wifi, accum_count, accum_type, os_version, notation, add_date) "
//			"VALUES('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15', '%16', '%17', '%18', '%19', '%20', '%21', '%22', '%23', '%24');";

//	str = strF.arg(WorkingDevice->DataAboutDevice.typeDevice)
//			.arg(WorkingDevice->DataAboutDevice.nameDevice)
//			.arg(WorkingDevice->DataAboutDevice.serialNumber)
//			.arg(WorkingDevice->DataAboutDevice.status)
//			.arg(WorkingDevice->DataAboutDevice.license)
//			.arg(WorkingDevice->DataAboutDevice.coworker)
//			.arg(WorkingDevice->DataAboutDevice.subDivision)
//			.arg(WorkingDevice->DataAboutDevice.fromSubDivision)
//			.arg(WorkingDevice->DataAboutDevice.newOrNot)
//			.arg(WorkingDevice->DataAboutDevice.guarantee)
//			.arg(WorkingDevice->DataAboutDevice.type_interface)
//			.arg(WorkingDevice->DataAboutDevice.ethernet_count)
//			.arg(WorkingDevice->DataAboutDevice.type_cartridge)
//			.arg(WorkingDevice->DataAboutDevice.type_contact)
//			.arg(WorkingDevice->DataAboutDevice.diagonal)
//			.arg(WorkingDevice->DataAboutDevice.video_in)
//			.arg(WorkingDevice->DataAboutDevice.usb_count)
//			.arg(WorkingDevice->DataAboutDevice.type_phone)
//			.arg(WorkingDevice->DataAboutDevice.type_wifi)
//			.arg(WorkingDevice->DataAboutDevice.accum_count)
//			.arg(WorkingDevice->DataAboutDevice.accum_type)
//			.arg(WorkingDevice->DataAboutDevice.os_version)
//			.arg(WorkingDevice->DataAboutDevice.note)
//			.arg("NOW()");
//	query.clear();
//	if (!query.exec(str))
//	{
//		qDebug() << "\nbrokerdb.cpp: " << query.lastError().databaseText();
//	}
//	return true;
//}

//bool brokerdb::insertNewNameToDB()
//{}

//bool brokerdb::insertNewFeatureToDB()
//{}

//реакция на кнопку ОК в окне проводного сканера
//void  brokerdb::slotAddDataAboutNewDevice(int typedevice)
//{
//	switch (typedevice)
//	{
//		//добавление в БД проводного сканера
//		case 1:
//		{
//			QSqlQuery query;
//			//Формируем запрос на добавление и отправляем его в БД
//			strF.clear();
//			str.clear();

//			strF =
//			  "INSERT INTO  summary (typedevice, namedevice, serialnumber, status, license, acceptor, subdivision, fromsubdivision, newornot,  guarantee, type_interface, ethernet_count, type_cartridge, type_contact, diagonal, video_in, usb_count, type_phone, type_wifi, accum_count, accum_type, os_version, notation, add_date) "
//			  "VALUES('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15', '%16', '%17', '%18', '%19', '%20', '%21', '%22', '%23', '%24');";

//			str = strF.arg(WorkingDevice->DataAboutDevice.typeDevice)
//					.arg(WorkingDevice->DataAboutDevice.nameDevice)
//					.arg(WorkingDevice->DataAboutDevice.serialNumber)
//					.arg(WorkingDevice->DataAboutDevice.status)
//					.arg(WorkingDevice->DataAboutDevice.license)
//					.arg(WorkingDevice->DataAboutDevice.coworker)
//					.arg(WorkingDevice->DataAboutDevice.subDivision)
//					.arg(WorkingDevice->DataAboutDevice.fromSubDivision)
//					.arg(WorkingDevice->DataAboutDevice.newOrNot)
//					.arg(WorkingDevice->DataAboutDevice.guarantee)
//					.arg(WorkingDevice->DataAboutDevice.type_interface)
//					.arg(WorkingDevice->DataAboutDevice.ethernet_count)
//					.arg(WorkingDevice->DataAboutDevice.type_cartridge)
//					.arg(WorkingDevice->DataAboutDevice.type_contact)
//					.arg(WorkingDevice->DataAboutDevice.diagonal)
//					.arg(WorkingDevice->DataAboutDevice.video_in)
//					.arg(WorkingDevice->DataAboutDevice.usb_count)
//					.arg(WorkingDevice->DataAboutDevice.type_phone)
//					.arg(WorkingDevice->DataAboutDevice.type_wifi)
//					.arg(WorkingDevice->DataAboutDevice.accum_count)
//					.arg(WorkingDevice->DataAboutDevice.accum_type)
//					.arg(WorkingDevice->DataAboutDevice.os_version)
//					.arg(WorkingDevice->DataAboutDevice.note)
//					.arg("NOW()");
//			query.clear();
//			if (!query.exec(str))
//			{
//				qDebug() << "\nbrokerdb.cpp: " << query.lastError().databaseText();
//			}
//			emit ClearAllItems();
//			emit refreshTable();
//		}
//			break;

//			//добавление в БД беспроводного сканера
//			case 2:
//			{
//				QSqlQuery query;
//				//Формируем запрос на добавление и отправляем его в БД
//				strF.clear();
//				str.clear();

//				strF =
//				  "INSERT INTO  summary (typedevice, namedevice, serialnumber, status, license, acceptor, subdivision, fromsubdivision, newornot,  guarantee, type_interface, ethernet_count, type_cartridge, type_contact, diagonal, video_in, usb_count, type_phone, type_wifi, accum_count, accum_type, os_version, notation, add_date) "
//				  "VALUES('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15', '%16', '%17', '%18', '%19', '%20', '%21', '%22', '%23', '%24');";

//				str = strF.arg(wirelescan->DataAboutDevice.typeDevice)
//						.arg(wirelescan->DataAboutDevice.nameDevice)
//						.arg(wirelescan->DataAboutDevice.serialNumber)
//						.arg(wirelescan->DataAboutDevice.status)
//						.arg(wirelescan->DataAboutDevice.license)
//						.arg(wirelescan->DataAboutDevice.coworker)
//						.arg(wirelescan->DataAboutDevice.subDivision)
//						.arg(wirelescan->DataAboutDevice.fromSubDivision)
//						.arg(wirelescan->DataAboutDevice.newOrNot)
//						.arg(wirelescan->DataAboutDevice.guarantee)
//						.arg(wirelescan->DataAboutDevice.type_interface)
//						.arg(wirelescan->DataAboutDevice.ethernet_count)
//						.arg(wirelescan->DataAboutDevice.type_cartridge)
//						.arg(wirelescan->DataAboutDevice.type_contact)
//						.arg(wirelescan->DataAboutDevice.diagonal)
//						.arg(wirelescan->DataAboutDevice.video_in)
//						.arg(wirelescan->DataAboutDevice.usb_count)
//						.arg(wirelescan->DataAboutDevice.type_phone)
//						.arg(wirelescan->DataAboutDevice.type_wifi)
//						.arg(wirelescan->DataAboutDevice.accum_count)
//						.arg(wirelescan->DataAboutDevice.accum_type)
//						.arg(wirelescan->DataAboutDevice.os_version)
//						.arg(wirelescan->DataAboutDevice.note)
//						.arg("NOW()");
//				query.clear();
//				if (!query.exec(str))
//				{
//					qDebug() << "\nbrokerdb.cpp: " << query.lastError().databaseText();
//				}
//				emit ClearAllItems();
//				emit refreshTable();
//			}
//			break;
//		default:
//				break;
//	}
//}

