#include "qcolor.h"
#include <QGraphicsDropShadowEffect>

Qcolor::Qcolor(Grille *grilleJeu, int numCase)
{
    setAlignment(Qt::AlignCenter);
    this->gameBoard = grilleJeu;
    this->valeurCase = grilleJeu->getValue(numCase);
}

void Qcolor::draw(){
    if(valeurCase == 0){
        setText("");
        setStyleSheet("Qcolor { background: rgb(204,192,179); border-radius: 10px; }");
    } else {
        setText(QString::number(valeurCase));
        switch (valeurCase) {
        case 2: {
            setStyleSheet("Qcolor { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 4: {
            setStyleSheet("Qcolor { background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 8: {
            setStyleSheet("Qcolor { background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 16: {
            setStyleSheet("Qcolor { background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 32: {
            setStyleSheet("Qcolor { background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 64: {
            setStyleSheet("Qcolor { background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 128: {
            setStyleSheet("Qcolor { background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 256: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(20);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("Qcolor { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 512: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(30);
            dse->setOffset(-1);
           setGraphicsEffect(dse);
            setStyleSheet("Qcolor { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 1024: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(40);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("Qcolor { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 2048: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(50);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("Qcolor { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        default: {
            setStyleSheet("Qcolor { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        }
    }
}
