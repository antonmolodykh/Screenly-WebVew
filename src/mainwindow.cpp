#include "mainwindow.h"
#include "view.h"
#include <QDebug>

MainWindow::MainWindow() : QMainWindow()
{
    view = new View(this);
    setCentralWidget(view);
    show();
}

void MainWindow::loadPage(QString uri)
{
    qDebug()<<"MainWindow::loadPage";
    view->loadPage(uri);
}

void MainWindow:: loadImage(QString uri)
{
    qDebug()<<"MainWindow::loadImage";
    view->loadImage(uri);
}
