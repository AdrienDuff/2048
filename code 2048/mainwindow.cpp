#include "mainwindow.h"
//#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) /*,
    ui(new Ui::MainWindow)*/
{
 //   ui->setupUi(this);
    jeu = new QJeu(this);
    setCentralWidget(jeu);
}

MainWindow::~MainWindow()
{
  //  delete ui;
}
