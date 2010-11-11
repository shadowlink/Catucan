#include "megaupload.h"
//
using namespace std;


size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

Megaupload::Megaupload(QString link, QTreeWidget* t)
{
    linea="";
	captchacode="";
	megavar="";
	captcha="";
	captchaDir="";
	downloadlink="";
	nombre="";
	megalink=link.toStdString();
        tMainList=t;
}

Megaupload::~Megaupload()
{
    linea="";
	captchacode="";
	megavar="";
	captcha="";
	captchaDir="";
	downloadlink="";
	megalink="";
	nombre="";
}

void Megaupload::InicializarDatos(QString link)
{
    linea="";
	captchacode="";
	megavar="";
	captcha="";
	captchaDir="";
	downloadlink="";
	megalink=link.toStdString();
	nombre="";
}

void Megaupload::run()
{
    QString megalinkBack=megalink.c_str();
    bool valido=true, valido2=true, valido3=true, valido4=true;
    do
    {
           InicializarDatos(megalinkBack);
            valido3=DescargaUrl();
            if(valido3)
            {
                    valido=AnalizaCaptcha();
                    if(valido)
                    {
                            valido2=CaptchaValido();
                    }
            }
    }
    while(!valido2 || !valido || !valido3);

    do
    {
            valido4=DescargaFichero();
    }
    while(!valido4);
    QThread::exit(0);
}

bool Megaupload::DescargaUrl()
{
	size_t found;
	bool correcto=true;
	char cMegalink[100]="";
	strcpy(cMegalink, megalink.c_str());
	curl = curl_easy_init();
	cout<<cMegalink<<endl;
	html = fopen("html.txt","wb");
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
				found=linea.find("captchacode");
				if (found!=string::npos)
				{
					for(int i=48; i<=67; i++)
					{
						captchacode+=linea[i];
					}
				}

				found=linea.find("megavar");
				if (found!=string::npos)
				{
					int i=44;			
					do{
						megavar+=linea[i];
						i++;
					}
					while(linea[i]!='"');
				}
				
				found=linea.find("<TD width=\"100\" align=\"center\" height=\"40\"><img src=\"");
				if (found!=string::npos)
				{
					for(int i=55; i<=114; i++)
					{
						captchaDir+=linea[i];
					}
				}

				found=linea.find("Filename:</font> <font style=\"font-family:arial; color:#FF6700; font-size:18px; font-weight:bold;\">");
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
	return correcto;
}

bool Megaupload::AnalizaCaptcha()
{
	bool correcto=true;
	char c[200]="";
	strcpy(c, captchaDir.c_str());

	cout<<"###########"<<endl;
	cout<<captchaDir<<endl;
	cout<<c<<endl;
	cout<<"###########"<<endl;
	
	if ( (captcha_download = fopen ("gen.gif" , "wb" ) ) != NULL )
	{
		curl = curl_easy_init();
		if(curl)
		{
			curl_easy_setopt(curl, CURLOPT_URL, c);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, captcha_download);
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);
		
			if (res == CURLE_OK)
			{
				cout<<"Captcha descargado!"<<endl;
			}
			else
			{
				cout<<"Captcha no descargado"<<endl;
				correcto=false;
			}
		}
		fclose(captcha_download);
	}

	#ifdef WINDOWS
		Sleep(5);
	#else
		sleep(5);
	#endif
	
	if(correcto)
	{
		system("convert -depth 8 -alpha off gen.gif gen.tif");
		system("tesseract gen.tif gen");
		imagen.open("gen.txt", ios::in);
		if(imagen.is_open())
		{
			getline(imagen, linea);
			captcha=linea;
		}
		imagen.close();
	}
	
	return correcto;
}

bool Megaupload::DescargaFichero()
{
	bool correcto=true;
	size_t found;
	char cCaptcha[200]="captcha=", cCaptchacode[200]="&captchacode=", cMegavar[1000]="&megavar=";
	strcat(cCaptcha, captcha.c_str());
	strcat(cCaptchacode, captchacode.c_str());
	strcat(cMegavar, megavar.c_str());
	char data[2000]="";
	strcat(data, cCaptcha);
	strcat(data, cCaptchacode);
	strcat(data, cMegavar);
	char cMegalink[100]="";
	strcpy(cMegalink, megalink.c_str());
	cout<<data<<endl;
	html2 = fopen("html2.txt","wb");
	curl = curl_easy_init();
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		curl_easy_setopt(curl, CURLOPT_URL, cMegalink);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, html2);
		curl_easy_perform(curl);	
		curl_easy_cleanup(curl);
		if (res == CURLE_OK)
		{
			cout<<"Html2 descargado!"<<endl;
		}
		else
		{
			cout<<"Html2 no descargado"<<endl;
		}
	}
    
    fclose(html2);
                
	docHtml2.open("html2.txt", ios::in);
	if(docHtml2.is_open())
	{
		getline(docHtml2, linea);
		while(!docHtml2.eof())
		{
			found=linea.find("downloadlink");
			if (found!=string::npos)
			{
				int j=95;				
				do{
					downloadlink+=linea[j];
					j++;
				}
				while(linea[j]!='"');
				break;
			}
			getline(docHtml2, linea);
		}
	}
	docHtml2.close();
    cout<<"Esperando..."<<endl;	

	#ifdef WINDOWS
    	Sleep(47000);
	#else
        sleep(47);
	#endif

	if(downloadlink!="")
	{
		char cDownloadlink[300]="";
		char cNombre[400]="";
		strcpy(cDownloadlink, "wget ");
		strcat(cDownloadlink, downloadlink.c_str());
		strcpy(cNombre, nombre.c_str());
                DownloadManager manager;
                QString d=downloadlink.c_str();
                QUrl a=d;
                manager.startNextDownload(a);
                //system(cDownloadlink);
	}
	else
	{
		correcto=false;
	}
	return correcto;
}

bool Megaupload::CaptchaValido()
{
	bool valido=true;

	cout<<"El captcha es: "<<captcha<<endl;
	int tam=captcha.length();
	if(tam==4)
	{
		for(int i=0; i<4; i++)
		{
			if((captcha[i]>=65 && captcha[i]<=90) || (captcha[i]>=48 && captcha[i]<=57))
			{
				
			}
			else
			{
				cout<<"No Valido"<<endl;
				valido=false;
			}
			cout<<captcha[i]<<endl;
		}
	}
	else
	{
		cout<<"No valido"<<endl;
		valido=false;
	}

	return valido;
}
//
