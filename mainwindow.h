#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QByteArray>
#include <QString>

#include "serialservice.h"
#include "enddevice.h"
#include "posix_qextserialport.h"
#include "qextserialbase.h"
#include "temp_humi_light.h"
#include "changepwm.h"
#include "motor.h"

class QTextEdit;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updatethl();
    void changeSerial(int);
signals:
    void addLog(QString);
    void addLog(int);
    void timeEqualSignal();
private slots:
    void process_msg_from_serial(QByteArray);
    void process_msg_from_serial_log(QByteArray);
    void showLog(QString);
    void button_serial_clicked();
    void changelight(int);
    void changemotor(int);
    void updatetimer();
    void slotTimeEqual();
    void openFile();
    void saveFile();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    SerialService *serial_server;

    Temp_Humi_Light *temp_humi_light;
    ChangePwm *light;
    Motor *motor;
    void open();
    QAction *openAction;
    QAction *saveAction;
    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H
