#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QTextStream>
#include <algorithm>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addPoint(double x, double y);
    void clearPlot();
    void plot();

private slots:
    void serialReceived();

    void on_to_page_1_button_clicked();

    void on_settings_button_clicked();

    void on_connect_button_clicked();

    void on_add_plov_val_button_clicked();

    void on_clear_plot_button_clicked();

    void on_to_page_1_button_2_clicked();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<double> qv_x, qv_y;
};
#endif // MAINWINDOW_H
