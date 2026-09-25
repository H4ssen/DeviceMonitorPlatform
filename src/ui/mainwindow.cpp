#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton* connect = new QPushButton("Connect");
    QWidget* widget = new QWidget(this);
    QVBoxLayout* lyout = new QVBoxLayout(widget);
    lyout->addWidget(connect);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}
