#include "brokerdb.h"

brokerdb::brokerdb()
{
	WorkingDevice = new WorkingDevice;

	QObject::connect(WorkingDevice, SIGNAL(signalAddDeviceData()), SLOT(slotAddDataAboutNewDevice()));
	QObject::connect(this, SIGNAL(ClearAllItems()), WorkingDevice, SLOT(cleanAllItems()));
}

brokerdb::~brokerdb()
{
	db.close();
	delete WorkingDevice;
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

bool brokerdb::GetDataFromDB(int typedevice)
{
	QSqlQuery query2;
	QSqlRecord rec;
	QString    strName;

	//массивы для временного хранения сопоставлений для выпадающих списков ID + порядок в выпадающем меню


	//переделать под универсальные массивы не привязанные к конкретному комбобоксу
	struct MenuModel
	{
		int id;
		Qstring value;
		int comboBoxIndex;
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
			WorkingDevice->DataAboutDevice.typeDevice = typedevice;
			//генерируем список для выпадающего списка типов устройств
			if (!query2.exec("SELECT * FROM namedevice WHERE index_device = 0 OR index_device = 1 ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecNamedevice.resize(query2.size());
			WorkingDevice->clearStringList();
			rec     = query2.record();
			i=0;
			j=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("namedevice")).toString();
				WorkingDevice->addStringToStringList(strName);
				vecNamedevice[i].id = query2.value(rec.indexOf("id")).toInt();
				vecNamedevice[i].value = query2.value(rec.indexOf("namedevice")).toString();
				vecNamedevice[i++].comboBoxIndex = j++;
			}

			WorkingDevice->SetListIntoItem(1);

			//генерируем выпадающий список откуда поступил
			if (!query2.exec("SELECT * FROM subdivision ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecSubdivision.resize(query2.size());
			rec     = query2.record();
			WorkingDevice->clearStringList();
			i=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("subdivision")).toString();
				WorkingDevice->addStringToStringList(strName);
				vecSubdivision[i].id = query2.value(rec.indexOf("id")).toInt();
				vecSubdivision[i].value = query2.value(rec.indexOf("subdivision")).toString();
				vecSubdivision[i++].comboBoxIndex = query2.value(rec.indexOf("program_index")).toInt();
			}

			WorkingDevice->SetListIntoItem(2);

			//генерируем выпадающий список откуда поступил
			if (!query2.exec("SELECT * FROM status ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecStatus.resize(query2.size());
			rec     = query2.record();
			WorkingDevice->clearStringList();

			i=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("status")).toString();
				WorkingDevice->addStringToStringList(strName);
				vecStatus[i].id = query2.value(rec.indexOf("id")).toInt();
				vecStatus[i].value = query2.value(rec.indexOf("status")).toString();
				vecStatus[i++].comboBoxIndex = query2.value(rec.indexOf("program_index")).toInt();
			}

			WorkingDevice->SetListIntoItem(3);

			//генерируем выпадающий список сотрудников
			if (!query2.exec("SELECT * FROM coworker ORDER BY id;"))
			{
				qDebug() << query2.lastError().databaseText();
				return 1;
			}

			vecCoworker.resize(query2.size());
			WorkingDevice->clearStringList();
			rec     = query2.record();
			i=0;
			while (query2.next())
			{
				strName  = query2.value(rec.indexOf("surname")).toString();
				WorkingDevice->addStringToStringList(strName);
				vecCoworker[i].id = query2.value(rec.indexOf("id")).toInt();
				vecCoworker[i].value = query2.value(rec.indexOf("surname")).toString();
				vecCoworker[i++].comboBoxIndex = query2.value(rec.indexOf("program_index")).toInt();
			}
			i=0;
			WorkingDevice->SetListIntoItem(4);
			WorkingDevice->show();
			query2.clear();
			break;

		{
//			//wirelessscanner
//		case 2:
//			wirelescan->DataAboutDevice.typeDevice = typedevice;
//			//генерируем список для выпадающего списка типов устройств
//			if (!query2.exec("SELECT * FROM namedevice  WHERE index_device = 0 OR index_device = 2 ORDER BY id;"))
//			{
//				qDebug() << query2.lastError().databaseText();
//				return 1;
//			}

//			vecNamedevice.resize(query2.size());
//			rec     = query2.record();
//			wirelescan->clearStringList();
//			i=j=0;
//			while (query2.next())
//			{
//				strName  = query2.value(rec.indexOf("namedevice")).toString();
//				wirelescan->addStringToStringList(strName);
//				vecNamedevice[i].id = query2.value(rec.indexOf("id")).toInt();
//				vecNamedevice[i].value = query2.value(rec.indexOf("namedevice")).toString();
//				vecNamedevice[i++].comboBoxIndex = query2.value(rec.indexOf("program_index")).toInt();
//			}
//			wirelescan->SetListIntoItem(1);

//			//генерируем выпадающий список откуда поступил
//			if (!query2.exec("SELECT * FROM subdivision ORDER BY id;"))
//			{
//				qDebug() << query2.lastError().databaseText();
//				return 1;
//			}

//			vecSubdivision.resize(query2.size());
//			rec     = query2.record();
//			wirelescan->clearStringList();
//			i=0;
//			while (query2.next())
//			{
//				strName  = query2.value(rec.indexOf("subdivision")).toString();
//				wirelescan->addStringToStringList(strName);
//				vecSubdivision[i].id = query2.value(rec.indexOf("id")).toInt();
//				vecSubdivision[i].value = query2.value(rec.indexOf("subdivision")).toString();
//				vecSubdivision[i++].comboBoxIndex = query2.value(rec.indexOf("program_index")).toInt();
//			}
//			wirelescan->SetListIntoItem(2);

//			//генерируем выпадающий список откуда поступил
//			if (!query2.exec("SELECT * FROM status ORDER BY id;"))
//			{
//				qDebug() << query2.lastError().databaseText();
//				return 1;
//			}

//			vecStatus.resize(query2.size());
//			rec     = query2.record();
//			wirelescan->clearStringList();
//			i=0;
//			while (query2.next())
//			{
//				strName  = query2.value(rec.indexOf("status")).toString();
//				wirelescan->addStringToStringList(strName);
//				vecStatus[i].id = query2.value(rec.indexOf("id")).toInt();
//				vecStatus[i].value = query2.value(rec.indexOf("status")).toString();
//				vecStatus[i++].comboBoxIndex = query2.value(rec.indexOf("program_index")).toInt();
//			}
//			wirelescan->SetListIntoItem(3);

//			//генерируем выпадающий список сотрудников
//			if (!query2.exec("SELECT * FROM coworker ORDER BY id;"))
//			{
//				qDebug() << query2.lastError().databaseText();
//				return 1;
//			}

//			vecCoworker.resize(query2.size());
//			rec     = query2.record();
//			wirelescan->clearStringList();
//			i=0;
//			while (query2.next())
//			{
//				strName  = query2.value(rec.indexOf("surname")).toString();
//				wirelescan->addStringToStringList(strName);
//				vecCoworker[i].id = query2.value(rec.indexOf("id")).toInt();
//				vecCoworker[i].value = query2.value(rec.indexOf("surname")).toString();
//				vecCoworker[i++].comboBoxIndex = query2.value(rec.indexOf("program_index")).toInt();
//			}
//			i=0;
//			wirelescan->SetListIntoItem(4);
//			wirelescan->show();
//			query2.clear();
//			break;

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
		}

		default:
			break;
	}
	return true;
}

void GetContentToWindowOfDevice(int typedevice)
{
	//выборка всех данных для заполнения окна работы с устройством. сначала выборка всех характеристик для конкретного типа устройства,
	//чтобы создать нужные выпадающие списки в форме. потом выборка всех возможных значений каждой характеристики, чтобы заполнить выпадающие списки.


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

			str = strF.arg(WorkingDevice->DataAboutDevice.typeDevice)
					.arg(WorkingDevice->DataAboutDevice.nameDevice)
					.arg(WorkingDevice->DataAboutDevice.serialNumber)
					.arg(WorkingDevice->DataAboutDevice.status)
					.arg(WorkingDevice->DataAboutDevice.license)
					.arg(WorkingDevice->DataAboutDevice.coworker)
					.arg(WorkingDevice->DataAboutDevice.subDivision)
					.arg(WorkingDevice->DataAboutDevice.fromSubDivision)
					.arg(WorkingDevice->DataAboutDevice.newOrNot)
					.arg(WorkingDevice->DataAboutDevice.guarantee)
					.arg(WorkingDevice->DataAboutDevice.type_interface)
					.arg(WorkingDevice->DataAboutDevice.ethernet_count)
					.arg(WorkingDevice->DataAboutDevice.type_cartridge)
					.arg(WorkingDevice->DataAboutDevice.type_contact)
					.arg(WorkingDevice->DataAboutDevice.diagonal)
					.arg(WorkingDevice->DataAboutDevice.video_in)
					.arg(WorkingDevice->DataAboutDevice.usb_count)
					.arg(WorkingDevice->DataAboutDevice.type_phone)
					.arg(WorkingDevice->DataAboutDevice.type_wifi)
					.arg(WorkingDevice->DataAboutDevice.accum_count)
					.arg(WorkingDevice->DataAboutDevice.accum_type)
					.arg(WorkingDevice->DataAboutDevice.os_version)
					.arg(WorkingDevice->DataAboutDevice.note)
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
