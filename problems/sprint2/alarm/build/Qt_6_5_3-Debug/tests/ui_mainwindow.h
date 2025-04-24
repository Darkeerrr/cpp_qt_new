/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_load_file;
    QAction *action_close;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *lbl_now;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpinBox *sb_hour;
    QSpinBox *sb_min;
    QSpinBox *sb_sec;
    QLabel *label_3;
    QLabel *lbl_melody;
    QLabel *label_5;
    QLabel *lbl_timeout;
    QSpacerItem *verticalSpacer;
    QPushButton *pb_start_stop;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(367, 315);
        MainWindow->setContextMenuPolicy(Qt::CustomContextMenu);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        action_load_file = new QAction(MainWindow);
        action_load_file->setObjectName("action_load_file");
        action_close = new QAction(MainWindow);
        action_close->setObjectName("action_close");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("application-exit")));
        action_close->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        lbl_now = new QLabel(centralwidget);
        lbl_now->setObjectName("lbl_now");
        QFont font;
        font.setFamilies({QString::fromUtf8("PT Mono")});
        font.setPointSize(36);
        font.setBold(true);
        lbl_now->setFont(font);
        lbl_now->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbl_now);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font1;
        font1.setBold(true);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        sb_hour = new QSpinBox(centralwidget);
        sb_hour->setObjectName("sb_hour");
        sb_hour->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        sb_hour->setAlignment(Qt::AlignCenter);
        sb_hour->setMaximum(23);

        horizontalLayout->addWidget(sb_hour);

        sb_min = new QSpinBox(centralwidget);
        sb_min->setObjectName("sb_min");
        sb_min->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        sb_min->setAlignment(Qt::AlignCenter);
        sb_min->setMaximum(59);

        horizontalLayout->addWidget(sb_min);

        sb_sec = new QSpinBox(centralwidget);
        sb_sec->setObjectName("sb_sec");
        sb_sec->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        sb_sec->setAlignment(Qt::AlignCenter);
        sb_sec->setMaximum(59);

        horizontalLayout->addWidget(sb_sec);


        verticalLayout->addLayout(horizontalLayout);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        lbl_melody = new QLabel(centralwidget);
        lbl_melody->setObjectName("lbl_melody");

        verticalLayout->addWidget(lbl_melody);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);

        verticalLayout->addWidget(label_5);

        lbl_timeout = new QLabel(centralwidget);
        lbl_timeout->setObjectName("lbl_timeout");

        verticalLayout->addWidget(lbl_timeout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pb_start_stop = new QPushButton(centralwidget);
        pb_start_stop->setObjectName("pb_start_stop");
        pb_start_stop->setMinimumSize(QSize(0, 35));
        QFont font2;
        font2.setPointSize(12);
        pb_start_stop->setFont(font2);
        pb_start_stop->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(pb_start_stop);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 367, 24));
        menubar->setContextMenuPolicy(Qt::ActionsContextMenu);
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_load_file);
        menu->addSeparator();
        menu->addAction(action_close);

        retranslateUi(MainWindow);
        QObject::connect(action_close, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));
        QObject::connect(MainWindow, &QMainWindow::customContextMenuRequested, menu, qOverload<>(&QMenu::showNormal));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\221\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272", nullptr));
        action_load_file->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\274\320\265\320\273\320\276\320\264\320\270\321\216", nullptr));
        action_close->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        lbl_now->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\262\321\200\320\265\320\274\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\273\320\276\320\264\320\270\321\217:", nullptr));
        lbl_melody->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276 \321\201\321\200\320\260\320\261\320\260\321\202\321\213\320\262\320\260\320\275\320\270\321\217 \320\261\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272\320\260 \320\276\321\201\321\202\320\260\320\273\320\276\321\201\321\214:", nullptr));
        lbl_timeout->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\320\265 \320\261\321\203\320\264\320\270\320\273\321\214\320\275\320\270\320\272", nullptr));
        pb_start_stop->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
