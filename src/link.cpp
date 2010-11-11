#include "link.h"
//
using namespace std;

Link::Link(int n)
{
	pSig=NULL;
        pos=n;
}

Link::~Link()
{
	pSig=NULL;
}

QString Link::getDir()
{
	return dir;
}

void Link::setDir(QString enlace)
{
	dir=enlace;
}

void Link::setServicio(QString serv)
{
	servicio=serv;
}

QString Link::getServicio()
{
	return servicio;
}

void Link::setPsig(Link* link)
{
	pSig=link;
}

Link* Link::getPsig()
{
	return pSig;
}

QString Link::getNombre()
{
        return nombre;
}

void Link::setNombre(QString n)
{
    nombre=n;
}

int Link::getPos()
 {
     return pos;
 }
//
