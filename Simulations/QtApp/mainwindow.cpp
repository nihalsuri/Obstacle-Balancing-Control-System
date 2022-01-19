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
    ui->setupUi(this);

        serial_port = new QSerialPort(this);

        serial_port->setPortName("COM16");
        serial_port->setBaudRate(QSerialPort::Baud115200);
        serial_port->setParity(QSerialPort::NoParity);
        serial_port->setDataBits(QSerialPort::Data8);
        serial_port->setStopBits(QSerialPort::OneStop);
        serial_port->setFlowControl(QSerialPort::NoFlowControl);
        if(serial_port->open(QIODevice::ReadWrite))
            ui->textBrowser->setText("success!");
        serial_port->write("Connection ok!");
        connect(serial_port, SIGNAL(readyRead()), this, SLOT(serialReceived()));

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
    ui->baud_setting->setText("115200");
    ui->word_length_setting->setText("8");
    ui->parity_combo->addItem("none");
    ui->parity_combo->addItem("odd");
    ui->parity_combo->addItem("even");
    ui->stop_bits_combo->addItem("0");
    ui->stop_bits_combo->addItem("1");

    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCrossCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
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
    ui->plot->graph(0)->setData(qv_x, qv_y);
    ui->plot->replot();
    ui->plot->update();
}

void MainWindow::serialReceived()
{
    QByteArray ba;
    QString msg;

    serial_port->setReadBufferSize(15);
    ba = serial_port->readAll();



    ui->textBrowser->setText(ba);
    qDebug()<<ba;


    //float val1=0.0, val2=0.0;
   // sscanf(ba, "%f,%f", val1, val2);
   // qv_x.append(val1);
   // qv_y.append(val2);




}


void MainWindow::on_to_page_1_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_settings_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_connect_button_clicked()
{

    serial_port->close();
    serial_port = new QSerialPort(this);

    serial_port->setPortName("COM16");
    serial_port->setBaudRate(QSerialPort::Baud115200);
    serial_port->setParity(QSerialPort::NoParity);
    serial_port->setDataBits(QSerialPort::Data8);
    serial_port->setStopBits(QSerialPort::OneStop);
    serial_port->setFlowControl(QSerialPort::NoFlowControl);
    if(serial_port->open(QIODevice::ReadWrite))
        ui->textBrowser->setText("success!");
    serial_port->write("Connection ok!");
    connect(serial_port, SIGNAL(readyRead()), this, SLOT(serialReceived()));

}


void MainWindow::on_add_plov_val_button_clicked()
{
    addPoint(ui->x_doubleSpinBox->value(), ui->y_doubleSpinBox_2->value());
    plot();
}


void MainWindow::on_clear_plot_button_clicked()
{
    clearPlot();
    plot();
}


void MainWindow::on_to_page_1_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}




void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

