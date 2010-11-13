 #ifndef DOWNLOADMANAGER_H
 #define DOWNLOADMANAGER_H

 #include <QFile>
 #include <QObject>
 #include <QQueue>
 #include <QTime>
 #include <QUrl>
 #include <QNetworkAccessManager>

 #include "textprogressbar.h"

 class DownloadManager: public QObject
 {
     Q_OBJECT
 public:
     DownloadManager();
     DownloadManager(QString filename);
     bool startNextDownload(QUrl);
     QString saveFileName(const QUrl &url);

 signals:
     void finished();

 private slots:
    void downloadReadyRead();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);

 private:
     QNetworkAccessManager manager;
     QQueue<QUrl> downloadQueue;
     QNetworkReply *currentDownload;
     QFile output;
     QTime downloadTime;
     TextProgressBar progressBar;
     QString filename;

     int downloadedCount;
     int totalCount;
 };

 #endif
