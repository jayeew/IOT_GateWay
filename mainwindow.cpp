#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QTime>
#include <QTimeEdit>
#include <QTimeLine>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QDialog>
#include <QDebug>
#include <QFileDialog>
#include <QTextEdit>
QTimer *timer;
int value_h = 0;
int value_m = 0;
//int value_s = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Intelligent child care system"));

    ui->textBrowser->setReadOnly(true);

    ui->horizontalSlider->setRange(1, 5);
    ui->horizontalSlider->setTickPosition(QSlider::TicksRight);
    ui->horizontalSlider->setPageStep(1);

    ui->spinBox->setRange(0, 24);
    ui->spinBox_2->setRange(0, 60);

    ui->comboBox->addItem(tr("None"));
    ui->comboBox->addItem(tr("Turn on"));
    ui->comboBox->addItem(tr("Turn off"));




    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open"), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));

    saveAction = new QAction(QIcon(":/images/doc-open"), tr("&Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

//    textEdit = new QTextEdit(this);
//    setCentralWidget(textEdit);

    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);




    serial_server = new SerialService();
    temp_humi_light = new Temp_Humi_Light();
    timer = new QTimer(this);
    light = new ChangePwm();
    motor = new Motor();

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(changelight(int)) );
    connect(this->serial_server, SIGNAL(receiveMsgFromSerial(QByteArray)), this, SLOT(process_msg_from_serial(QByteArray)));

    connect(this->serial_server, SIGNAL(receiveMsgFromSerial(QByteArray)), this, SLOT(process_msg_from_serial_log(QByteArray)));

    connect(this, SIGNAL(addLog(QString)), this, SLOT(showLog(QString)));
    connect(timer, SIGNAL(timeout()), this, SLOT(updatetimer()));
    timer->start(1000);
    connect(this, SIGNAL(timeEqualSignal()), this, SLOT(slotTimeEqual()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLog(QString log){
    ui->textBrowser->append(log);
}
void MainWindow::updatethl(){

    ui->lcdNumber->display(temp_humi_light->getTemp());
    ui->lcdNumber_2->display(temp_humi_light->getHumi());
    ui->lcdNumber_3->display(QString::number(temp_humi_light->getLight(), 'f', 2));

}
void MainWindow::process_msg_from_serial(QByteArray msg){
    if(msg.length() < 6)
        return;
    if(msg[3] == 0x02 && msg[4] == 0x01){
        temp_humi_light->setValue(msg);
        updatethl();
    }

    else if(msg[3] == 0x04 && msg[4] == 0x01){
     if(msg[5] = 0x01){
         ui->label_4->setText("Firing");
         QMessageBox::warning(this, tr("Danger!"), tr("Smoke detected!"));
     }
     else if(msg[5] == 0x00){
         ui->label_4->setText("*");
     }
    }

    else if(msg[3] == 0x05 && msg[4] == 0x01){
        if(msg[5] == 0x01){
            ui->label_12->setText(tr("Danger"));
            QMessageBox::warning(this, tr("Danger!"), tr("Too close to the window!"));
        }
        else if(msg[5] == 0x00){
            ui->label_12->setText("*");
        }
    }

    else if(msg[3] == 0x08 && msg[4] == 0x01){
        double len = msg[5] * 256 + msg[6];
        if(len <= 0.3){
            ui->label_10->setText(tr("Warning"));
            QMessageBox::information(this, tr("Warning!"), tr("Too close to the computer!"));
        }
        else{
            ui->label_10->setText("*");
        }
    }

    else if(msg[3] == 0x07 && msg[4] == 0x01){
        if(msg[5] == 0x01){
            ui->label_11->setText("Help");
            QMessageBox::warning(this, tr("Help!"), tr("Needing help!"));
        }
        else if(msg[5] == 0x00){
            ui->label_11->setText("*");
        }
    }

}
void MainWindow::changeSerial(int state){
    if(1 == state){
        if(serial_server->closeCom()){
            ui->pushButton->setText("Power ON");
//            changelight(0);
//            changemotor(0);
            emit addLog("close success");
        }
        else
            emit addLog("close failed");
    }
    else if(0 == state){
        if(serial_server->openCom()){
            ui->pushButton->setText("Power OFF");
            ui->horizontalSlider->setValue(1);
            changelight(0);
            sleep(0.5);
            changemotor(0);
            emit addLog("open success");
        }
        else
            emit addLog("open failed");
    }
}
void MainWindow::button_serial_clicked(){

}

void MainWindow::on_pushButton_clicked()
{
    changeSerial(serial_server->getComState());
}


void MainWindow::changelight(int value){
    light->setState(value);
    unsigned char range = ChangePwm::RANGE[value];
    ChangePwm::MSG_PWM[4] = range;
    ChangePwm::MSG_PWM[5] = 0x50 + range;
    if(-1 == serial_server->writeToSerial(ChangePwm::MSG_PWM))
    {
        emit addLog("Filed");
        return;
    }
    emit addLog("Success");
}


void MainWindow::changemotor(int state)
{
    if(0 == state){
        if(-1 == serial_server->writeToSerial(Motor::MSG_MOTOR_STOP)){
            emit addLog("failed");
            return;
        }
        motor->setState(0);
        emit addLog("Success");
    }

    else if (1 == state){
        if(-1 == serial_server->writeToSerial(Motor::MSG_MOTOR_FORE)){
            emit addLog("failed");
            return;
        }
        motor->setState(1);
        emit addLog("Success");
    }

    else if(2 == state){
        if(-1 == serial_server->writeToSerial(Motor::MSG_MOTOR_BACK)){
            emit addLog("failed");
            return;
        }
        motor->setState(2);
        emit addLog("Success");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    changemotor(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    changemotor(2);
}

void MainWindow::on_pushButton_4_clicked()
{
    changemotor(0);
}

void MainWindow::updatetimer(){
    QTime  time_now = QTime::currentTime();
    QString strtime = time_now.toString("h:m:s");

    ui->label_time->setText(strtime);


    value_h = ui->spinBox->value();
    value_m = ui->spinBox_2->value();

    if(QTime::currentTime().hour() == value_h && QTime::currentTime().minute() == value_m && QTime::currentTime().second() == 0){
        emit timeEqualSignal();
        QMessageBox::information(this, tr("Timed event!"), tr("The event you set up just now is time."));
    }

}

void MainWindow::slotTimeEqual()
{
    QString time_event = ui->comboBox->currentText();
    if(time_event == "None") return;
    else if(time_event == "Turn on"){
        changelight(4);
    }
    else if(time_event == "Turn off"){
        changelight(0);
    }
//    emit addLog(time_event);
}

void MainWindow::open(){
    QDialog dialog(this);
    //dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog.setWindowTitle(tr("Hello, dialog!"));

    QMessageBox msgBox;
    msgBox.setText(tr("The document has been modified."));
    msgBox.setInformativeText(tr("Do you want to save your changes?"));
    msgBox.setDetailedText(tr("Differences here..."));
    msgBox.setStandardButtons(QMessageBox::Save
                              | QMessageBox::Discard
                              | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
        case QMessageBox::Save:
            qDebug() << "Save document!";
        break;
    case QMessageBox::Discard:
        qDebug() << "Discard changed!";
        break;
    case QMessageBox::Cancel:
        qDebug() << "Close doucment";
        break;

    }

    dialog.exec();
    qDebug() << dialog.result();

    QMessageBox::information(this, tr("Information"), tr("Open"));
}

void MainWindow::openFile(){

    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text File(*.txt)"));
    if(!path.isEmpty()){
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QMessageBox::warning(this, tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }else{
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}
void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if(!path.isEmpty())
    {
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QMessageBox::warning(this, tr("Write File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
           }
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
    }
            else{
            QMessageBox::warning(this, tr("Path"),
                                 tr("You did not select any file."));
    }
}

void MainWindow::process_msg_from_serial_log(QByteArray msg){
    QFile file("/home/wjy/wjy.txt");
    if(file.open(QFile::WriteOnly | QIODevice::Truncate)){
        QTextStream out(&file);
        out << msg;
    }

}
