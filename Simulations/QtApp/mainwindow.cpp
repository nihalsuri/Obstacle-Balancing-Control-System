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

//    establish initial connection - probably delete it in future
        serial_port = new QSerialPort(this);

        serial_port->setPortName("COM16");
        serial_port->setBaudRate(QSerialPort::Baud115200);
        serial_port->setParity(QSerialPort::NoParity);
        serial_port->setDataBits(QSerialPort::Data8);
        serial_port->setStopBits(QSerialPort::OneStop);
        serial_port->setFlowControl(QSerialPort::NoFlowControl);
        if(serial_port->open(QIODevice::ReadWrite))
            ui->textBrowser->setText("Success!");
        else
            ui->textBrowser->setText("Error - check settings");
        connect(serial_port, SIGNAL(readyRead()), this, SLOT(serialReceived()));

    //get COM ports
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
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->plot->xAxis->setLabel("time[?]");
    ui->plot->yAxis->setLabel("Position [cm]");
    ui->plot->xAxis->setRange(0, 60);
    ui->plot->yAxis->setRange(0, 40);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->setpointSlider->setRange(10, 20);
    ui->setpointSlider->setTickInterval(1);
    ui->setpointSlider->setTickPosition(QSlider::TickPosition(15));
    ui->setpointSlider->setSliderPosition(15);
    ui->setpoint_val_label->setText(QString::number(ui->setpointSlider->tickPosition()));
    ui->stackedWidget->setCurrentIndex(0);
    //=  QCPItemLine(ui->plot);

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
        QCPItemLine *arrow = new QCPItemLine(ui->plot);
        arrow->deleteLater();
        arrow->setPen(QPen(Qt::red));
        arrow->start->setCoords(0,setpoint_val);
        arrow->end->setCoords(1000, setpoint_val);
    ui->plot->replot();
    ui->plot->update();
}

void MainWindow::serialReceived()
{
    QByteArray ba;
    float xx, yy;

    serial_port->setReadBufferSize(0);
    if(serial_port->waitForReadyRead(30)){

        ba = serial_port->readAll();

        ui->textBrowser->setText(ba);

        std::string str(ba, strlen(ba));
        const char *c = str.c_str();
        std::sscanf(c, "%f, %f", &xx, &yy);

        qv_x.append(xx);
        qv_y.append(yy*25);
        plot();

        qDebug()<<ba;
        qDebug()<<xx;
        qDebug()<<yy;
        if(ba=="")
            on_connect_button_clicked();
    }
}

void MainWindow::on_connect_button_clicked()
{
    ConnectSerial();
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

void MainWindow::ConnectSerial()
{
    serial_port->close();
    serial_port = new QSerialPort(this);

    serial_port->setPortName(ui->com_combo->currentText());
    serial_port->setBaudRate(QSerialPort::Baud115200);
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


void MainWindow::on_settings_button_clicked()
{
    getCOMports();
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_setpointSlider_valueChanged(int value)
{

    ui->setpoint_val_label->setText(QString::number(value));
    setpoint_val = value;


    //ui->plot->savePng()
}


void MainWindow::on_save_button_clicked()
{
    ui->com_combo->setCurrentIndex(2);
    if(QMessageBox::information(this, "Information", "Settings saved successfully!", QMessageBox::Ok) == QMessageBox::Ok)
        ui->stackedWidget->setCurrentIndex(0);
    else
        QMessageBox::information(this, "Information", "Error saving settings!", QMessageBox::Ok);
}

//send through UART
void MainWindow::on_pushButton_3_clicked()
{
    char msg[50]={};
    QString msg_qs = ui->textEdit->toPlainText();
    std::string msg_s = msg_qs.toStdString();
//    for(int i=0; i<sizeof(msg_s);i++)
//        msg[i] = msg_s[i];
    int n = sprintf(msg, "SETPOINT=%d", setpoint_val);
    serial_port->write(msg, n);
}

