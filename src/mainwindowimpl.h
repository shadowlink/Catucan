#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <QString>
#include "curl/curl.h"
#include "downloader.h"
#include "link.h"
#include <QThread>
//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
        QTabWidget *main;
private:
        Downloader *d;
private slots:
	void addClicked();
        void startClicked();
        void insertClicked();
        void threadFinished();
};
#endif




