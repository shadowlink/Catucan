#include "downloadmanager.h"

#include <QFileInfo>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QStringList>
#include <QTimer>
#include <QEventLoop>

DownloadManager::DownloadManager()
{
	filename="";
}

DownloadManager::DownloadManager(QString filename)
{
	this->filename=filename;
}

QString DownloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download";

    if (QFile::exists(basename)) {
        // already exists, don't overwrite
        int i = 0;
        basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }

    return basename;
}

bool DownloadManager::startNextDownload(QUrl link)
{
    QUrl url = link;
    currentDownload= manager.get(QNetworkRequest(link));
    QEventLoop loop;
    connect(currentDownload, SIGNAL(downloadProgress(qint64,qint64)), SLOT(downloadProgress(qint64,qint64)));
    connect(currentDownload, SIGNAL(finished()),&loop, SLOT(quit()));
    loop.exec();

	if(filename.toStdString()=="")
	{
	    filename =  saveFileName(url);
	    output.setFileName(filename);
	    if (!output.open(QIODevice::WriteOnly)) {
	        fprintf(stderr, "Problem opening save file '%s' for download '%s': %s\n",
	                qPrintable(filename), url.toEncoded().constData(),
	                qPrintable(output.errorString()));
	
        return false;
       }
    }
    else
    {
    	output.setFileName(filename);
   	}
    output.write(currentDownload->readAll());

    progressBar.clear();
    output.close();
    currentDownload->deleteLater();
    return true;
}

void DownloadManager::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    progressBar.setStatus(bytesReceived, bytesTotal);

    // calculate the download speed
    double speed = bytesReceived * 1000.0 / downloadTime.elapsed();
    QString unit;
    if (speed < 1024) {
        unit = "bytes/sec";
    } else if (speed < 1024*1024) {
        speed /= 1024;
        unit = "kB/s";
    } else {
        speed /= 1024*1024;
        unit = "MB/s";
    }

    progressBar.setMessage(QString::fromLatin1("%1 %2")
                           .arg(speed, 3, 'f', 1).arg(unit));
    progressBar.update();
}

void DownloadManager::downloadReadyRead()
{
    output.write(currentDownload->readAll());
}
