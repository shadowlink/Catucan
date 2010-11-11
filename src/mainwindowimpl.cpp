#include "mainwindowimpl.h"

//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);
	connect(btAdd, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(btStart, SIGNAL(clicked()), this, SLOT(startClicked()));
        connect(btAgregar, SIGNAL(clicked()), this, SLOT(insertClicked()));
        d=new Downloader(tMainList);
        main=tabMain;
}
//

void MainWindowImpl::addClicked()
{
        QString nombre="";
        if(edText->text() == "") // Si no hay nada no añade nada
		return;
        d->NuevoLink(edText->text()); //Crea un nuevo nodo de descarga
        lbMyList->addItem(d->getUltimo()->getNombre()); // Añade el nombre real del archivo a la lista
        edText->setText(""); // Borra el texto de la linea de insercion
        edText->setFocus(); // Pone el foco en la linea de insercion
}

void MainWindowImpl::insertClicked()
{
    int tam = lbMyList->count(), i=0;

    for(i=0; i<tam; i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(tMainList);
        item->setText(0, lbMyList->item(i)->text());
        item->setText(1, "hola");
        item->setText(2, "hola");
        item->setText(3, "hola");
        item->setText(4, "hola");
        item->setText(5, "hola");
    }
    lbMyList->clear();
}

void MainWindowImpl::startClicked()
{
   // if(lbMainList->count()>0)
    //{
        d->start();
    //}
}

void MainWindowImpl::threadFinished()
{
    cout<<"HE TERMINADO"<<endl;
}

//####################################################
