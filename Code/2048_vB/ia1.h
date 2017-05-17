#ifndef IA1_H
#define IA1_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <QVector>

class IA1
{
protected:

private:
    int meilleur_op;
    QVector<int> grille_IA;
    int node;
    int max_depth;

public:
    IA1();
    int estimate();
};

#endif // IA1_H
