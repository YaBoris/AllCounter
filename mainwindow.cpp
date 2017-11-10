#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	QWidget* mainWidget = new QWidget();
	mainWidget->setParent(this);
	brokerdb* broker = new brokerdb;
	headers = QStringList() << trUtf8("id")
							<< trUtf8("Тип устройства")
							<< trUtf8("Название устройства")
							<< trUtf8("Серийный номер")
							<< trUtf8("Статус")
							<< trUtf8("Наличие лицензии")
							<< trUtf8("Кто принял")
							<< trUtf8("Подразделение")
							<< trUtf8("Откуда поступил")
							<< trUtf8("Новый или нет")
							<< trUtf8("Наличие гарантии")
							<< trUtf8("Тип разъема")
							<< trUtf8("Кол-во портов")
							<< trUtf8("Тип картриджа")
							<< trUtf8("Конт-ая площадка")
							<< trUtf8("Размер экрана")
							<< trUtf8("Видеовходы")
							<< trUtf8("Количество USB")
							<< trUtf8("Тип телефона")
							<< trUtf8("Стандарты Wi-Fi")
							<< trUtf8("Кол-во аккумуляторов")
							<< trUtf8("Тип аккумуляторов")
							<< trUtf8("Версия ОС")
							<< trUtf8("Примечание")
							<< trUtf8("Дата изменения");


	QObject::connect(this, SIGNAL(workInDB(int)), broker, SLOT(RecieverInDB(int)));
	QObject::connect(broker, SIGNAL(refreshTable()), SLOT(slotRefreshTable()));

	if (!broker->createConnection())
	{
		qDebug() << "message: " << db.lastError();
	}
	model = new QSqlRelationalTableModel(this);

	this->configViewTable();
	this->setMainWindow(mainWidget);
	this->show();
}

MainWindow::~MainWindow()
{
	//delete broker;
	db.close();
	delete ui;
}

void MainWindow::WiredScanner()
{
	emit workInDB(1);
}

void MainWindow::WirelessScanner()
{
	emit workInDB(2);
}

void MainWindow::configViewTable()
{
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	// Устанавливаем режим выделения лишь одной строки в таблице
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	// Устанавливаем размер колонок по содержимому
	ui->tableView->resizeColumnsToContents();
	ui->tableView->horizontalHeader()->setStretchLastSection(true);

	model->setTable("summary");
	model->setRelation(1, QSqlRelation("typedevice", "id", "typedevice"));
	model->setRelation(2, QSqlRelation("namedevice", "id", "namedevice"));
	model->setRelation(4, QSqlRelation("status", "id", "status"));
	model->setRelation(5, QSqlRelation("license", "id", "license"));
	model->setRelation(6, QSqlRelation("coworker", "id", "surname"));
	model->setRelation(7, QSqlRelation("subdivision", "id", "subdivision"));
	model->setRelation(8, QSqlRelation("subdivision", "id", "subdivision"));
	model->setRelation(9, QSqlRelation("new_old", "id", "new_old"));
	model->setRelation(10, QSqlRelation("guarantee", "id", "guarantee"));
	model->setRelation(11, QSqlRelation("type_contact", "id", "type_contact"));
	model->setRelation(12, QSqlRelation("ethernet_count", "id", "ethernet_count"));
	model->setRelation(13, QSqlRelation("type_cartridge", "id", "type_cartridge"));
	model->setRelation(14, QSqlRelation("type_contact", "id", "type_contact"));
	model->setRelation(15, QSqlRelation("diagonal", "id", "diagonal"));
	model->setRelation(16, QSqlRelation("video_in", "id", "video_in"));
	model->setRelation(17, QSqlRelation("usb_count", "id", "usb_count"));
	model->setRelation(18, QSqlRelation("type_phone", "id", "type_phone"));
	model->setRelation(19, QSqlRelation("type_wifi", "id", "type_wifi"));
	model->setRelation(20, QSqlRelation("accum_count", "id", "accum_count"));
	model->setRelation(21, QSqlRelation("accum_type", "id", "accum_type"));
	model->setRelation(22, QSqlRelation("os_version", "id", "os_version"));

	//по умолчанию сортировка по ID
	model->setSort(0,Qt::AscendingOrder);
	if (!model->select())
	{
		qDebug() << "Cannot read table \"summary\":" << db.lastError();
	}
	ui->tableView->setModel(model);

//	qDebug() << "General read error:" << db.lastError();

	for(int i = 0, j = 0; i < model->columnCount(); i++, j++)
	{
		model->setHeaderData(i, Qt::Horizontal, headers[i]);
	}
	ui->tableView->show();
	ui->tableView->setColumnHidden(0, true); //скрываем ID
	ui->tableView->setColumnHidden(21, true);//скрываем дату и время создания записи

}

void MainWindow::setMainWindow(QWidget *mainWidget)
{
	//создаем меню программы и добавляем его в готовый виджет меню формы
	QMenu* pMnuFile = new QMenu("&Menu");
//	pMnuFile->addAction("&About AllCounter", mainWidget, SLOT(AboutAllCounter()), Qt::CTRL+Qt::Key_Q);
	QAction* pChekableAction = pMnuFile->addAction("&CheckableItem");
	pChekableAction->setCheckable(true);
	pChekableAction->setChecked(true);

	QMenu* pMnuSubMenu = new QMenu("&Submenu", pMnuFile);
	pMnuFile->addMenu(pMnuSubMenu);
	pMnuSubMenu->addAction("&Test");
	QAction* pDisabledAction = pMnuFile->addAction("&DisabledItem");
	pDisabledAction->setEnabled(false);
//	pMnuFile->addAction("&Exit", mainWidget, SLOT(quit()));

	QMenu* pMnuNewDevice = new QMenu("&Добавить устройство");
	pMnuNewDevice->addAction("&Проводной сканер", this, SLOT(WiredScanner()));
	pMnuNewDevice->addAction("&Беспроводной сканер", this, SLOT(WirelessScanner()));


	ui->mnuBar->addMenu(pMnuFile);
	ui->mnuBar->addMenu(pMnuNewDevice);
	ui->mnuBar->show();

	//создаем панель инструментов
	QAction* pActWork = new QAction("Техника в работе", 0);
	pActWork->setText("&Техника в работе");
//    pActWork->setShortcut(QKeySequence("CTRL+W"));
	pActWork->setToolTip("Техника в работе");
	pActWork->setStatusTip("Техника в работе");
	pActWork->setWhatsThis("Техника в работе");
//    pActWork->setIcon(QPixmap(":/workplace.png"));
//	connect(pActWork, SIGNAL(triggered()), SLOT(slotTechWork()));

	QAction* pActRezerve = new QAction("Резерв", 0);
	pActRezerve->setText("&Резерв");
	pActRezerve->setToolTip("Резерв");
	pActRezerve->setStatusTip("Резерв");
	pActRezerve->setWhatsThis("Резерв");
//	connect(pActRezerve, SIGNAL(triggered()), SLOT(slotRezerve()));

	QAction* pActFix = new QAction("Техника в ремонте", 0);
	pActFix->setText("&Техника в ремонте");
	pActFix->setToolTip("Техника в ремонте");
	pActFix->setStatusTip("Техника в ремонте");
	pActFix->setWhatsThis("Техника в ремонте");
//	connect(pActFix, SIGNAL(triggered()), SLOT(slotFix()));

	QAction* pActAll = new QAction("Вся техника", 0);
	pActAll->setText("&Вся техника");
	pActAll->setToolTip("Вся техника");
	pActAll->setStatusTip("Вся техника");
	pActAll->setWhatsThis("Вся техника");
//	connect(pActAll, SIGNAL(triggered()), SLOT(slotAllTech()));

	QAction* pActOrder = new QAction("Заявленные на приобретение", 0);
	pActOrder->setText("&Заявленные на приобретение");
	pActOrder->setToolTip("Заявленные на приобретение");
	pActOrder->setStatusTip("Заявленные на приобретение");
	pActOrder->setWhatsThis("Заявленные на приобретение");
//	connect(pActOrder, SIGNAL(triggered()), SLOT(slotNewDoc()));

	//Короткая запись создания элемента ToolBar
	//pToolBarBase->addAction(QPixmap(":/imgs/notebook.png"), "&Заявленные на приобретение", this, SLOT(slotNewDoc()));

	ui->ToolBarBase->addAction(pActWork);
	ui->ToolBarBase->addAction(pActRezerve);
	ui->ToolBarBase->addAction(pActFix);
	ui->ToolBarBase->addAction(pActAll);
	ui->ToolBarBase->addAction(pActOrder);
//	ui->ToolBarBase->addAction(pActBD);
	ui->ToolBarBase->setIconSize(QSize(50, 50));

	QHBoxLayout* pHorBoxLayout = new QHBoxLayout;
	pHorBoxLayout->setMargin(2);
	pHorBoxLayout->setSpacing(1);
	pHorBoxLayout->addWidget(ui->ToolBarBase);
	pHorBoxLayout->addWidget(ui->tableView);
	mainWidget->setLayout(pHorBoxLayout);

	QVBoxLayout* pVertBoxLayout = new QVBoxLayout;
	pVertBoxLayout->addWidget(ui->mnuBar);
	pVertBoxLayout->addLayout(pHorBoxLayout);

	mainWidget->setLayout(pVertBoxLayout);
	//ранее наполненный layout
	setCentralWidget(mainWidget);

	mainDesktopWidget = QApplication::desktop();
	CountScreens = mainDesktopWidget->screenCount();
	widthFirstScreen = mainDesktopWidget->screenGeometry(0).width();
	heightFirstScreen = mainDesktopWidget->screenGeometry(0).height();
	if(CountScreens == 2)
	{
		widthSecondScreen = mainDesktopWidget->screenGeometry(1).width();
		heightSecondScreen = mainDesktopWidget->screenGeometry(1).height();
	}
	int iWidthWindow = this->widthFirstScreen/1.2;
	int iHeightWindow = this->heightFirstScreen/1.2;
	this->move((this->widthFirstScreen-iWidthWindow)/2, 0);//(this->heightFirstScreen-iHeightWindow)/2
	this->resize(iWidthWindow, iHeightWindow);

}

void MainWindow::slotRefreshTable()
{
//	delete model;
	model->clear();
	this->configViewTable();
}

//bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
//{
//    if (obj == ui->MainWindow && ev->type() == QEvent::Resize)
//    {
//	;
//    }
//}
