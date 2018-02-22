#include <QApplication>
#include "mainwindow.h"
#include <QWebView>
#include <QtDBus>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow();

    QDBusConnection connection = QDBusConnection::sessionBus();

    if (!connection.registerObject("/Screenly", window,  QDBusConnection::ExportAllSlots))
    {
        fprintf(stderr, "%s\n",
                qPrintable("Can't register object"));
        exit(1);
    }
    qDebug()<<"WebView connected to D-bus";

    if (!connection.registerService("screenly.webview")) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::sessionBus().lastError().message()));
        exit(1);
    }
    qDebug()<<"Screenly service start";


    return app.exec();
}
