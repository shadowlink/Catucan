#include "mainwindowimpl.h"

int countItems=0;

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
        QString link="";
        QTextCursor tc = textAdd->textCursor();
        tc.movePosition( QTextCursor::Start );

        while(!tc.atEnd())
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(tComprobados);
            tc.select( QTextCursor::LineUnderCursor );
            link=tc.selectedText();
            d->NuevoLink(link);
            item->setText(0, d->getUltimo()->getNombre());
            tc.removeSelectedText();
            tc.movePosition( QTextCursor::Down );
            textAdd->setTextCursor(tc);
            countItems++;
        }
        tc.movePosition( QTextCursor::Start );
        textAdd->setTextCursor(tc);
}

void MainWindowImpl::insertClicked()
{
    int i=0;
    QTreeWidgetItem *item2 = new QTreeWidgetItem(tComprobados);
    for(i=0; i<countItems; i++)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(tMainList);
        item2=tComprobados->itemAt(0, i*17);
        item->setText(0, item2->text(0));
        tComprobados->removeItemWidget(item2, 0);
    }
    countItems=0;
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
