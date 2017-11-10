#include "brokerdb.h"

brokerdb::brokerdb()
{
//	charger = new addcharger;
//	compcase = new addcompcase;
//	hoover = new addhoover;
//	keyboard = new addkeyboard;
//	monitor = new addmonitor;
//	mouse = new addmouse;
//	notebook = new addnotebook;
//	phone = new addphone;
//	photo = new addphoto;
//	printera4 = new addprintera4;
//	printerzebra = new addprinterzebra;
//	switch_ = new addswitch;
//	tsd = new addtsd;
//	wifi = new addwifi;
	wirelescan = new addwirelescan;
	wiredscanner = new addwiredscanner;

	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
	QObject::connect(wirelescan, SIGNAL(signalAddDeviceData(int)), SLOT(slotAddDataAboutNewDevice(int)));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
//	QObject::connect(wiredscanner, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
	QObject::connect(this, SIGNAL(ClearAllItems()), wiredscanner, SLOT(cleanAllItems()));
}

brokerdb::~brokerdb()
{
	db.close();
//	delete charger;
//	delete compcase;
//	delete hoover;
//	delete keyboard;
//	delete monitor;
//	delete mouse;
//	delete notebook;
//	delete phone;
//	delete photo;
//	delete printera4;
//	delete printerzebra;
//	delete switch_;
//	delete tsd;
//	delete wifi;
	delete wirelescan;
	delete wiredscanner;
}

bool brokerdb::createConnection()
{
	db = QSqlDatabase::addDatabase("QPSQL7");
	db.setDatabaseName("allcounter");
	db.setUserName("postgres");
	db.setHostName("localhost");
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

bool brokerdb::RecieverInDB(int typedevice)
{
	QSqlQuery query2;
	QSqlRecord rec;
	QString    strName;

	//массивы для временного хранения сопоставлений для выпадающих списков ID + порядок в выпадающем меню
	struct MenuModel
	{
		int id;
		Qstring value;
		int programm_index;
	};

	QVector <MenuModel> vecNamedevice;
	QVector <MenuModel> vecCoworker;
	QVector <MenuModel> vecSubdivision;
	QVector <MenuModel> vecStatus;

	int i = 0;
	int j = 0;

	switch (typedevice)
	{
		case 1:
			wiredscanner->DataAboutDevice.typeDevice = typedevice;
			//генерируем список для выпадающего списка типов устройств
			if (!query2.exec("SELECT * FROM namedevice WHERE index_device = 0 OR index_device = 1 ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecNamedevice.resize(query2.size());
			wiredscanner->clearStringList();
			rec     = query2.record();
			i=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("namedevice")).toString();
				wiredscanner->addStringToStringList(strName);
				vecNamedevice[i].id = query2.value(rec.indexOf("id")).toInt();
				vecNamedevice[i].value = query2.value(rec.indexOf("namedevice")).toString();
				vecNamedevice[i++].programm_index = query2.value(rec.indexOf("program_index")).toInt();
			}

			wiredscanner->SetListIntoItem(1);

			//генерируем выпадающий список откуда поступил
			if (!query2.exec("SELECT * FROM subdivision ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecSubdivision.resize(query2.size());
			rec     = query2.record();
			wiredscanner->clearStringList();
			i=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("subdivision")).toString();
				wiredscanner->addStringToStringList(strName);
				vecSubdivision[i].id = query2.value(rec.indexOf("id")).toInt();
				vecSubdivision[i].value = query2.value(rec.indexOf("subdivision")).toString();
				vecSubdivision[i++].programm_index = query2.value(rec.indexOf("program_index")).toInt();
			}

			wiredscanner->SetListIntoItem(2);

			//генерируем выпадающий список откуда поступил
			if (!query2.exec("SELECT * FROM status ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecStatus.resize(query2.size());
			rec     = query2.record();
			wiredscanner->clearStringList();

			i=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("status")).toString();
				wiredscanner->addStringToStringList(strName);
				vecStatus[i].id = query2.value(rec.indexOf("id")).toInt();
				vecStatus[i].value = query2.value(rec.indexOf("status")).toString();
				vecStatus[i++].programm_index = query2.value(rec.indexOf("program_index")).toInt();
			}

			wiredscanner->SetListIntoItem(3);

			//генерируем выпадающий список сотрудников
			if (!query2.exec("SELECT * FROM coworker ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecCoworker.resize(query2.size());
			wiredscanner->clearStringList();
			rec     = query2.record();
			i=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("surname")).toString();
				wiredscanner->addStringToStringList(strName);
				vecCoworker[i].id = query2.value(rec.indexOf("id")).toInt();
				vecCoworker[i].value = query2.value(rec.indexOf("surname")).toString();
				vecCoworker[i++].programm_index = query2.value(rec.indexOf("program_index")).toInt();
			}
			i=0;
			wiredscanner->SetListIntoItem(4);
			wiredscanner->show();
			query2.clear();
			break;

			//wirelessscanner
		case 2:
			wirelescan->DataAboutDevice.typeDevice = typedevice;
			//генерируем список для выпадающего списка типов устройств
			if (!query2.exec("SELECT * FROM namedevice  WHERE index_device = 0 OR index_device = 2 ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecNamedevice.resize(query2.size());
			rec     = query2.record();
			wirelescan->clearStringList();
			i=j=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("namedevice")).toString();
				wirelescan->addStringToStringList(strName);
				vecNamedevice[i].id = query2.value(rec.indexOf("id")).toInt();
				vecNamedevice[i].value = query2.value(rec.indexOf("namedevice")).toString();
				vecNamedevice[i++].programm_index = query2.value(rec.indexOf("program_index")).toInt();
			}
			wirelescan->SetListIntoItem(1);

			//генерируем выпадающий список откуда поступил
			if (!query2.exec("SELECT * FROM subdivision ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecSubdivision.resize(query2.size());
			rec     = query2.record();
			wirelescan->clearStringList();
			i=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("subdivision")).toString();
				wirelescan->addStringToStringList(strName);
				vecSubdivision[i].id = query2.value(rec.indexOf("id")).toInt();
				vecSubdivision[i].value = query2.value(rec.indexOf("subdivision")).toString();
				vecSubdivision[i++].programm_index = query2.value(rec.indexOf("program_index")).toInt();
			}
			wirelescan->SetListIntoItem(2);

			//генерируем выпадающий список откуда поступил
			if (!query2.exec("SELECT * FROM status ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecStatus.resize(query2.size());
			rec     = query2.record();
			wirelescan->clearStringList();
			i=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("status")).toString();
				wirelescan->addStringToStringList(strName);
				vecStatus[i].id = query2.value(rec.indexOf("id")).toInt();
				vecStatus[i].value = query2.value(rec.indexOf("status")).toString();
				vecStatus[i++].programm_index = query2.value(rec.indexOf("program_index")).toInt();
			}
			wirelescan->SetListIntoItem(3);

			//генерируем выпадающий список сотрудников
			if (!query2.exec("SELECT * FROM coworker ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecCoworker.resize(query2.size());
			rec     = query2.record();
			wirelescan->clearStringList();
			i=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("surname")).toString();
				wirelescan->addStringToStringList(strName);
				vecCoworker[i].id = query2.value(rec.indexOf("id")).toInt();
				vecCoworker[i].value = query2.value(rec.indexOf("surname")).toString();
				vecCoworker[i++].programm_index = query2.value(rec.indexOf("program_index")).toInt();
			}
			i=0;
			wirelescan->SetListIntoItem(4);
			wirelescan->show();
			query2.clear();
			break;

					//hoover
			//		case 3:

			//			break;
			//		//keyboard
			//		case 4:

			//			break;
			//		//monitor
			//		case 5:

			//			break;
			//		//mouse
			//		case 6:

			//			break;
			//		//notebook
			//		case 7:

			//			break;
			//		//phone
			//		case 8:

			//			break;
			//		//phone
			//		case 9:

			//			break;
			//		//photo
			//		case 10:

			//			break;
			//		//printerA4
			//		case 11:

			//			break;
			//		//printerzebra
			//		case 12:

			//			break;
			//		//switch
			//		case 13:

			//			break;
			//		//tsd
			//		case 14:

			//			break;
			//		//wifi
			//		case 15:

			//			break;

			//			break;
			//		//wirelessscanner
			//		case 17:

			//			break;
		default:
			break;
	}
	return true;
}

//реакция на кнопку ОК в окне проводного сканера
void  brokerdb::slotAddDataAboutNewDevice(int typedevice)
{
	switch (typedevice)
	{
		//добавление в БД проводного сканера
		case 1:
		{
			QSqlQuery query;
			//Формируем запрос на добавление и отправляем его в БД
			strF.clear();
			str.clear();

			strF =
			  "INSERT INTO  summary (typedevice, namedevice, serialnumber, status, license, acceptor, subdivision, fromsubdivision, newornot,  guarantee, type_interface, ethernet_count, type_cartridge, type_contact, diagonal, video_in, usb_count, type_phone, type_wifi, accum_count, accum_type, os_version, notation, add_date) "
			  "VALUES('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15', '%16', '%17', '%18', '%19', '%20', '%21', '%22', '%23', '%24');";

			str = strF.arg(wiredscanner->DataAboutDevice.typeDevice)
					.arg(wiredscanner->DataAboutDevice.nameDevice)
					.arg(wiredscanner->DataAboutDevice.serialNumber)
					.arg(wiredscanner->DataAboutDevice.status)
					.arg(wiredscanner->DataAboutDevice.license)
					.arg(wiredscanner->DataAboutDevice.coworker)
					.arg(wiredscanner->DataAboutDevice.subDivision)
					.arg(wiredscanner->DataAboutDevice.fromSubDivision)
					.arg(wiredscanner->DataAboutDevice.newOrNot)
					.arg(wiredscanner->DataAboutDevice.guarantee)
					.arg(wiredscanner->DataAboutDevice.type_interface)
					.arg(wiredscanner->DataAboutDevice.ethernet_count)
					.arg(wiredscanner->DataAboutDevice.type_cartridge)
					.arg(wiredscanner->DataAboutDevice.type_contact)
					.arg(wiredscanner->DataAboutDevice.diagonal)
					.arg(wiredscanner->DataAboutDevice.video_in)
					.arg(wiredscanner->DataAboutDevice.usb_count)
					.arg(wiredscanner->DataAboutDevice.type_phone)
					.arg(wiredscanner->DataAboutDevice.type_wifi)
					.arg(wiredscanner->DataAboutDevice.accum_count)
					.arg(wiredscanner->DataAboutDevice.accum_type)
					.arg(wiredscanner->DataAboutDevice.os_version)
					.arg(wiredscanner->DataAboutDevice.note)
					.arg("NOW()");
			query.clear();
			if (!query.exec(str))
			{
				qDebug() << "\nbrokerdb.cpp: " << query.lastError().databaseText();
			}
			emit ClearAllItems();
			emit refreshTable();
		}
			break;

			//добавление в БД беспроводного сканера
			case 2:
			{
				QSqlQuery query;
				//Формируем запрос на добавление и отправляем его в БД
				strF.clear();
				str.clear();

				strF =
				  "INSERT INTO  summary (typedevice, namedevice, serialnumber, status, license, acceptor, subdivision, fromsubdivision, newornot,  guarantee, type_interface, ethernet_count, type_cartridge, type_contact, diagonal, video_in, usb_count, type_phone, type_wifi, accum_count, accum_type, os_version, notation, add_date) "
				  "VALUES('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11', '%12', '%13', '%14', '%15', '%16', '%17', '%18', '%19', '%20', '%21', '%22', '%23', '%24');";

				str = strF.arg(wirelescan->DataAboutDevice.typeDevice)
						.arg(wirelescan->DataAboutDevice.nameDevice)
						.arg(wirelescan->DataAboutDevice.serialNumber)
						.arg(wirelescan->DataAboutDevice.status)
						.arg(wirelescan->DataAboutDevice.license)
						.arg(wirelescan->DataAboutDevice.coworker)
						.arg(wirelescan->DataAboutDevice.subDivision)
						.arg(wirelescan->DataAboutDevice.fromSubDivision)
						.arg(wirelescan->DataAboutDevice.newOrNot)
						.arg(wirelescan->DataAboutDevice.guarantee)
						.arg(wirelescan->DataAboutDevice.type_interface)
						.arg(wirelescan->DataAboutDevice.ethernet_count)
						.arg(wirelescan->DataAboutDevice.type_cartridge)
						.arg(wirelescan->DataAboutDevice.type_contact)
						.arg(wirelescan->DataAboutDevice.diagonal)
						.arg(wirelescan->DataAboutDevice.video_in)
						.arg(wirelescan->DataAboutDevice.usb_count)
						.arg(wirelescan->DataAboutDevice.type_phone)
						.arg(wirelescan->DataAboutDevice.type_wifi)
						.arg(wirelescan->DataAboutDevice.accum_count)
						.arg(wirelescan->DataAboutDevice.accum_type)
						.arg(wirelescan->DataAboutDevice.os_version)
						.arg(wirelescan->DataAboutDevice.note)
						.arg("NOW()");
				query.clear();
				if (!query.exec(str))
				{
					qDebug() << "\nbrokerdb.cpp: " << query.lastError().databaseText();
				}
				emit ClearAllItems();
				emit refreshTable();
			}
			break;
		default:
				break;
	}
}
