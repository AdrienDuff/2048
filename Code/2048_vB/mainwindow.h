#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qjeu.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
//    Ui::MainWindow *ui;
    QJeu *jeu;

};

#endif // MAINWINDOW_H
