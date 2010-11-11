#include "download_handler.h"

using namespace std;

Download_Handler::Download_Handler(QTreeWidget* t)
{
    lMegaupload=NULL;
    lMegaupload=NULL;
    megaupload=mediafire=false;
    tMainList=t;
}

Download_Handler::~Download_Handler()
{
    lMegaupload=NULL;
    lMegaupload=NULL;
    megaupload=mediafire=false;
}

void Download_Handler::addMegaupload(Link* l)
{
    if(lMegaupload==NULL)
    {
        lMegaupload=l;
    }
    else
    {
        lMegaupload->setPsig(l);;
    }
}

void Download_Handler::addMediafire(Link* l)
{
    if(lMediafire==NULL)
    {
        lMediafire=l;
    }
    else
    {
        lMediafire->setPsig(l);
    }
}

void Download_Handler::setMegaupload()
{
    megaupload=true;
}

void Download_Handler::setMediafire()
{
    mediafire=true;
}

void Download_Handler::unsetAll()
{
    megaupload=mediafire=false;
}

void Download_Handler::run()
{
    if(megaupload)
    {
        downMegaupload();
    }
    else if(mediafire)
    {
        cout<<"hola"<<endl;
    }
}

void Download_Handler::downMegaupload()
{
    while(lMegaupload!=NULL)
    {
            SMegaupload(lMegaupload);
            lMegaupload=lMegaupload->getPsig();
    }
}

void Download_Handler::SMegaupload(Link *link)
{
    bool valido=true, valido2=true, valido3=true, valido4=true;
    QTreeWidgetItem* item=new QTreeWidgetItem(tMainList);
    Megaupload *m=new Megaupload(link->getDir(), tMainList);
    do
    {
            m->InicializarDatos(link->getDir());
            valido3=m->DescargaUrl();
            if(valido3)
            {
                cout<<link->getPos()<<endl;
                    item=tMainList->itemAt(0, link->getPos());
                    item->setText(1, "Analizando captcha");
                    valido=m->AnalizaCaptcha();
                    if(valido)
                    {
                            valido2=m->CaptchaValido();
                    }
            }
    }
    while(!valido2 || !valido || !valido3);

    do
    {
            valido4=m->DescargaFichero();
    }
    while(!valido4);

    delete m;
    m=NULL;
}
