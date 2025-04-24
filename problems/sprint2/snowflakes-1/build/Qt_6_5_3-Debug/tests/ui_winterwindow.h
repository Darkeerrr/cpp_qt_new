/********************************************************************************
** Form generated from reading UI file 'winterwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINTERWINDOW_H
#define UI_WINTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinterWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSlider *sld_size;
    QLabel *label;
    QSlider *sld_line;
    QLabel *label_5;
    QSlider *sld_rotation;
    QPushButton *btn_color;

    void setupUi(QMainWindow *WinterWindow)
    {
        if (WinterWindow->objectName().isEmpty())
            WinterWindow->setObjectName("WinterWindow");
        WinterWindow->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(217, 217, 217, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(191, 191, 191, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        QBrush brush2(QColor(128, 128, 128, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush3);
        QBrush brush4(QColor(72, 72, 72, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        QBrush brush6(QColor(71, 71, 71, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        WinterWindow->setPalette(palette);
        centralwidget = new QWidget(WinterWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2, 0, Qt::AlignVCenter);

        sld_size = new QSlider(centralwidget);
        sld_size->setObjectName("sld_size");
        sld_size->setMinimum(1);
        sld_size->setMaximum(250);
        sld_size->setValue(100);
        sld_size->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sld_size, 0, Qt::AlignVCenter);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        sld_line = new QSlider(centralwidget);
        sld_line->setObjectName("sld_line");
        sld_line->setMinimum(1);
        sld_line->setMaximum(50);
        sld_line->setValue(5);
        sld_line->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sld_line);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5, 0, Qt::AlignVCenter);

        sld_rotation = new QSlider(centralwidget);
        sld_rotation->setObjectName("sld_rotation");
        sld_rotation->setMaximum(360);
        sld_rotation->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sld_rotation);

        btn_color = new QPushButton(centralwidget);
        btn_color->setObjectName("btn_color");

        horizontalLayout->addWidget(btn_color);


        verticalLayout->addLayout(horizontalLayout);

        WinterWindow->setCentralWidget(centralwidget);

        retranslateUi(WinterWindow);
        QObject::connect(sld_line, &QSlider::valueChanged, WinterWindow, qOverload<>(&QMainWindow::repaint));
        QObject::connect(sld_rotation, &QSlider::valueChanged, WinterWindow, qOverload<>(&QMainWindow::repaint));
        QObject::connect(sld_size, &QSlider::valueChanged, WinterWindow, qOverload<>(&QMainWindow::repaint));

        QMetaObject::connectSlotsByName(WinterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WinterWindow)
    {
        WinterWindow->setWindowTitle(QCoreApplication::translate("WinterWindow", "Winter Window", nullptr));
        label_2->setText(QCoreApplication::translate("WinterWindow", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
        label->setText(QCoreApplication::translate("WinterWindow", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("WinterWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        btn_color->setText(QCoreApplication::translate("WinterWindow", "\320\246\320\262\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinterWindow: public Ui_WinterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINTERWINDOW_H
