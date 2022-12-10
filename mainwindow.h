#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include "QVBoxLayout"
#include <QLayout>
#include <QGroupBox>
#include <QGridLayout>
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

    QPushButton *admitButton;
    QPushButton *deleteButton;

    QGroupBox *parametresGroupbox;
    QGroupBox *fullnameGroupbox;

    QGridLayout *fullnameLayout;
    QGridLayout *parametresLayout;
    QGridLayout *widgetLayout;

public slots:
    void on_admitButtonClicked(int row_counter);
    void on_deleteButtonClicked();
    void birthdaydate_clicked();
};
#endif // MAINWINDOW_H
