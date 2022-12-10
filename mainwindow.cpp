#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include "QVBoxLayout"
#include <QLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QTableWidget>




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
    nameLineEdit->setPlaceholderText("Name");
    surnameLineEdit = new QLineEdit;
    surnameLineEdit->setPlaceholderText("Surname");
    lastnameLineEdit = new QLineEdit;
    lastnameLineEdit->setPlaceholderText("Last name");

    fullnameGroupbox = new QGroupBox(tr("Full name"));
    fullnameLayout = new QGridLayout;
    fullnameLayout->addWidget(nameLineEdit, 0, 0);
    fullnameLayout->addWidget(surnameLineEdit, 1, 0);
    fullnameLayout->addWidget(lastnameLineEdit, 2, 0);
    fullnameGroupbox->setLayout(fullnameLayout);

    birthdateLineEdit = new QLineEdit;
    birthdateLineEdit->setPlaceholderText("Birth date");
    heightLineEdit = new QLineEdit;
    heightLineEdit->setPlaceholderText("Height");
    weightLineEdit = new QLineEdit;
    weightLineEdit->setPlaceholderText("Weight");

    parametresGroupbox = new QGroupBox(tr("Information"));
    parametresLayout = new QGridLayout;
    parametresLayout->addWidget(birthdateLineEdit, 0, 0);
    parametresLayout->addWidget(heightLineEdit, 1, 0);
    parametresLayout->addWidget(weightLineEdit, 2, 0);
    parametresGroupbox->setLayout(parametresLayout);

    //tableWidget
    tableWidget = new QTableWidget;
    int row = 3;
    int column = 6;
    QStringList headers;
    headers << "Name" << "Surname" << "Last name" <<"Birth date" <<"Height" << "Weight";
    tableWidget->setRowCount(row);
    tableWidget->setColumnCount(column);
    tableWidget->setHorizontalHeaderLabels(headers);
    tableWidget->insertRow(tableWidget->rowCount());
    tableWidget->setItem(0, 0, new QTableWidgetItem("first row, first column"));


    admitButton = new QPushButton(tr("Add"));
    deleteButton = new QPushButton(tr("Delete selected row"));

    //GridLayout for widget
    widgetLayout = new QGridLayout;
    widgetLayout->addWidget(fullnameGroupbox, 0, 0);
    widgetLayout->addWidget(parametresGroupbox, 0, 1);
    widgetLayout->addWidget(admitButton, 1, 0);
    widgetLayout->addWidget(deleteButton, 1, 1);
    widgetLayout->addWidget(tableWidget, 2, 0, 1, 2);
    Widget->setLayout(widgetLayout);

    //connectors
   // connect(nameLineEdit, &QLineEdit::textEdited, this, &MainWindow::name_textChanged);
    connect(admitButton, &QPushButton::clicked, this, &MainWindow::on_admitButtonClicked);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButtonClicked);
    connect(birthdateLineEdit, &QLineEdit::editingFinished, this, &MainWindow::birthdaydate_clicked);



}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::name_textChanged(const QString &text)
{

    //tableWidget->setItem(1,0,new QTableWidgetItem (nameLineEdit->text()) );

}
*/
void MainWindow::on_admitButtonClicked(int row_counter)
{


    tableWidget->insertRow(tableWidget->rowCount());

    tableWidget->setItem(row_counter,0,new QTableWidgetItem (nameLineEdit->text()) );
    tableWidget->setItem(row_counter,1,new QTableWidgetItem (surnameLineEdit->text()) );
    tableWidget->setItem(row_counter,2,new QTableWidgetItem (lastnameLineEdit->text()) );
    tableWidget->setItem(row_counter,3,new QTableWidgetItem (birthdateLineEdit->text()) );
    tableWidget->setItem(row_counter,4,new QTableWidgetItem (heightLineEdit->text()) );
    tableWidget->setItem(row_counter,5,new QTableWidgetItem (weightLineEdit->text()) );
    // tableWidget->setItem(0, 0, nameLineEdit->text());
    row_counter++;
}

void MainWindow::on_deleteButtonClicked()
{
    tableWidget->removeRow(tableWidget->currentRow());
}

void MainWindow::birthdaydate_clicked()
{
    birthdateLineEdit->setInputMask("00.00.0000");
}

