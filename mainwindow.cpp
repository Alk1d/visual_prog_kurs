#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include "QVBoxLayout"
#include <QLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QTableWidget>
#include <QMenuBar>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("kurs test"));
    Widget = new QWidget;
    setCentralWidget(Widget);

    //Widget overall layout
    nameLineEdit = new QLineEdit;
    nameLabel = new QLabel (tr("Name"));
    surnameLineEdit = new QLineEdit;
    surnameLabel = new QLabel (tr("Surname"));
    lastnameLineEdit = new QLineEdit;
    lastnameLabel = new QLabel (tr("Last name"));

    fullnameGroupbox = new QGroupBox(tr("Full name"));
    fullnameLayout = new QGridLayout;

    fullnameLayout->addWidget(nameLabel, 0, 0);
    fullnameLayout->addWidget(nameLineEdit, 1, 0);

    fullnameLayout->addWidget(surnameLabel, 2, 0);
    fullnameLayout->addWidget(surnameLineEdit, 3, 0);

    fullnameLayout->addWidget(lastnameLabel, 4, 0);
    fullnameLayout->addWidget(lastnameLineEdit, 5, 0);

    fullnameGroupbox->setLayout(fullnameLayout);

    birthdateLineEdit = new QLineEdit;
    birthdateLabel = new QLabel (tr("Birth date"));
    birthdateLineEdit->setInputMask("00.00.0000");
    heightLineEdit = new QLineEdit;
    heightLabel = new QLabel (tr("Height"));
    weightLineEdit = new QLineEdit;
    weightLabel = new QLabel (tr("Weight"));

    parametresGroupbox = new QGroupBox(tr("Information"));
    parametresLayout = new QGridLayout;

    parametresLayout->addWidget(birthdateLabel, 0, 0);
    parametresLayout->addWidget(birthdateLineEdit, 1, 0);

    parametresLayout->addWidget(heightLabel, 2, 0);
    parametresLayout->addWidget(heightLineEdit, 3, 0);

    parametresLayout->addWidget(weightLabel, 4, 0);
    parametresLayout->addWidget(weightLineEdit, 5, 0);

    parametresGroupbox->setLayout(parametresLayout);

    //tableWidget
    tableWidget = new QTableWidget;
    int row = 0;
    int column = 6;
    QStringList headers;
    headers << "Name" << "Surname" << "Last name" <<"Birth date" <<"Height" << "Weight";
    tableWidget->setRowCount(row);
    tableWidget->setColumnCount(column);
    tableWidget->setHorizontalHeaderLabels(headers);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    //buttons
    admitButton = new QPushButton(tr("Add"));
    deleteButton = new QPushButton(tr("Delete selected row"));

    //action
    redactAct = new QAction("Editable table", this);
    redactAct->setCheckable(true);
    redactAct->setChecked(false);

    //menu
    Menubar = new QMenuBar;
    Menu = menuBar()->addMenu("Menu");
    Menu->addAction(redactAct);

    //GridLayout for widget
    widgetLayout = new QGridLayout;
    widgetLayout->addWidget(Menubar, 0, 0);
    widgetLayout->addWidget(fullnameGroupbox, 1, 0);
    widgetLayout->addWidget(parametresGroupbox, 1, 1);
    widgetLayout->addWidget(admitButton, 2, 0);
    widgetLayout->addWidget(deleteButton, 2, 1);
    widgetLayout->addWidget(tableWidget, 3, 0, 1, 2);
    Widget->setLayout(widgetLayout);

    //connectors
    connect(admitButton, &QPushButton::clicked, this, &MainWindow::on_admitButtonClicked);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButtonClicked);
    connect(redactAct, &QAction::triggered, this, &MainWindow::redact);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_admitButtonClicked(int row_counter)
{

    row_counter = tableWidget->rowCount();
    tableWidget->insertRow(tableWidget->rowCount());
    tableWidget->setItem(row_counter,0,new QTableWidgetItem (nameLineEdit->text()) );
    tableWidget->setItem(row_counter,1,new QTableWidgetItem (surnameLineEdit->text()) );
    tableWidget->setItem(row_counter,2,new QTableWidgetItem (lastnameLineEdit->text()) );
    tableWidget->setItem(row_counter,3,new QTableWidgetItem (birthdateLineEdit->text()) );
    tableWidget->setItem(row_counter,4,new QTableWidgetItem (heightLineEdit->text()) );
    tableWidget->setItem(row_counter,5,new QTableWidgetItem (weightLineEdit->text()) );

}

void MainWindow::on_deleteButtonClicked()
{
    tableWidget->removeRow(tableWidget->currentRow());
}

void MainWindow::redact()
{
    if (redactAct->isChecked() == true)
        tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    else
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

