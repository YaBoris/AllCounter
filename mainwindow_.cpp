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

	QObject::connect(this, SIGNAL(workInDB(int)), broker, SLOT(RecieverInDB(int)));
	QObject::connect(broker, SIGNAL(refreshTable), SLOT(refreshTable()));

	QRect BasicWindowSize = QApplication::desktop()->screenGeometry(0);
	widthWindow = BasicWindowSize.width();
	heightWindow = BasicWindowSize.height();


	//создаем меню программы и добавляем его в готовый виджет меню формы
	QMenu* pMnuFile = new QMenu("&Menu");
	pMnuFile->addAction("&About AllCounter", mainWidget, SLOT(AboutAllCounter()), Qt::CTRL+Qt::Key_Q);
	QAction* pChekableAction = pMnuFile->addAction("&CheckableItem");
	pChekableAction->setCheckable(true);
	pChekableAction->setChecked(true);
	QMenu* pMnuSubMenu = new QMenu("&Submenu", pMnuFile);
	pMnuFile->addMenu(pMnuSubMenu);
	pMnuSubMenu->addAction("&Test");
	QAction* pDisabledAction = pMnuFile->addAction("&DisabledItem");
	pDisabledAction->setEnabled(false);
	pMnuFile->addAction("&Exit", mainWidget, SLOT(quit()));

	QMenu* pMnuNewDevice = new QMenu("&Добавить устройство");
	pMnuNewDevice->addAction("&Проводной сканер", this, SLOT(WiredScanner()));


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
	connect(pActWork, SIGNAL(triggered()), SLOT(slotTechWork()));
	QAction* pActRezerve = new QAction("Резерв", 0);
	pActRezerve->setText("&Резерв");
	pActRezerve->setToolTip("Резерв");
	pActRezerve->setStatusTip("Резерв");
	pActRezerve->setWhatsThis("Резерв");
	connect(pActRezerve, SIGNAL(triggered()), SLOT(slotRezerve()));
	QAction* pActFix = new QAction("Техника в ремонте", 0);
	pActFix->setText("&Техника в ремонте");
	pActFix->setToolTip("Техника в ремонте");
	pActFix->setStatusTip("Техника в ремонте");
	pActFix->setWhatsThis("Техника в ремонте");
	connect(pActFix, SIGNAL(triggered()), SLOT(slotFix()));
	QAction* pActAll = new QAction("Вся техника", 0);
	pActAll->setText("&Вся техника");
	pActAll->setToolTip("Вся техника");
	pActAll->setStatusTip("Вся техника");
	pActAll->setWhatsThis("Вся техника");
	connect(pActAll, SIGNAL(triggered()), SLOT(slotAllTech()));
	QAction* pActOrder = new QAction("Заявленные на приобретение", 0);
	pActOrder->setText("&Заявленные на приобретение");
	pActOrder->setToolTip("Заявленные на приобретение");
	pActOrder->setStatusTip("Заявленные на приобретение");
	pActOrder->setWhatsThis("Заявленные на приобретение");
	connect(pActOrder, SIGNAL(triggered()), SLOT(slotNewDoc()));

	//Короткая запись создания элемента ToolBar
	//pToolBarBase->addAction(QPixmap(":/imgs/notebook.png"), "&Заявленные на приобретение", this, SLOT(slotNewDoc()));

	ui->ToolBarBase->addAction(pActWork);
	ui->ToolBarBase->addAction(pActRezerve);
	ui->ToolBarBase->addAction(pActFix);
	ui->ToolBarBase->addAction(pActAll);
	ui->ToolBarBase->addAction(pActOrder);
//	ui->ToolBarBase->addAction(pActBD);
	ui->ToolBarBase->setIconSize(QSize(50, 50));

	if (!createConnection()) {
		qDebug() << "Нот коннект сука";
//		return -1;
	}

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

	this->setTableView(QStringList() << trUtf8("id")
					   << trUtf8("Тип устройства")
					   << trUtf8("Название устройства")
					   << trUtf8("Серийный номер")
					   << trUtf8("Статус")
					   << trUtf8("Кто принял")
					   << trUtf8("Откуда поступил")
					   << trUtf8("Новый или нет")
					   << trUtf8("Примечание")
					   );

	this->show();

}

MainWindow::~MainWindow()
{
	//delete broker;
	delete ui;
}

void MainWindow::setTableView(const QStringList &headers)
{
	model.setTable("summary");
	model.setRelation(2, QSqlRelation("typedevice", "id", "typedevice"));
	model.setRelation(3, QSqlRelation("nameproduct", "id", "nameproduct"));
	model.setRelation(5, QSqlRelation("status", "id", "status"));
	model.setRelation(6, QSqlRelation("coworker", "id", "surname"));
	model.setRelation(7, QSqlRelation("coworker", "id", "surname"));
	model.setRelation(8, QSqlRelation("new_old", "id", "new_old"));

	//Устанавливаем названия колонок в таблице с сортировкой данных
	for(int i = 0, j = 0; i < model.columnCount(); i++, j++)
	{
		model.setHeaderData(i,Qt::Horizontal,headers[j]);
	}

	//		model.select();
	QSqlQuery query("SELECT * FROM summary;" );

	if (model.lastError().isValid())
	{
		qDebug() << model.lastError();
	}

	ui->tableView->setModel(&model);     // Устанавливаем модель на TableView
	ui->tableView->setColumnHidden(0, true);    // Скрываем колонку с id записей
	// Разрешаем выделение строк
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	// Устанавливаем режим выделения лишь одно строки в таблице
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	// Устанавливаем размер колонок по содержимому
	ui->tableView->resizeColumnsToContents();
	ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
	ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableView->horizontalHeader()->setStretchLastSection(true);



}

void MainWindow::WiredScanner()
{
	int typedevice = 1;
	emit workInDB(typedevice);
}

bool MainWindow::createConnection()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL7");
	db.setDatabaseName("allcounter");
	db.setUserName("postgres");
	db.setHostName("localhost");
	db.setPassword("123456");
	if (!db.open())
	{
		qDebug() << "Cannot open database:" << db.lastError();
		return false;
	}
	return true;
}

void MainWindow::refreshTable()
{
//	model.setTable("summary");
//	model.select();
//	model.setQuery("SELECT * FROM summary;" );

	if (model.lastError().isValid())
	{
		qDebug() << model.lastError();
	}
//	ui->tableView->setModel(&model);

}


//bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
//{
//    if (obj == ui->MainWindow && ev->type() == QEvent::Resize)
//    {
//	;
//    }
//}
