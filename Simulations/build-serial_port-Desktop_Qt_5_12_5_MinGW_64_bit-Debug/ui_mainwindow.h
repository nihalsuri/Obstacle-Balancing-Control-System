/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QStackedWidget *stackedWidget;
    QWidget *main_page;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_8;
    QTextBrowser *textBrowser;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_10;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *SendSerialButton;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *connect_button;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *settings_button;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_9;
    QWidget *settings_page;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_com;
    QComboBox *com_combo;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_baud;
    QLineEdit *baud_setting;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_word_length;
    QLineEdit *word_length_setting;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_parity;
    QComboBox *parity_combo;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_stop_bits;
    QComboBox *stop_bits_combo;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *save_button;
    QSpacerItem *horizontalSpacer;
    QPushButton *to_page_1_button;
    QSpacerItem *horizontalSpacer_13;
    QWidget *plotting;
    QCustomPlot *plot;
    QDoubleSpinBox *x_doubleSpinBox;
    QDoubleSpinBox *y_doubleSpinBox_2;
    QPushButton *add_plov_val_button;
    QPushButton *clear_plot_button;
    QPushButton *to_page_1_button_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        main_page = new QWidget();
        main_page->setObjectName(QString::fromUtf8("main_page"));
        gridLayout_2 = new QGridLayout(main_page);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        label_2 = new QLabel(main_page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        textBrowser = new QTextBrowser(main_page);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setMinimumSize(QSize(600, 200));

        horizontalLayout_9->addWidget(textBrowser);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer_7 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_7);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);

        textEdit = new QTextEdit(main_page);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 27));

        horizontalLayout_7->addWidget(textEdit);

        horizontalSpacer_2 = new QSpacerItem(1, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        SendSerialButton = new QPushButton(main_page);
        SendSerialButton->setObjectName(QString::fromUtf8("SendSerialButton"));

        horizontalLayout_7->addWidget(SendSerialButton);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_8);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        connect_button = new QPushButton(main_page);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));

        horizontalLayout_8->addWidget(connect_button);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(main_page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_8->addWidget(pushButton);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        settings_button = new QPushButton(main_page);
        settings_button->setObjectName(QString::fromUtf8("settings_button"));

        horizontalLayout_8->addWidget(settings_button);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        pushButton_2 = new QPushButton(main_page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_8->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_9);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(main_page);
        settings_page = new QWidget();
        settings_page->setObjectName(QString::fromUtf8("settings_page"));
        gridLayout_4 = new QGridLayout(settings_page);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_com = new QLabel(settings_page);
        label_com->setObjectName(QString::fromUtf8("label_com"));
        sizePolicy.setHeightForWidth(label_com->sizePolicy().hasHeightForWidth());
        label_com->setSizePolicy(sizePolicy);
        label_com->setMinimumSize(QSize(75, 0));
        label_com->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_6->addWidget(label_com);

        com_combo = new QComboBox(settings_page);
        com_combo->setObjectName(QString::fromUtf8("com_combo"));
        sizePolicy.setHeightForWidth(com_combo->sizePolicy().hasHeightForWidth());
        com_combo->setSizePolicy(sizePolicy);
        com_combo->setMinimumSize(QSize(115, 0));
        com_combo->setMaximumSize(QSize(115, 16777215));

        horizontalLayout_6->addWidget(com_combo);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_baud = new QLabel(settings_page);
        label_baud->setObjectName(QString::fromUtf8("label_baud"));
        sizePolicy.setHeightForWidth(label_baud->sizePolicy().hasHeightForWidth());
        label_baud->setSizePolicy(sizePolicy);
        label_baud->setMinimumSize(QSize(75, 16));
        label_baud->setMaximumSize(QSize(75, 16));

        horizontalLayout->addWidget(label_baud);

        baud_setting = new QLineEdit(settings_page);
        baud_setting->setObjectName(QString::fromUtf8("baud_setting"));
        sizePolicy.setHeightForWidth(baud_setting->sizePolicy().hasHeightForWidth());
        baud_setting->setSizePolicy(sizePolicy);
        baud_setting->setMinimumSize(QSize(115, 0));
        baud_setting->setMaximumSize(QSize(115, 16777215));

        horizontalLayout->addWidget(baud_setting);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_word_length = new QLabel(settings_page);
        label_word_length->setObjectName(QString::fromUtf8("label_word_length"));
        sizePolicy.setHeightForWidth(label_word_length->sizePolicy().hasHeightForWidth());
        label_word_length->setSizePolicy(sizePolicy);
        label_word_length->setMinimumSize(QSize(75, 16));
        label_word_length->setMaximumSize(QSize(75, 16));

        horizontalLayout_2->addWidget(label_word_length);

        word_length_setting = new QLineEdit(settings_page);
        word_length_setting->setObjectName(QString::fromUtf8("word_length_setting"));
        sizePolicy.setHeightForWidth(word_length_setting->sizePolicy().hasHeightForWidth());
        word_length_setting->setSizePolicy(sizePolicy);
        word_length_setting->setMinimumSize(QSize(115, 0));
        word_length_setting->setMaximumSize(QSize(115, 16777215));

        horizontalLayout_2->addWidget(word_length_setting);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_parity = new QLabel(settings_page);
        label_parity->setObjectName(QString::fromUtf8("label_parity"));
        sizePolicy.setHeightForWidth(label_parity->sizePolicy().hasHeightForWidth());
        label_parity->setSizePolicy(sizePolicy);
        label_parity->setMinimumSize(QSize(75, 0));
        label_parity->setMaximumSize(QSize(75, 16));

        horizontalLayout_3->addWidget(label_parity);

        parity_combo = new QComboBox(settings_page);
        parity_combo->setObjectName(QString::fromUtf8("parity_combo"));
        sizePolicy.setHeightForWidth(parity_combo->sizePolicy().hasHeightForWidth());
        parity_combo->setSizePolicy(sizePolicy);
        parity_combo->setMinimumSize(QSize(115, 0));
        parity_combo->setMaximumSize(QSize(115, 16777215));

        horizontalLayout_3->addWidget(parity_combo);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_stop_bits = new QLabel(settings_page);
        label_stop_bits->setObjectName(QString::fromUtf8("label_stop_bits"));
        sizePolicy.setHeightForWidth(label_stop_bits->sizePolicy().hasHeightForWidth());
        label_stop_bits->setSizePolicy(sizePolicy);
        label_stop_bits->setMinimumSize(QSize(75, 0));
        label_stop_bits->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_4->addWidget(label_stop_bits);

        stop_bits_combo = new QComboBox(settings_page);
        stop_bits_combo->setObjectName(QString::fromUtf8("stop_bits_combo"));
        sizePolicy.setHeightForWidth(stop_bits_combo->sizePolicy().hasHeightForWidth());
        stop_bits_combo->setSizePolicy(sizePolicy);
        stop_bits_combo->setMinimumSize(QSize(115, 0));
        stop_bits_combo->setMaximumSize(QSize(115, 16777215));

        horizontalLayout_4->addWidget(stop_bits_combo);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        save_button = new QPushButton(settings_page);
        save_button->setObjectName(QString::fromUtf8("save_button"));

        horizontalLayout_5->addWidget(save_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        to_page_1_button = new QPushButton(settings_page);
        to_page_1_button->setObjectName(QString::fromUtf8("to_page_1_button"));

        horizontalLayout_5->addWidget(to_page_1_button);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_10->addLayout(verticalLayout_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_13);


        gridLayout_4->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        stackedWidget->addWidget(settings_page);
        plotting = new QWidget();
        plotting->setObjectName(QString::fromUtf8("plotting"));
        plot = new QCustomPlot(plotting);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(110, 10, 561, 341));
        x_doubleSpinBox = new QDoubleSpinBox(plotting);
        x_doubleSpinBox->setObjectName(QString::fromUtf8("x_doubleSpinBox"));
        x_doubleSpinBox->setGeometry(QRect(260, 430, 62, 22));
        y_doubleSpinBox_2 = new QDoubleSpinBox(plotting);
        y_doubleSpinBox_2->setObjectName(QString::fromUtf8("y_doubleSpinBox_2"));
        y_doubleSpinBox_2->setGeometry(QRect(350, 430, 62, 22));
        add_plov_val_button = new QPushButton(plotting);
        add_plov_val_button->setObjectName(QString::fromUtf8("add_plov_val_button"));
        add_plov_val_button->setGeometry(QRect(460, 430, 93, 28));
        clear_plot_button = new QPushButton(plotting);
        clear_plot_button->setObjectName(QString::fromUtf8("clear_plot_button"));
        clear_plot_button->setGeometry(QRect(570, 430, 93, 28));
        to_page_1_button_2 = new QPushButton(plotting);
        to_page_1_button_2->setObjectName(QString::fromUtf8("to_page_1_button_2"));
        to_page_1_button_2->setGeometry(QRect(670, 430, 93, 28));
        stackedWidget->addWidget(plotting);

        gridLayout_3->addWidget(stackedWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "PID Beam App", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Serial Port", nullptr));
        SendSerialButton->setText(QApplication::translate("MainWindow", "Send", nullptr));
        connect_button->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Plotting", nullptr));
        settings_button->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label_com->setText(QApplication::translate("MainWindow", "COM port", nullptr));
        label_baud->setText(QApplication::translate("MainWindow", "Baud rate", nullptr));
        label_word_length->setText(QApplication::translate("MainWindow", "Word length", nullptr));
        label_parity->setText(QApplication::translate("MainWindow", "Parity", nullptr));
        label_stop_bits->setText(QApplication::translate("MainWindow", "Stop bits", nullptr));
        save_button->setText(QApplication::translate("MainWindow", "Save", nullptr));
        to_page_1_button->setText(QApplication::translate("MainWindow", "Back", nullptr));
        add_plov_val_button->setText(QApplication::translate("MainWindow", "Add", nullptr));
        clear_plot_button->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        to_page_1_button_2->setText(QApplication::translate("MainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
