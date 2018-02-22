#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebView>
#include "view.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow();

    public slots:
        void loadPage(QString uri);
        void loadImage(QString uri);

    private:
        View *view;

};

#endif // MAINWINDOW_H
