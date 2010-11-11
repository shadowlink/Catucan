/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Nov 11 15:15:33 2010
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabMain;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QPushButton *btStart;
    QTreeWidget *tMainList;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *edText;
    QPushButton *btAdd;
    QVBoxLayout *verticalLayout_2;
    QListWidget *lbMyList;
    QPushButton *btAgregar;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(744, 521);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(32, 32));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabMain = new QTabWidget(centralwidget);
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        tabMain->setIconSize(QSize(32, 32));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setEnabled(true);
        tab->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btStart = new QPushButton(tab);
        btStart->setObjectName(QString::fromUtf8("btStart"));

        gridLayout_2->addWidget(btStart, 1, 0, 1, 1);

        tMainList = new QTreeWidget(tab);
        tMainList->setObjectName(QString::fromUtf8("tMainList"));
        tMainList->setColumnCount(6);
        tMainList->header()->setDefaultSectionSize(120);

        gridLayout_2->addWidget(tMainList, 0, 0, 1, 1);

        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/Earth-Download-256x256.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMain->addTab(tab, icon1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        edText = new QLineEdit(tab_2);
        edText->setObjectName(QString::fromUtf8("edText"));

        horizontalLayout->addWidget(edText);

        btAdd = new QPushButton(tab_2);
        btAdd->setObjectName(QString::fromUtf8("btAdd"));

        horizontalLayout->addWidget(btAdd);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lbMyList = new QListWidget(tab_2);
        lbMyList->setObjectName(QString::fromUtf8("lbMyList"));

        verticalLayout_2->addWidget(lbMyList);

        btAgregar = new QPushButton(tab_2);
        btAgregar->setObjectName(QString::fromUtf8("btAgregar"));

        verticalLayout_2->addWidget(btAgregar);


        gridLayout_3->addLayout(verticalLayout_2, 1, 0, 1, 1);

        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resource/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMain->addTab(tab_2, icon2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resource/downloaded.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMain->addTab(tab_3, icon3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resource/opciones.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMain->addTab(tab_4, icon4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resource/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMain->addTab(tab_5, icon5, QString());

        gridLayout->addWidget(tabMain, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 744, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabMain->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Catucan", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btStart->setText(QApplication::translate("MainWindow", "Descargar todo", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = tMainList->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("MainWindow", "Estimado", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("MainWindow", "Velocidad", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "Progreso", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "Tama\303\261o", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Estado", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Nombre del fichero", 0, QApplication::UnicodeUTF8));
        tabMain->setTabText(tabMain->indexOf(tab), QApplication::translate("MainWindow", "Descargas", 0, QApplication::UnicodeUTF8));
        btAdd->setText(QApplication::translate("MainWindow", "Comprobar", 0, QApplication::UnicodeUTF8));
        btAgregar->setText(QApplication::translate("MainWindow", "A\303\261adir", 0, QApplication::UnicodeUTF8));
        tabMain->setTabText(tabMain->indexOf(tab_2), QApplication::translate("MainWindow", "A\303\261adir enlaces", 0, QApplication::UnicodeUTF8));
        tabMain->setTabText(tabMain->indexOf(tab_3), QApplication::translate("MainWindow", "Descargados", 0, QApplication::UnicodeUTF8));
        tabMain->setTabText(tabMain->indexOf(tab_4), QApplication::translate("MainWindow", "Opciones", 0, QApplication::UnicodeUTF8));
        tabMain->setTabText(tabMain->indexOf(tab_5), QApplication::translate("MainWindow", "Ayuda", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
