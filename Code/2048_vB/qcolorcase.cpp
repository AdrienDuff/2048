#include "qcolorcase.h"
#include <QGraphicsDropShadowEffect>

Qcolorcase::Qcolorcase(Grille *grilleJeu, int numCase)
{
    setAlignment(Qt::AlignCenter);
    this->gameBoard = grilleJeu;
    this->valeurCase = grilleJeu->getValue(numCase);
}

void Qcolorcase::draw(){
    if(valeurCase == 0){
        setText("");
        setStyleSheet("Qcolorcase { background: rgb(138,138,138); border-radius: 10px; }");
    } else {
        setText(QString::number(valeurCase));
        switch (valeurCase) {
        case 2: {
            setStyleSheet("Qcolorcase { background: rgb(165,255,235); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 4: {
            setStyleSheet("Qcolorcase { background: rgb(105,255,102); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 8: {
            setStyleSheet("Qcolorcase { background: rgb(105,255,152); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 16: {
            setStyleSheet("Qcolorcase { background: rgb(0,255,158); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 32: {
            setStyleSheet("Qcolorcase { background: rgb(0,128,255); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 64: {
            setStyleSheet("Qcolorcase { background: rgb(0,204,0); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 128: {
            setStyleSheet("Qcolorcase { background: rgb(0,0,204); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 256: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(20);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("Qcolorcase { background: rgb(0,204,204); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 512: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(30);
            dse->setOffset(-1);
           setGraphicsEffect(dse);
            setStyleSheet("Qcolorcase { background: rgb(153,0,153); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 1024: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(40);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("Qcolorcase { background: rgb(96,96,96); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 2048: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(50);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("Qcolorcase { background: rgb(0,102,51); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 4096: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(50);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("Qcolorcase { background: rgb(153,76,0); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        case 8192: {
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(50);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("Qcolorcase { background: rgb(0,0,102); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        default: {
            setStyleSheet("Qcolorcase { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
            break;
        }
        }
    }
}
