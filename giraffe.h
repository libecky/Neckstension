#ifndef GIRAFFE_H
#define GIRAFFE_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QActionGroup>
#include <QObject>
#include "neck.h"

/**
 * @brief The Giraffe class
 * is used to represent Necky's head, specifically, the portion that counts towards
 * collisions with objects. Giraffe is a QGraphicsItem. The function spawn is used to spawn flying objects.
 */

class Giraffe: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Giraffe(QGraphicsItem * parent = 0);

public slots:

    // Spawns food
    void spawn();

};

#endif // GIRAFFE_H
