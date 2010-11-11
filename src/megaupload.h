#ifndef MEGAUPLOAD_H
#define MEGAUPLOAD_H
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "curl/curl.h"
#include <string.h>
#include <QString>
#include <QThread>
#include "downloadmanager.h"
#include <QTreeWidget>
//
using namespace std;
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);

class Megaupload : public QThread
{

public:
        Megaupload(QString link, QTreeWidget* tMainList);
	~Megaupload();
        void run();
	bool DescargaUrl();
	bool AnalizaCaptcha();
	bool DescargaFichero();
	bool CaptchaValido();
	void InicializarDatos(QString);	
private:
	ifstream imagen, docHtml, docHtml2;
	CURL *curl;
  	CURLcode res;
	string captchacode, megavar, captcha, captchaDir, downloadlink, linea, megalink, nombre;
	FILE * html;
	FILE *captcha_download;
	FILE *file_download;
	FILE * html2;
        QTreeWidget* tMainList;
};
#endif
