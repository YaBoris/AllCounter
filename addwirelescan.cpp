#include "addwirelescan.h"
#include "ui_addwirelescan.h"

addwirelescan::addwirelescan(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::addwirelescan)
{
	ui->setupUi(this);
	this->setModal(true);

//	validator = new serial_validator(ui->addSerial);
//	ui->addSerial->setValidator(validator);

	DataAboutDevice.typeDevice = 2;
	ui->leftSymbols->setText("Осталось 150 символов");
	ui->leftSymbols->setStyleSheet("color: rgb(80, 80, 80)");
	ui->leftSymbols->show();
	ui->leftSymbolsSerial->setText("Осталось 40 символов");
	ui->leftSymbolsSerial->setStyleSheet("color: rgb(80, 80, 80)");
	ui->leftSymbolsSerial->setAlignment(Qt::AlignRight);
	ui->leftSymbolsSerial->show();

	QObject::connect(ui->addNoSerial, SIGNAL(clicked(bool)), SLOT(on_addNoSerial_clicked(bool)));

	setWindowView();
	cleanAllItems();
}

void addwirelescan::setWindowView()
{
	this->setWindowTitle("Добавление беспроводного сканера");
}

addwirelescan::~addwirelescan()
{
	delete ui;
}

void addwirelescan::addStringToStringList(QString stringItem)
{
	lst << stringItem;
}

void addwirelescan::clearStringList()
{
	lst.clear();
}

//добавление списка в выпадающие списки. параметр указывает на конкретный список
void addwirelescan::SetListIntoItem(int NumberItem)
{
	switch (NumberItem)
	{
		case 1:
			//Name Device
			lstNameDevice.clear();
			ui->addNameDevice->clear();
			lstNameDevice = lst;
			ui->addNameDevice->addItems(lstNameDevice);
			break;
		case 2:
			//From recieved
			lstSubdivision.clear();
			ui->addWhereFrom->clear();
			lstSubdivision = lst;
			ui->addWhereFrom->addItems(lstSubdivision);
			break;
		case 3:
			//Device status
			lstStatus.clear();
			ui->addStatus->clear();
			lstStatus = lst;
			ui->addStatus->addItems(lstStatus);
			break;
		case 4:
			//Responcible
			lstCoworker.clear();
			ui->addCoworker->clear();
			lstCoworker = lst;
			ui->addCoworker->addItems(lstCoworker);
			break;

		default:
			break;
	}
}

bool addwirelescan::controlEnteredData()
{
	//переменная checkResult должна быть равна 0, когда все поля корректно заполнены
	checkResult = 0;
	//блок контроля корректности введенных данных
	if(ui->addCoworker->currentIndex() <= 0 &&
		ui->addCoworker->currentIndex() > ui->addCoworker->count())
	{
		checkResult++;
	}
	else
	{
		DataAboutDevice.coworker = ui->addCoworker->currentIndex()+1;
	}

	if(ui->addNameDevice->currentIndex() <= 0 &&
		ui->addNameDevice->currentIndex() > ui->addNameDevice->count())
	{
		checkResult++;
	}
	else
	{
		DataAboutDevice.nameDevice = ui->addNameDevice->currentIndex()+1;
	}

	if(ui->addStatus->currentIndex() <= 0 &&
		ui->addStatus->currentIndex() > ui->addStatus->count())
	{
		checkResult++;
	}
	else
	{
		DataAboutDevice.status = ui->addStatus->currentIndex()+1;
	}

	if(ui->addWhereFrom->currentIndex() <= 0 &&
		ui->addWhereFrom->currentIndex() > ui->addWhereFrom->count())
	{
		checkResult++;
	}
	else
	{
		DataAboutDevice.subDivision = ui->addWhereFrom->currentIndex()+1;
	}

	DataAboutDevice.note = ui->addNoteDevice->toPlainText();
	if(DataAboutDevice.note.length() == 0)
	{
		checkResult++;
	}

	DataAboutDevice.serialNumber = ui->addSerial->text();
	if(DataAboutDevice.serialNumber.length() == 0)
	{
		checkResult++;
	}

	if(ui->radioButtonNew->isChecked())
	{
		DataAboutDevice.newOrNot = 2;
	}
	else if(ui->radioButtonOld->isChecked())
	{
		DataAboutDevice.newOrNot = 1;
	}
	else
	{
		checkResult++;
	}

	return checkResult;
}

void addwirelescan::cleanAllItems()
{
	ui->addNameDevice->clear();
	ui->addCoworker->clear();
	ui->addNoSerial->setChecked(false);
	ui->addSerial->setEnabled(true);
	ui->addSerial->clear();
	ui->addNoteDevice->clear();
	ui->addStatus->clear();
	ui->addWhereFrom->clear();
	ui->radioButtonNew->setChecked(false);
	ui->radioButtonOld->setChecked(false);
	DataAboutDevice.coworker = 0;
	DataAboutDevice.nameDevice = 0;
	DataAboutDevice.newOrNot = 2;
	DataAboutDevice.note = "";
	DataAboutDevice.serialNumber = "";
	DataAboutDevice.status = 0;
	DataAboutDevice.subDivision = 0;
	DataAboutDevice.accum_count = 0;
	DataAboutDevice.accum_type = 0;
	DataAboutDevice.diagonal = 0;
	DataAboutDevice.ethernet_count = 0;
	DataAboutDevice.guarantee = 0;
	DataAboutDevice.license = 0;
	DataAboutDevice.os_version = 0;
	DataAboutDevice.video_in = 0;
	DataAboutDevice.usb_count = 0;
	DataAboutDevice.type_wifi = 0;
	DataAboutDevice.type_phone = 0;
	DataAboutDevice.type_interface = 0;
	DataAboutDevice.type_contact = 0;
	DataAboutDevice.type_cartridge = 0;
	lst.clear();
}

//SLOTS
void addwirelescan::on_addNoSerial_clicked(bool state)
{
	if(state)
	{
		ui->addSerial->setEnabled(false);
		ui->addSerial->setText("Без номера");
		DataAboutDevice.serialNumber = ui->addSerial->text();
	}
	else
	{
		ui->addSerial->setEnabled(true);
		ui->addSerial->setText("");
	}
}

void addwirelescan::on_pushButtonSave_clicked()
{
	if (controlEnteredData())
	{
		QMessageBox::critical(0, "Внимание!", "Поля, помеченные символом '*', должны быть заполнены!", QMessageBox::Ok);
	}
	else
	{
		DataAboutDevice.fromSubDivision = DataAboutDevice.subDivision;
		DataAboutDevice.accum_count = 1;
		DataAboutDevice.accum_type = 1;
		DataAboutDevice.diagonal = 1;
		DataAboutDevice.ethernet_count = 1;
		DataAboutDevice.guarantee = 1;
		DataAboutDevice.license = 1;
		DataAboutDevice.os_version = 1;
		DataAboutDevice.type_cartridge = 1;
		DataAboutDevice.type_contact = 1;
		DataAboutDevice.type_interface = 1;
		DataAboutDevice.type_phone = 1;
		DataAboutDevice.type_wifi = 1;
		DataAboutDevice.usb_count = 1;
		DataAboutDevice.video_in = 1;

		emit signalAddDeviceData(DataAboutDevice.typeDevice);
		ui->addSerial->clear();
		ui->addNoteDevice->clear();
		accept();
	}
}

void addwirelescan::on_pushButtonCancel_clicked()
{
	cleanAllItems();
	reject();
}

void addwirelescan::on_addNoteDevice_textChanged()
{
	const int countDown = 150;
	NoteString = ui->addNoteDevice->toPlainText();
	if(NoteString.length() > countDown && NoteString.length() > prevNoteString.length())
	{
		ui->pushButtonSave->setDisabled(true);
		ui->pushAddAndContinue->setDisabled(true);
		ui->leftSymbols->setText("Осталось " + QString::number(countDown - (NoteString.length())) + " символов");
		QMessageBox::critical(0, "Внимание!", "Текст примечания не должен превышать 150 символов!", QMessageBox::Ok);
	}
	else if(NoteString.length() > countDown && NoteString.length() < prevNoteString.length())
	{
		ui->pushButtonSave->setDisabled(true);
		ui->pushAddAndContinue->setDisabled(true);
		ui->leftSymbols->setText("Осталось " + QString::number(countDown - (NoteString.length())) + " символов");
	}
	else if(NoteString.length() <= countDown)
	{
		ui->pushButtonSave->setDisabled(false);
		ui->pushAddAndContinue->setDisabled(false);
		ui->leftSymbols->setText("Осталось " + QString::number(countDown - (NoteString.length())) + " символов");
	}
	prevNoteString = NoteString;
}

void addwirelescan::on_addSerial_textEdited(const QString &arg1)
{
	SerialString = arg1;
	const int countDown = 40;
	ui->addSerial->setText(SerialString.remove(QRegExp("[^0-9a-zA-Z/-]")));

	if(SerialString.length() > countDown && SerialString.length() > prevSerialString.length())
	{
		ui->pushButtonSave->setDisabled(true);
		ui->pushAddAndContinue->setDisabled(true);
		ui->leftSymbolsSerial->setText("Осталось " + QString::number(countDown - SerialString.length()) + " символов");
		QMessageBox::critical(0, "Внимание!", "Длина серийного номера не должна превышать 40 символов!", QMessageBox::Ok);
	}
	else if(SerialString.length() > countDown && SerialString.length() < prevSerialString.length())
	{
		ui->pushButtonSave->setDisabled(true);
		ui->pushAddAndContinue->setDisabled(true);
		ui->leftSymbolsSerial->setText("Осталось " + QString::number(countDown - SerialString.length()) + " символов");
	}
	else if(SerialString.length() <= countDown)
	{
		ui->pushButtonSave->setDisabled(false);
		ui->pushAddAndContinue->setDisabled(false);
		ui->leftSymbolsSerial->setText("Осталось " + QString::number(countDown - SerialString.length()) + " символов");
	}
	prevSerialString = SerialString;
}

void addwirelescan::on_pushAddAndContinue_clicked()
{
	DataAboutDevice.typeDevice = 2;

	if (controlEnteredData())
	{
		QMessageBox::critical(0, "Внимание!", "Поля, помеченные символом '*', должны быть заполнены!", QMessageBox::Ok);
	}
	else
	{
		DataAboutDevice.fromSubDivision = DataAboutDevice.subDivision;
		DataAboutDevice.accum_count = 1;
		DataAboutDevice.accum_type = 1;
		DataAboutDevice.diagonal = 1;
		DataAboutDevice.ethernet_count = 1;
		DataAboutDevice.guarantee = 1;
		DataAboutDevice.license = 1;
		DataAboutDevice.os_version = 1;
		DataAboutDevice.type_cartridge = 1;
		DataAboutDevice.type_contact = 1;
		DataAboutDevice.type_interface = 1;
		DataAboutDevice.type_phone = 1;
		DataAboutDevice.type_wifi = 1;
		DataAboutDevice.usb_count = 1;
		DataAboutDevice.video_in = 1;

		emit signalAddDeviceData(DataAboutDevice.typeDevice);

		ui->addNoSerial->setChecked(false);
		cleanAllItems();
		ui->addNameDevice->addItems(lstNameDevice);
		ui->addCoworker->addItems(lstCoworker);
		ui->addStatus->addItems(lstStatus);
		ui->addWhereFrom->addItems(lstSubdivision);
	}
}
