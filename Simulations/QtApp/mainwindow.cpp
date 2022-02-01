#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QVector>
#include <cstdio>
QSerialPort *serial_port;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/put.ico"));

    ui->setupUi(this);

        //establish initial connection with default COM port
        serial_port = new QSerialPort(this);

        serial_port->setPortName("COM4");
        serial_port->setBaudRate(QSerialPort::Baud115200);
        serial_port->setParity(QSerialPort::NoParity);
        serial_port->setDataBits(QSerialPort::Data7);
        serial_port->setStopBits(QSerialPort::OneStop);
        //serial_port->setFlowControl(QSerialPort::SoftwareControl);
        serial_port->setFlowControl(QSerialPort::NoFlowControl);      //sprawdz 2

        if(serial_port->open(QIODevice::ReadWrite))
            ui->textBrowser->setText("Success!");
        else
            ui->textBrowser->setText("Error - check settings");
        connect(serial_port, SIGNAL(readyRead()), this, SLOT(serialReceived()));

    //get COM ports and write them to settings page
    QString com;
    QList<QSerialPortInfo> infoList = QSerialPortInfo::availablePorts();
    QSerialPortInfo info;
    bool first = true;
    foreach(info, infoList)
    {
        if(first == true)
            com = info.portName();
        first = false;
        ui->com_combo->addItem(info.portName());
    }
    //settings tab setup
    ui->com_combo->setCurrentIndex(2);
    ui->baud_setting->setText("115200");
    ui->word_length_setting->setText("8");
    ui->parity_combo->addItem("none");
    ui->parity_combo->addItem("odd");
    ui->parity_combo->addItem("even");
    ui->stop_bits_combo->addItem("0");
    ui->stop_bits_combo->addItem("1");

    //plot tab setup
    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssDot);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->plot->xAxis->setLabel("time[?]");
    ui->plot->yAxis->setLabel("Position [cm]");
    ui->plot->xAxis->setRange(0, 30);
    ui->plot->yAxis->setRange(5, 35);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->stackedWidget->setCurrentIndex(0);
    ui->autoscroll_checkbox->setChecked(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
}

void MainWindow::clearPlot()
{
    qv_x.clear();
    qv_y.clear();
}

void MainWindow::plot()
{
    ui->plot->xAxis->rescale(true);
    ui->plot->graph(0)->setData(qv_x, qv_y);

    QCPItemLine *arrow = new QCPItemLine(ui->plot);
    arrow->setPen(QPen(Qt::red));
    arrow->start->setCoords(0,setpoint_val);
    arrow->end->setCoords(10000, setpoint_val);
    arrow->deleteLater();

    ui->plot->replot();
    ui->plot->update();
}

void MainWindow::serialReceived()
{
    QByteArray ba;
    float yy;

    if(serial_port->bytesAvailable() == strlen("29.89, 20")) {

        ba = serial_port->readLine();

        ui->textBrowser->setText(ba);

        std::string str(ba, strlen(ba));
        const char *c = str.c_str();
        //std::sscanf(c, "%f, %f", &xx, &yy);
        if(strlen(c) == strlen("29.89, 20") || strlen(c) == strlen("1.89, 20")){
        std::sscanf(c, "%f, %d", &yy, &setpoint_val);

      //  if(yy != 0 && setpoint_val != 0){
            if(yy != setpoint_val){
                qv_x.append(x_axis_val);
                qv_y.append(yy);
                plot();
                x_axis_val = x_axis_val+0.1;
                qDebug()<<ba;
                qDebug()<<yy;
                ui->setpoint_val_label->setText(QString::number(setpoint_val));
                ui->setpoint_val_label_2->setText(QString::number(yy));
                if(ba=="")
                    on_connect_button_clicked();
            }
        }
    }
 //     }
}

void MainWindow::on_connect_button_clicked()
{
    ConnectSerial();
}

void MainWindow::on_clear_plot_button_clicked()
{
    clearPlot();
    plot();
    x_axis_val=0;
}

void MainWindow::ConnectSerial()
{
    serial_port->close();
    serial_port = new QSerialPort(this);
    if(ui->baud_setting->text() == "115200")
        serial_port->setBaudRate(QSerialPort::Baud115200);
    else
        serial_port->setBaudRate(QSerialPort::Baud115200);
    serial_port->setPortName(ui->com_combo->currentText());
    serial_port->setParity(QSerialPort::NoParity);
    serial_port->setDataBits(QSerialPort::Data8);
    serial_port->setStopBits(QSerialPort::OneStop);
    serial_port->setFlowControl(QSerialPort::NoFlowControl);
    if(serial_port->open(QIODevice::ReadWrite))
        ui->textBrowser->setText("success!");
    connect(serial_port, SIGNAL(readyRead()), this, SLOT(serialReceived()));
    qDebug()<<"Serial com : "<<ui->com_combo->currentText();
}

void MainWindow::getCOMports()
{
    ui->com_combo->clear();
    QList<QSerialPortInfo> infoList = QSerialPortInfo::availablePorts();
    QSerialPortInfo info;
    bool first = true;
    foreach(info, infoList)
    {
        if(first == true)
            QString com = info.portName();
        first = false;
        ui->com_combo->addItem(info.portName());
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    MainWindow::close();
}

void MainWindow::on_to_page_1_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_save_button_clicked()
{
    ui->com_combo->setCurrentIndex(2);
    if(QMessageBox::information(this, "Information", "Settings saved successfully!", QMessageBox::Ok) == QMessageBox::Ok)
        ui->stackedWidget->setCurrentIndex(0);
    else
        QMessageBox::information(this, "Information", "Error saving settings!", QMessageBox::Ok);
}

void MainWindow::on_to_page_1_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_go_settings_button_clicked()
{
    getCOMports();
    ui->stackedWidget->setCurrentIndex(1);
}

