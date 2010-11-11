#ifndef DOWNLOAD_HANDLER_H
#define DOWNLOAD_HANDLER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <QString>
#include "curl/curl.h"
#include "link.h"
#include "megaupload.h"
#include <QTreeWidget>
//
using namespace std;

class Download_Handler : public QThread {
public:
    Download_Handler(QTreeWidget* tMainList);
    ~Download_Handler();
    void addMegaupload(Link*);
    void addMediafire(Link*);
    void setMegaupload();
    void setMediafire();
    void unsetAll();
    void downMegaupload();
    void SMegaupload(Link *link);
    void run();
private:
    QTreeWidget *tMainList;
    bool megaupload;
    bool mediafire;
    Link *lMegaupload;
    Link *lMediafire;
};

#endif // DOWNLOAD_HANDLER_H
