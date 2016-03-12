#ifndef NECK_H
#define NECK_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

/**
 * @brief The Neck class
 * represents the rest of Necky's body. Flying objects will move past the body without
 * counting as a collision.
 */

class Neck: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Neck(QGraphicsItem * parent = 0);
};

#endif NECK_H
