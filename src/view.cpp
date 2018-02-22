#include "view.h"
#include <QFileInfo>
#include <QUrl>
#include <QDebug>

View::View(QWidget* parent) : QWebView(parent)
{
    connect(QWebView::page()->networkAccessManager(), SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),
            this, SLOT(handleAuthRequest(QNetworkReply*,QAuthenticator*)));
}

void View::loadPage(QString uri)
{
    qDebug() << "Type: Webpage";
    this->stop();
    this->load(QUrl(uri));
}

void View::loadImage(QString preUri)
{
    qDebug() << "Type: Image";
    QFileInfo fileInfo = QFileInfo();
    fileInfo.setFile(preUri);
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
                      "var i = new Image();"
                      "i.onload = function() {"
                        "document.body.style.backgroundSize = i.width > window.innerWidth || i.height > window.innerHeight ? 'contain' : 'auto';"
                        "document.body.style.backgroundImage = 'url(' + " + uri + " + ')';"
                      "}"
                      "i.src =" + uri + ";"
                     "}";
    QString styles = "background-image: url(" + uri + "); background-color: rgb(0, 0, 0); background-size: contain; background-position: 50% 50%; background-repeat: no-repeat no-repeat;";

    this->stop();
    this->setHtml("<html><head><script>" + script + "</script></head><body style='" + styles + "'></body></html>");
}

void View::handleAuthRequest(QNetworkReply*, QAuthenticator*)
{
    this->load(QUrl("file:///usr/local/share/ScreenlyWebview/res/access_denied.html"));
}
