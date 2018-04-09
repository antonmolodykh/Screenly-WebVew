#include <QDebug>
#include <QFileInfo>
#include <QUrl>
#include <QStandardPaths>

#include "view.h"


View::View(QWidget* parent) : QWebView(parent)
{
    // Need to convert this to a new syntax
    connect(QWebView::page()->networkAccessManager(), SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),
            this, SLOT(handleAuthRequest(QNetworkReply*,QAuthenticator*)));
}

void View::loadPage(const QString &uri)
{
    qDebug() << "Type: Webpage";
    stop();
    load(QUrl(uri));
}

void View::loadImage(const QString &preUri)
{
    qDebug() << "Type: Image";
    QFileInfo fileInfo = QFileInfo(preUri);
    QString uri;

    if (fileInfo.isFile())
    {
        qDebug() << "Location: Local File";
        uri = QUrl::fromLocalFile(fileInfo.absoluteFilePath()).toEncoded();
    }
    else
    {
        qDebug() << "Location: Remote URL";
        uri = preUri;
    }

    QString script = "window.setimg = function (" + uri + ") {"
                     " var i = new Image();"
                     " i.onload = function() {"
                     "   document.body.style.backgroundSize = i.width > window.innerWidth || i.height > window.innerHeight ? 'contain' : 'auto';"
                     "   document.body.style.backgroundImage = 'url(' + " + uri + " + ')';"
                     " }"
                     " i.src =" + uri + ";"
                     "}";
    QString styles = "background-image: url(" + uri + "); background-color: rgb(0, 0, 0); background-size: contain; background-position: 50% 50%; background-repeat: no-repeat no-repeat;";

    stop();
    setHtml("<html><head><script>" + script + "</script></head><body style='" + styles + "'></body></html>");
}

void View::handleAuthRequest(QNetworkReply* reply, QAuthenticator* auth)
{
    Q_UNUSED(reply)
    Q_UNUSED(auth)
    load(QUrl::fromLocalFile(QStandardPaths::locate(QStandardPaths::DataLocation, "res/access_denied.html")));
}
