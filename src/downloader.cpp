#include "downloader.h"
//
#include <string>

using namespace std;

int contLink=0;

Downloader::Downloader(QTreeWidget* tree)
{
	lista=NULL;
        tMainList=tree;
}

Downloader::~Downloader()
{
	lista=NULL;
}

void Downloader::run()
{
    DescargaLista();
}

bool Downloader::ListaVacia()
{
	bool vacio=false;
	if(lista==NULL)
		vacio=true;
	return vacio;
}

Link* Downloader::getUltimo()
{
    return pUlt;
}

QString Downloader::DetectarServicio(QString enlace)
{
	QString servicio;
	int found;
	
	found=enlace.indexOf("megaupload");
	if(found>-1)
		servicio="Megaupload";
	return servicio;
}

QString Downloader::DetectarNombre(QString enlace)
{
    QString nombre="";
    CURLcode res;
    string link="", linea="";
    FILE * html;
    size_t found;
    bool correcto=true;
    char cMegalink[100]="";
    CURL *curl;
    ifstream docHtml;

    curl = curl_easy_init();
    html = fopen("html.txt","wb");

    if(pUlt->getServicio()=="Megaupload")
    {
        link=enlace.toStdString();
        strcpy(cMegalink, link.c_str());
        if(curl)
        {
                curl_easy_setopt(curl, CURLOPT_URL, cMegalink);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, html);
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
                if (res == CURLE_OK)
                {
                        cout<<"Html descargado"<<endl;
                }
                else
                {
                        cout<<"Html no descargado"<<endl;
                        correcto=false;
                }
        }
        fclose(html);
        if(correcto)
        {
                docHtml.open("html.txt", ios::in);
                if(docHtml.is_open())
                {
                        getline(docHtml, linea);
                        while(!docHtml.eof())
                        {
                            found=linea.find("Filename:</font> <font style=\"font-family:arial;");
                            if (found!=string::npos)
                            {
                                bool marca=true;
                                for(int i=183; i<=linea.length(); i++)
                                {
                                        if(marca==true)
                                        {
                                                if(linea[i]!='<')
                                                        nombre+=linea[i];
                                                else
                                                        marca=false;
                                        }
                                }
                            }
                            getline(docHtml, linea);
                        }
                }
         }
        docHtml.close();
    }
    else
    {
        nombre="null";
    }
    return nombre;
}

void Downloader::NuevoLink(QString enlace)
{
	QString servicio;
	servicio=DetectarServicio(enlace);
        Link* link=new Link(contLink);
	link->setDir(enlace);
	link->setServicio(servicio);
	if(ListaVacia())
	{
		lista=link;
		pUlt=lista;
	}
	else
	{
		pUlt->setPsig(link);
		pUlt=link;
	}
        link->setNombre(DetectarNombre(enlace));
        contLink++;
}

void Downloader::DescargaLista()
{
        Download_Handler *d=new Download_Handler(tMainList);
        bool megaupload=false, mediafire=false;
	while(lista!=NULL)
	{
		if(lista->getServicio()=="Megaupload")
		{
                        d->addMegaupload(lista);
                        megaupload=true;
		}
                else if(lista->getServicio()=="Mediafire")
                {
                    d->addMediafire(lista);
                    mediafire=true;
                }
		lista=lista->getPsig();
	}
        if(megaupload)
        {
            d->unsetAll();
            d->setMegaupload();
            d->start();
        }
        else if(mediafire)
        {
            d->unsetAll();
            d->setMediafire();
            d->start();
        }

}
//
