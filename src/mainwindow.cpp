#include "mainwindow.h"
#include "view.h"


MainWindow::MainWindow() : QMainWindow()
{
    view = new View(this);
    setCentralWidget(view);
}

void MainWindow::loadPage(const QString &uri)
{
    view->loadPage(uri);
}

void MainWindow:: loadImage(const QString &uri)
{
    view->loadImage(uri);
}
