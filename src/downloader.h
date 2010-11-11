#ifndef DOWNLOADER_H
#define DOWNLOADER_H
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <QString>
#include "curl/curl.h"
#include "megaupload.h"
#include "link.h"
#include "download_handler.h"
#include <QTabWidget>
#include <QTreeWidget>

//
using namespace std;

class Downloader : public QThread {
public:
        Downloader(QTreeWidget *t);
	~Downloader();
        void run();
	void NuevoLink(QString);
	void SMegaupload(Link *link);
	bool ListaVacia();
        void DescargaLista();
        Link* getUltimo();
private:
	QString DetectarServicio(QString);
        QString DetectarNombre(QString);
	Link *lista;
	Link *pUlt; //Puntero al ultimo elemento insertado;
        QTreeWidget *tMainList;

};
#endif
