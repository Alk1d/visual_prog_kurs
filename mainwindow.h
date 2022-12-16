#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include "QVBoxLayout"
#include "qjsondocument.h"
#include <QLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QAction>
#include <QLabel>
#include <QMenuBar>

#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QFileDialog>
#include <QJsonParseError>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *Widget;
    QTableWidget *tableWidget;

    QLineEdit *nameLineEdit;
    QLineEdit *surnameLineEdit;
    QLineEdit *lastnameLineEdit;
    QLineEdit *birthdateLineEdit;
    QLineEdit *heightLineEdit;
    QLineEdit *weightLineEdit;

    QLabel *nameLabel;
    QLabel *surnameLabel;
    QLabel *lastnameLabel;
    QLabel *birthdateLabel;
    QLabel *heightLabel;
    QLabel *weightLabel;

    QPushButton *admitButton;
    QPushButton *deleteButton;

    QGroupBox *parametresGroupbox;
    QGroupBox *fullnameGroupbox;

    QGridLayout *fullnameLayout;
    QGridLayout *parametresLayout;
    QGridLayout *widgetLayout;

    QAction *redactAct;
    QAction *addDbAct;
    QMenuBar *Menubar;
    QMenu *Menu;

    QJsonDocument db;
    QJsonArray dbArr;
    QJsonParseError dbErr;
    QString dbPath;
    QFile file;

    void Db_reader(int row_counter);



public slots:
    void on_admitButtonClicked(int row_counter);
    void on_deleteButtonClicked();
    void redact();
    void on_addDbClicked();
};
#endif // MAINWINDOW_H
