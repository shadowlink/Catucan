#ifndef LINK_H
#define LINK_H
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <QString>
//
using namespace std;

class Link  
{

public:
        Link(int n);
	~Link();
	QString getDir();
	void setDir(QString);
	void setServicio(QString);
	QString getServicio();
	void setPsig(Link*);
        QString getNombre();
        void setNombre(QString);
        int getPos();
	Link* getPsig();

private:
	QString dir;
	QString servicio;
        QString nombre;
        int pos;
	bool descargado;
	Link *pSig;	
};
#endif
